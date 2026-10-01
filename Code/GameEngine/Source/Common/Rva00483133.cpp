// cl: /O1 /MD /arch:SSE
//
// ?rva00483133@Rva00482E96@@QAE?AW4UpdateSleepTime@@XZ, retail 0x00483133, 152 bytes.
// Slot 16 (offset 0x40) of vtable 0x008497B4 (class of ??1Rva00482E96).
// Calls rowed ?rva00483083@PoisonedBehavior@@QAEXXZ and rowed
// ?calcSleepTime@PoisonedBehavior@@IAE?AW4UpdateSleepTime@@XZ on the
// PoisonedBehavior at this-0x10, rowed ??0Rva00263895Member@@QAE@XZ for the
// DamageInfo at ebp-0x7c and pinned ?attemptDamage@Object@@QAEXPAVDamageInfo@@@Z
// with the owner Object at this-0x08. Chain lane: all callees rowed after
// 0x00483083 landed. Neighbours Rva00483111 and RebuildHole getInterface.

class Thing;
class ModuleData;
class Object;
class DamageInfo;

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class Rva00263895Member
{
public:
	Rva00263895Member();
	unsigned m_a;
	unsigned m_b;
};

class DamageInfo
{
public:
	Rva00263895Member m_head;
	unsigned m_08;
	unsigned m_0C;
	unsigned m_10;
	unsigned m_14;
	unsigned m_18;
	unsigned m_1C;
	float m_20;
	unsigned char m_pad[0x7c - 0x24];
};

class Object
{
public:
	void attemptDamage(DamageInfo *damageInfo);
	unsigned char m_pad[0x438];
	unsigned char m_flag;
};

class GameLogic
{
public:
	unsigned getFrame() { return m_frame; }
private:
	unsigned char m_pad[0x40];
	unsigned m_frame;
};

extern GameLogic *TheGameLogic;

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

class DamageModuleInterface
{
public:
	DamageModuleInterface() {}
	virtual void onDamage(DamageInfo *damageInfo);
};

class Rva00482E96;

class PoisonedBehavior : public UpdateModule, public DamageModuleInterface
{
public:
	void rva00483083();
protected:
	UpdateSleepTime calcSleepTime();
	friend class Rva00482E96;
private:
	unsigned int m_poisonDamageFrame;
	unsigned int m_poisonOverallStopFrame;
	float m_poisonDamageAmount;
	int m_deathType;
};

class PoisonedModuleData
{
public:
	unsigned char m_pad[8];
	unsigned m_interval;
};

class Rva00482E96
{
public:
	UpdateSleepTime rva00483133();
private:
	unsigned char m_pad[0x14];
	unsigned m_damageFrame;
	unsigned m_overallStop;
	float m_damageAmount;
	int m_deathType;
};

UpdateSleepTime Rva00482E96::rva00483133()
{
	unsigned frame = TheGameLogic->getFrame();
	const ModuleData *md = ((PoisonedBehavior *)((char *)this - 0x10))->m_moduleData;
	if (m_overallStop == 0)
		return UPDATE_SLEEP_FOREVER;
	if (m_damageFrame != 0 && frame >= m_damageFrame) {
		DamageInfo damageInfo;
		Object *obj = ((PoisonedBehavior *)((char *)this - 0x10))->m_object;
		damageInfo.m_08 = 0;
		damageInfo.m_1C = (unsigned)m_deathType;
		damageInfo.m_20 = m_damageAmount;
		damageInfo.m_10 = 8;
		damageInfo.m_14 = 0x1b;
		obj->attemptDamage(&damageInfo);
		m_damageFrame = ((PoisonedModuleData *)md)->m_interval + frame;
	}
	if (m_overallStop != 0 && frame >= m_overallStop) {
		Object *owner = ((PoisonedBehavior *)((char *)this - 0x10))->m_object;
		if (!(owner->m_flag & 1))
			((PoisonedBehavior *)((char *)this - 0x10))->rva00483083();
	}
	return ((PoisonedBehavior *)((char *)this - 0x10))->calcSleepTime();
}
