// ?rva004C21A9@Rva004C21A9@@QAEXPAX@Z
// partial score=0.93 date=2026-10-04
// cl: /O1 /DNDEBUG /MD /arch:SSE2
//
// ?rva004C21A9@Rva004C21A9@@QAEXPAX@Z @0x004C21A9 135B
// Evidence: unlock lane, prev Rva004C20D5IsWithin 0x004C20D5 next
// PorcupineFormationBodyModuleDataCtor 0x004C225D, caller 0x004C2230, callees
// findObjectByID row plus getRoadWidth row plus Rva004C20D5IsWithin row plus
// rva002CE964 row, globals TheGameLogic and TheWeaponStore, ObjectID at
// arg+8. Identity: thiscall method with 1 stack arg (ret 4), honest address
// name.
typedef unsigned int ObjectID;

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Object
{
public:
	char m_pad0[4];
	void *m_ptr4;
	char m_pad8[0x30];
	Coord3D m_pos;
	char m_pad2[0x3F4];
	unsigned char m_flag438;
};

class GameLogic
{
public:
	class Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

class TerrainRoadType
{
public:
	float getRoadWidth();
};

class WeaponTemplate
{
};

class WeaponStore
{
public:
	void rva002CE964(const WeaponTemplate *a, const class Object *b, const class Object *c);
};

extern WeaponStore *TheWeaponStore;

bool __stdcall Rva004C20D5IsWithin(float dist, const Coord3D *a, const Coord3D *b);

struct Rva004C21A9Helper
{
	void *m_ptr4;
	class Object *m_ptr8;
};

class Rva004C21A9
{
public:
	void rva004C21A9(void *arg);
private:
	char m_pad0[4];
	void *m_ptr4;
	class Object *m_ptr8;
};

// ?rva004C21A9@Rva004C21A9@@QAEXPAX@Z present-unmatched
void Rva004C21A9::rva004C21A9(void *arg)
{
	Rva004C21A9 *self = this;
	Object * volatile objB = self->m_ptr8;
	if (!objB)
		return;
	void *helper = self->m_ptr4;
	if (!helper)
		return;
	if (*(void **)((char *)helper + 0x64) == 0)
		return;
	ObjectID id = *(ObjectID *)((char *)arg + 8);
	Object *obj = TheGameLogic->findObjectByID(id);
	if (!obj)
		return;
	if (obj->m_flag438 & 1)
		return;
	void *inner = *(void **)((char *)obj + 4);
	if (*(unsigned char *)((char *)inner + 0x10b) & 2)
		return;
	const Coord3D *a = &obj->m_pos;
	const Coord3D *b = &objB->m_pos;
	float width = ((TerrainRoadType *)*(void **)((char *)helper + 0x64))->getRoadWidth();
	if (!Rva004C20D5IsWithin(width, a, b))
		return;
	TheWeaponStore->rva002CE964(*(WeaponTemplate **)((char *)helper + 0x64), objB, obj);
}
