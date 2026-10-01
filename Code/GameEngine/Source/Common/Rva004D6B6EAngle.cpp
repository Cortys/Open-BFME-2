// cl: /O1 /arch:SSE /MD /Oi-
// ?Rva004D6B6E@@YAMM@Z @0x004D6B6E 47B, callers 0x0025EDCB and 0x004D6BC0.
// Free __cdecl float angle: pi/2 when value <= 0, else twice atan(12 / value).
// Target evidence: SSE compare (movss/comiss) against the pooled 0.0 at
// 0x00BBAEAC, x87 divide of the pooled 12.0 at 0x00BC2924, double atan via
// the msvcr71 thunk, fadd st0,st0 doubling, pooled pi/2 at 0x00BC2A24 on the
// low path. Donor carried: BFME1 Code/GameEngine/Source/Common/
// Bfme5SixtyNine.cpp bfmeAngle (same shape, __stdcall, different globals).
// Structural inference: the doubling is a + a on the float result, which
// pops one argument dword before the fadd as retail does.

extern "C" double __cdecl atan(double value);

float __cdecl Rva004D6B6E(float value)
{
	if (value > 0.0f)
	{
		float a = (float)atan(12.0f / value);
		return a + a;
	}
	return 1.5707964f;
}

// ?Rva004D6BB8@@YAMM@Z @0x004D6BB8 21B, caller 0x0025EDBA: the same angle in
// degrees. Target evidence: forwards its float to 0x004D6B6E and multiplies
// by the pooled 57.2957763671875 at 0x00BBB8CC, which is 180.0f / PI with
// the float PI rounded once (not the nearest float to 180/pi).
float __cdecl Rva004D6BB8(float value)
{
	return Rva004D6B6E(value) * (180.0f / 3.14159265359f);
}
