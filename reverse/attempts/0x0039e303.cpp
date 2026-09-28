// ?didAllExit@Team@@QAE_NPAVPolygonTrigger@@I@Z
// partial score=0.98 date=2026-09-28
// ?didAllExit@Team@@QAE_NPAVPolygonTrigger@@I@Z
// partial score=0.98 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?didAllExit@Team@@QAE_NPAVPolygonTrigger@@I@Z @0x0039E303 (197B).
// Team::didAllExit(): true when a considered member exited and none remains
// inside. Retail guard is the byte at Team+0x5c; the member walk uses the
// rowed iterate_TeamMemberList at 0x263864 and the pinned DLINK advance at
// 0x263526, asking the pinned Object::didExit at 0x28D757 plus the rowed
// Object::isInside at 0x28B411. Retail filter is AI at Object+0x258 with
// surfaces at AI+0x1DC tested against 1<<which, ground units via (1<<which)&1,
// dead bit at Object+0x438 bit0, then template at Object+0x04 with kind bytes
// at +0x113 bit2 and +0x118 bit0x40. BFME1 donor
// reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/TeamTriggerAreaTests.cpp:228
// proves the name and loop; BFME2 deltas are the non-const signature plus the
// +0x5c/+0x258/+0x1DC/+0x438/+0x04/+0x113/+0x118 layout and the shift filter
// above. Callers at 0x003E6EC6 and 0x003E7024 pass Team ECX with trigger/type args.

typedef unsigned int UnsignedInt;

class PolygonTrigger;

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

class AIUpdateInterface
{
public:
	unsigned char m_pad[0x1dc];
	UnsignedInt m_surfaces;
};

struct ThingTemplate
{
	unsigned char m_pad[0x113];
	unsigned char m_kindByte113;
	unsigned char m_pad114[0x118 - 0x114];
	unsigned char m_kindByte118;
};

class Object
{
public:
	bool didExit(PolygonTrigger *pTrigger);
	bool isInside(PolygonTrigger *pTrigger);

public:
	unsigned char m_pad0[4];
	ThingTemplate *m_template;
	unsigned char m_pad1[0x258 - 0x8];
	AIUpdateInterface *m_ai;
	unsigned char m_pad2[0x438 - 0x25c];
	unsigned char m_dead;
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
	bool didAllExit(PolygonTrigger *pTrigger, UnsignedInt whichToConsider);

private:
	unsigned char m_pad[0x5c];
	bool m_enteredOrExited;
};

// ?didAllExit@Team@@QAE_NPAVPolygonTrigger@@I@Z present-unmatched
bool Team::didAllExit(PolygonTrigger *pTrigger, UnsignedInt whichToConsider)
{
	if (!m_enteredOrExited)
		return false;

	bool anyConsidered = false;
	bool exited = false;
	bool inside = false;
	for (DLINK_ITERATOR<Object> iter = iterate_TeamMemberList(); !iter.done(); iter.advance()) {
		Object *cur = iter.cur();
		AIUpdateInterface *ai = cur->m_ai;
		if (ai) {
			UnsignedInt mask = 1u << whichToConsider;
			if ((ai->m_surfaces & mask) == 0)
				continue;
		} else {
			unsigned char mask8 = (unsigned char)(1u << whichToConsider);
			if ((mask8 & 1) == 0)
				continue;
		}
		if ((cur->m_dead & 1) != 0)
			continue;
		ThingTemplate *tmpl = cur->m_template;
		if ((tmpl->m_kindByte113 & 2) != 0)
			continue;
		if ((tmpl->m_kindByte118 & 0x40) != 0)
			continue;
		if (cur->didExit(pTrigger))
			exited = true;
		else if (cur->isInside(pTrigger))
			inside = true;
		anyConsidered = true;
	}
	return anyConsidered && exited && !inside;
}
