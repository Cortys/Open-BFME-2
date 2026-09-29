// ?isSelf@Rva002E0687@@QBE_NXZ
// partial score=0.9 date=2026-09-28
// ?isSelf@Rva002E0687@@QBE_NXZ
// partial score=0.90 date=2026-09-28
// cl: /O1
#define TheRva00DFEF10 (*(void **)0x00DFEF10)
struct Rva002E0687 { bool isSelf() const; };
bool Rva002E0687::isSelf() const
{
    return *(Rva002E0687 **)((char *)TheRva00DFEF10 + 0x98) == this;
}
