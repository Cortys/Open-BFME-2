// ?Rva00074C3FGet@@YGPAVRva000748F6@@PAUMat12Src@@PAUVec3@@HEH@Z
// partial score=0.98 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// ?Rva00074C3FGet@@YGPAVRva000748F6@@PAUMat12Src@@PAUVec3@@HEH@Z, retail 0x00074C3F, 250 bytes.
// Copies 12-float matrix into global Rva000748F6 via rowed getter, scales 3x3 by vector.
// Evidence: chain lane, calls just-landed ?Rva00074AFFGet, vtable slot 12 context, offsets to 0x38.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
struct Mat12Src
{
	float v[12];
};

struct Vec3
{
	float x;
	float y;
	float z;
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

// ?Rva00074C3FGet@@YGPAVRva000748F6@@PAUMat12Src@@PAUVec3@@HEH@Z present-unmatched
Rva000748F6 *__stdcall Rva00074C3FGet(Mat12Src *a, Vec3 *s, int c, unsigned char d, int dummy)
{
	Rva000748F6 *g = Rva00074AFFGet(dummy);
	g->m00 = 1;
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
	float sz = s->z;
	float sy = s->y;
	float sx = s->x;
	g->m04[0] *= sx;
	g->m04[4] *= sx;
	g->m04[8] *= sx;
	_ReadWriteBarrier();
	g->m04[1] *= sy;
	g->m04[5] *= sy;
	g->m04[9] *= sy;
	_ReadWriteBarrier();
	g->m04[2] *= sz;
	g->m04[6] *= sz;
	g->m04[10] *= sz;
	return g;
}
