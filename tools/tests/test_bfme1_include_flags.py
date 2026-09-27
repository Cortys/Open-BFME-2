"""BFME1 donor include paths must resolve from BFME2's working directory."""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))

import build  # noqa: E402


def test_current_layout_donor_flags_are_rooted_at_the_submodule(tmp_path, monkeypatch):
    monkeypatch.setattr(build, "BFME1_ROOT", tmp_path)
    (tmp_path / "game").mkdir()
    (tmp_path / "inputs" / "reference").mkdir(parents=True)
    source = tmp_path / "game" / "Libraries" / "sample.cpp"

    assert build._current_bfme1_include_flag(
        "-Igame/Libraries/Include", source) == (
            "-Ireference/open-bfme-1/game/Libraries/Include")
    assert build._current_bfme1_include_flag(
        "-Iinputs/reference/shims/sweep", source) == (
            "-Ireference/open-bfme-1/inputs/reference/shims/sweep")
    assert build._current_bfme1_include_flag(
        "-IC:/SDK/include", source) == "-IC:/SDK/include"
    assert build._current_bfme1_include_flag(
        "-I\\SDK\\include", source) == "-I\\SDK\\include"


def test_legacy_layout_donor_flags_resolve_against_the_legacy_tree(tmp_path, monkeypatch):
    monkeypatch.setattr(build, "BFME1_ROOT", tmp_path)
    (tmp_path / "Code").mkdir()
    source = tmp_path / "Code" / "Libraries" / "sample.cpp"

    assert build._current_bfme1_include_flag("-ICode/Libraries/Include", source) == (
        "-Ireference/open-bfme-1/Code/Libraries/Include")


def test_bfme2_local_game_include_is_not_rewritten():
    source = build.ROOT / "Code" / "Libraries" / "sample.cpp"
    assert build._current_bfme1_include_flag("-Igame/local/include", source) == (
        "-Igame/local/include")


def test_explicit_submodule_legacy_include_still_maps_to_current_layout():
    assert build._current_bfme1_include_flag(
        "-Ireference/open-bfme-1/Code/Libraries/Include") == (
            "-Ireference/open-bfme-1/game/Libraries/Include")
