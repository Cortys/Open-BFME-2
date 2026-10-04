#!/usr/bin/env python3
"""Close banked near-misses by random source permutation (decomp-permuter style).

A banked attempt (reverse/attempts/<rva>.cpp) is a standalone unit whose body
compiles close to, but not exactly, retail's bytes. This mutates the source
text, recompiles each candidate and keeps the ones whose bytes get closer,
until the body matches exactly or the time budget runs out.

Mutations need not be provably semantics-preserving: a candidate is only ever
reported as a win when its resolved bytes equal retail's exactly, and identical
machine code is the proof of identical behaviour. Nothing here lands a row;
a win is written to build/permute/<rva>/win.cpp for tools/add_match.py and the
normal gates.

Every candidate compiles inside build/permute/<rva>/, never to a real source's
object, so the shared object cache (build/match/) is untouched.

Usage:
  python3 tools/permute.py --list [--min-score 0.9]       the queue, best first
  python3 tools/permute.py RVA [RVA ...] [--minutes 10]   permute these attempts
  python3 tools/permute.py --top N [--min-score 0.9] [--minutes 10] [--jobs J]
  python3 tools/permute.py --recheck     compile every banked attempt once; exact ones become wins
  python3 tools/permute.py --land        land every win via add_match, then commit
"""
import argparse
import concurrent.futures
import difflib
import hashlib
import json
import os
import random
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402

ATTEMPTS = ROOT / "reverse" / "attempts"
LOG = ROOT / "reverse" / "re_attempts.log"
OUT = ROOT / "build" / "permute"


# ----------------------------------------------------------------- queue

def attempt_sizes():
    """{(symbol, rva lower): size} from re_attempts.log, last entry wins."""
    sizes = {}
    for line in LOG.open(encoding="utf-8", errors="replace"):
        parts = line.rstrip("\n").split("\t")
        if len(parts) > 3:
            try:
                sizes[(parts[0], parts[1].lower())] = int(parts[2])
            except ValueError:
                pass
    return sizes


def queue(min_score=0.9):
    """[(score, size, rva, symbol)] for banked attempts, highest score x size first."""
    sizes = attempt_sizes()
    out = []
    for path in ATTEMPTS.glob("0x*.cpp"):
        head = path.read_text(encoding="latin-1", errors="replace")[:400]
        symbol = re.match(r"//\s*(\S+)", head)
        score = re.search(r"score=([0-9.]+)", head)
        if not symbol or not score:
            continue
        rva = path.stem.lower()
        size = sizes.get((symbol.group(1), rva))
        if size and float(score.group(1)) >= min_score:
            out.append((float(score.group(1)), size, rva, symbol.group(1)))
    return sorted(out, key=lambda item: (-item[0] * item[1], item[2]))


# ----------------------------------------------------------------- scoring

class Scorer:
    def __init__(self, rva, symbol, size, workdir):
        self.rva, self.symbol, self.size, self.dir = rva, symbol, size, workdir
        self.symbol_map = build.load_symbol_map()
        self.seen = {}
        self.trials = 0
        self.hits = 0  # consecutive candidates already compiled: the search is spinning
        self.unresolved = False
        self.last = None

    def score(self, text):
        """(fitness 0..1, exact) for a candidate source; (-1, False) if it does not compile."""
        key = hashlib.sha1(text.encode("latin-1", "replace")).hexdigest()
        if key in self.seen:
            self.hits += 1
            return self.seen[key]
        self.hits = 0
        self.trials += 1
        source = self.dir / f"t{self.trials % 4}.cpp"
        output = source.with_suffix(".obj")
        source.write_text(text, encoding="latin-1", errors="replace")
        result = (-1.0, False)
        try:
            ok, _, _ = build.try_compile_source(source, output)
            if ok:
                row = {"name": self.symbol, "target_rva": self.rva, "target_size": str(self.size),
                       "source": source.relative_to(ROOT).as_posix(), "notes": ""}
                got = build.compile_function(row, self.symbol_map, output)
                compiled, target = got["bytes"], got["target"]
                self.unresolved = bool(got["unresolved"])
                self.last = (compiled, target)
                if compiled == target and not got["unresolved"]:
                    result = (1.0, True)
                else:
                    result = (fitness(compiled, target), False)
        except (SystemExit, Exception):  # a symbol the candidate no longer emits, etc.
            result = (-1.0, False)
        self.seen[key] = result
        return result


