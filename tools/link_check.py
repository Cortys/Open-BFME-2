#!/usr/bin/env python3
"""Predict whether units link, without linking: a census for a handful of files.

tools/link_census.py links every ledger object with link.exe under Wine,
which is the ground truth but costs a full run. A worker who just changed
one unit wants to know, before pushing, whether that unit now links and
what still blocks it. This answers from the objects' symbol tables:

  U  a name the unit references that no ledger object defines and the real
     link would not supply either (msvcrt.lib, retail's imports: the
     census's own excused())
  D  a name the unit defines strongly that another ledger object also
     defines strongly
  L  a COMDAT the unit defines whose body (relocation targets resolved to
     retail addresses, as the census compares them) differs from the copy
     most objects compiled; STLport templates and array helpers excepted
  A  a hard-coded image address in the source (tools/link_debt.py)

It uses each unit's current object from the shared cache, so run ./build.sh
on what you changed first. Objects other workers' commits made stale are
counted and reported; --refresh recompiles them first (build.compile_rows,
the census's own compile phase), which the prediction needs after a pull. The per-object index (defined names and COMDAT
digests) is cached in build/link_check_index.json by object mtime and
refreshed incrementally: the first run reads every ledger object, later runs
only what changed.

It is a prediction. It does not see the alias scaffold, link order or a
crashed link, and the census remains the measure of record.

Usage:
  python3 tools/link_check.py SOURCE [SOURCE ...]
  python3 tools/link_check.py --staged            the units staged for commit
  python3 tools/link_check.py --refresh SOURCE    recompile stale objects first
"""
import argparse
import collections
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import link_census as lc  # noqa: E402
import link_debt  # noqa: E402

CACHE = ROOT / "build" / "link_check_index.json"


def symbols(data):
    """(strong defs, undefined externals) of one object; COMDAT defs come from comdat_bodies."""
    count = struct.unpack_from("<H", data, 2)[0]
    optional = struct.unpack_from("<H", data, 16)[0]
    flags = [struct.unpack_from("<I", data, 20 + optional + i * 40 + 36)[0] for i in range(count)]
    table, total = struct.unpack_from("<II", data, 8)
    strings = table + 18 * total
    strong, undefined = set(), set()
    index = 0
    while index < total:
        record = data[table + 18 * index:table + 18 * index + 18]
        if record[:4] == b"\0\0\0\0":
            offset = struct.unpack_from("<I", record, 4)[0]
            name = data[strings + offset:data.index(b"\0", strings + offset)]
        else:
            name = record[:8].rstrip(b"\0")
        value, section, _, storage, aux = struct.unpack_from("<IhHBB", record, 8)
        name = name.decode("latin-1")
        if storage == lc.EXTERNAL:
            if section > 0 and not flags[section - 1] & lc.COMDAT:
                strong.add(name)
            elif section == 0 and value == 0:
                undefined.add(name)
            elif section == 0:
                strong.add(name)  # a common block defines itself
        index += 1 + aux
    return strong, undefined


def directives(data):
    """{alias: target} from the object's /alternatename linker directives."""
    count = struct.unpack_from("<H", data, 2)[0]
    optional = struct.unpack_from("<H", data, 16)[0]
    out = {}
    for i in range(count):
        header = 20 + optional + i * 40
        if data[header:header + 8].rstrip(b"\0") != b".drectve":
            continue
        size, pointer = struct.unpack_from("<II", data, header + 16)
        text = data[pointer:pointer + size].decode("latin-1")
        for alias, target in re.findall(r"/alternatename:([^=\s]+)=(\S+)", text, re.I):
            out[alias.strip('"')] = target.strip('"')
    return out


def describe(obj, retail):
    data = obj.read_bytes()
    strong, undefined = symbols(data)
    comdats = {name: digest for name, digest, _ in lc.comdat_bodies(obj, retail)}
    return {"strong": sorted(strong), "undefined": sorted(undefined), "comdat": comdats,
            "aliases": directives(data)}


