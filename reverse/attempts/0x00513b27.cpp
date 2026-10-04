// ?Rva00513B27Init@@YAXPAURva00513B27Pair@@PBGH@Z
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /Os /EHsc
// ?Rva00513B27Init@@YAXPAURva00513B27Pair@@PBGH@Z @0x00513B27 52B: builds 12B title rec via initWide plus int extra then 3x movsd to dst; unlocks 0x00513ED1; neighbours WinMainPairUnicode.cpp.
class Rva000B3F84Pair
{
public:
	Rva000B3F84Pair *initWide(const unsigned short *src);
	const char *m_ptr;
	int m_len;
};
struct Rva00513B27Pair
{
	const char *m_ptr;
	int m_len;
	int m_extra;
};
// ?Rva00513B27Init@@YAXPAURva00513B27Pair@@PBGH@Z present-unmatched
void __cdecl Rva00513B27Init(Rva00513B27Pair *dst, const unsigned short *src, int extra)
{
	Rva000B3F84Pair wide;
	wide.initWide(src);
	Rva00513B27Pair tmp;
	tmp.m_ptr = wide.m_ptr;
	tmp.m_len = wide.m_len;
	tmp.m_extra = extra;
	*dst = tmp;
}
