// ?Rva000A925DGet@@YAMMM@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /Oi- /arch:SSE
// ?Rva000A925DGet@@YAMMM@Z @0x000A925D 69B
// Free float op: if G1 > a return 1.0f else if G2 <= fabs(b-a) return b/a else return 1.0f.
// Evidence: movss/comiss/ja plus x87 fabs/fcompi/jbe plus divss; globals G1 0x00BC93B4
// G2 g_Va00BCF628 1.0f g_Va00BBB8D8; callers at 0x000A9630 0x000A9659 0x000A96A1
// pass two floats; neighbours ConstIntGetters/GlobalFloatGetters give Common dir.
extern float g_00BC93B4;
extern float g_Va00BCF628;
extern float g_Va00BBB8D8;
extern "C" double __cdecl fabs(double x);

// ?Rva000A925DGet@@YAMMM@Z present-unmatched
float Rva000A925DGet(float a, float b)
{
	if (g_00BC93B4 > a)
		return g_Va00BBB8D8;
	if (fabs(b - a) < g_Va00BCF628)
		return g_Va00BBB8D8;
	return b / a;
}
