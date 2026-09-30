// ?rva0039DB89@Team@@QAEXHPAPAVThingTemplate@@_NPAH1@Z
// partial score=0.96 date=2026-09-30
// ?rva0039DB89@Team@@QAEXHPAPAVThingTemplate@@_NPAH1@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
// ?rva0039DB89@Team@@QAEXHPAPAVThingTemplate@@_NPAH1@Z, retail 0x0039DB89, 124 bytes.
// Unlock: counts team members by template equivalence with status and flag
// checks via rowed iterate/advance/isEquivalentTo/testStatus. Evidence:
// unlock lane, callers 0x0039EC03 0x004F3EBF, neighbours TeamRva0039DA2A/etc.

class Object;
class ThingTemplate;
enum ObjectStatusTypes
{
	STATUS_2 = 2
};

class BfmeObjectVirtualTail { public: unsigned char m_vt[4]; };
class BfmeObjectVbptrCarrier : public virtual BfmeObjectVirtualTail
{
public:
	unsigned char m_carrier[4];
};
class BfmeObjectVtbl { public: virtual void bfmeObjectSlot0(); };
class BfmeObjectDlinkBase
{
public:
	Object *dlink_next_TeamMemberList() const;
};
class BfmeObjectDlinkPad { public: unsigned char m_pad[0x64]; };
class Object : public BfmeObjectVtbl, public BfmeObjectDlinkBase,
	public BfmeObjectDlinkPad, public BfmeObjectVbptrCarrier
{
public:
	bool testStatus(ObjectStatusTypes s) const;
	unsigned char m_tail[0x40];
	ThingTemplate *m_template04;
	char m_pad2[0x438 - 0x48];
	unsigned char m_flags438;
};

class ThingTemplate
{
public:
	bool isEquivalentTo(const ThingTemplate *other) const;
};

template<class OBJCLASS>
class DLINK_ITERATOR
{
public:
	typedef OBJCLASS *(OBJCLASS::*GetNextFunc)() const;
	DLINK_ITERATOR(OBJCLASS *cur, GetNextFunc getNextFunc)
		: m_cur(cur), m_getNextFunc(getNextFunc)
	{
	}
	void advance();
	OBJCLASS *m_cur;
	GetNextFunc m_getNextFunc;
};

template<class OBJCLASS>
class Rva001705A0DlinkIterator
{
public:
	void advance();
	OBJCLASS *m_cur;
	char m_pad[20];
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
	void rva0039DB89(int count, ThingTemplate **templates, bool flag1, int *counts, bool flag2);
};

// ?rva0039DB89@Team@@QAEXHPAPAVThingTemplate@@_NPAH1@Z present-unmatched
void Team::rva0039DB89(int count, ThingTemplate **templates, bool flag1, int *counts, bool flag2)
{
	DLINK_ITERATOR<Object> it = iterate_TeamMemberList();
	for (Object *obj = it.m_cur; obj; ) {
		ThingTemplate *tmpl = *(ThingTemplate **)((char *)obj + 4);
		for (int i = 0; i < count; i++) {
			if (templates[i]->isEquivalentTo(tmpl)) {
				if (flag1 && ((*(unsigned char *)((char *)obj + 0x438) & 1) != 0))
					break;
				if (flag2 && !obj->testStatus(STATUS_2))
					break;
				counts[i]++;
				break;
			}
		}
		((Rva001705A0DlinkIterator<Object> *)&it)->advance();
		obj = it.m_cur;
	}
}
