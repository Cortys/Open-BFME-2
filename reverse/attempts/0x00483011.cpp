// ?rva00483011@PoisonedBehavior@@QAEXPAVDamageInfo@@@Z
// partial score=0.93 date=2026-10-04
// ?rva00483011@PoisonedBehavior@@QAEXPAVDamageInfo@@@Z
// partial score=0.93 date=2026-10-04
// ?rva00483011@PoisonedBehavior@@QAEXPAVDamageInfo@@@Z
// partial score=0.93 date=2026-10-01
// ?rva00483011@PoisonedBehavior@@QAEXPAVDamageInfo@@@Z
// partial score=0.91 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /GX
//
// ?rva00483011@PoisonedBehavior@@QAEXPAVDamageInfo@@@Z, retail 0x00483011, 114 bytes.
// PoisonedBehavior damage handler: copies damage amount float at +0x2C from
// DamageInfo +0x70, sets overall stop frame at +0x28 to module duration +0xC
// plus current GameLogic frame at +0x40, folds damage frame at +0x24 to the
// earliest nonzero of itself and module interval +0x8 plus frame, copies death
// type at +0x30 from DamageInfo +0x1C, then sets bit 4 directly via an OR at
// +0x118 on the rowed ?getDesiredGatherers@BuildListInfo@@QAEHXZ result when
// nonzero (retail shows no call there, so a raw OR through the int result
// rather than the Rva00270619Clear call the clearing sibling uses), and
// Layout is the rowed PoisonedBehavior class from PoisonedBehaviorCtor.cpp
// (UpdateModule base 0x20 plus DamageModuleInterface at +0x20) and the rowed
// PoisonedBehaviorModuleData fields (+0x8 interval, +0xC duration). Caller at
// 0x00483109; neighbours PoisonedBehavior deleting dtor and rva00483083.

typedef unsigned int UnsignedInt;

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class Thing;
class ModuleData;
class Object;
class DamageInfo;

class BuildListInfo
{
public:
	int getDesiredGatherers();
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

class GameLogic
{
public:
	UnsignedInt getFrame() { return m_frame; }

private:
	unsigned char m_pad[0x40];
	UnsignedInt m_frame; // +0x40 (retail; reference header says +0x3C)
};

extern GameLogic *TheGameLogic;

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();
protected:
	void setWakeFrame(Object *obj, UpdateSleepTime frame);
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

class PoisonedBehaviorModuleData
{
public:
	void *m_vtable; // +0 (explicit; no virtuals declared, so no vtable is emitted)
	int m_unused04; // +4
	int m_poisonDamageInterval; // +8
	int m_poisonDuration; // +0xC
};

class DamageInfo
{
public:
	unsigned char m_pad[0x1C]; // +0
	int m_001C; // +0x1C death type
	unsigned char m_pad2[0x70 - 0x1C - 4]; // to +0x70
	float m_0070; // +0x70 damage amount
};

class PoisonedBehavior : public UpdateModule, public DamageModuleInterface
{
public:
	void rva00483011(DamageInfo *damageInfo);
protected:
	UpdateSleepTime calcSleepTime();
private:
	volatile unsigned int m_poisonDamageFrame; // +0x24
	volatile unsigned int m_poisonOverallStopFrame; // +0x28
	float m_poisonDamageAmount; // +0x2C
	int m_deathType; // +0x30
};

// ?rva00483011@PoisonedBehavior@@QAEXPAVDamageInfo@@@Z present-unmatched
void PoisonedBehavior::rva00483011(DamageInfo *damageInfo)
{
	PoisonedBehaviorModuleData *data = (PoisonedBehaviorModuleData *)m_moduleData;
	GameLogic *gl = TheGameLogic;
	UnsignedInt now = gl->getFrame();
	m_poisonDamageAmount = damageInfo->m_0070;
	m_poisonOverallStopFrame = (UnsignedInt)data->m_poisonDuration + now;
	UnsignedInt newDamageFrame = (UnsignedInt)data->m_poisonDamageInterval + now;
	if (m_poisonDamageFrame == 0)
		m_poisonDamageFrame = newDamageFrame;
	else
	{
		UnsignedInt *pFrame = m_poisonDamageFrame < newDamageFrame ? (UnsignedInt *)&m_poisonDamageFrame : &newDamageFrame;
		m_poisonDamageFrame = *pFrame;
	}
	m_deathType = damageInfo->m_001C;
	int v = ((BuildListInfo *)m_object)->getDesiredGatherers();
	if (v)
		*(int *)(v + 0x118) |= 4;
	Object *obj = m_object;
	UpdateSleepTime sleep = calcSleepTime();
	setWakeFrame(obj, sleep);
}
