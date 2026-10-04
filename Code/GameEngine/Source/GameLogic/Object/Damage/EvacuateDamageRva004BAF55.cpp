// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /arch:SSE /D_STLP_USE_STATIC_LIB
// stlport
//
// ?onDamage@EvacuateDamage@@UAEXPAUDamageInfo@@@Z @ 0x004BAF55 144B
// EvacuateDamage onDamage with evacuation record and threshold. Evidence:
// BFME1 donor EvacuateDamage_onDamage.cpp (same shape, DamageInfo +0x08
// source +0x10 type +0x20 amount, moduleData +0x0C type +0x10 scale,
// list at +0x14, TheGameLogic frame +0x40, BodyModule getHealth slot 0x18,
// rowed list<BfmeSpecialPowerTimer8>::push_back 0x004DE74D, rowed sum
// 0x004BADC1, rowed findObjectByID 0x00049DC5, rowed rva004BAF2D 0x004BAF2D);
// 8B record is list<BfmeSpecialPowerTimer8>, amount bitcast to m_templateID
// per Rva004E5344 precedent; sole caller 0x004BB0AF in 0x004BAFE5;
#define _STLP_NO_EXCEPTIONS 1
#include <list>

enum ObjectID
{
	OBJECTID_NONE = 0
};

struct DamageInfo
{
	unsigned char m_pad00[0x08];
	ObjectID m_sourceObject;
	unsigned char m_pad0C[0x04];
	int m_damageType;
	unsigned char m_pad14[0x0C];
	float m_amount;
};

class BodyModule
{
public:
	virtual void s0() = 0;
	virtual void s1() = 0;
	virtual void s2() = 0;
	virtual void s3() = 0;
	virtual void s4() = 0;
	virtual void s5() = 0;
	virtual float getHealth() = 0;
};

class Object
{
public:
	unsigned char m_pad[0x254];
	BodyModule *m_body;
};

class EvacuateDamageModuleData
{
public:
	unsigned char m_pad[0x0C];
	int m_damageType;
	float m_evacuationScale;
};

class GameLogic
{
public:
	unsigned char m_pad[0x40];
	int m_frame;
	Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

struct BfmeSpecialPowerTimer8
{
	unsigned int m_templateID;
	unsigned int m_readyFrame;
};

class EvacuateDamage
{
public:
	virtual void onDamage(DamageInfo *damageInfo);
	void rva004BAF2D(void *obj);
	float rva004BADC1();
private:
	EvacuateDamageModuleData *m_moduleData;
	Object *m_object;
	unsigned char m_pad0C[8];
	_STL::list<BfmeSpecialPowerTimer8> m_pendingEvacuations;
};

void EvacuateDamage::onDamage(DamageInfo *damageInfo)
{
	if (damageInfo == 0)
		return;
	int damageType = damageInfo->m_damageType;
	EvacuateDamageModuleData *moduleData = m_moduleData;
	if (moduleData->m_damageType != damageType)
		return;
	if (m_object->m_body == 0)
		return;
	BfmeSpecialPowerTimer8 record;
	*(float *)&record.m_templateID = damageInfo->m_amount;
	record.m_readyFrame = TheGameLogic->m_frame;
	m_pendingEvacuations.push_back(record);
	float health = m_object->m_body->getHealth();
	if (rva004BADC1() >= health * moduleData->m_evacuationScale)
	{
		Object *source = TheGameLogic->findObjectByID(damageInfo->m_sourceObject);
		if (source != 0)
			rva004BAF2D(source);
	}
}
