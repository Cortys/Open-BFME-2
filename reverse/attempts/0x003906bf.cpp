// ?rva003906BF@PhysicsBehavior@@QAEXXZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /arch:SSE /GX /Oy- /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ?rva003906BF@PhysicsBehavior@@QAEXXZ @0x003906BF 106B. Identity: PhysicsBehavior wake helper beside ctor 0x3907A6; same TU layout/flags. Reads Object+4/+274 float at +0x610 vs kF7C, Object+11C flag via pinned Object::rva0028AE6D, then moduleData+20 to +58, flag +5C, setWakeFrame(NONE) via rowed 0x44DF71.
// Evidence: callers 0x2961CD/0x495065, callee rows/pins in packet, neighbour PhysicsBehaviorCtor layout.

#include <vector>

extern "C" float kF7C;

struct Holder610
{
	unsigned char m_pad[0x610];
	float m_610;
};

struct Mid274
{
	void *m_vptr;
	Holder610 *m_04;
};

class Object
{
public:
	void rva0028AE6D();
	void *m_vptr;
	Holder610 *m_04;
	unsigned char m_pad08[0x11C - 0x08];
	int m_11C;
	unsigned char m_pad120[0x274 - 0x120];
	Mid274 *m_274;
};

struct BfmeE16
{
	unsigned char m_pad[16];
};

struct Coord3D
{
	float x;
	float y;
	float z;
	void zero() { x = 0.0f; y = 0.0f; z = 0.0f; }
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class Thing;
class ModuleData
{
public:
	unsigned char m_pad[0x20];
	int m_20;
};

class BehaviorModuleBase
{
public:
	virtual void behaviorModuleBaseAnchor();
	const ModuleData *m_moduleData;
	Object *m_object;
};

class BehaviorModuleOther
{
public:
	virtual void behaviorModuleOtherAnchor();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};

class UpdateModuleInterface
{
public:
	virtual void update();
};

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();
protected:
	void setWakeFrame(Object *obj, UpdateSleepTime wakeDelay);
private:
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;
};

class PhysicsBehavior : public UpdateModule
{
public:
	PhysicsBehavior(Thing *thing, const ModuleData *moduleData);
	virtual ~PhysicsBehavior();
	void rva003906BF();
private:
	_STL::vector<BfmeE16> m_elements;
	Coord3D m_bfme2C;
	Coord3D m_bfme38;
	float m_bfme44;
	float m_bfme48;
	int m_bfme4C;
	int m_bfme50;
	int m_bfme54;
	int m_bfme58;
	bool m_bfme5C;
	unsigned char m_bfme5D;
	bool m_bfme5E;
	bool m_bfme5F;
	int m_bfme60;
	int m_bfme64;
};

// ?rva003906BF@PhysicsBehavior@@QAEXXZ present-unmatched
void PhysicsBehavior::rva003906BF()
{
	Object *obj = m_object;
	Holder610 *h1 = obj->m_04;
	Mid274 *mid = obj->m_274;
	float f1 = h1->m_610;
	if (f1 >= kF7C)
		return;
	if (mid)
	{
		if (mid->m_04->m_610 >= kF7C)
			return;
	}
	if ((obj->m_11C & 1) == 0)
	{
		obj->m_11C |= 1;
		obj->rva0028AE6D();
	}
	m_bfme5C = true;
	m_bfme58 = m_moduleData->m_20;
	setWakeFrame(obj, UPDATE_SLEEP_NONE);
}
