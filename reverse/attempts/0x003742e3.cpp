// ?rva003742E3@Rva003742E3@@QAEHPAX0@Z
// partial score=0.92 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
//
// ?rva003742E3@Rva003742E3@@QAEHPAX0@Z @0x003742E3 166B.
// Honest address-named __thiscall method returning int with two pointer args
// (ret 8). Reads ecx (this) via [ebp-4]: this+4 is InnerState* with bytes at
// +0x30/+0x56, this+0x3c int gate. Arg1 (edi) is Object-like: byte at +0x438
// bit0 gate, Team* at +0x304, Object::testStatus bits 0xF/0x11. Arg2 (esi) has
// Team* at +0x2ec for Team::getRelationship and BfmeMemberRV::bfmeAskRV.
// Callees are rowed: Object::testStatus 0x0004E536, Team::getRelationship
// 0x003A0FD2, BfmeMemberRV::bfmeAskRV 0x002AA231. Caller 0x003756A8. Next TU
// Rva003743CFBehavior.cpp gives /O1 /DNDEBUG /MD and Object* at +8 precedent.

enum ObjectStatusTypes
{
	OBJECT_STATUS_DUMMY = 0
};

enum Relationship
{
	ENEMIES = 0,
	NEUTRAL = 1,
	ALLIES = 2
};

class Object
{
public:
	bool testStatus(ObjectStatusTypes bit) const;
};

class Team
{
public:
	Relationship getRelationship(const Team *that) const;
};

class BfmeMemberRV
{
public:
	bool bfmeAskRV();
};

struct Arg1Layout
{
	char m_pad00[0x304];
	Team *m_304;
	char m_pad308[0x438 - 0x308];
	unsigned char m_438;
};

struct Arg2Layout
{
	char m_pad00[0x2ec];
	Team *m_2ec;
};

struct Rva003742E3State
{
	char m_pad00[0x30];
	unsigned char m_30;
	char m_pad31[0x56 - 0x30 - 1];
	unsigned char m_56;
};

class Rva003742E3
{
public:
	int rva003742E3(void *a, void *b);
private:
	char m_00[4];
	Rva003742E3State *m_04;
	char m_08[0x3c - 0x08];
	int m_3c;
};

// ?rva003742E3@Rva003742E3@@QAEHPAX0@Z present-unmatched
int Rva003742E3::rva003742E3(void *a, void *b)
{
	Arg1Layout *obj = (Arg1Layout *)a;
	Arg2Layout *other = (Arg2Layout *)b;
	Object *o = (Object *)a;
	int rel;
	unsigned char mask = 1;
	if (obj->m_438 & mask)
		return 0;
	if (!o->testStatus((ObjectStatusTypes)15))
		return 0;
	rel = 1;
	Team *team = obj->m_304;
	if (team != 0)
		rel = (int)team->getRelationship(other->m_2ec);
	BfmeMemberRV *rv = (BfmeMemberRV *)b;
	if (!rv->bfmeAskRV())
		rel = 2;
	Rva003742E3State *st = m_04;
	if (st->m_30 != 0)
	{
		if (rel == 2)
			return 0;
		if (m_3c == 0)
			return 0;
		return 2;
	}
	else
	{
		if (!o->testStatus((ObjectStatusTypes)17))
			return (rel == 2) ? 1 : 5;
		if (st->m_56 != 0)
			return 0;
		return (rel == 2) ? 4 : 3;
	}
}
