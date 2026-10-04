// ?Rva003E96F5Check@@YG_NPAVParameter@@0@Z
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /arch:SSE2 /O1
// ?Rva003E96F5Check@@YG_NPAVParameter@@0@Z @0x003E96F5 137B
// ScriptConditions-adjacent free predicate: the unit named by the first
// Parameter must expose a slot-15 object whose +8 ObjectID resolves via
// TheGameLogic, and the second Parameter's player mask (via ScriptEngine
// rva00357B82) must contain the target's controlling player (via ThePlayerList
// getEachPlayerFromMask). Evidence: rowed getUnitNamed 0x003588E7 plus
// findObjectByID 0x00049DC5 plus rva00357B82 plus getEachPlayerFromMask
// 0x002A7BC9 plus getControllingPlayer 0x0028AFA9; globals g_Va009FE16C plus
// TheGameLogic plus ThePlayerList; single caller at 0x003EB00E; neighbours
// share flags per packet prev/next.

class Parameter;
class Object;
class Player;

enum ObjectID
{
	INVALID_ID = 0
};

struct Rva003E96F5Inner
{
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void *s15();
};

class Object
{
public:
	Player *getControllingPlayer() const;
	char m_pad[0x254];
	Rva003E96F5Inner *m_inner254;
};

class ScriptEngine
{
public:
	Object *getUnitNamed(Parameter *p);
	int rva00357B82(Parameter *p);
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

class PlayerList
{
public:
	Player *getEachPlayerFromMask(int &mask);
};

extern ScriptEngine *g_Va009FE16C;
extern GameLogic *TheGameLogic;
extern PlayerList *ThePlayerList;

// ?Rva003E96F5Check@@YG_NPAVParameter@@0@Z present-unmatched
bool __stdcall Rva003E96F5Check(Parameter *a, Parameter *b)
{
	Object *unit = g_Va009FE16C->getUnitNamed(a);
	if (!unit)
		return false;
	Rva003E96F5Inner *inner = unit->m_inner254;
	if (inner == 0)
		return false;
	void *res = inner->s15();
	if (res == 0)
		return false;
	Object *target = TheGameLogic->findObjectByID(*(ObjectID *)((char *)res + 8));
	if (target == 0)
		return false;
	int mask = g_Va009FE16C->rva00357B82(b);
	if (mask == 0)
		return false;
	Player *p = 0;
	for (;;)
	{
		p = ThePlayerList->getEachPlayerFromMask(mask);
		if (target->getControllingPlayer() == p)
			return true;
		if (mask != 0)
			continue;
		return false;
	}
}
