// ?Rva0009DE01Get@@YAMMM@Z
// partial score=0.95 date=2026-09-29
// ?Rva0009DE01Get@@YAMMM@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /Oy-

// ?Rva0009DE01Get@@YAMMM@Z, RVA 0x0009DE01, 37B. Unlock lane: log-ratio
// helper computing log10(a)/log10(b) through the rowed msvcr71 log10 import
// thunk ji_0062997c at 0x0062997C; each float arg goes to double on reserved
// stack space (reused for the second call), b is converted back to float in
// its own slot, result divided by x87 fdiv and left in ST(0). Referenced via
// extern-plus-cast like nbench1.c so the calls stay direct E8 to the thunk.
// Callers in 0x0009E365/0x0009E71C. Owner unknown so honest neutral Get name.
extern void ji_0062997c();
typedef double (__cdecl *Log10Fn)(double);

// ?Rva0009DE01Get@@YAMMM@Z present-unmatched
float Rva0009DE01Get(float a, float b)
{
	b = (float)((Log10Fn)ji_0062997c)((double)b);
	return (float)(((Log10Fn)ji_0062997c)((double)a) / b);
}
