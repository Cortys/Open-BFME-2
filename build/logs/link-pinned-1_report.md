# Link-pinned-1 outcomes

- `0x003623E5` — landed the 82-byte address-derived member constructor in `Code/GameEngine/Source/GameLogic/Object/Rva003623E5MemberCtor.cpp`; byte-verified in local commit `d278a253b`. Member-versus-filter identity remains unresolved.
- `0x00362087` — landed the 153-byte two-storage initializer in the same source; byte-verified in local commit `5c2658515`. Member-versus-filter identity remains unresolved.
- `0x0044EB54` — landed the 378-byte address-derived base constructor in `Code/GameEngine/Source/GameLogic/Object/Update/Rva0044EB54Ctor.cpp`; `add_match.py` byte-verified it and `check_csv.py` passed. Commit `14a6ac4e0`; exact semantic identity remains unproven.
- `0x0044EF5E` — no landing. Retained the existing partial at `reverse/attempts/0x0044ef5e.cpp`; Ghidra's 246-byte extent remains authoritative. The constructor-order/vtable mismatch is unresolved; claim released.
- `0x004930A0` — landed the 359-byte address-derived base constructor in `Code/GameEngine/Source/GameLogic/Object/SpecialPower/Rva004930A0Ctor.cpp`; `add_match.py` byte-verified it. Exact semantic identity remains unproven.

No push made.
