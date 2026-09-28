// ?Rva004F6B8DCopy@@YAPAURva004F6966@@PBU1@0PAU1@@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// ?Rva004F6B8DCopy@@YAPAURva004F6966@@PBU1@0PAU1@@Z @0x004F6B8D (38B): uninitialized_copy.
// Copies [first,last) of 0xC-sized Rva004F6966 to result via rowed placement
// construct ?Rva004F6B69Construct@@YAXPAURva004F6966@@PBU1@@Z at 0x004F6B69
// and returns the result end. Callers at 0x004F8A76 0x004F8AC1 walk into
// 0x004F8A35. Prev Init next Fill /O1 /DNDEBUG /MD.
struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};

struct Rva004F6966
{
	TargetRef00217D4C *m_00;
	int m_04;
	int m_08;
};

void Rva004F6B69Construct(Rva004F6966 *dst, const Rva004F6966 *src);

// ?Rva004F6B8DCopy@@YAPAURva004F6966@@PBU1@0PAU1@@Z present-unmatched
Rva004F6966 *Rva004F6B8DCopy(const Rva004F6966 *first, const Rva004F6966 *last, Rva004F6966 *result)
{
	Rva004F6966 *dst = result;
	Rva004F6966 *src = (Rva004F6966 *)first;
	for (; src != last; ++dst, ++src) {
		Rva004F6B69Construct(dst, src);
	}
	return dst;
}
