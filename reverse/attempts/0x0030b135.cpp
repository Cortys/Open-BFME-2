// ?rva0030B135@Rva0030B92C@@QAEXPBUBfmePod8@@@Z
// partial score=0.93 date=2026-10-02
// cl: /O2 /arch:SSE /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva0030B135@Rva0030B92C@@QAEXPBUBfmePod8@@@Z @0x0030B135 114B
// Vector-plus-mid float accumulate via rowed Pod8 vector then flag-gated mid.
// Evidence: touches [ecx]/[ecx+4] step8 with addss from [edx]; flag 0x24; mid 0x0C-0x18; caller 0x00330B75; same layout as 0x0030B92C op=.
#include <vector>
struct BfmePod8 { float x; float y; };
struct Rva0030B92C
{
	_STL::vector<BfmePod8, _STL::allocator<BfmePod8> > m_vec;
	float m_0c;
	float m_10;
	float m_14;
	float m_18;
	int m_1c;
	int m_20;
	unsigned char m_24;
	void rva0030B135(const BfmePod8 *a);
};
void Rva0030B92C::rva0030B135(const BfmePod8 *a)
{
	for (BfmePod8 *p = m_vec.begin(), *e = m_vec.end(); p != e; ++p) {
		p->x += a->x;
		p->y += a->y;
	}
	if (m_24 != 0)
		return;
	m_0c += a->x;
	m_10 += a->y;
	m_14 += a->x;
	m_18 += a->y;
}