_DISASM = None


def _instructions(blob):
    global _DISASM
    if _DISASM is None:
        import capstone
        _DISASM = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return [(insn.mnemonic, insn.op_str) for insn in _DISASM.disasm(bytes(blob), 0)]


def unreachable(compiled, target):
    """Why no source reordering can close this body, or None.

    When every instruction already has retail's mnemonic and registers and
    only numbers differ (displacements, immediates), the gap is a layout,
    offset or constant fact: mutations only move statements and operators."""
    try:
        ours, theirs = _instructions(compiled), _instructions(target)
    except Exception:
        return None
    if not ours or len(ours) != len(theirs) or [m for m, _ in ours] != [m for m, _ in theirs]:
        return None
    strip = lambda op: re.sub(r"0x[0-9a-f]+|\b\d+\b", "#", op)
    differing = [(a, b) for (_, a), (_, b) in zip(ours, theirs) if a != b]
    if differing and all(strip(a) == strip(b) for a, b in differing):
        return f"only constants or offsets differ ({len(differing)} instruction(s)): a layout fact, not an order"
    return None


def fitness(compiled, target):
    """0..1 closeness of two bodies (exact is checked separately).

    A byte ratio is nearly flat across the changes a mutation causes: a
    register swap or a reordered pair rewrites many bytes. Instruction
    alignment sees them: the mnemonic sequence carries most of the weight,
    full instructions (operands) refine it, the byte ratio breaks ties."""
    ratio = lambda a, b: difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()
    try:
        ours, theirs = _instructions(compiled), _instructions(target)
    except Exception:  # no capstone: bytes alone, as before
        return ratio(compiled, target)
    if not ours or not theirs:
        return ratio(compiled, target)
    return (0.5 * ratio([m for m, _ in ours], [m for m, _ in theirs])
            + 0.3 * ratio(ours, theirs)
            + 0.2 * ratio(compiled, target))


# ----------------------------------------------------------------- mutations

BODY_START = re.compile(r"^[^\s#/][^;{}]*\)\s*(?:const\s*)?\{?\s*$")
CMP = re.compile(r"(\b[\w.\->\[\]]+)\s*(<=|>=|<|>)\s*([\w.\->\[\]]+\b)")
EQ = re.compile(r"(\b[\w.\->\[\]]+)\s*(==|!=)\s*([\w.\->\[\]]+\b)")
COMMUTE = re.compile(r"(\b[A-Za-z_][\w.\->\[\]]*)\s*([+*&|^])\s*([A-Za-z_][\w.\->\[\]]*\b)(?!\s*[(\[])")
MIRROR = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
SIGNS = [("unsigned int ", "int "), ("unsigned char ", "char "), ("unsigned short ", "short "),
         ("unsigned long ", "long ")]
FLAG_SWAPS = [("/O1", "/O2"), ("/O2", "/O1"), ("/O2", "/Ox"), ("/Ox", "/O2"), ("/Ob2", "/Ob1"),
              ("/Ob1", "/Ob2"), ("/G6", "/G7"), ("/G7", "/G6")]
# flags toggled on or off: x87 store/reload order (/Op), frame pointer (/Oy-)
FLAG_TOGGLES = ["/Op", "/Oy-"]


def body_lines(lines, focus=None):
    """Indexes of lines inside function bodies (between a definition's braces);
    with `focus` (a regex for the target's name), only the target's body, so
    mutations never spend trials on the unit's other functions. Falls back to
    every body when the target's definition cannot be found."""
    out, depth, inside, keep = [], 0, False, True
    for i, line in enumerate(lines):
        stripped = line.strip()
        if not inside and BODY_START.match(line) and "class " not in line and "struct " not in line:
            inside, depth = True, 0
            keep = focus is None or bool(re.search(focus, line))
        if inside:
            depth += line.count("{") - line.count("}")
            if keep and depth > 0 and stripped and not stripped.startswith(("//", "#", "{", "}")):
                out.append(i)
            if depth <= 0 and "}" in line:
                inside = False
    if focus is not None and not out:
        return body_lines(lines)
    return out


