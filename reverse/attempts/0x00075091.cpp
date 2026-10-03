// ?Rva00075091Get@@YGPAVRva000748F6@@PAUMat12Src@@MHEH@Z
// partial score=0.97 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// ?Rva00075091Get@@YGPAVRva000748F6@@PAUMat12Src@@MHEH@Z, retail 0x00075091, 238 bytes.
// Copies 12-float matrix into global Rva000748F6 via rowed getter, scales 3x3 part.
// Evidence: chain lane calls rowed ?Rva00074AFFGet, vtable slot 18 context, offsets to 0x38.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
struct Mat12Src
{
	float v[12];
};

class Rva000748F6
{
public:
	int m00;
	float m04[12];
	int m34;
	unsigned char m38;
};

Rva000748F6 *__stdcall Rva00074AFFGet(int dummy);

// ?Rva00075091Get@@YGPAVRva000748F6@@PAUMat12Src@@MHEH@Z present-unmatched
Rva000748F6 *__stdcall Rva00075091Get(Mat12Src *a, float s, int c, unsigned char d, int dummy)
{
	Rva000748F6 *g = Rva00074AFFGet(dummy);
	g->m00 = 4;
	_ReadWriteBarrier();
	g->m34 = c;
	g->m38 = d;
	g->m04[0] = a->v[0];
	g->m04[1] = a->v[1];
	g->m04[2] = a->v[2];
	g->m04[3] = a->v[3];
	g->m04[4] = a->v[4];
	g->m04[5] = a->v[5];
	g->m04[6] = a->v[6];
	g->m04[7] = a->v[7];
	g->m04[8] = a->v[8];
	g->m04[9] = a->v[9];
	g->m04[10] = a->v[10];
	g->m04[11] = a->v[11];
	_ReadWriteBarrier();
	g->m04[0] *= s;
	g->m04[4] *= s;
	g->m04[8] *= s;
	g->m04[1] *= s;
	g->m04[5] *= s;
	g->m04[9] *= s;
	g->m04[2] *= s;
	g->m04[6] *= s;
	g->m04[10] *= s;
	return g;
}
