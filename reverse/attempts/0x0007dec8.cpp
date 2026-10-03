// ?Rva0007DEC8Add@@YAXPAMMMPBM@Z
// partial score=0.9 date=2026-10-03
// cl: /O2 /arch:SSE /MD
// ?Rva0007DEC8Add@@YAXPAMMMPBM@Z, RVA 0x0007DEC8, 39B. Free SSE add of 2-float vec.
// out[0]=b[0]+ax, out[1]=b[1]+ay via movss/addss. Callers 0x000831D4 0x002F8C64 0x006B31F1.
// Evidence: packet disasm; unlocks 0x006B3100 0x002F8B00 0x0008304A.
// ?Rva0007DEC8Add@@YAXPAMMMPBM@Z present-unmatched
void Rva0007DEC8Add(float *out, float ax, float ay, const float *b)
{
	float x = b[0];
	float y = b[1];
	out[1] = y + ay;
	out[0] = x + ax;
}
