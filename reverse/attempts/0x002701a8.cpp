// ?Rva002701A8Scale@@YGXPAMM@Z
// partial score=0.93 date=2026-10-01
// cl: /O2 /arch:SSE
//
// ?Rva002701A8Scale@@YGXPAMM@Z, retail 0x002701A8, 76 bytes. Unlock lane.
// Free __stdcall (ret 8) scaling three floats at p: p[i] = p[i]*b - b*g.
// Global g_Va007C26F0 (float 0.5, VA 0xBC26F0) is the shared 0.5 literal used
// by 3 TUs. Prev is Disp0DwordImmSetters.cpp (default flags), next is
// Rva002701F4Ctor.cpp (/O1); SSE flags from ScriptActionsRva003BBF51 precedent.

extern float g_Va007C26F0;

// ?Rva002701A8Scale@@YGXPAMM@Z present-unmatched
void __stdcall Rva002701A8Scale(float *p, float b)
{
	float k = b * g_Va007C26F0;
	p[0] = p[0] * b - k;
	p[1] = p[1] * b - k;
	p[2] = p[2] * b - k;
}
