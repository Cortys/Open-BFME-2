// ?rva00390629@PhysicsBehavior@@QAEX_N@Z
// partial score=0.87 date=2026-10-01
// cl: /O1 /arch:SSE /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ?rva00390629@PhysicsBehavior@@QAEX_N@Z @0x00390629 150B neighbors 0x3901C9/0x3907A6 Object+0x274 containedBy Object+4 template+0x610 kF7C pin rva0028AE6D
#include <vector>

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
class ModuleData;

extern "C" float kF7C;

class ObjectTemplate
{
public:
	unsigned char m_pad610[0x610];
	float m_610;
};

class Object
{
public:
	void rva0028AE6D();
	void *m_vptr;
	ObjectTemplate *m_template;
	unsigned char m_pad08[0x11B - 0x08];
	volatile unsigned char m_11b;
	union
	{
		volatile unsigned int m_11c;
		volatile unsigned char m_11c_byte;
	};
	union
	{
		volatile unsigned int m_120;
		volatile unsigned char m_120_byte;
	};
	unsigned char m_pad124[0x274 - 0x124];
	Object *m_containedBy;
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

class PhysicsBehaviorModuleData
{
public:
	unsigned char m_pad[0x58];
	unsigned char m_bfme58;
};

class PhysicsBehavior : public UpdateModule
{
public:
	PhysicsBehavior(Thing *thing, const ModuleData *moduleData);
	virtual ~PhysicsBehavior();
	void rva00390629(bool arg);
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

// ?rva00390629@PhysicsBehavior@@QAEX_N@Z present-unmatched
void PhysicsBehavior::rva00390629(bool arg)
{
	Object *obj = m_object;
	float f1 = obj->m_template->m_610;
	Object *container = obj->m_containedBy;
	bool v;
	if (f1 >= kF7C)
		v = false;
	else if (container == 0)
		v = arg;
	else
	{
		float f2 = container->m_template->m_610;
		if (f2 >= kF7C)
			v = false;
		else
			v = arg;
	}
	m_bfme5C = v;
	if (!v)
	{
		if (obj->m_120_byte & 8)
		{
			obj->m_120 &= ~8u;
			obj->rva0028AE6D();
		}
		if (obj->m_11b & 0x80)
		{
			obj->m_11b &= ~0x80;
			obj->rva0028AE6D();
		}
		if (obj->m_11c_byte & 1)
		{
			obj->m_11c &= ~1u;
			obj->rva0028AE6D();
		}
		m_bfme58 &= 0;
	}
}
