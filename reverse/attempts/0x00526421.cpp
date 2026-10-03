// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z
// partial score=0.94 date=2026-10-03
// cl: /Ireference/shims/bfmelist /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z @0x00526421 142B evidence: outer list via +0x10 holder +0x14 sentinel per retail [eax]==eax empty and [esi] next with ID +8 flag +0xC; TheGameLogic findObjectByID getControllingPlayer isLocalPlayer Rva00524FEDCheck push_back list<void*>.
// Honest-address method (naming rule): reads ecx before writing it.
#include <list>

enum ObjectID
{
	OBJECTID_NONE = 0
};

class Object;
class Player
{
public:
	bool isLocalPlayer() const;
};

class Object
{
public:
	Player *getControllingPlayer() const;
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;

typedef unsigned char UChar;
UChar __stdcall Rva00524FEDCheck(Object *o);

struct OuterElem
{
	OuterElem *m_next;
	void *m_unk4;
	ObjectID m_id;
	unsigned char m_flag;
};

struct Holder
{
	char m_pad[0x14];
	OuterElem *m_sentinel;
};

class Rva00526421
{
public:
	void rva00526421(_STL::list<void *> *out, int flag);
private:
	char m_pad0[0x10];
	Holder *m_holder;
	char m_pad14[0x1DA - 0x14];
	unsigned char m_1DA;
};

// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z present-unmatched
void Rva00526421::rva00526421(_STL::list<void *> *out, int flag)
{
	((_STL::_List_base<int, _STL::allocator<int> > *)out)->clear();
	Holder *h = m_holder;
	OuterElem *sentinel = h->m_sentinel;
	if (*(OuterElem * *)sentinel == sentinel)
		return;
	for (OuterElem *cur = h->m_sentinel->m_next; cur != m_holder->m_sentinel; cur = cur->m_next)
	{
		Object *obj = TheGameLogic->findObjectByID(cur->m_id);
		if (obj != 0 && obj->getControllingPlayer()->isLocalPlayer())
		{
			if (cur->m_flag)
				m_1DA = 1;
			if (flag != 1 || Rva00524FEDCheck(obj) != 0)
				out->push_back((void *)cur);
		}
		else
			cur->m_flag = 0;
	}
}
