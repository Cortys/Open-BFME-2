// ?rva006C1F60@Rva006C1F60@@QAEHI@Z
// partial score=0.9 date=2026-09-27
// ?rva006C1F60@Rva006C1F60@@QAEHI@Z
// partial score=0.90 date=2026-09-27
// ?rva006C1F60@Rva006C1F60@@QAEHI@Z @ 0x006C1F60 113B chain of 0x00030DF0 Release
// AddRef at +0x4e4 Release guarded float clamp via __ftol2 returning clamped int.
// Evidence: calls AddRef 0x00030DD0 Release 0x00030DF0 __ftol2 rowed; flag bit
// 0x800 at +0x514 scale float at +0x534 min at +0x538 max at +0x53c; caller at
// 0x006C2463. Honest address-derived method of Rva006C1F60. Current body is
// 113B/40ins exact size/count with only this/result reg swap (esi/edi) and push
// scheduling left; see align_diff vs 0x006C1F60.
struct Rva00030DD0Lock;
int Rva00030DD0AddRef(Rva00030DD0Lock *lock);
int Rva00030DF0Release(Rva00030DD0Lock *lock);
extern "C" int __cdecl __ftol2(float f);
class Rva006C1F60
{
public:
	int rva006C1F60(unsigned int v);
private:
	unsigned char m_pad0[0x4e4];
	Rva00030DD0Lock *m_lock;
	unsigned char m_pad1[0x514 - 0x4e4 - 4];
	int m_flags;
	unsigned char m_pad2[0x534 - 0x514 - 4];
	float m_scale;
	unsigned int m_min;
	unsigned int m_max;
};
int Rva006C1F60::rva006C1F60(unsigned int v)
{
	Rva00030DD0Lock *lock = m_lock;
	if (lock != 0)
		Rva00030DD0AddRef(lock);
	unsigned int result = 0;
	if ((m_flags & 0x800) != 0) {
		float f = (float)v * m_scale;
		unsigned int iv = (unsigned int)(int)f;
		if (iv < m_min)
			iv = m_min;
		if (iv > m_max)
			iv = m_max;
		result = iv;
	}
	if (lock != 0)
		Rva00030DF0Release(lock);
	return (int)result;
}
