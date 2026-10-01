// ?Rva004F53C3Cb@@YAXPAX0@Z
// partial score=0.97 date=2026-10-01
// ?Rva004F53C3Cb@@YAXPAX0@Z
// partial score=0.97 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?Rva004F53C3Cb@@YAXPAX0@Z retail 0x004F53C3 115B
// Float healing callback via DamageInfo 0x7C: frame check with unsigned fild/fadd fixup, amount via body slot06 direct or divided by float threshold, body slot01 attemptHealing. Evidence: calls rowed 0x263895 ctor; TheGameLogic+0x40 minus obj+0x27C; three virtual calls at +0x18 +0x18 +0x04 with fcomi/jb and fdiv; LINK BONUS caller Rva004F553FEnum names YAXPAX0.
// Sibling of Rva00466C04Heal with float threshold.
class GameLogic
{
public:
	char m_pad[0x40];
	unsigned m_frame40;
};
extern GameLogic *TheGameLogic;

class Rva00263653
{
public:
	Rva00263653() throw();
	virtual void rva00263653_dummy();
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
	int m_18;
	float m_1C;
	unsigned char m_20;
	unsigned char m_21;
	unsigned char m_pad22[2];
	float m_24;
	int m_28;
	int m_2C;
	float m_30;
	float m_34;
	float m_38;
	float m_3C;
	float m_40;
	float m_44;
	float m_48;
	unsigned char m_4C;
	unsigned char m_pad4D[3];
	float m_50;
	float m_54;
	float m_58;
	float m_5C;
	float m_60;
	float m_64;
};

class Rva00263895Member
{
public:
	Rva00263895Member() throw();
	virtual void rva00263895_dummy();
	Rva00263653 m_mem;
	const void *m_ptr;
	float m_f70;
	float m_f74;
	unsigned char m_b78;
};

class BodyModuleInterface
{
public:
	virtual void slot00() throw();
	virtual void attemptHealing(Rva00263895Member *info) throw();
	virtual void slot02() throw();
	virtual void slot03() throw();
	virtual void slot04() throw();
	virtual void slot05() throw();
	virtual float slot06() throw();
};

class Object
{
public:
	char m_pad00[0x254];
	BodyModuleInterface *m_body254;
	char m_pad258[0x27C - 0x258];
	unsigned m_frame27C;
};

// ?Rva004F53C3Cb@@YAXPAX0@Z present-unmatched
void __cdecl Rva004F53C3Cb(void *data, void *user)
{
	Object *obj = (Object *)data;
	float const *val = (float const *)user;
	Rva00263895Member dmg;
	dmg.m_mem.m_0C = 7;
	dmg.m_mem.m_18 = 1;
	unsigned frameDiff = TheGameLogic->m_frame40 - obj->m_frame27C;
	BodyModuleInterface *body = obj->m_body254;
	float fdiff = (float)frameDiff;
	dmg.m_mem.m_1C = (fdiff >= *val) ? body->slot06() : body->slot06() / *val;
	body->attemptHealing(&dmg);
}
