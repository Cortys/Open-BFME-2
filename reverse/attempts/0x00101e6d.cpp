// ?Rva00101E6DCalc@@YAXHHPAM0HH@Z
// partial score=0.9 date=2026-09-29
// ?Rva00101E6DCalc@@YAXHHPAM0HH@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /Ot /Oy- /MD /arch:SSE
// ?Rva00101E6DCalc@@YAXHHPAM0HH@Z @0x00101E6D (86B):
// Free SSE helper: pixel-to-NDC style map of two ints by global 2.0f 0xBC28F4
// over two more ints minus literal 1.0f from shared pool 0xBBB8D8; stores the
// first result and 0.0f minus the second through two out pointers.
// Evidence: callers 0x00089689 0x000995AA 0x001028E0; unblocks 0x00089658 0x001028AA.
extern float g_Va00BC28F4;
// ?Rva00101E6DCalc@@YAXHHPAM0HH@Z present-unmatched
void Rva00101E6DCalc(int a, int b, float *out1, float *out2, int c, int d)
{
	float g1 = g_Va00BC28F4;
	float t1 = (float)a * g1 / (float)c - 1.0f;
	*out1 = t1;
	float t2 = (float)b * g1 / (float)d - 1.0f;
	*out2 = 0.0f - t2;
}