def focus_of(symbol):
    """Regex for the definition line of the function a mangled name denotes."""
    found = re.match(r"\?(\w+)@(?:(\w+)@@)?", symbol or "")
    if not found or symbol.startswith("??"):
        return None  # constructors, destructors, operators: keep every body
    name = rf"\b{found.group(2)}\s*::\s*{found.group(1)}\s*\(" if found.group(2) else rf"\b{found.group(1)}\s*\("
    return name


def statement(line):
    s = line.strip()
    return s.endswith(";") and not re.match(r"(return|break|continue|goto|case|default)\b", s)


def mutate(text, rng, focus=None):
    lines = text.split("\n")
    body = body_lines(lines, focus)
    kinds = ["swap", "swap", "cmp", "eq", "commute", "incr", "sign", "flag", "move", "ifelse",
             "const", "forwhile"]
    body_set = set(body)

    def indent(line):
        return len(line) - len(line.lstrip())

    for _ in range(12):
        kind = rng.choice(kinds)
        if kind == "swap" and len(body) > 1:
            # swap two statements of one block up to 3 lines apart
            i = rng.choice(body[:-1])
            j = i + rng.choice((1, 1, 2, 3))
            if j in body_set and statement(lines[i]) and statement(lines[j]) and \
                    indent(lines[i]) == indent(lines[j]) and \
                    all(k in body_set and indent(lines[k]) >= indent(lines[i]) and "{" not in lines[k]
                        and "}" not in lines[k] for k in range(i, j + 1)):
                lines[i], lines[j] = lines[j], lines[i]
                return "\n".join(lines), kind
        elif kind == "move" and len(body) > 1:
            # move one statement (often a local declaration) up or down one line
            i = rng.choice(body)
            j = i + rng.choice((-1, 1))
            if j in body_set and statement(lines[i]) and indent(lines[i]) == indent(lines[j]) and \
                    "{" not in lines[j] and "}" not in lines[j]:
                line = lines.pop(i)
                lines.insert(j, line)
                return "\n".join(lines), kind
        elif kind == "const" and body:
            # toggle const on a local declaration with an initializer
            i = rng.choice(body)
            found = re.match(r"^(\s*)(const\s+)?([A-Za-z_][\w:<>]*(?:\s+[A-Za-z_]\w*)*\s*\**\s*[A-Za-z_]\w*\s*=[^=].*;)\s*$",
                             lines[i])
            if found and not re.match(r"\s*(return|delete|throw)\b", lines[i]):
                lines[i] = found.group(1) + ("" if found.group(2) else "const ") + found.group(3)
                return "\n".join(lines), kind
        elif kind == "forwhile" and body:
            # for (init; cond; step) { B }  ->  init; while (cond) { B step; }
            i = rng.choice(body)
            found = re.match(r"^(\s*)for \(([^;]*);([^;]*);([^)]*)\)\s*$", lines[i])
            if found and i + 1 < len(lines) and lines[i + 1].strip() == "{":
                pad, init, cond, step = found.group(1), found.group(2).strip(), found.group(3).strip(), found.group(4).strip()
                depth, k = 0, i + 1
                while k < len(lines):
                    depth += lines[k].count("{") - lines[k].count("}")
                    if depth == 0:
                        break
                    k += 1
                inner = lines[i + 2:k]
                if k < len(lines) and cond and step and not any(re.search(r"\bcontinue\b", l) for l in inner):
                    head = ([f"{pad}{init};"] if init else []) + [f"{pad}while ({cond})", f"{pad}{{"]
                    lines[i:k + 1] = head + inner + [f"{pad}\t{step};", f"{pad}}}"]
                    return "\n".join(lines), kind
        elif kind == "ifelse" and body:
            # if (c) { A } else { B }  ->  if (!(c)) { B } else { A }, braces on own lines
            i = rng.choice(body)
            found = re.match(r"^(\s*)if \((.*)\)\s*$", lines[i])
            if found and i + 1 < len(lines) and lines[i + 1].strip() == "{":
                pad = found.group(1)
                depth, k = 0, i + 1
                while k < len(lines):
                    depth += lines[k].count("{") - lines[k].count("}")
                    if depth == 0:
                        break
                    k += 1
                if k + 2 < len(lines) and lines[k + 1].strip() == "else" and lines[k + 2].strip() == "{":
                    depth, m = 0, k + 2
                    while m < len(lines):
                        depth += lines[m].count("{") - lines[m].count("}")
                        if depth == 0:
                            break
                        m += 1
                    if m < len(lines):
                        then_block, else_block = lines[i + 1:k + 1], lines[k + 2:m + 1]
                        lines[i:m + 1] = ([f"{pad}if (!({found.group(2)}))"] + else_block +
                                          [f"{pad}else"] + then_block)
                        return "\n".join(lines), kind
        elif kind in ("cmp", "eq", "commute", "incr", "sign") and body:
            i = rng.choice(body)
            line = lines[i]
            if kind == "cmp":
                new = CMP.sub(lambda m: f"{m.group(3)} {MIRROR[m.group(2)]} {m.group(1)}", line, count=1)
            elif kind == "eq":
                new = EQ.sub(lambda m: f"{m.group(3)} {m.group(2)} {m.group(1)}", line, count=1)
            elif kind == "commute":
                new = COMMUTE.sub(lambda m: f"{m.group(3)} {m.group(2)} {m.group(1)}", line, count=1)
            elif kind == "incr":
                new = re.sub(r"\b(\w+)\+\+", r"++\1", line, count=1)
                if new == line:
                    new = re.sub(r"\+\+(\w+)\b", r"\1++", line, count=1)
                if new == line:
                    new = re.sub(r"\b(\w+)\s*\+=\s*1\s*;", r"++\1;", line, count=1)
            else:
                new = line
                for a, b in rng.sample(SIGNS, len(SIGNS)):
                    if re.match(rf"\s*{re.escape(a)}\w", line):
                        new = line.replace(a, b, 1)
                        break
                    if re.match(rf"\s*{re.escape(b)}\w", line):
                        new = line.replace(b, a, 1)
                        break
            if new != line:
                lines[i] = new
                return "\n".join(lines), kind
        elif kind == "flag":
            for k, line in enumerate(lines[:12]):
                if line.startswith("// cl:"):
                    words = line.split()
                    if rng.random() < 0.4:
                        flag = rng.choice(FLAG_TOGGLES)
                        words = [w for w in words if w != flag] if flag in words else words + [flag]
                        lines[k] = " ".join(words)
                        return "\n".join(lines), kind
                    a, b = rng.choice(FLAG_SWAPS)
                    if a in words:
                        lines[k] = " ".join(b if w == a else w for w in words)
                        return "\n".join(lines), kind
    return text, None


