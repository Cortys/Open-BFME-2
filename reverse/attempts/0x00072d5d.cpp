// ?Rva00072D5DColor@@YAHE@Z
// partial score=0.93 date=2026-09-30
// ?Rva00072D5DColor@@YAHE@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD
// ?Rva00072D5DColor@@YAHE@Z @0x00072D5D 179B byte-index color ramp with GlobalData float gains
// Evidence: movzx byte param; 3x (int)(float)idx*gain via __ftol2 rows (gains at +0xBDC/+0xBE0/+0xBE4); (idx-4 clamped>0)*255/46 clamped<255 ramp; 0xFF index forces white; nibble pack; bare ret with caller pop (cdecl); callers 0x72E2E 0x72EA2 0x73265.
class GlobalData
{
public:
	char _pad[0xBDC];
	float m_bdc;
	float m_be0;
	float m_be4;
};

extern GlobalData *TheWritableGlobalData;

int __cdecl Rva00072D5DColor(unsigned char index)
{
	GlobalData *g = TheWritableGlobalData;
	int idx = index;
	float f = (float)idx;
	unsigned int r = (int)(f * g->m_be4);
	int gg = (int)(f * g->m_be0);
	int bb = (int)(f * g->m_bdc);
	int a = 0;
	int b = idx - 4;
	int cap = 255;
	int *pm = (b > 0) ? &b : &a;
	a = *pm * 255 / 46;
	int *pq = (a < cap) ? &a : &cap;
	int a2 = *pq;
	if (index == 0xFF)
	{
		bb = 255;
		gg = 255;
		r = 255;
		a2 = 255;
	}
	a2 = ((a2 & 0xF0) << 4) | (bb & 0xF0);
	r >>= 4;
	gg &= 0xF0;
	r &= 0xF;
	a2 <<= 4;
	a2 |= r;
	a2 |= gg;
	return a2;
}
