// ?rva00481A9E@Rva0048180C@@QAEXPAVObject@@_NPAURva00481A9EInfo@@@Z
// partial score=0.97 date=2026-10-01
// cl: /O1 /G7 /DNDEBUG /MD /arch:SSE
//
// ?rva00481A9E@Rva0048180C@@QAEXPAVObject@@_NPAURva00481A9EInfo@@@Z @0x00481A9E (225B).
// Chain from 0x0028FEA7 you landed: healing-benefactor forward plus body
// DamageInfo forward plus effectively-dead handling via vtable slot 15 of
// 0x00849248 (class of ??1Rva0048180C). Evidence: rowed getControllingPlayer
// 0x0028AFA9 plus rowed Player::rva002AB87D 0x002AB87D over +0x2c template
// plus rowed Rva0028ADECmpBoolField::get plus Object body at +0x254 slot 6
// plus g_Va00DBA4E4 int plus rva0028FEA7 row; neighbours 0x00481A54 and
// BitFlags 0x00481B7F share /O1.

typedef unsigned int UnsignedInt;

class Object;
class UpgradeTemplate;

class Player
{
public:
	bool rva002AB87D(const UpgradeTemplate *tmpl) const;
};

class UpgradeTemplate
{
public:
	char m_pad00[0x38];
	int m_bitIndex;
};

class Rva0028ADECmpBoolField
{
public:
	bool get() const;
};

class BodyModule
{
public:
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5();
	virtual float f6();
};

class Object
{
public:
	Player *getControllingPlayer() const;
	bool rva0028FEA7(float amount, const Object *source, UnsignedInt extra);
	bool testWeaponBonusCondition(int condition) const
	{
		return (m_flags380 & (1 << condition)) != 0;
	}
	void setWeaponBonusCondition(int condition)
	{
		m_flags380 |= (1 << condition);
	}

	char m_pad00[0x254];
	BodyModule *m_body; // +0x254
	char m_pad258[0x380 - 0x258];
	UnsignedInt m_flags380; // +0x380
	char m_pad384[0x100];
};

struct Rva00481A9EInfo
{
	char m_pad00[0x0c];
	UnsignedInt m_extra; // +0x0c
	float m_f10; // +0x10
	char m_pad14[0x08];
	float m_f1c; // +0x1c
};

extern int g_Va00DBA4E4; // ?g_Va00DBA4E4@@3HA

class Rva0048180C
{
public:
	void rva00481A9E(Object *tgt, bool flag, Rva00481A9EInfo *info);

private:
	char m_pad00[0x08];
	Object *m_owner; // +0x08
	char m_pad0C[0x2c - 0x0c];
	const UpgradeTemplate *m_tmpl; // +0x2c
};

// ?rva00481A9E@Rva0048180C@@QAEXPAVObject@@_NPAURva00481A9EInfo@@@Z present-unmatched
void Rva0048180C::rva00481A9E(Object *tgt, bool flag, Rva00481A9EInfo *info)
{
	if (m_owner == 0)
		return;
	Player *pl = m_owner->getControllingPlayer();
	if (pl == 0)
		return;
	bool hasUpgrade;
	if (m_tmpl != 0)
		hasUpgrade = pl->rva002AB87D(m_tmpl);
	else
		hasUpgrade = false;
	if (flag) {
		if (((Rva0028ADECmpBoolField *)tgt)->get() == true) {
			if (tgt->testWeaponBonusCondition(8) == false)
				tgt->setWeaponBonusCondition(8);
			if (hasUpgrade) {
				if (tgt->testWeaponBonusCondition(15) == false)
					tgt->setWeaponBonusCondition(15);
			}
		}
		BodyModule *body = tgt->m_body;
		if (body == 0)
			return;
		float fsel;
		if (hasUpgrade)
			fsel = info->m_f1c;
		else
			fsel = info->m_f10;
		float mult = body->f6();
		tgt->rva0028FEA7((fsel / (float)g_Va00DBA4E4) * mult, m_owner, info->m_extra);
	} else {
		((unsigned char *)&tgt->m_flags380)[1] &= 0x7e;
	}
}
