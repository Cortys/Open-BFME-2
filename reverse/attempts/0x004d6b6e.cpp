// ?Rva004D6B6E@@YAMM@Z
// partial score=0.94 date=2026-09-27
// ?Rva004D6B6E@@YAMM@Z
// partial score=0.94 date=2026-09-27
// cl: /O1 /arch:SSE /MD /Oi-
// ?Rva004D6B6E@@YAMM@Z @0x004D6B6E (47B):
// Free __cdecl float angle: if (value <= 0.0f) return pi/2 else return
// (float)(atan(12.0f / value) * 2). Retail SSE compare (movss/comiss vs pooled
// 0.0 at 0x00BBAEAC), x87 divide of pooled 12.0 at 0x00BC2924, double atan via
// msvcr71 thunk, fadd doubling, pooled pi/2 at 0x00BC2A24 on the low path.
// BFME1 donor Code/GameEngine/Source/Common/Bfme5SixtyNine.cpp bfmeAngle
// (same shape, __stdcall, different globals); BFME2 is __cdecl (ret, caller
// cleans) with retail pooled constants. Callers 0x0025EDCB and 0x004D6BC0;
// unblocks 0x004D6BB8. Honest-address name.

extern "C" double __cdecl atan(double value);

extern float g_Va00BBAEAC;
extern float g_Va00BC2924;
extern float g_Va00BC2A24;

// ?Rva004D6B6E@@YAMM@Z present-unmatched
float __cdecl Rva004D6B6E(float value)
{
	if (value > g_Va00BBAEAC)
		return (float)(atan(g_Va00BC2924 / value) * 2.0);
	return g_Va00BC2A24;
}