# ----------------------------------------------------------------- search

def permute(rva, minutes=10.0, seed=None):
    rva = rva.lower()
    path = ATTEMPTS / f"{rva}.cpp"
    try:
        text = path.read_text(encoding="latin-1", errors="replace")
    except FileNotFoundError:
        # landed elsewhere (an upstream merge or another agent) mid-batch
        return {"rva": rva, "error": "banked attempt gone: closed elsewhere"}
    symbol = re.match(r"//\s*(\S+)", text).group(1)
    size = attempt_sizes().get((symbol, rva))
    if not size:
        return {"rva": rva, "error": "no size in re_attempts.log"}
    workdir = OUT / rva
    workdir.mkdir(parents=True, exist_ok=True)
    scorer = Scorer(rva, symbol, size, workdir)
    rng = random.Random(seed if seed is not None else int(rva, 16))
    best_text = text
    best, exact = scorer.score(text)
    start_score = best
    if best < 0:
        return {"rva": rva, "symbol": symbol, "error": "banked body does not compile here"}
    if scorer.unresolved and best >= 0.999:
        # Bytes already right; a call the symbol map cannot resolve keeps it
        # from counting as exact, and reordering source cannot fix that.
        result = {"rva": rva, "symbol": symbol, "size": size, "start": round(best, 4),
                  "best": round(best, 4), "exact": False, "trials": scorer.trials,
                  "stop": "unresolved calls: pin the callees"}
        with (OUT / "results.jsonl").open("a", encoding="utf-8") as handle:
            handle.write(json.dumps(result) + "\n")
        return result
    reason = unreachable(*scorer.last) if scorer.last else None
    if reason:
        result = {"rva": rva, "symbol": symbol, "size": size, "start": round(best, 4),
                  "best": round(best, 4), "exact": False, "trials": scorer.trials, "stop": reason}
        with (OUT / "results.jsonl").open("a", encoding="utf-8") as handle:
            handle.write(json.dumps(result) + "\n")
        return result
    deadline = time.time() + minutes * 60
    focus = focus_of(symbol)
    current_text, current = best_text, best
    stale = 0
    since_gain = 0  # trials since the best improved
    stop = "deadline"
    while not exact and time.time() < deadline:
        # Measured over 520 runs: every win came within 567 trials, and a run
        # whose mutations are exhausted only replays cached candidates.
        if scorer.hits > 200:
            stop = "mutations exhausted"
            break
        if since_gain > 600:
            stop = "no gain in 600 trials"
            break
        trials_before = scorer.trials
        candidate = current_text
        for _ in range(rng.choice((1, 1, 2, 3))):
            candidate, _kind = mutate(candidate, rng, focus)
        fitness, exact = scorer.score(candidate)
        if fitness < 0:
            continue
        if fitness > current or (fitness == current and rng.random() < 0.5):
            current_text, current = candidate, fitness
        if fitness > best or exact:
            best_text, best, stale, since_gain = candidate, fitness, 0, 0
        else:
            stale += 1
            since_gain += scorer.trials - trials_before
        if stale > 150:  # restart from the best so far
            current_text, current, stale = best_text, best, 0
    (workdir / "best.cpp").write_text(best_text, encoding="latin-1", errors="replace")
    if exact:
        (workdir / "win.cpp").write_text(best_text, encoding="latin-1", errors="replace")
    result = {"rva": rva, "symbol": symbol, "size": size, "start": round(start_score, 4),
              "best": round(best, 4), "exact": exact, "trials": scorer.trials,
              "stop": "exact" if exact else stop}
    with (OUT / "results.jsonl").open("a", encoding="utf-8") as handle:
        handle.write(json.dumps(result) + "\n")
    return result


