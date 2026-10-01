// cl: /O1 /MD
//
// ?rva00483111@Rva00482E96@@QAEXH@Z, retail 0x00483111, 34 bytes.
// Slot 14 (offset 0x38) of vtable 0x008497B4 (class of ??1Rva00482E96).
// Calls rowed ?rva00483083@PoisonedBehavior@@QAEXXZ on the UpdateModule at
// this-0x20, then rowed ?setWakeFrame@UpdateModule@@IAEXPAVObject@@W4UpdateSleepTime@@@Z
// with the owner Object at this-0x18 and UPDATE_SLEEP_FOREVER. Chain lane:
// all callees rowed after 0x00483083 landed. Callers none; neighbours
// PoisonedBehavior xfer and RebuildHole getInterface.

class Thing;
class ModuleData;
class Object;
class DamageInfo;

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class Rva00482E96;

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
	friend class Rva00482E96;
private:
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;
};

class DamageModuleInterface
{
public:
	DamageModuleInterface() {}
	virtual void onDamage(DamageInfo *damageInfo);
};

class PoisonedBehavior : public UpdateModule, public DamageModuleInterface
{
public:
	void rva00483083();
};

class Rva00482E96
{
public:
	void rva00483111(int unused);
};

void Rva00482E96::rva00483111(int unused)
{
	PoisonedBehavior *pb = (PoisonedBehavior *)((char *)this - 0x20);
	pb->rva00483083();
	Object *obj = *(Object **)((char *)this - 0x18);
	pb->setWakeFrame(obj, UPDATE_SLEEP_FOREVER);
}
