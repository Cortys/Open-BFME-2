// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z
// partial score=0.96 date=2026-10-04
// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z
// partial score=0.94 date=2026-10-04
// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z
// partial score=0.94 date=2026-10-03
// cl: /Ireference/shims/bfmelist /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva00526421@Rva00526421@@QAEXPAV?$list@PAXV?$allocator@PAX@_STL@@@_STL@@H@Z @0x00526421 142B evidence: outer list via +0x10 holder +0x14 sentinel per retail [eax]==eax empty and [esi] next with ID +8 flag +0xC; TheGameLogic findObjectByID getControllingPlayer isLocalPlayer Rva00524FEDCheck push_back list<void*>.
// TWO findings this pass. (1) Rva00524FEDCheck is called RETAIL-STYLE as a
// thiscall MEMBER on this (mov ecx,edi; push ebx; call) even though its own
// rowed body at 0x524FED is the free __stdcall(Object*) ?Rva00524FEDCheck@@YG
// E. Declaring it here as a member `unsigned char check(Object*)` (member
// functions are thiscall by default under MSVC) is what emits the mov ecx,edi;
// that alone moved the body from 138B/49 to 140B with the whole loop tail
// becoming retail-identical. The member is DECLARED but not defined here: the
// next agent must point it at the rowed 0x524FED address to land. (2) The
// empty-check must read h->m_sentinel TWICE textually (the `sentinel` local is
// kept alive but used only as a cl allocation hint, NOT in the loop condition);
// caching it into one local used for the compare drops to 140B/33 because cl
// re-assigns the register. With the double read the body is 142B exact-size,
// 134 of 142 bytes, the sole residual being cl's mov edx,ecx extra copy on the
// two-read sentinel where retail reads once into eax.
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
	unsigned char check(Object *o);
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
	if (*(OuterElem * *)h->m_sentinel == h->m_sentinel)
		return;
	for (OuterElem *cur = h->m_sentinel->m_next; cur != m_holder->m_sentinel; cur = cur->m_next)
	{
		Object *obj = TheGameLogic->findObjectByID(cur->m_id);
		if (obj != 0 && obj->getControllingPlayer()->isLocalPlayer())
		{
			if (cur->m_flag)
				m_1DA = 1;
			if (flag != 1 || check(obj) != 0)
				out->push_back((void *)cur);
		}
		else
			cur->m_flag = 0;
	}
}
