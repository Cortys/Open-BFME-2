# link-dataglob-5 outcomes

## Linked

- `Code/GameEngine/Source/GameLogic/ScriptEngine/Rva00206E63Search.cpp` — `f5bba1ba5d8af9cff2216661419682eacdfd54fc`; `LINKED 100` bytes. Defined `g_00BE3908` at VA `0x00BE3908` (.rdata) as four `FieldParse` entries plus the zero sentinel, bounded at VA `0x00BE3958` by the `HelpText` token. Matched DIR32 witnesses in both search rows establish the table address; the rowed `INI::parseAsciiString` target and the recovered `Rva003B39C7` offsets establish parser/layout use. Local literals reproduce token text; string-pointer identity is not asserted. Exact decorated global verified in the built object.
- `Code/GameEngine/Source/GameLogic/ScriptEngine/Rva00206DFFSearch.cpp` — shared definition from `f5bba1ba5d8af9cff2216661419682eacdfd54fc`; `LINKED 100` bytes. Uses the shared `g_00BE3908` definition above.

Both units: `./build.sh` Functions OK 1/1; `check_csv.py`, frozen-file gate, and `class_gate.py` pass; `link_check.py` LINKS both units, 200 linked bytes total.

## Skipped

- `Code/GameEngine/Source/Common/Rva002A9ACCDict.cpp`: skipped because `be1c6b9a6` by Peppy Penguin changed this unit within the preceding 3 hours; its newly landed function recovery is too recent for this lane's rule. No claims taken.
- `Code/GameEngine/Source/Common/BfmeConv1369.cpp`: unresolved `g_bfmeVftBVHW` at VA `0x00CE3B38` (.rdata). Retail data contains an RTTI-like pointer and function pointers, but the table's target object/source identity is not independently established. No initializer invented; no claims taken.
- `Code/GameEngine/Source/Common/BfmeConv1343.cpp`: unresolved `g_bfmeVftUUA` at VA `0x00CE3ED4` (.rdata). Two pointer targets (`0x00A6F380`, `0x00A6F100`) precede unrelated text at `0x00CE3EDC`; without source objects for those targets, I left the vtable-like data undefined. No claims taken.
