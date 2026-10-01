// ?rva00390CCA@PhysicsBehavior@@QAEX_N@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /arch:SSE /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva00390CCA@PhysicsBehavior@@QAEX_N@Z @0x00390CCA 134B. Identity: PhysicsBehavior method beside ctor 0x3907A6; clears vector at +0x20, zeroes +0x50/+0x54, checks +0x5F and moduleData+0x59, setWakeFrame FOREVER via 0x44DF71 or kill via Object::kill, weapon cleanup via WeaponStore 0x2CE964 and TheWeaponStore.
// Evidence: callers 0x390E61/0x390FAF; callees rowed/pinned in packet; neighbours 0x3908A1/0x3913E4; same layout/flags as PhysicsBehaviorCtor.
#include <vector>

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Gen_p12pod
{
	int a[3];
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

enum DamageType
{
	DAMAGE_FALLING = 8
};

enum DeathType
{
	DEATH_NORMAL = 0
};

class Thing;
class WeaponTemplate;

class ModuleData
{
public:
	unsigned char m_pad[0x59];
	unsigned char m_59;
};

class Object
{
public:
	void rva0028AE6D();
	void kill(DamageType damage, DeathType death);
	unsigned char m_pad[0x118];
	volatile unsigned int m_118;
};

class WeaponStore
{
public:
	void rva002CE964(const WeaponTemplate *wt, const Object *source, const Object *victim);
};

extern WeaponStore *TheWeaponStore;

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
	void rva00390CCA(bool arg);
private:
	_STL::vector<Gen_p12pod> m_elements;
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
	const Object *m_bfme60;
	const WeaponTemplate *m_bfme64;
};

// ?rva00390CCA@PhysicsBehavior@@QAEX_N@Z present-unmatched
void PhysicsBehavior::rva00390CCA(bool arg)
{
	Object *obj = m_object;
	m_elements.clear();
	m_bfme50 = 0;
	m_bfme54 = 0;
	if (m_bfme5F || m_moduleData->m_59 != 0)
	{
		if ((obj->m_118 & 0x4000000) == 0)
		{
			_ReadWriteBarrier();
			obj->m_118 |= 0x4000000;
			obj->rva0028AE6D();
		}
		obj->kill(DAMAGE_FALLING, DEATH_NORMAL);
	}
	else if (!arg)
	{
		setWakeFrame(obj, UPDATE_SLEEP_FOREVER);
	}
	if (m_bfme64 != 0)
	{
		TheWeaponStore->rva002CE964(m_bfme64, m_bfme60, obj);
		m_bfme64 = 0;
	}
	m_bfme60 = 0;
}
