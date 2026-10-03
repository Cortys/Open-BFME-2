// ?Rva0037BA97Init@@YAXPAUTriple12@@PBUPair8@@H@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /EHsc /MD
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

void __cdecl Rva0037BA97Init(Triple12 *dest, const Pair8 *src, int c)
{
    Triple12 tmp;
    tmp.a = src->a;
    tmp.b = src->b;
    tmp.c = c;
    *dest = tmp;
}
