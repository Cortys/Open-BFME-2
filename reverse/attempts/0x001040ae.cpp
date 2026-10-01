// ?Rva001040AESub@@YAXPAMMMPBM@Z
// partial score=0.93 date=2026-10-01
// cl: /O2 /arch:SSE /MD
// ?Rva001040AESub@@YAXPAMMMPBM@Z retail 0x001040AE 39B
// Evidence: LINK BONUS via 0x0030B3D1; callers ClosestPointOnLineSegment 0x006B3100 twice plus 0x00104359 twice plus 0x002F8B00 plus 0x0030B3D1; prev 0x00104076 next 0x001042C1; SSE subss pair dest0 x-src0 dest1 y-src1
// ?Rva001040AESub@@YAXPAMMMPBM@Z present-unmatched
void __cdecl Rva001040AESub(float *dest, float x, float y, const float *src)
{
	float dx;
	float dy;
	dx = x - src[0];
	dy = y - src[1];
	dest[0] = dx;
	dest[1] = dy;
}
