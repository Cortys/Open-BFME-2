// ?Rva0037BA97Init@@YAXPAUTriple12@@PBUPair8@@H@Z
// partial score=0.91 date=2026-10-01
// cl: /O1 /EHsc /MD
// ?Rva0037BA97Init@@YAXPAUTriple12@@PBUPair8@@H@Z retail 0x0037BA97 43B
// Evidence: LINK BONUS via 0x0002CBCC; callers 0x0002CBFF 0x0037D607 0x0037D7BA 0x0037DA6D 0x005D09F0; prev 0x0037BA62 next 0x0037BAC2; copies 12B via movsd x3 from 8B src plus 4B third
struct Pair8
{
	int a;
	int b;
};

struct Triple12
{
	int a;
	int b;
	int c;
};

// ?Rva0037BA97Init@@YAXPAUTriple12@@PBUPair8@@H@Z present-unmatched
void __cdecl Rva0037BA97Init(Triple12 *dest, const Pair8 *src, int c)
{
	int a = src->a;
	Triple12 tmp;
	tmp.b = src->b;
	tmp.c = c;
	tmp.a = a;
	*dest = tmp;
}