def recheck(rva):
    """Compile a banked attempt unchanged once: headers, pins and ledger fixes
    landed since it was banked can make it exact with no search at all."""
    rva = rva.lower()
    text = (ATTEMPTS / f"{rva}.cpp").read_text(encoding="latin-1", errors="replace")
    found = re.match(r"//\s*(\S+)", text)
    symbol = found.group(1) if found else ""
    size = attempt_sizes().get((symbol, rva))
    if not size:
        return {"rva": rva, "recheck": "no size"}
    workdir = OUT / rva
    workdir.mkdir(parents=True, exist_ok=True)
    fitness, exact = Scorer(rva, symbol, size, workdir).score(text)
    if exact:
        (workdir / "win.cpp").write_text(text, encoding="latin-1", errors="replace")
    return {"rva": rva, "symbol": symbol, "recheck": round(fitness, 4), "exact": exact}


LITERAL = re.compile(r"(?<![\w.])(0[xX][0-9A-Fa-f]+|\d+)(?![\w.])")
COMMENT_OR_STRING = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', re.S)


def _offset_deltas(compiled, target):
    """Retail number minus ours, for each number that differs between two
    instruction streams of the same shape (the `unreachable` case)."""
    deltas = set()
    for (_, ours), (_, theirs) in zip(_instructions(compiled), _instructions(target)):
        if ours == theirs:
            continue
        a = re.findall(r"0x[0-9a-f]+|\b\d+\b", ours)
        b = re.findall(r"0x[0-9a-f]+|\b\d+\b", theirs)
        for x, y in zip(a, b):
            d = int(y, 0) - int(x, 0)
            if d and abs(d) < 0x10000:
                deltas.add(d)
    return sorted(deltas, key=abs)


