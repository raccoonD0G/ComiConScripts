#!/usr/bin/env python3
"""Utility for exporting ComicCon save game data into CSV files.

This script decodes the ``BattleSave.sav`` (or any other Unreal Engine save game
built from the ``UScoreSaveGame`` class) and exports the recorded metrics to a
set of CSV files:

* ``summary.csv`` – scalar fields such as ``BestScore`` and ``TotalBattleCount``.
* ``battle_timestamps.csv`` – chronological list of battle connection
  timestamps.
* ``score_history.csv`` – score leaderboard entries with the associated hunter
  count.

Example
-------

```bash
python tools/extract_savegame_to_csv.py \
    --input /path/to/Saved/SaveGames/BattleSave.sav \
    --output battle_metrics
```

When ``--output`` points to a directory (like ``battle_metrics`` above) the
script will create the folder if required and place
``battle_metrics/battle_metrics_summary.csv``,
``battle_metrics/battle_metrics_battle_timestamps.csv`` and
``battle_metrics/battle_metrics_score_history.csv`` inside it. You can also pass
an explicit file path such as ``--output battle_metrics.csv`` to keep the CSVs
next to that file path. Provide ``--base-name SomePrefix`` if you want a custom
file prefix inside a directory.

The implementation only understands the properties used by ``UScoreSaveGame``;
if you extend the save game with additional types you may need to update the
parsers below.
"""

from __future__ import annotations

import argparse
import csv
import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, List, Tuple


class SaveGameParseError(RuntimeError):
    """Raised when the save file cannot be decoded."""


@dataclass
class ParsedSaveGame:
    """Container for the pieces we export to CSV."""

    scalars: Dict[str, Any]
    battle_timestamps: List[str]
    score_history: List[Dict[str, int]]


class MemoryReader:
    """Lightweight reader for the Unreal Engine binary format."""

    def __init__(self, data: bytes) -> None:
        self._data = data
        self._offset = 0

    def tell(self) -> int:
        return self._offset

    def read_bytes(self, size: int) -> bytes:
        if self._offset + size > len(self._data):
            raise SaveGameParseError("Unexpected end of file")
        chunk = self._data[self._offset : self._offset + size]
        self._offset += size
        return chunk

    def read_int32(self) -> int:
        return struct.unpack_from("<i", self.read_bytes(4))[0]

    def read_uint32(self) -> int:
        return struct.unpack_from("<I", self.read_bytes(4))[0]

    def read_float(self) -> float:
        return struct.unpack_from("<f", self.read_bytes(4))[0]

    def read_guid(self) -> Tuple[int, int, int, int]:
        return struct.unpack_from("<IIII", self.read_bytes(16))

    def read_fstring(self) -> str:
        length = self.read_int32()
        if length == 0:
            return ""
        if length < 0:
            raw = self.read_bytes(-length)
            return raw[:-1].decode("utf-8")
        raw = self.read_bytes(length * 2)
        return raw[:-2].decode("utf-16-le")

    def skip(self, size: int) -> None:
        self.read_bytes(size)


def read_save_game_header(reader: MemoryReader) -> None:
    """Consume the standard ``FSaveGameHeader`` block.

    The exact values are not needed for exporting, but we sanity check the
    structure to make sure the file resembles an Unreal Engine save game.
    """

    save_version = reader.read_int32()
    if save_version < 0 or save_version > 1000:
        raise SaveGameParseError("Not a valid Unreal Engine save file (version)")

    # UE file and engine version numbers – kept for validation but ignored.
    reader.read_int32()  # PackageFileUEVersion
    engine_major = reader.read_int32()
    engine_minor = reader.read_int32()
    engine_patch = reader.read_int32()
    reader.read_int32()  # Changelist
    reader.read_fstring()  # Branch name

    if not (0 <= engine_major < 100 and 0 <= engine_minor < 100 and 0 <= engine_patch < 100):
        raise SaveGameParseError("Engine version values look incorrect")

    custom_version_format = reader.read_int32()
    if custom_version_format not in (0, 1, 2, 3):
        raise SaveGameParseError("Unsupported custom version format")

    if custom_version_format != 0:
        custom_version_count = reader.read_int32()
        for _ in range(custom_version_count):
            reader.read_guid()
            reader.read_int32()
            if custom_version_format == 3:
                # Format 3 stores friendly names as strings.
                reader.read_fstring()

    # Class name of the save game object (e.g. "/Script/ComicCon.ScoreSaveGame").
    class_name = reader.read_fstring()
    if not class_name:
        raise SaveGameParseError("Save game class name was empty")

    # Some engine versions append the full class path twice. Peek ahead and
    # discard the duplicate if present, otherwise rewind so the property stream
    # stays intact.
    possible_duplicate_offset = reader.tell()
    possible_duplicate = reader.read_fstring()
    if not (possible_duplicate and possible_duplicate.startswith(class_name)):
        reader._offset = possible_duplicate_offset


