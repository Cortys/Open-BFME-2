// ?rva002943B2@Object@@QAE_NPBVPlayer@@@Z
// partial score=0.96 date=2026-10-01
// ?rva002943B2@Object@@QAE_NPBVPlayer@@@Z
// partial score=0.96 date=2026-10-01
// cl: /O1 /G7
// ?rva002931F5@Object@@QAEPAV1@_N@Z, retail 0x002931F5, 84 bytes.
// Object helper: if own template dword +0x114 carries 0x2000 return this;
// else if containedBy (+0x274) template carries it return containedBy;
// else if bool arg set look up producerID (+0x78) via TheGameLogic
// findObjectByID (rowed 0x00049DC5) and return producer if its template
// carries it, else null. Evidence: Object offsets template +0x04
// (Object_isAbleToAttack/ObjectScriptStatus), producer +0x78
// (ObjectSetProducer), containedBy +0x274 (Object_isAbleToAttack),
// TheGameLogic at 0x00DFE78C; callers 0x002933CD (chain + testStatus
// 0x5F/0x60) and 0x00293926 (isKindOf gate) prove Object owner.

typedef bool Bool;

enum ObjectID
{
	INVALID_ID = 0
};

enum KindOfType
{
	KINDOF_DUMMY = 0
};

enum ObjectStatusTypes
{
	STATUS_5F = 0x5F,
	STATUS_60 = 0x60
};

struct ThingTemplate
{
	unsigned char m_pad[0x114];
	unsigned int m_flags114;
};

class Object;

class GameLogic
{
public:
	class Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

class Object
{
public:
	Object *rva002931F5(Bool checkProducer);
	Bool rva00293926(KindOfType kind);
	int rva002933CD();
	void *rva0029439D();
	Bool isKindOf(KindOfType kind) const;
	Bool testStatus(ObjectStatusTypes bit) const;
	void *rva0028C197() const;
	bool rva0028F518();
	bool rva0028C1CC() const;
	class Rva00373EC6 *rva0028F4BC();
	bool rva002943B2(const class Player *other);

private:
	unsigned char m_pad00[4];
	ThingTemplate *m_template;
	unsigned char m_pad08[0x78 - 0x08];
	ObjectID m_producerID;
	unsigned char m_pad7C[0x274 - 0x7C];
	Object *m_containedBy;
};

Object *Object::rva002931F5(Bool checkProducer)
{
	if ((m_template->m_flags114 & 0x2000) != 0)
		return this;
	Object *contained = m_containedBy;
	if (contained != 0 && (contained->m_template->m_flags114 & 0x2000) != 0)
		return contained;
	if (checkProducer)
	{
		Object *producer = TheGameLogic->findObjectByID(m_producerID);
		if (producer != 0 && (producer->m_template->m_flags114 & 0x2000) != 0)
			return producer;
	}
	return 0;
}

Bool Object::rva00293926(KindOfType kind)
{
	if (isKindOf(kind))
		return true;
	Object *related = rva002931F5(false);
	if (related != 0)
		return related->isKindOf(kind);
	return false;
}

int Object::rva002933CD()
{
	Object *cur = this;
	for (;;)
	{
		Object *next = cur->rva002931F5(false);
		if (next == 0)
			break;
		if (next == cur)
			break;
		cur = next;
	}
	if (cur->testStatus(STATUS_60) || cur->testStatus(STATUS_5F))
		return 1;
	return 0;
}

// ?rva0029439D@Object@@QAEPAXXZ, retail 0x0029439D, 21 bytes.
// Object helper: related via rva002931F5(false); if non-null tail to
// rva0028C197 else null. Evidence: thiscall with no args proven by callers
// 0x002946AB (mov esi ecx then call) and 0x002957FC (mov ecx esi then call);
// callees rowed 0x002931F5 and 0x0028C197; sits after 0x00293926 in this TU.
void *Object::rva0029439D()
{
	Object *related = rva002931F5(false);
	if (related != 0)
		return related->rva0028C197();
	return 0;
}

// ?rva002943B2@Object@@QAE_NPBVPlayer@@@Z @ 0x002943B2 191B: chain from
// 0x0028F518 landed this session; array via rowed get 0x002B224B with virtual
// +0xF0 gate, then rva002933CD, testStatus 0x11, (rva0028F518 or testStatus
// 0x0F), optional Player+0x5C/rva0028C1CC gate, template+0x113 bit, then
// rva0028F4BC/ThePlayerList/getNthPlayer/getRelationship chain. Callers
// 0x0004E70D 0x002690AF 0x00294FB6 prove Object owner. Same /O1 /G7.
class Rva002B224BDwordField
{
public:
	int get() const;
};

class RvaNode002943B2
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual bool v60();
};

enum Relationship
{
	REL_NONE = 0
};

class Player
{
public:
	Relationship getRelationship(const Player *other) const;
};

class PlayerList
{
public:
	Player *getNthPlayer(int index);
};

extern PlayerList *ThePlayerList;

class Rva00373EC6
{
public:
	unsigned char m_pad[0x38];
	int m_38;
	int m_3C;
};

// ?rva002943B2@Object@@QAE_NPBVPlayer@@@Z present-unmatched
bool Object::rva002943B2(const Player *other)
{
	const Rva002B224BDwordField *field = *(const Rva002B224BDwordField *const *)((const char *)this + 0x84);
	if (field != 0)
	{
		RvaNode002943B2 **arr = (RvaNode002943B2 **)field->get();
		for (; *arr != 0; ++arr)
		{
			RvaNode002943B2 *e = *arr;
			if (!e->v60())
				return false;
		}
	}
	if ((unsigned char)rva002933CD())
		return false;
	if (testStatus((ObjectStatusTypes)0x11))
		return false;
	if (!rva0028F518())
	{
		if (!testStatus((ObjectStatusTypes)0x0F))
			return false;
	}
	if (other != 0)
	{
		if (*(const int *)((const char *)other + 0x5C) == 1)
		{
			if (rva0028C1CC())
				return false;
		}
	}
	if ((m_template->m_pad[0x113] & 1) == 0)
		return true;
	Rva00373EC6 *r = rva0028F4BC();
	if (r == 0)
		return true;
	if (r->m_3C == 0)
		return true;
	Player *p = ThePlayerList->getNthPlayer(r->m_38);
	if (p == 0)
		return true;
	if (p->getRelationship(other) != REL_NONE)
		return true;
	return false;
}
