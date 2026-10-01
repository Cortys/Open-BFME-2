// ?rva00469012@Rva00469012@@QAE_NPAVObject@@PBUCoord3D@@@Z
// partial score=0.98 date=2026-10-01
// ?rva00469012@Rva00469012@@QAE_NPAVObject@@PBUCoord3D@@@Z
// partial score=0.98 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
//
// ?Rva00468F0FInRange@@YG_NPAVObject@@0@Z, retail 0x00468F0F 89B.
// SSE range check: dx dy from +0x38 +0x3C, null guard at +0x258,
// radius at +0x1F0 +0x3C, distSq vs radiusSq via comiss.
// Caller 0x47390E, prev 0x468E26 Get, next 0x469075 setter.

class Object
{
public:
	float m_38_unused[14];
	float m_38;
	float m_3C;
	char m_pad3C[0x258 - 0x40];
	void *m_258;
};

struct Rva00468F0FOuter
{
	char m_pad[0x1F0];
	void *m_1F0;
};

struct Rva00468F0FInner
{
	char m_pad[0x3C];
	float m_3C;
};

bool __stdcall Rva00468F0FInRange(Object *a, Object *b)
{
	float dx = a->m_38 - b->m_38;
	float dy = a->m_3C - b->m_3C;
	void *p = a->m_258;
	if (p == 0)
		return false;
	float r = ((Rva00468F0FInner *)((Rva00468F0FOuter *)p)->m_1F0)->m_3C;
	float distSq = dy * dy;
	distSq = distSq + dx * dx;
	float rSq = r * r;
	return distSq < rSq;
}

// ?rva00469012@Rva00469012@@QAE_NPAVObject@@PBUCoord3D@@@Z, retail 0x00469012, 99 bytes.
// Behind check: dx dy from arg Coord minus Object +0x38/+0x3C, null guard on
// Thing at this+8, dot with Thing::getUnitDirectionVector2D, true when dot<0.
// Callers at 0x00474A8E 0x00476F41; honest-address method. Prev shares +0x38
// layout and /arch:SSE flags.
struct Coord3D
{
	float x;
	float y;
	float z;
};

class Thing
{
public:
	void getUnitDirectionVector2D(Coord3D &out) const;
};

class Rva00469012
{
public:
	bool rva00469012(Object *a, Coord3D const *b);
	char m_pad[8];
	Thing *m_thing;
};

bool Rva00469012::rva00469012(Object *a, Coord3D const *b)
{
	Coord3D delta;
	delta.x = b->x;
	delta.y = b->y;
	delta.x -= a->m_38;
	delta.y -= a->m_3C;
	if (m_thing == 0)
		return false;
	Coord3D dir;
	m_thing->getUnitDirectionVector2D(dir);
	if (delta.x * dir.x + delta.y * dir.y < 0.0f)
		return true;
	return false;
}
