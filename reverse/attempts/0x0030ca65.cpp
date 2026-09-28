// ?Rva0030CA65Copy@@YAPAVRva004733E0@@PBV1@0PAV1@@Z
// partial score=0.93 date=2026-09-28
// ?Rva0030CA65Copy@@YAPAVRva004733E0@@PBV1@0PAV1@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1
// Retail 0x0030CA65 38B chain after 0x0030CA53. Copy(src_first,src_last,dst_first)
// returning dst_end via Rva0030CA53Set(dst,src). Callers at 0x002828AE/0x002828F9
// push 4 (4th lea [ebp+0x1b] unread at [E+16]); body reads only 3 slots.
// Best /O1 gives exact 38B but EBP frame with dst in mem (add [ebp+0x10],8)
// vs retail frameless with dst+src in regs (edi+esi). /O2 gives 52B.
struct Rva004733E0Obj
{
	int m_00;
	int m_04;
};
class Rva004733E0
{
	int m_00;
	Rva004733E0Obj *m_04;
public:
	Rva004733E0 *set(const Rva004733E0 *src);
};
void Rva0030CA53Set(Rva004733E0 *dst, const Rva004733E0 *src);
Rva004733E0 *Rva0030CA65Copy(const Rva004733E0 *src, const Rva004733E0 *end, Rva004733E0 *dst)
{
	while (src != end) {
		Rva0030CA53Set(dst, src);
		++src;
		++dst;
	}
	return dst;
}
