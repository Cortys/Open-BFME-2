# Structural reconciliation — the manual-RE workflow

For drift rows classed `structural`/`register-swap` the source exists but
compiles to a different shape. Expect 30-60 minutes per function.

## The loop for ONE function

1. `python3 tools/next_work.py --tier structural` draws one candidate from the
   highest-quality band. If it prints a `stash:` line, start from that body — a
   previous attempt already reached the score shown.
2. `python3 tools/explain_mismatch.py '<sym>' --rva <candidate_rva> --size <size> --source <src>`
   Read the classification line first, then the side-by-side disasm.
3. Fix in dependency order; earlier classes mask later ones:
   a. **unresolved REL32 call** — resolve callees FIRST:
      `python3 tools/decode_calls.py <src> --rva <candidate_rva>` prints the
      symbols.csv pins. Add them, re-explain; the real diff often shrinks or
      vanishes.
   b. **misplaced candidate** — target bytes opening like another function's
      tail (`ret`/`int3` within a few bytes) mean the drift vote shifted. Find
      the true start in `reverse/ghidra_functions.csv`; trust a `ret` boundary
      plus export evidence where Ghidra merged functions.

      Do this BEFORE anything else, because it is the usual case rather than
      the exception. Measured 2026-09-29: of the 3,782 `structural` rows in
      `reverse/zh_sweep/drift_report.csv`, only **28** have a `candidate_rva`
      that appears as a function start in the inventory -- 99.3% do not. Mean
      alignment is ~20% either way, so a low score does not tell you which kind
      you have. Confirming the boundary costs one query; not confirming it costs
      the 30-60 minutes this loop warns about. `0x00758338` is the worked
      example: it is mid-instruction inside a function at `0x00758310`, decodes
      as `or al,0x98`, and reached `next_work --tier structural` as a served
      candidate carrying the correct byte count -- which is why the count alone
      is not evidence.

      Then check the inventory ENTRY, not just its presence. Two of those 28
      point at `Unwind@` records -- 11-byte unwind tables that sit inside real
      functions and look like small bodies -- which leaves 26 genuine starts.
      That mattered here: the best-looking row in the whole tier, a 117B
      destructor at 54% alignment, is `0x007690E1,11,Unwind@00b690e1`. Once
      unwind records are excluded the best genuine alignment in the tier is
      35%, on `??0FileSystem@@QAE@XZ` at `0x007398D0`, so nothing in this tier
      is close enough to be worth the loop's budget before the reference lanes
      have been tried.
   c. **field-offset diffs** (`[reg+0xNN]` vs `[reg+0xMM]`, same shape): BFME
      relaid a struct, or retail has a real bug. Change the member access — the
      header only when verified siblings permit — then byte-verify the file.
   d. **literal diffs** (immediates, string addresses): fix the constant.
   e. **shape diffs** (branch layout, register choice, inlining): the hard
      class. Try early-return versus nesting, inverted arms, hoist/sink,
      declaration order, temp versus re-read, split/merge conditions. Do not
      chase x87 operand order or register renames past two attempts; see
      `docs/matching.md`.
4. If exact, `python3 tools/add_match.py '<sym>' <rva> <size> <src>` validates,
   appends, strips the marker and re-verifies; then bank the unit.
5. If it did not land, bank it before reverting:
   `re_log.py record '<sym>' <rva> <size> partial '<diff>' --stash <src>
   --score <0..1>` — both flags required, else `blocked`. Then revert; keep no
   nonmatching body in `Code/`.

An interior-only body is probably inlined; identical already-claimed bytes are
probably ICF-folded. Compiler-only machinery (SEH array-constructor,
`_initterm` stubs) may need the naked-assembly precedent. Each time: verify the
evidence, revert the experiment, take another candidate.

## Escalation beyond drift rows

When this queue thins, `python3 tools/next_work.py --tier ghidra` serves
string-anchored absent functions under the same rules.
