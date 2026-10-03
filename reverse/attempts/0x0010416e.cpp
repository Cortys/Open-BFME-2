// ?Rva0010416EFloat@@YAMMM@Z
// partial score=0.91 date=2026-10-03
// cl: /O2 /MD /arch:SSE /Oy-
// ?Rva0010416EFloat@@YAMMM@Z, retail 0x0010416E, 39 bytes.
// Evidence: unlock lane, callers at 0x0010451F/0x00104548 in 0x00104359, float const g_00BC746C.
extern float g_00BC746C;

// ?Rva0010416EFloat@@YAMMM@Z present-unmatched
float __cdecl Rva0010416EFloat(float a, float b)
{
	if (b > a)
		a += g_00BC746C;
	return a - b;
}
