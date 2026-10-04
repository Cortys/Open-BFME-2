#!/usr/bin/env python3
"""Git merge driver for the ledgers: a three-way merge by row.

`merge=union` keeps every line of both sides, so a rebase onto a ledger
another agent rewrote (re-sorted, re-quoted, or pins re-applied) duplicated
hundreds of rows. This driver keys each row (functions.csv: name and
address; symbols.csv: name and address; anything else: the line itself),
applies the other side's additions, edits and deletions to the current
side, and keeps the current side's order with new rows appended.

Configured by tools/setup_hooks.sh:
    git config merge.ledger.driver "python3 tools/ledger_merge.py %O %A %B %P"
Exit 0 on a clean merge; 1 when both sides changed one row differently
(the current side's row is kept and each such row is named on stderr).
"""
import csv
import sys


def key(path, line):
    fields = next(csv.reader([line]), [])
    if path.endswith("functions.csv") and len(fields) > 2:
        return (fields[0], fields[2].lower())
    if path.endswith("symbols.csv") and len(fields) > 1:
        return (fields[0], fields[1].lower())
    return line


def read(path):
    with open(path, encoding="utf-8", newline="") as handle:
        return [l for l in handle.read().split("\n") if l.strip()]


def merge(base_lines, ours_lines, theirs_lines, path=""):
    """(merged lines, conflicting keys). Ours is the side being merged into."""
    def index(lines):
        rows = {}
        for line in lines:
            rows.setdefault(key(path, line), line)  # a duplicate key keeps its first row
        return rows
    base, ours, theirs = index(base_lines), index(ours_lines), index(theirs_lines)
    out, emitted, conflicts = [], set(), []
    for line in ours_lines:
        k = key(path, line)
        if k in emitted:
            continue  # drop a duplicate the current side already carries
        emitted.add(k)
        mine = ours[k]
        if k in theirs:
            if theirs[k] != mine:
                if base.get(k) == mine:
                    mine = theirs[k]          # only they changed it
                elif base.get(k) != theirs[k]:
                    conflicts.append(k)       # both changed it differently: keep ours
        elif k in base and base[k] == mine:
            continue                          # they deleted a row we left alone
        out.append(mine)
    for line in theirs_lines:
        k = key(path, line)
        if k in emitted:
            continue
        emitted.add(k)
        if k in base and base[k] == theirs[k]:
            continue                          # we deleted a row they left alone
        out.append(theirs[k])                 # they added it (or changed one we deleted)
    return out, conflicts


def main(argv):
    base_path, ours_path, theirs_path = argv[1:4]
    name = argv[4] if len(argv) > 4 else ours_path
    out, conflicts = merge(read(base_path), read(ours_path), read(theirs_path), name)
    with open(ours_path, "w", encoding="utf-8", newline="\n") as handle:
        handle.write("\n".join(out) + "\n")
    for k in conflicts:
        print(f"ledger_merge: {name}: both sides changed {k}; kept the current side's row",
              file=sys.stderr)
    return 1 if conflicts else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