def parse_property_stream(reader: MemoryReader) -> ParsedSaveGame:
    scalars: Dict[str, Any] = {}
    battle_timestamps: List[str] = []
    score_history: List[Dict[str, int]] = []

    while True:
        prop_name = reader.read_fstring()
        if prop_name == "None":
            break

        prop_type = reader.read_fstring()
        size = reader.read_int32()
        reader.read_int32()  # array index, unused

        value_start = reader.tell()
        value = parse_property_value(reader, prop_type, size)
        value_end = reader.tell()

        # Skip any unknown padding if the parser failed to consume exactly ``size`` bytes.
        consumed = value_end - value_start
        if consumed < size:
            reader.skip(size - consumed)
        elif consumed > size:
            raise SaveGameParseError(f"Property {prop_name} consumed more than its declared size")

        if prop_name == "BattleTimestamps" and isinstance(value, list):
            battle_timestamps = [str(item) for item in value]
        elif prop_name == "ScoreHistory" and isinstance(value, list):
            score_history = [dict(item) for item in value if isinstance(item, dict)]
        else:
            scalars[prop_name] = value

    return ParsedSaveGame(scalars=scalars, battle_timestamps=battle_timestamps, score_history=score_history)


def parse_property_value(reader: MemoryReader, prop_type: str, size: int) -> Any:
    if prop_type == "IntProperty":
        return reader.read_int32()
    if prop_type == "FloatProperty":
        return reader.read_float()
    if prop_type == "StrProperty":
        return reader.read_fstring()
    if prop_type == "StructProperty":
        struct_name = reader.read_fstring()
        reader.skip(16)  # struct GUID
        return parse_struct(reader, struct_name, size)
    if prop_type == "ArrayProperty":
        return parse_array(reader)
    # Fallback – skip the bytes so that parsing can continue.
    reader.skip(size)
    return None


def parse_array(reader: MemoryReader) -> List[Any]:
    inner_type = reader.read_fstring()

    struct_name = None
    if inner_type == "StructProperty":
        struct_name = reader.read_fstring()
        reader.skip(16)  # struct GUID

    count = reader.read_int32()
    values = []
    for _ in range(count):
        if inner_type == "IntProperty":
            values.append(reader.read_int32())
        elif inner_type == "FloatProperty":
            values.append(reader.read_float())
        elif inner_type == "StrProperty":
            values.append(reader.read_fstring())
        elif inner_type == "StructProperty" and struct_name:
            values.append(parse_struct(reader, struct_name, None))
        else:
            raise SaveGameParseError(f"Unsupported array element type: {inner_type}")
    return values


def parse_struct(reader: MemoryReader, struct_name: str, size: int | None) -> Any:
    if struct_name.endswith("ScoreEntry"):
        return {
            "Score": reader.read_int32(),
            "HunterCount": reader.read_int32(),
        }
    if struct_name.endswith("LinearColor"):
        return {
            "R": reader.read_float(),
            "G": reader.read_float(),
            "B": reader.read_float(),
            "A": reader.read_float(),
        }

    if size is not None:
        reader.skip(size)
    return None


