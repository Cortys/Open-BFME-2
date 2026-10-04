#!/usr/bin/env python3
"""What each agent lands: real-C++ bytes and bodies per agent per day.

Reads the `Agent:` trailer the commit-msg hook adds (BFME_CLAIM_OWNER).
A commit counts the matched rows it adds at an address that had no
real-C++ row before (so repoints, note edits and moves count nothing);
gen-* placeholders and upstream merges are not ours and are left out.
Untagged commits from before the trailer existed show as "untagged".

  python3 tools/agent_yield.py [--since 2026-10-04] [--days]
"""
import argparse
import collections
import csv
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
LEDGER = "reverse/functions.csv"


def git(*args):
    return subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True,
                          errors="replace").stdout


def real(row):
    return row[5:6] == ["matched"] and not row[4].startswith(("Code/gen_asm/", "Code/gen_small/"))


def commit_gain(sha):
    """(bodies, bytes) of real-C++ rows at addresses that had none before."""
    diff = git("show", "--format=", "--unified=0", sha, "--", LEDGER)
    added, removed = {}, set()
    for line in diff.splitlines():
        if line.startswith(("+++", "---")) or not line[:1] in "+-":
            continue
        row = next(csv.reader([line[1:]]), [])
        if len(row) < 7 or not real(row):
            continue
        rva = row[2].lower()
        if line[0] == "+":
            added[rva] = int(row[3] or 0, 0)
        else:
            removed.add(rva)
    new = {rva: size for rva, size in added.items() if rva not in removed}
    return len(new), sum(new.values())


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--since", default="7 days ago")
    ap.add_argument("--days", action="store_true", help="break each agent down by day")
    args = ap.parse_args(argv)
    # Only the fork's own commits: anything upstream/master holds is theirs.
    exclude = ["^upstream/master"] if git("rev-parse", "-q", "--verify", "upstream/master").strip() else []
    log = git("log", "--no-merges", f"--since={args.since}", "HEAD", *exclude,
              "--format=%H%x09%cs%x09%(trailers:key=Agent,valueonly,separator=%x2C)", "--", LEDGER)
    totals = collections.defaultdict(lambda: [0, 0, 0])
    for line in log.splitlines():
        sha, day, agent = (line.split("\t") + ["", ""])[:3]
        bodies, size = commit_gain(sha)
        if not bodies:
            continue
        key = (agent.strip() or "untagged", day if args.days else "")
        totals[key][0] += 1
        totals[key][1] += bodies
        totals[key][2] += size
    print(f"{'agent':24} {'day' if args.days else '':10} {'commits':>8} {'bodies':>7} {'bytes':>9}")
    for (agent, day), (commits, bodies, size) in sorted(totals.items(), key=lambda kv: (-kv[1][2], kv[0])):
        print(f"{agent:24} {day:10} {commits:8} {bodies:7} {size:9,}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
