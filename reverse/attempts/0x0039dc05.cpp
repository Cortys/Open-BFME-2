// ?countKind@Team@@QAEHH_N0@Z
// partial score=0.93 date=2026-09-28
// ?countKind@Team@@QAEHH_N0@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?rva0039D9E3@Team@@QBEHXZ @0x0039D9E3 (71B).
// Team::rva0039D9E3(): counts live members that either have an AI interface
// or whose template kind0 has bit 0x80. Retail walks via the rowed
// iterate_TeamMemberList at 0x263864 and advance at 0x263526, skipping dead
// bit at Object+0x438 bit0, then counting when AI at Object+0x258 is present
// otherwise checking template at Object+0x04 kind byte at +0x108 bit 0x80.
// Callers none yet; neighbours getControllingPlayer and healAllObjects share
// the /O1 flags and 24-byte iterator shape.

typedef unsigned int UnsignedInt;
typedef bool Bool;

enum ObjectStatusTypes
{
	OBJECT_STATUS_2 = 2
};

class Object;

template<class OBJCLASS>
class DLINK_ITERATOR
{
private:
	OBJCLASS *m_cur;
	unsigned char m_targetAbiState[20];

public:
	void advance();
	bool done() const { return m_cur == 0; }
	OBJCLASS *cur() const { return m_cur; }
};

struct ThingTemplate
{
	int rva000456AC(int bit) const;
	unsigned char m_pad[0x108];
	unsigned char m_kind0;
};

class AIUpdateInterface;

class Object
{
public:
	Bool testStatus(ObjectStatusTypes bit) const;

public:
	unsigned char m_pad0[4];
	ThingTemplate *m_template;
	unsigned char m_pad1[0x258 - 0x08];
	AIUpdateInterface *m_ai;
	unsigned char m_pad2[0x438 - 0x25C];
	unsigned char m_dead;
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
	int rva0039D9E3() const;
	int rva0039DC63() const;
	int countKind(int kind, bool a, bool b);
};

int Team::rva0039D9E3() const
{
	int count = 0;
	for (DLINK_ITERATOR<Object> iter = iterate_TeamMemberList(); !iter.done(); iter.advance()) {
		Object *cur = iter.cur();
		if ((cur->m_dead & 1) != 0)
			continue;
		if (cur->m_ai != 0) {
			++count;
			continue;
		}
		ThingTemplate *tmpl = cur->m_template;
		if ((tmpl->m_kind0 & 0x80) == 0)
			continue;
		++count;
	}
	return count;
}

// ?rva0039DC63@Team@@QBEHXZ @0x0039DC63 (59B).
// Team::rva0039DC63(): counts members whose template is present and whose
// template kind0 has bit 0x80. Retail walks via the rowed
// iterate_TeamMemberList at 0x263864 and advance at 0x263526, with the same
// 24-byte iterator and +0x04/+0x108 layout as the rva0039D9E3 sibling above.
// Caller at 0x0039ECF4.
int Team::rva0039DC63() const
{
	int count = 0;
	for (DLINK_ITERATOR<Object> iter = iterate_TeamMemberList(); !iter.done(); iter.advance()) {
		Object *cur = iter.cur();
		ThingTemplate *tmpl = cur->m_template;
		if( tmpl == 0 )
			continue;
		if( (tmpl->m_kind0 & 0x80) == 0 )
			continue;
		++count;
	}
	return count;
}

// ?countKind@Team@@QAEHH_N0@Z @0x0039DC05 (94B).
// Team::countKind(): counts members whose template passes the kind-bit test
// at 0x000456AC. Retail walks via the rowed iterate_TeamMemberList at
// 0x00263864 and advance at 0x00263526, filtering dead bit at Object+0x438
// when the second bool is set and status bit 2 via testStatus at 0x0004E536
// when the third bool is set, then testing template at Object+0x04.
// Caller at 0x003E5E6A in FUN_007E5E2F; BFME1 ScriptConditionsTeamCompare
// proves the (int kind, Bool, Bool) shape.
// ?countKind@Team@@QAEHH_N0@Z present-unmatched
int Team::countKind(int kind, bool a, bool b)
{
	int count = 0;
	DLINK_ITERATOR<Object> iter = iterate_TeamMemberList();
	Object *cur;
	for (; (cur = iter.cur()) != 0; iter.advance()) {
		if (a && ((cur->m_dead & 1) != 0))
			continue;
		if (b && cur->testStatus(OBJECT_STATUS_2))
			continue;
		if ((unsigned char)cur->m_template->rva000456AC(kind) == 0)
			continue;
		++count;
	}
	return count;
}
