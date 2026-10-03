// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z
// partial score=0.97 date=2026-10-04
// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z
// partial score=0.95 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z, retail 0x00074B3B, 141 bytes.
// Fills the global Rva000748F6 via rowed getter ?Rva00074AFFGet 0x00074AFF:
// header 0 at +0, int c at +0x34, byte d at +0x38, then three rows of
// diff = b - a, zero, zero, base = a over the +4..+0x38 range.
// Evidence: chain lane; calls just-landed ?Rva00074AFFGet; vtable slot 11 context;
// offsets to 0x38. `a` is read from memory twice per lane (folded into the
// subss memory operand and into the base store), so the source keeps only the
// `b` lanes in locals -- that is what puts them in xmm0/xmm1/xmm2 as retail does.

struct Vec3
{
	float x;
	float y;
	float z;
};

struct Row4
{
	float diff;
	float z1;
	float z2;
	float base;
};

class Rva000748F6
{
public:
	int m00;
	Row4 m_r0;
	Row4 m_r1;
	Row4 m_r2;
	int m34;
	unsigned char m38;
};

class Rva000748F6;
Rva000748F6 *__stdcall Rva00074AFFGet(int dummy);

// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z present-unmatched
Rva000748F6 *__stdcall Rva00074B3BGet(Vec3 *a, Vec3 *b, int c, unsigned char d, int dummy)
{
	Rva000748F6 *g = Rva00074AFFGet(dummy);
	g->m00 = 0;
	g->m34 = c;
	g->m38 = d;
	float bx = b->x, by = b->y, bz = b->z;
	float d0 = bx - a->x, d1 = by - a->y, d2 = bz - a->z;
	g->m_r2.diff = d2;
	g->m_r1.diff = d1;
	g->m_r0.diff = d0;
	float ax = a->x, ay = a->y, az = a->z;
	g->m_r0.z1 = 0.0f;
	g->m_r0.z2 = 0.0f;
	g->m_r0.base = ax;
	g->m_r1.z1 = 0.0f;
	g->m_r1.z2 = 0.0f;
	g->m_r1.base = ay;
	g->m_r2.z1 = 0.0f;
	g->m_r2.z2 = 0.0f;
	g->m_r2.base = az;
	return g;
}