def load_index(objects):
    cached = {}
    if CACHE.exists():
        try:
            cached = json.loads(CACHE.read_text(encoding="utf-8"))
        except ValueError:
            cached = {}
    retail = lc.retail_addresses()
    stamp_ledger = (ROOT / "reverse" / "symbols.csv").stat().st_mtime + (ROOT / "reverse" / "functions.csv").stat().st_mtime
    if cached.get("ledger") != stamp_ledger or cached.get("format") != 2:
        cached = {"ledger": stamp_ledger, "format": 2, "objects": {}}  # retail addresses changed: COMDAT digests may too
    entries = cached.setdefault("objects", {})
    fresh = 0
    for obj in objects:
        key = obj.as_posix()
        try:
            mtime = obj.stat().st_mtime
        except OSError:
            continue
        entry = entries.get(key)
        if entry and entry.get("mtime") == mtime:
            continue
        entries[key] = dict(describe(obj, retail), mtime=mtime)
        fresh += 1
    if fresh:
        CACHE.parent.mkdir(parents=True, exist_ok=True)
        CACHE.write_text(json.dumps(cached), encoding="utf-8")
    live = {o.as_posix() for o in objects}
    return {k: v for k, v in entries.items() if k in live}


def staged():
    out = subprocess.run(["git", "diff", "--cached", "--name-only", "--diff-filter=ACMR", "--", "Code/"],
                         cwd=ROOT, capture_output=True, text=True).stdout.split()
    return [p for p in out if p.lower().endswith((".c", ".cpp"))]


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("sources", nargs="*")
    parser.add_argument("--staged", action="store_true")
    parser.add_argument("--refresh", action="store_true")
    args = parser.parse_args(argv)
    targets = staged() if args.staged else args.sources
    if not targets:
        print("link_check: nothing to check")
        return 0
    rows = lc.ledger()
    sources = [s for s in dict.fromkeys(ROOT / r["source"] for r in rows) if s.suffix.lower() != build.LIB_SUFFIX]
    if args.refresh:
        build.compile_rows(rows, sources)
    else:
        stale = build.stale_sources(sources, {s: build.obj_path(s) for s in sources}, build._pool_size())
        if stale:
            print(f"link_check: {len(stale)} ledger object(s) are stale; predictions that depend on them "
                  f"may be wrong (--refresh recompiles them)", file=sys.stderr)
    present, _ = lc.objects(rows)
    index = load_index(present)
    order = {obj.as_posix(): n for n, obj in enumerate(present)}
    object_of = {}
    for row in rows:
        object_of.setdefault(row["source"], build.row_object(row).as_posix())
    strong_by = collections.defaultdict(set)
    defined = set()
    copies = collections.defaultdict(collections.Counter)
    aliases = {}
    first = {}
    for key, entry in sorted(index.items(), key=lambda kv: order.get(kv[0], 0)):
        for name in entry["strong"]:
            strong_by[name].add(key)
        defined.update(entry["strong"])
        defined.update(entry["comdat"])
        for alias, target in entry.get("aliases", {}).items():
            aliases.setdefault(alias, target)
        for name, digest in entry["comdat"].items():
            copies[name][digest] += 1
            first.setdefault((name, digest), order.get(key, 0))
    crt = build.vc71_root() / "Vc7" / "lib" / "msvcrt.lib"
    runtime, thunks = lc.library_symbols(crt), lc.library_import_thunks(crt) | lc.sdk_import_thunks()
    imported = lc.retail_imports()
    blocked = 0
    for source in targets:
        key = object_of.get(source)
        entry = index.get(key) if key else None
        if entry is None:
            print(f"{source}: no ledger object (no matched row, or not built yet)")
            blocked += 1
            continue
        found = []
        for name in entry["undefined"]:
            if name in aliases and aliases[name] in defined:
                continue  # /alternatename: the linker uses the target
            if name not in defined and not lc.excused(name, runtime, imported, thunks):
                found.append(("U", name))
        for name in entry["strong"]:
            if len(strong_by[name]) > 1:
                found.append(("D", name))
        for name, digest in entry["comdat"].items():
            counts = copies[name]
            kept = min(counts, key=lambda d: (-counts[d], first[(name, d)]))  # the census's rule
            if digest != kept and not lc.comdat_exempt(name):
                found.append(("L", name))
        try:
            if link_debt.addresses((ROOT / source).read_text(encoding="utf-8", errors="replace")):
                found.append(("A", "hard-coded image address in the source"))
        except OSError:
            pass
        print(f"{source}: {'links' if not found else f'{len(found)} blocker(s)'}")
        for kind, name in sorted(found):
            print(f"  {kind} {name}")
        blocked += bool(found)
    return 0


if __name__ == "__main__":
    sys.exit(main())
