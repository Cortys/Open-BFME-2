// ?rva0048491F@PassiveAreaEffectBehavior@@UAEXPAVObject@@@Z
// partial score=0.97 date=2026-10-01
// cl: /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
//
// ?rva0048491F@PassiveAreaEffectBehavior@@UAEXPAVObject@@@Z, retail 0x0048491F, 233 bytes.
// Slot 15 (offset 0x3C) of vtable 0x0084A448 (class of ??0PassiveAreaEffectBehavior ctor
// 0x00484A67 in PassiveAreaEffectBehaviorCtor.cpp). Heals one candidate object: skips null,
// skips recent-damage via rowed Object 0x0028C264, skips zero heal rate via BfmeZeroRange,
// skips null body at Object+0x254, skips full health (getHealth == getMaxHealth via body
// slots 0x10/0x18, max at 0x18 per ObjectKill precedent), honors nonStackable at ModuleData
// +0x28 via body timestamp slot 0x44 plus pingDelay at +0x10 vs TheGameLogic frame +0x40,
// heals via rowed Object 0x0028FEA7 amount = max*heal/LogicFrames(0xDBA4E4=5)*pingDelay,
// then FX via rowed FXList 0x000B2235 with healFX at +0x34. Donor BFME1
// PassiveAreaEffectBehavior_rva00201fd0.cpp proves +0x04 moduleData +0x08 object and heal
// flow; BFME2 adds full-health skip plus nonStackable window plus ping-scaled amount.

extern const float BfmeZeroRange;
extern int g_Va00DBA4E4;
extern float g_00BC26EC;

class Object;
class FXList
{
public:
	static void doFXObj(const FXList *fx, const Object *primary, const Object *secondary);
};

class BodyModuleInterface
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual float getHealth() const;
	virtual void s05();
	virtual float getMaxHealth() const;
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual void s16();
	virtual unsigned getLastTimestamp() const;
};

class Object
{
public:
	bool rva0028C264(int *out, int n);
	bool rva0028FEA7(float amount, const Object *source, unsigned int extra);

public:
	char m_pad00[0x254];
	BodyModuleInterface *m_body;
};

class GameLogic
{
public:
	char m_pad00[0x40];
	unsigned m_frame;
};
extern GameLogic *TheGameLogic;

class PassiveAreaEffectBehaviorModuleData
{
public:
	char m_pad00[0x0C];
	float m_healPercentPerSecond;
	unsigned m_pingDelay;
	char m_pad14[0x28 - 0x14];
	bool m_nonStackable;
	char m_pad29[3];
	int m_antiCategories;
	int m_antiFX;
	const FXList *m_healFX;
};

class PassiveAreaEffectBehavior
{
public:
	virtual void rva0048491F(Object *object);

	const PassiveAreaEffectBehaviorModuleData *m_moduleData;
	Object *m_object;
};

// ?rva0048491F@PassiveAreaEffectBehavior@@UAEXPAVObject@@@Z present-unmatched
void PassiveAreaEffectBehavior::rva0048491F(Object *object)
{
	if (object == 0)
		return;
	int tmp;
	if (object->rva0028C264(&tmp, 4))
		return;
	const PassiveAreaEffectBehaviorModuleData *data = m_moduleData;
	if (!(data->m_healPercentPerSecond > BfmeZeroRange))
		return;
	BodyModuleInterface *body = object->m_body;
	if (body == 0)
		return;
	if (body->getHealth() == body->getMaxHealth())
		return;
	if (data->m_nonStackable)
	{
		unsigned frame = TheGameLogic->m_frame;
		unsigned stamp = body->getLastTimestamp();
		if (stamp + data->m_pingDelay > frame)
			return;
	}
	float heal = data->m_healPercentPerSecond;
	float amount = heal / (float)g_Va00DBA4E4 * body->getMaxHealth();
	unsigned delay = data->m_pingDelay;
	if (delay != 0)
		amount *= (float)delay;
	object->rva0028FEA7(amount, m_object, delay);
	const FXList *fx = data->m_healFX;
	if (fx != 0)
		FXList::doFXObj(fx, object, 0);
}
