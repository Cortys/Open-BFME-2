// ?rva005445FF@Rva005445FF@@QAEXXZ
// partial score=0.93 date=2026-09-29
// ?rva005445FF@Rva005445FF@@QAEXXZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD
// ?rva005445FF@Rva005445FF@@QAEXXZ @0x005445FF (71B): turret target accumulator
// that resolves via +0x18/+0x14/+0x258 virtual +0x17C then combines via
// TurretStateMachine goal plus GameLogic +0x40 into +0x20. Evidence: callers
// 0x00544667 0x00544BCC; rowed getGoalObject 0x004D7726 plus GameLogic
// 0x009FE78C plus virtuals +0x17C +0x4C from retail bytes.
class Object;

class Slot4CObj
{
public:
	virtual void t00(); virtual void t01(); virtual void t02(); virtual void t03();
	virtual void t04(); virtual void t05(); virtual void t06(); virtual void t07();
	virtual void t08(); virtual void t09(); virtual void t10(); virtual void t11();
	virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
	virtual void t16(); virtual void t17(); virtual void t18();
	virtual int slot4C(Object *o);
};

class Slot17CObj
{
public:
	virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
	virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
	virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
	virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
	virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
	virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
	virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
	virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
	virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
	virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
	virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63();
	virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67();
	virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
	virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
	virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
	virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83();
	virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87();
	virtual void s88(); virtual void s89(); virtual void s90(); virtual void s91();
	virtual void s92(); virtual void s93(); virtual void s94();
	virtual Slot4CObj *slot17C();
};

struct Mid14
{
	char m_pad[0x258];
	Slot17CObj *m_258;
};

class TurretStateMachine
{
public:
	Object *getGoalObject();

private:
	char m_pad[0x14];

public:
	Mid14 *m_14;
};

class GameLogic
{
public:
	char m_pad[0x40];
	unsigned int m_frame;
};

extern GameLogic *TheGameLogic;

class Rva005445FF
{
public:
	void rva005445FF();

private:
	char m_pad[0x18];
	TurretStateMachine *m_18;
	int m_1C;
	int m_20;
};

// ?rva005445FF@Rva005445FF@@QAEXXZ present-unmatched
void Rva005445FF::rva005445FF()
{
	Slot17CObj *objA = m_18->m_14->m_258;
	Slot4CObj *v0 = objA->slot17C();
	GameLogic *g = TheGameLogic;
	int result;
	if (v0 != 0) {
		int base = (int)g->m_frame;
		Object *goal = m_18->getGoalObject();
		int r = v0->slot4C(goal);
		result = r + base;
	} else {
		result = (int)g->m_frame;
	}
	m_20 = result;
}