def ensure_directory(path: Path) -> Path:
    """Create ``path`` if it does not exist and return it."""

    path.mkdir(parents=True, exist_ok=True)
    return path


def resolve_output_paths(output: Path, override_base: str | None, fallback_base: str) -> Tuple[Path, Path, Path]:
    """Resolve where the CSV files should be written.

    ``output`` can be either a directory or a file prefix. When a directory is
    provided the resulting CSV files share the directory and use ``override_base``
    (or the directory name) as their base name.
    """

    output = output.expanduser()

    if output.suffix:
        directory = output.parent if output.parent != Path("") else Path.cwd()
        base_name = output.stem or override_base or fallback_base
    elif output.exists() and output.is_file():
        directory = output.parent if output.parent != Path("") else Path.cwd()
        base_name = output.stem or override_base or fallback_base
    else:
        invalid_names = {"", ".", ".."}
        directory = output if output.name not in invalid_names else Path.cwd()
        if override_base:
            base_name = override_base
        elif output.name not in invalid_names:
            base_name = output.name
        else:
            base_name = fallback_base

    directory = ensure_directory(directory.resolve())

    summary_path = directory / f"{base_name}_summary.csv"
    timestamps_path = directory / f"{base_name}_battle_timestamps.csv"
    scores_path = directory / f"{base_name}_score_history.csv"
    return summary_path, timestamps_path, scores_path


def write_summary_csv(parsed: ParsedSaveGame, summary_path: Path) -> None:
    with summary_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.writer(handle)
        writer.writerow(["Field", "Value"])
        for key, value in sorted(parsed.scalars.items()):
            writer.writerow([key, value])


def write_timestamps_csv(parsed: ParsedSaveGame, timestamps_path: Path) -> None:
    with timestamps_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.writer(handle)
        writer.writerow(["Index", "Timestamp"])
        for index, timestamp in enumerate(parsed.battle_timestamps, start=1):
            writer.writerow([index, timestamp])


def write_scores_csv(parsed: ParsedSaveGame, scores_path: Path) -> None:
    with scores_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.writer(handle)
        writer.writerow(["Rank", "Score", "HunterCount"])
        for index, entry in enumerate(parsed.score_history, start=1):
            writer.writerow([index, entry.get("Score", 0), entry.get("HunterCount", 0)])


def export_to_csv(
    parsed: ParsedSaveGame, output: Path, override_base: str | None, fallback_base: str
) -> Tuple[Path, Path, Path]:
    summary_path, timestamps_path, scores_path = resolve_output_paths(output, override_base, fallback_base)
    write_summary_csv(parsed, summary_path)
    write_timestamps_csv(parsed, timestamps_path)
    write_scores_csv(parsed, scores_path)
    return summary_path, timestamps_path, scores_path


def extract_save_game(path: Path) -> ParsedSaveGame:
    data = path.read_bytes()
    reader = MemoryReader(data)
    read_save_game_header(reader)
    return parse_property_stream(reader)


def main() -> None:
    parser = argparse.ArgumentParser(description="Export ComicCon Battle save data to CSV files.")
    parser.add_argument("--input", type=Path, required=True, help="Path to the .sav file (e.g. BattleSave.sav)")
    parser.add_argument(
        "--output",
        type=Path,
        required=True,
        help="Directory or file prefix for the generated CSV files (e.g. battle_metrics)",
    )
    parser.add_argument(
        "--base-name",
        type=str,
        help="Override the base file name when --output points to a directory.",
    )
    args = parser.parse_args()

    try:
        parsed = extract_save_game(args.input)
    except FileNotFoundError:
        parser.error(f"Input save file not found: {args.input}")
    except SaveGameParseError as exc:
        parser.error(f"Failed to parse save game: {exc}")

    fallback_base = args.input.stem or "BattleSave"
    written_paths = export_to_csv(parsed, args.output, args.base_name, fallback_base)

    print("Export complete. Generated CSV files:")
    for path in written_paths:
        print(f"  - {path}")


if __name__ == "__main__":
    main()