def _literal_sites(text):
    """(start, end, value, is_hex) of integer literals outside comments and strings."""
    masked = list(text)
    for found in COMMENT_OR_STRING.finditer(text):
        masked[found.start():found.end()] = " " * (found.end() - found.start())
    masked = "".join(masked)
    return [(m.start(), m.end(), int(m.group(1), 0), m.group(1).lower().startswith("0x"))
            for m in LITERAL.finditer(masked)]


def offset_search(rva, budget=400):
    """Close a body whose only gap is numbers (offsets, pads, constants): apply
    each retail-minus-ours delta to each integer literal in the source, keep
    what scores better, repeat until exact or the budget is spent. The
    compiler, not the search, decides: only a byte-exact compile is a win."""
    rva = rva.lower()
    try:
        text = (ATTEMPTS / f"{rva}.cpp").read_text(encoding="latin-1", errors="replace")
    except FileNotFoundError:
        return {"rva": rva, "error": "banked attempt gone: closed elsewhere"}
    found = re.match(r"//\s*(\S+)", text)
    symbol = found.group(1) if found else ""
    size = attempt_sizes().get((symbol, rva))
    if not size:
        return {"rva": rva, "error": "no size in re_attempts.log"}
    workdir = OUT / rva
    workdir.mkdir(parents=True, exist_ok=True)
    scorer = Scorer(rva, symbol, size, workdir)
    best, exact = scorer.score(text)
    start = best
    if best < 0:
        return {"rva": rva, "symbol": symbol, "error": "banked body does not compile here"}
    if not exact and not (scorer.last and unreachable(*scorer.last)):
        return {"rva": rva, "symbol": symbol, "skip": "not an offset-only gap", "start": round(start, 4)}
    improved = True
    while not exact and improved and scorer.trials < budget and scorer.last:
        improved = False
        deltas = _offset_deltas(*scorer.last)
        for begin, end, value, is_hex in _literal_sites(text):
            for delta in deltas:
                if value + delta < 0 or scorer.trials >= budget:
                    continue
                new = value + delta
                candidate = text[:begin] + (hex(new).upper().replace("0X", "0x") if is_hex else str(new)) + text[end:]
                fitness, exact = scorer.score(candidate)
                if exact or fitness > best:
                    text, best, improved = candidate, fitness, True
                    break
            if improved or exact:
                break
    if exact:
        (workdir / "win.cpp").write_text(text, encoding="latin-1", errors="replace")
    result = {"rva": rva, "symbol": symbol, "size": size, "start": round(start, 4), "best": round(best, 4),
              "exact": exact, "trials": scorer.trials, "mode": "offsets"}
    with (OUT / "offsets.jsonl").open("a", encoding="utf-8") as handle:
        handle.write(json.dumps(result) + "\n")
    return result


def home_dir(symbol):
    """Where a win's unit goes: the directory most of its class's ledger units
    live in, else Code/GameEngine/Source/Common."""
    import collections
    import csv
    found = re.match(r"\?[^@]+@([A-Za-z_]\w*)@@", symbol)
    if found:
        dirs = collections.Counter()
        with (ROOT / "reverse" / "functions.csv").open(encoding="utf-8", newline="") as handle:
            for row in csv.DictReader(handle):
                if f"@{found.group(1)}@@" in row["name"] and not row["source"].startswith("Code/gen_"):
                    dirs[str(Path(row["source"]).parent)] += 1
        if dirs:
            return dirs.most_common(1)[0][0], found.group(1)
    return "Code/GameEngine/Source/Common", found.group(1) if found else ""


def add_row(symbol, rva, size, source, notes):
    """Land one row through tools/add_match.py, which byte-verifies it."""
    import subprocess
    result = subprocess.run(
        ["python3", "tools/add_match.py", symbol, f"0x{int(rva, 16):08X}", str(size), source,
         "--notes", notes], cwd=ROOT, capture_output=True, text=True)
    return "verified OK" in result.stdout + result.stderr


