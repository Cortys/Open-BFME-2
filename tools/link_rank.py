#!/usr/bin/env python3
"""Rank link blockers by the matched bytes they keep from linking.

A matched row whose unit cannot link is half done: the bytes are proved,
but the unit is not yet part of a buildable game. This reads the last link
census (build/link_census/, written by tools/link_census.py) and says where
a fix pays most.

For every ledger unit it collects what holds the unit back:

  U name   an unresolved name the unit references
  D name   a name the unit and another unit both define
  L name   a COMDAT the unit compiled differently from the copy kept
  A        a hard-coded image address in the source (tools/link_debt.py)

and reports:

  sole     blockers that are a unit's ONLY blocker, by that unit's bytes:
           fix one, a unit links
  names    every blocking name by bytes shared out among the blockers of
           the units it blocks: what a fix moves overall
  near     units with at most --near blockers, largest first: the work list

Usage:
  python3 tools/link_rank.py [--top N] [--near K] [--kind U|D|L|A] [--json PATH]
  python3 tools/link_rank.py --file SOURCE     one unit's blockers

Run tools/link_census.py first; this reuses its log and objects and never
links anything itself.
"""
import argparse
import collections
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import link_census as lc  # noqa: E402
import link_debt  # noqa: E402


def blockers():
    """({source: {(kind, name)}}, {source: matched bytes})."""
    rows = lc.ledger()
    log = (lc.OUT / "census.log").read_text(encoding="utf-8", errors="replace")
    crt = build.vc71_root() / "Vc7" / "lib" / "msvcrt.lib"
    runtime, thunks = lc.library_symbols(crt), lc.library_import_thunks(crt) | lc.sdk_import_thunks()
    imported = lc.retail_imports()
    present, _ = lc.objects(rows)
    unresolved, duplicates = collections.defaultdict(set), collections.defaultdict(set)
    for line in log.splitlines():
        found = lc.UNRESOLVED.search(line)
        if found:
            symbol = found.group(1) or found.group(2)
            referrer = lc.REFERRER.match(line)
            if referrer and not lc.excused(symbol, runtime, imported, thunks):
                unresolved[Path(referrer.group(1)).name].add(symbol)
            continue
        found = lc.DUPLICATE.match(line)
        if found:
            symbol = found.group(2) or found.group(3)
            duplicates[Path(found.group(1)).name].add(symbol)
            duplicates[Path(found.group(4)).name].add(symbol)
    losers = lc.comdat_losers(present)
    sizes, objects, seen = collections.Counter(), {}, set()
    for row in rows:
        source = row["source"]
        if not source.lower().endswith((".c", ".cpp")):
            continue
        key = (source, row["target_rva"])
        if key not in seen:
            seen.add(key)
            sizes[source] += int(row["target_size"] or 0, 0)
        objects[source] = build.row_object(row).name
    out = {}
    for source, obj in objects.items():
        found = {("U", s) for s in unresolved.get(obj, ())}
        found |= {("D", s) for s in duplicates.get(obj, ())}
        found |= {("L", s) for s in losers.get(obj, ())}
        try:
            if link_debt.addresses((ROOT / source).read_text(encoding="utf-8", errors="replace")):
                found.add(("A", ""))
        except OSError:
            pass
        out[source] = found
    return out, sizes


def generated(source):
    return source.startswith(("Code/gen_asm/", "Code/gen_small/"))


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--top", type=int, default=30)
    parser.add_argument("--near", type=int, default=3)
    parser.add_argument("--kind", choices="UDLA")
    parser.add_argument("--file")
    parser.add_argument("--json", help="write {source: [[kind, name], ...]} here")
    args = parser.parse_args(argv)
    found, sizes = blockers()
    if args.json:
        Path(args.json).write_text(json.dumps({s: sorted(b) for s, b in found.items()}), encoding="utf-8")
    if args.file:
        names = sorted(found.get(args.file, ()))
        print(f"{args.file}: {sizes[args.file]} matched bytes, "
              f"{'links' if not names else f'{len(names)} blocker(s)'}")
        for kind, name in names:
            print(f"  {kind} {name}")
        return 0
    authored = {s: b for s, b in found.items() if not generated(s)}
    linked = [s for s, b in authored.items() if not b]
    print(f"{len(linked):,} of {len(authored):,} authored units link "
          f"({sum(sizes[s] for s in linked):,} of {sum(sizes[s] for s in authored):,} matched bytes)")

    def wanted(item):
        return args.kind is None or item[0] == args.kind

    sole, sole_units = collections.Counter(), collections.Counter()
    share, share_units = collections.Counter(), collections.Counter()
    for source, items in authored.items():
        if len(items) == 1:
            item = next(iter(items))
            sole[item] += sizes[source]
            sole_units[item] += 1
        for item in items:
            share[item] += sizes[source] / len(items)
            share_units[item] += 1

    def label(item):
        return f"{item[0]} {item[1] or '(source has a hard-coded image address)'}"

    print(f"\nsole blockers (fix one, these units link):")
    for item, value in [(i, v) for i, v in sole.most_common() if wanted(i)][:args.top]:
        print(f"  {value:8,} {sole_units[item]:4} units  {label(item)[:150]}")
    print(f"\nblocking names by shared bytes:")
    for item, value in [(i, v) for i, v in share.most_common() if wanted(i)][:args.top]:
        print(f"  {int(value):8,} {share_units[item]:4} units  {label(item)[:150]}")
    print(f"\nunits within {args.near} blocker(s) of linking:")
    near = sorted((s for s, b in authored.items() if 0 < len(b) <= args.near and all(wanted(i) for i in b)),
                  key=lambda s: -sizes[s])
    for source in near[:args.top]:
        names = "; ".join(label(i)[:70] for i in sorted(authored[source]))
        print(f"  {sizes[source]:7,}  {source}  [{names}]")
    return 0


if __name__ == "__main__":
    sys.exit(main())
