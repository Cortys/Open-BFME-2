#!/usr/bin/env python3
"""Move split-out rows back to the unit that already defines the function.

A common way to land one function is a small unit that re-declares just
enough to compile it. When the function's own unit (dx8wrapper.cpp,
ModuleFactory.cpp, ...) still compiles the same function, the two strong
definitions are a duplicate-symbol error: neither unit can link, and the
census lists both under `duplicates`.

When the home unit's copy matches retail exactly at the row's address, the
row belongs there. This finds those cases and, with --apply, moves them:

  1. From the last link census log, every split unit Y all of whose rows
     are also defined by one other ledger unit X.
  2. Each of Y's rows compared, at its own address and size, against X's
     copy (tools/explain_mismatch.py --rva --source X): all must be exact.
  3. --apply: each row repointed to X with tools/add_match.py
     --replace-existing (which verifies X and strips a marker that named
     the function present-unmatched), then Y removed with git rm.

A unit or home claimed by another seat (tools/claims.py claim file:PATH) is
skipped. Nothing is committed: review and commit the result. A row that
fails to verify leaves its unit in place, with the ledger untouched for it.

Usage:
  python3 tools/rehome_rows.py [--apply] [--limit N]
"""
import argparse
import collections
import csv
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import claims  # noqa: E402
import link_census as lc  # noqa: E402


def candidates():
    """[(split unit, home unit, [rows])] from the last census log."""
    rows = lc.ledger()
    log = (lc.OUT / "census.log").read_text(encoding="utf-8", errors="replace")
    source_of = {}
    by_source = collections.defaultdict(list)
    for row in rows:
        if row["source"].startswith(("Code/gen_asm/", "Code/gen_small/")):
            continue
        source_of.setdefault(build.row_object(row).name, row["source"])
        by_source[row["source"]].append(row)
    defined_by = collections.defaultdict(set)  # symbol -> sources defining it
    for line in log.splitlines():
        found = lc.DUPLICATE.match(line)
        if not found:
            continue
        symbol = found.group(2) or found.group(3)
        for obj in (found.group(1), found.group(4)):
            source = source_of.get(Path(obj).name)
            if source:
                defined_by[symbol].add(source)
    out = []
    for split, split_rows in by_source.items():
        homes = None
        for row in split_rows:
            others = defined_by.get(row["name"], set()) - {split}
            homes = others if homes is None else homes & others
            if not homes:
                break
        if homes and len(homes) == 1:
            out.append((split, next(iter(homes)), split_rows))
    return sorted(out)


def exact(row, home):
    result = subprocess.run(["python3", "tools/explain_mismatch.py", row["name"], "--rva", row["target_rva"],
                             "--size", row["target_size"], "--source", home],
                            cwd=ROOT, capture_output=True, text=True)
    return "OK: bytes match" in result.stdout


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--apply", action="store_true")
    parser.add_argument("--limit", type=int, default=0)
    args = parser.parse_args(argv)
    me = claims.owner()
    held = {key for key, info in claims.active().items()
            if isinstance(key, str) and key.startswith("file/") and info.get("owner") != me}
    found = candidates()
    print(f"rehome_rows: {len(found)} split unit(s) whose rows one home unit also defines", flush=True)
    moved = 0
    for split, home, rows in found:
        if args.limit and moved >= args.limit:
            break
        if claims.key_of(f"file:{split}") in held or claims.key_of(f"file:{home}") in held:
            print(f"CLAIMED {split} -> {home}", flush=True)
            continue
        if not all(exact(row, home) for row in rows):
            print(f"NO      {split} -> {home}", flush=True)
            continue
        if not args.apply:
            print(f"MATCH   {split} -> {home} ({len(rows)} row(s))", flush=True)
            moved += 1
            continue
        ok = True
        for row in rows:
            note = (row["notes"] + "; " if row["notes"] else "") + "row moved home from " + Path(split).name
            result = subprocess.run(["python3", "tools/add_match.py", row["name"], row["target_rva"],
                                     row["target_size"], home, "--replace-existing", "--notes", note],
                                    cwd=ROOT, capture_output=True, text=True)
            if "verified OK" not in result.stdout + result.stderr:
                print(f"FAILED  {split} -> {home}: {row['name']}", flush=True)
                ok = False
                break
        if not ok:
            continue
        remaining = [r for r in csv.DictReader((ROOT / "reverse/functions.csv").open(newline="", encoding="utf-8"))
                     if r["source"] == split]
        if remaining:
            print(f"PARTIAL {split} -> {home}: {len(remaining)} row(s) still there; unit kept", flush=True)
            continue
        subprocess.run(["git", "rm", "-q", split], cwd=ROOT)
        moved += 1
        print(f"MOVED   {split} -> {home} ({len(rows)} row(s))", flush=True)
    print(f"rehome_rows: {moved} unit(s) {'moved' if args.apply else 'movable'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
