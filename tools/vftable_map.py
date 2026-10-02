#!/usr/bin/env python3
"""Map retail vftables from the code that installs them.

The retail image carries RTTI for only a few dozen classes (the game was
built without /GR), so vftables are found the way a constructor reveals
them: a `mov dword ptr [reg], imm32` (C7 /0, mod 00, reg != esp/ebp) whose
immediate is an .rdata address holding a run of .text pointers. That run is
the table; its length up to the first non-code dword is the slot count (an
upper bound when two tables are adjacent: the next table's own installer
then marks where it starts).

For each table: its VA, slot count, every slot's target with the ledger
name at that address, the functions that install it (by Ghidra boundary and
ledger name), and the ledger's own ??_7 names there. An address with several
??_7 names, or installers from unrelated classes, is a folded table: several
identical vftables merged by the linker, which no single class name owns.

Writes reverse/vftables.csv (regenerable; one row per table).

Usage:
  python3 tools/vftable_map.py [--out PATH]
  python3 tools/vftable_map.py --va 0xC4ED70      one table, verbose
"""
import argparse
import bisect
import collections
import csv
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402

BASE = 0x400000
OUT = ROOT / "reverse" / "vftables.csv"


def sections():
    image, secs = build.exe_image()
    by = {s["name"]: s for s in secs}
    return bytes(image), secs, by


def reader(image, secs):
    def read(rva, size):
        try:
            offset = build.rva_to_file_offset(secs, rva)
        except ValueError:
            return None
        chunk = image[offset:offset + size]
        return chunk if len(chunk) == size else None
    return read


def ledger_names():
    """{rva: [names]} for matched rows (functions) at their start address."""
    out = collections.defaultdict(list)
    with (ROOT / "reverse" / "functions.csv").open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle):
            if row["status"] == "matched":
                out[int(row["target_rva"], 16)].append(row["name"])
    return out


def function_starts():
    starts = []
    with (ROOT / "reverse" / "ghidra_functions.csv").open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle):
            starts.append(int(row["rva"], 16))
    return sorted(set(starts))


def scan(image, secs, by):
    read = reader(image, secs)
    text, rdata = by[".text"], by[".rdata"]
    t_lo, t_hi = text["rva"], text["rva"] + text["size"]
    r_lo, r_hi = rdata["rva"], rdata["rva"] + rdata["size"]
    code = read(t_lo, text["size"])
    installs = collections.defaultdict(set)  # table rva -> {store rva}
    for i in range(len(code) - 6):
        if code[i] != 0xC7:
            continue
        modrm = code[i + 1]
        if modrm >> 6 != 0 or (modrm >> 3) & 7 != 0 or modrm & 7 in (4, 5):
            continue  # need C7 /0 with [reg] addressing, not SIB/disp32
        va = struct.unpack_from("<I", code, i + 2)[0]
        rva = va - BASE
        if not r_lo <= rva < r_hi:
            continue
        first = read(rva, 4)
        if first is None or not t_lo <= struct.unpack("<I", first)[0] - BASE < t_hi:
            continue
        installs[rva].add(t_lo + i)
    tables = {}
    for rva in installs:
        slots = []
        while len(slots) < 512:
            dword = read(rva + 4 * len(slots), 4)
            if dword is None:
                break
            target = struct.unpack("<I", dword)[0] - BASE
            if not t_lo <= target < t_hi:
                break
            slots.append(target)
        tables[rva] = slots
    # a table's run cannot extend into the next installed table
    ordered = sorted(tables)
    for a, b in zip(ordered, ordered[1:]):
        limit = (b - a) // 4
        if len(tables[a]) > limit:
            tables[a] = tables[a][:limit]
    return tables, installs


def vtable_names():
    """{rva: [??_7 names]} the ledger objects define there (name_globals' index)."""
    import name_globals
    out = collections.defaultdict(list)
    for va, symbols in name_globals.load_index().items():
        for symbol in symbols:
            if symbol.startswith("??_7"):
                out[va - BASE].append(symbol)
    return out


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--out", default=str(OUT))
    parser.add_argument("--va")
    args = parser.parse_args(argv)
    image, secs, by = sections()
    tables, installs = scan(image, secs, by)
    names = ledger_names()
    starts = function_starts()
    vt = vtable_names()

    def owner(rva):
        k = bisect.bisect_right(starts, rva) - 1
        start = starts[k] if k >= 0 else None
        return start, (names.get(start) or [""])[0] if start is not None else ""

    rows = []
    for rva in sorted(tables):
        slots = tables[rva]
        installers = sorted({owner(s) for s in installs[rva]}, key=lambda x: x[0] or 0)
        known = vt.get(rva, [])
        rows.append({
            "va": f"0x{rva + BASE:08X}",
            "slots": len(slots),
            "vtable_names": ";".join(sorted(known)),
            "folded": "yes" if len(known) > 1 else "",
            "installers": ";".join(f"0x{s:08X}={n}" if n else f"0x{s:08X}" for s, n in installers if s is not None),
            "slot_targets": ";".join(f"0x{t:08X}={(names.get(t) or [''])[0]}" for t in slots),
        })
    if args.va:
        want = int(args.va, 16)
        want = want if want >= BASE else want + BASE
        for row in rows:
            if int(row["va"], 16) == want:
                for key, value in row.items():
                    print(f"{key}: {value.replace(';', chr(10) + '    ') if isinstance(value, str) else value}")
                return 0
        print("no installed vftable at that address")
        return 1
    with open(args.out, "w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    named = sum(1 for r in rows if r["vtable_names"])
    folded = sum(1 for r in rows if r["folded"])
    print(f"vftable_map: {len(rows):,} installed tables, {named:,} with a ledger ??_7 name "
          f"({folded:,} folded), {sum(r['slots'] for r in rows):,} slots -> {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
