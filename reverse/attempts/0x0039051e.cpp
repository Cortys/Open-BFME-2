// ?rva0039051E@PhysicsBehavior@@QAEHXZ
// partial score=0.91 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva0039051E@PhysicsBehavior@@QAEHXZ @0x0039051E 21B. Identity: PhysicsBehavior nonempty via 12B vector at +0x20; returns 1 when size nonzero else 0.
// Evidence: caller 0x45DD60; neighbours 0x3901C9/0x390601; same +0x20 layout as PhysicsBehaviorRva00390601.
#include <vector>

struct Gen_p12pod
{
	int a[3];
};

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Thing;
class ModuleData;
class Object;

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
	int rva0039051E();
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
	int m_bfme60;
	int m_bfme64;
};

// ?rva0039051E@PhysicsBehavior@@QAEHXZ present-unmatched
int PhysicsBehavior::rva0039051E()
{
	int count = m_elements.size();
	return count != 0;
}
