// ?Rva00101E6DCalc@@YAXHHPAM0HH@Z
// partial score=0.95 date=2026-10-04
// cl: /O1 /Ot /Oy- /MD /arch:SSE
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
extern float g_Va00BC28F4;
void Rva00101E6DCalc(int a, int b, float *out1, float *out2, int c, int d)
{
	float g1 = g_Va00BC28F4;
	float t1 = (float)a * g1 / (float)c - 1.0f;
	*out1 = t1;
	float t2 = (float)b * g1 / (float)d - 1.0f;
	_ReadWriteBarrier();
	*out2 = 0.0f - t2;
}
