// ?rva006BE220@Rva0087E900Shape@@QAEXPBURva0087E900Coord@@MPAU2@@Z
// partial score=0.99 date=2026-09-29
// ?rva006BE220@Rva0087E900Shape@@QAEXPBURva0087E900Coord@@MPAU2@@Z
// partial score=0.99 date=2026-09-29
// cl: /O2 /Ob2 /G6 /DNDEBUG /MD /EHs-c-
// ?rva006BE220@Rva0087E900Shape@@QAEXPBURva0087E900Coord@@MPAU2@@Z 0x006BE220 50B evidence: wrapper over Rva0087E900 via transform TU flags; caller 0x004B7408; callee row declares void but body uses pointer return - declared as returns Coord*
struct Rva0087E900Coord { float x; float y; float z; };
struct Rva0087E900Shape { char pad[0x10]; Rva0087E900Coord m_field0x10; void rva006BE220(const Rva0087E900Coord *position, float angle, Rva0087E900Coord *dest); };
Rva0087E900Coord *Rva0087E900(Rva0087E900Coord *out, const Rva0087E900Coord *position, const Rva0087E900Shape *shape, float angle);
// ?rva006BE220@Rva0087E900Shape@@QAEXPBURva0087E900Coord@@MPAU2@@Z present-unmatched
void Rva0087E900Shape::rva006BE220(const Rva0087E900Coord *position, float angle, Rva0087E900Coord *dest)
{
	Rva0087E900Coord tmp;
	Rva0087E900Coord *p = Rva0087E900(&tmp, position, this, angle);
	*dest = *p;
}
