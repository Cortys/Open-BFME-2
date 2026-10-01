// ?rva002ABD93@Rva002ABD93@@QAEXABVAsciiString@@_N@Z
// partial score=0.9 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva002ABD93@Rva002ABD93@@QAEXABVAsciiString@@_N@Z, RVA 0x002ABD93, size 145.
// Evidence: callers 0x003BB35B/0x003BB41A pass (string 0,1); outer circular list head at +0x32c
// with data at node+8 holding Team at +0x334; Team member iteration via rowed iterate/advance;
// StringBase compare row; Object setScriptStatus row; next-Team via Rva005C4AF5DwordField get (Team+0x40).
#include "ascii_string.h"

class Object;
class Team;

template<class OBJCLASS>
class DLINK_ITERATOR
{
public:
	DLINK_ITERATOR(OBJCLASS *cur, void *f);
	OBJCLASS *cur() const { return m_cur; }
	bool done() const { return m_cur == 0; }
private:
	OBJCLASS *m_cur;
	char m_pad[28];
};

template<class OBJCLASS>
class Rva001705A0DlinkIterator
{
public:
	void advance();
	OBJCLASS *cur() const { return m_cur; }
private:
	OBJCLASS *m_cur;
	char m_pad[28];
};

class Rva005C4AF5Base1 { char m_b1; };
class Rva005C4AF5Base2 { char m_b2; };
class Rva005C4AF5DwordField : public Rva005C4AF5Base1, public Rva005C4AF5Base2
{
public:
	int get() const;
};

enum ObjectScriptStatusBit
{
	OBJECT_STATUS_SCRIPT_DISABLED = 0x01,
	OBJECT_STATUS_SCRIPT_UNPOWERED = 0x02
};

class ObjectHolder
{
public:
	char m_pad[0x64];
	AsciiString m_name;
};

class Object
{
public:
	void setScriptStatus(ObjectScriptStatusBit, bool);
	void *m_vtbl;
	ObjectHolder *m_holder;
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
};

struct OuterNode
{
	OuterNode *m_next;
	OuterNode *m_prev;
	void *m_data;
};

struct OuterData
{
	char m_pad[0x334];
	Team *m_team;
};

class Rva002ABD93
{
public:
	void rva002ABD93(const AsciiString &name, bool flag);
private:
	char m_pad[0x32c];
	OuterNode *m_head;
};

// ?rva002ABD93@Rva002ABD93@@QAEXABVAsciiString@@_N@Z present-unmatched
void Rva002ABD93::rva002ABD93(const AsciiString &name, bool flag)
{
	int (Rva005C4AF5DwordField::*getNext)() const = &Rva005C4AF5DwordField::get;
	OuterNode *cur = m_head->m_next;
	if (cur == m_head)
		return;
	do
	{
		OuterData *data = (OuterData *)cur->m_data;
		Team *team = data->m_team;
		while (team != 0)
		{
			DLINK_ITERATOR<Object> it = team->iterate_TeamMemberList();
			Rva001705A0DlinkIterator<Object> *rit = (Rva001705A0DlinkIterator<Object> *)&it;
			for (;;)
			{
				Object *obj = rit->cur();
				if (obj == 0)
					break;
				ObjectHolder *h = obj->m_holder;
				if (h->m_name.compare(name) == 0)
					obj->setScriptStatus(OBJECT_STATUS_SCRIPT_DISABLED, flag == false);
				rit->advance();
			}
			Rva005C4AF5DwordField *fp = (Rva005C4AF5DwordField *)team;
			team = (Team *)((fp->*getNext)());
		}
		cur = cur->m_next;
	} while (cur != m_head);
}