def existing_home(symbol):
    """The one Code/ unit that already defines the function `symbol` names."""
    import subprocess
    found = re.match(r"\?(\w+)@(?:(\w+)@@)?", symbol)
    if not found:
        return None
    name = f"{found.group(2)}::{found.group(1)}" if found.group(2) else found.group(1)
    pattern = rf"^[^;/#]*\b{re.escape(name)}\s*\([^;]*$"
    hits = subprocess.run(["git", "grep", "-lP", pattern, "--", "Code/*.cpp"],
                          cwd=ROOT, capture_output=True, text=True).stdout.split()
    hits = [h for h in hits if not h.startswith("Code/gen_")]
    return hits[0] if len(hits) == 1 else None


def land(rva):
    """Write build/permute/<rva>/win.cpp as a Code/ unit and land it with
    tools/add_match.py (which verifies and clears the banked attempt).
    Returns the source path, or None if it did not verify."""
    import subprocess
    rva = rva.lower()
    win = OUT / rva / "win.cpp"
    lines = win.read_text(encoding="latin-1").split("\n")
    symbol = re.match(r"//\s*(\S+)", lines[0]).group(1)
    size = attempt_sizes().get((symbol, rva))
    score = re.search(r"score=([0-9.]+)", "\n".join(lines[:4]))
    body = [l for l in lines if not (l.startswith(f"// {symbol}") or l.startswith("// partial score"))]
    cl = next((l for l in body if l.startswith("// cl:")), None)
    if cl:
        body.remove(cl)
    definitions = sum(1 for l in body if BODY_START.match(l) and "class " not in l and "struct " not in l)
    if definitions > 3:
        # The banked attempt is a copy of a whole unit: a new file would
        # define its other functions a second time. Only the unit that
        # already holds the function may take it, so try repointing the row
        # there (add_match verifies); otherwise leave the win for a hand port.
        home = existing_home(symbol)
        if home and add_row(symbol, rva, size, home, "banked attempt exact; the home unit's copy verified"):
            win.rename(win.with_suffix(".landed"))
            return home
        print(f"HAND-PORT {rva} {symbol}: win.cpp is a whole unit ({definitions} definitions); "
              f"port the function into {home or 'its home unit'}", file=sys.stderr)
        return None
    directory, cls = home_dir(symbol)
    name = f"{cls}Rva{int(rva, 16):08X}.cpp" if cls else f"Rva{int(rva, 16):08X}Permuted.cpp"
    source = Path(directory) / name
    if (ROOT / source).exists():
        return None
    header = ([cl] if cl else []) + [
        "//",
        f"// {symbol}, retail {rva}, {size} bytes. Banked partial"
        f"{f' (score {score.group(1)})' if score else ''} closed by tools/permute.py;",
        "// the body is the banked one up to statement/operand order and local types.",
    ]
    (ROOT / source).write_text("\n".join(header + body), encoding="latin-1")
    if not add_row(symbol, rva, size, source.as_posix(),
                   "banked partial closed by tools/permute.py; identity carried from the banked attempt"):
        (ROOT / source).unlink(missing_ok=True)
        return None
    win.rename(win.with_suffix(".landed"))
    return source.as_posix()


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("rvas", nargs="*")
    parser.add_argument("--list", action="store_true")
    parser.add_argument("--top", type=int, default=0)
    parser.add_argument("--next", type=int, default=0,
                        help="run the next N untried banked bodies no other agent has claimed, claiming them")
    parser.add_argument("--min-score", type=float, default=0.9)
    parser.add_argument("--minutes", type=float, default=10.0)
    parser.add_argument("--jobs", type=int, default=int(os.environ.get("BUILD_POOL", "1") or 1))
    parser.add_argument("--land", action="store_true",
                        help="land every build/permute/<rva>/win.cpp via add_match (no commit)")
    parser.add_argument("--offsets", action="store_true",
                        help="offset search on bodies the triage found differ only in numbers (or the RVAs given)")
    parser.add_argument("--all", action="store_true",
                        help="with --offsets: every banked attempt (one compile each to find the offset-only ones)")
    parser.add_argument("--recheck", action="store_true",
                        help="compile every banked attempt (any score) unchanged once; exact ones become wins")
    args = parser.parse_args(argv)
    if args.offsets:
        # bodies the triage marked as a layout fact, or the RVAs given
        rvas = args.rvas
        if not rvas and args.all:
            rvas = [rva for _, _, rva, _ in queue(0.0)]
        elif not rvas and (OUT / "results.jsonl").exists():
            seen = set()
            for line in (OUT / "results.jsonl").read_text().splitlines():
                try:
                    entry = json.loads(line)
                except ValueError:
                    continue
                if str(entry.get("stop", "")).startswith("only constants or offsets differ"):
                    seen.add(entry["rva"])
            done = set()
            if (OUT / "offsets.jsonl").exists():
                done = {json.loads(l)["rva"] for l in (OUT / "offsets.jsonl").read_text().splitlines() if l.strip()}
            rvas = sorted(seen - done)
        wins = 0
        with concurrent.futures.ProcessPoolExecutor(max(1, args.jobs)) as pool:
            for result in pool.map(offset_search, rvas):
                wins += bool(result.get("exact"))
                if "skip" not in result:
                    print(json.dumps(result), flush=True)
        print(f"permute: offset search closed {wins} of {len(rvas)}")
        return 0
    if args.recheck:
        rvas = [rva for _, _, rva, _ in queue(0.0)]
        hits = 0
        with concurrent.futures.ProcessPoolExecutor(max(1, args.jobs)) as pool:
            for result in pool.map(recheck, rvas, chunksize=4):
                if result.get("exact"):
                    hits += 1
                    print(f"EXACT {result['rva']} {result['symbol']}", flush=True)
        print(f"permute: recheck found {hits} banked attempt(s) already exact of {len(rvas)}")
        return 0
    if args.land:
        landed = []
        for win in sorted(OUT.glob("0x*/win.cpp")):
            source = land(win.parent.name)
            print(f"{'LANDED' if source else 'FAILED'} {win.parent.name} {source or ''}", flush=True)
            if source:
                landed.append(source)
        print(f"permute: landed {len(landed)} win(s); stage {' '.join(landed) or '-'} "
              "plus reverse/functions.csv and the cleared reverse/attempts files, then commit")
        return 0
    items = queue(args.min_score)
    if args.list:
        for score, size, rva, symbol in items:
            print(f"{score:.2f} {size:6d} {rva} {symbol}")
        print(f"{len(items)} banked attempt(s) at score >= {args.min_score}")
        return 0
    claimed = []
    if args.next:
        # Several agents may run the closer on this fork: take the next
        # untried bodies nobody holds, and claim them before starting.
        import claims
        tried = set()
        if (OUT / "results.jsonl").exists():
            for line in (OUT / "results.jsonl").read_text().splitlines():
                try:
                    tried.add(json.loads(line)["rva"].lower())
                except (ValueError, KeyError):
                    pass
        busy = claims.busy_rvas()
        wanted = [rva for _, _, rva, _ in items
                  if rva not in tried and int(rva, 16) not in busy][:args.next]
        got, _refused = claims.claim([int(rva, 16) for rva in wanted], note="permute")
        claimed = [f"0x{rva:08x}" for rva in got]
        rvas = claimed if got or not wanted else wanted  # no network: run unclaimed
    else:
        rvas = args.rvas or [rva for _, _, rva, _ in items[:args.top]]
    if not rvas:
        parser.error("give RVAs, --top N or --next N (nothing untried and unclaimed left)")
    OUT.mkdir(parents=True, exist_ok=True)
    wins, won = 0, set()
    try:
        with concurrent.futures.ProcessPoolExecutor(max(1, args.jobs)) as pool:
            for result in pool.map(permute, rvas, [args.minutes] * len(rvas)):
                wins += bool(result.get("exact"))
                if result.get("exact"):
                    won.add(result["rva"])
                print(json.dumps(result), flush=True)
    finally:
        if claimed:
            import claims
            # Every claim but a win's is released, even if the batch died;
            # wins stay claimed until --land, where add_match releases them.
            claims.release([int(rva, 16) for rva in claimed if rva not in won])
    print(f"permute: {wins} of {len(rvas)} closed exactly")
    return 0


if __name__ == "__main__":
    sys.exit(main())
