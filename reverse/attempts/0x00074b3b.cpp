// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z, retail 0x00074B3B, 141 bytes.
// Fills global Rva000748F6 via rowed getter: header 0, int/byte tail, 3 rows of diff/zero/zero/base.
// Evidence: chain lane, calls just-landed ?Rva00074AFFGet, vtable slot 11 context, offsets to 0x38.
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

class Rva00074B3B
{
public:
	static Rva000748F6 *get(Vec3 *a, Vec3 *b, int c, unsigned char d, int dummy);
};

// ?Rva00074B3BGet@@YGPAVRva000748F6@@PAUVec3@@0HEH@Z present-unmatched
Rva000748F6 *__stdcall Rva00074B3BGet(Vec3 *a, Vec3 *b, int c, unsigned char d, int dummy)
{
	Rva000748F6 *g = Rva00074AFFGet(dummy);
	g->m00 = 0;
	g->m34 = c;
	g->m38 = d;
	float bx = b->x;
	float by = b->y;
	float bz = b->z;
	float ax = a->x;
	float ay = a->y;
	float az = a->z;
	float dx = bx - ax;
	float dy = by - ay;
	float dz = bz - az;
	g->m_r0.diff = dx;
	g->m_r0.z1 = 0.0f;
	g->m_r0.z2 = 0.0f;
	g->m_r0.base = ax;
	g->m_r1.diff = dy;
	g->m_r1.z1 = 0.0f;
	g->m_r1.z2 = 0.0f;
	g->m_r1.base = ay;
	g->m_r2.diff = dz;
	g->m_r2.z1 = 0.0f;
	g->m_r2.z2 = 0.0f;
	g->m_r2.base = az;
	return g;
}
