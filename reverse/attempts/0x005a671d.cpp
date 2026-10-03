// ?Rva005A671DGet@@YAHXZ
// partial score=0.9 date=2026-10-03
// cl: /O1
// ?Rva005A671DGet@@YAHXZ @0x005A671D 21B. Unlock lane: global counter at
// 0x00E063FC that never returns 0; callers 0x005A6903 and 0x005A7A96.
// Target evidence: test/jne/inc shape with post-increment store.
extern int g_00E063FC;
// ?Rva005A671DGet@@YAHXZ present-unmatched
int Rva005A671DGet()
{
	int v = g_00E063FC;
	if (v == 0)
		v = 1;
	int r = v;
	++v;
	g_00E063FC = v;
	return r;
}
