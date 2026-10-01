// ?Rva003641AEClamp@@YGHMM@Z
// partial score=0.93 date=2026-10-01
// ?Rva003641AEClamp@@YGHMM@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /arch:SSE

// ?Rva003641AEClamp@@YGHMM@Z @0x003641AE 68B via Path neighbour TU plus retail clamp shape
// Evidence: callers 0x00364FBA and 0x0036596A; globals g_00BC9D14 g_00C17274 as float factors; IAT ceil.
// x87 fld/fistp needs inline asm helper (BaseType.h pattern); plain (int) cast emits _ftol2 call.

extern float g_00BC9D14;
extern float g_00C17274;

__declspec(dllimport) double __cdecl ceil(double v);

__forceinline long fast_float2long_round(float f)
{
	long i;
	__asm {
		fld [f]
		fistp [i]
	}
	return i;
}

// ?Rva003641AEClamp@@YGHMM@Z present-unmatched
int __stdcall Rva003641AEClamp(float a, float b)
{
	b = (float)ceil(g_00BC9D14 * b * a * g_00C17274);
	int i = fast_float2long_round(b);
	if (i < 1)
		i = 1;
	if (i > 128)
		i = 128;
	return i;
}
