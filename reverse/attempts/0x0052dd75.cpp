// ?rva0052DD75@Rva0052DD75@@QAEMMHM@Z
// partial score=0.93 date=2026-09-30
// ?rva0052DD75@Rva0052DD75@@QAEMMHM@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /G7 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva0052DD75@Rva0052DD75@@QAEMMHM@Z, retail 0x0052DD75, 230 bytes.
// Mid at this+0 with int x+0 y+4 plus inner ptr+8 holding int x+0 y+4.
// Early out returns a when mid null or inner null. Loop zeroes Coord2D acc,
// factor starts from shared 1.0f at 0x00BBB8D8, dec n accumulates
// inv*dx*factor plus inv*dy*factor with inv = 1.0/sqrt(dx*dx+dy*dy),
// factor *= c each turn, final acc.toAngle. Evidence: callers 0x002F0610
// 0x002F8B64 0x002FCDDF; callees sqrt thunk 0x0062921C plus toAngle 0x00005923;
// ret 0xC three args plus ecx thiscall; SSE per movss.
#include <math.h>

class Coord2D
{
public:
	float toAngle() const;
	float x;
	float y;
};

struct Rva0052DD75Inner
{
	int x;
	int y;
};

struct Rva0052DD75Mid
{
	int x;
	int y;
	Rva0052DD75Inner *m_8;
};

extern float g_Va00BBB8D8;

class Rva0052DD75
{
public:
	float rva0052DD75(float a, int n, float c);
	Rva0052DD75Mid *m_0;
};

// ?rva0052DD75@Rva0052DD75@@QAEMMHM@Z present-unmatched
float Rva0052DD75::rva0052DD75(float a, int n, float c)
{
	Rva0052DD75Mid *mid = m_0;
	if (mid == 0)
		return a;
	if (mid->m_8 == 0)
		return a;
	Coord2D acc;
	acc.x = 0.0f;
	acc.y = 0.0f;
	float factor = g_Va00BBB8D8;
	while (n > 0) {
		Rva0052DD75Inner *inner = m_0->m_8;
		--n;
		if (inner == 0)
			break;
		float inv;
		float dx = (float)(mid->x - inner->x);
		float dy = (float)(mid->y - inner->y);
		inv = g_Va00BBB8D8 / sqrt(dy * dy + dx * dx);
		acc.x += inv * dx * factor;
		acc.y += inv * dy * factor;
		factor *= c;
	}
	return acc.toAngle();
}
