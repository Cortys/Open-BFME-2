import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import ledger_merge  # noqa: E402

HEAD = "name,export_rva,target_rva,target_size,source,status,notes"
F = "reverse/functions.csv"


def row(name, rva, note=""):
    return f"{name},,{rva},4,Code/a.cpp,matched,{note}"


def test_appends_from_both_sides():
    base = [HEAD, row("a", "0x1")]
    out, conflicts = ledger_merge.merge(base, base + [row("b", "0x2")], base + [row("c", "0x3")], F)
    assert out == [HEAD, row("a", "0x1"), row("b", "0x2"), row("c", "0x3")] and not conflicts


def test_rewritten_side_does_not_duplicate():
    base = [HEAD, row("a", "0x1"), row("b", "0x2")]
    rewritten = [HEAD, row("b", "0x2"), row("a", "0x1")]  # same rows, new order
    mine = base + [row("c", "0x3")]
    out, conflicts = ledger_merge.merge(base, rewritten, mine, F)
    assert sorted(out) == sorted([HEAD, row("a", "0x1"), row("b", "0x2"), row("c", "0x3")])
    assert len(out) == 4 and not conflicts


def test_edit_and_delete_apply():
    base = [HEAD, row("a", "0x1"), row("b", "0x2")]
    theirs = [HEAD, row("a", "0x1", "renamed note")]  # edits a, deletes b
    out, conflicts = ledger_merge.merge(base, base, theirs, F)
    assert out == [HEAD, row("a", "0x1", "renamed note")] and not conflicts


def test_both_changed_keeps_ours_and_reports():
    base = [HEAD, row("a", "0x1")]
    out, conflicts = ledger_merge.merge(base, [HEAD, row("a", "0x1", "x")], [HEAD, row("a", "0x1", "y")], F)
    assert out == [HEAD, row("a", "0x1", "x")] and conflicts == [("a", "0x1")]


def test_symbols_keyed_by_name_and_address():
    base = ["name,address,notes", "s,0x10,old"]
    out, _ = ledger_merge.merge(base, base, ["name,address,notes", "s,0x10,new", "s,0x20,second pin"],
                                "reverse/symbols.csv")
    assert out == ["name,address,notes", "s,0x10,new", "s,0x20,second pin"]
