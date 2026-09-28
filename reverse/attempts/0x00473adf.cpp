// ?rva00473ADF@Rva00473ADF@@QAEXXZ
// partial score=0.93 date=2026-09-28
// ?rva00473ADF@Rva00473ADF@@QAEXXZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /MD
//
// ?rva00473ADF@Rva00473ADF@@QAEXXZ, retail 0x00473ADF, 87 bytes.
// Contain helper: if int at +0x184 is nonzero call virtual slot 78; then get
// the list pair via Rva0046247D at this-0x11c and iterate its head list,
// issuing AI command 0x31 value 0 source 2 for each member with live AI.
// Evidence: slot 0x138 call plus rowed 0x0046247D plus rowed 0x0045003E;
// callers none; prev/next are Contain and stlport; chain from 0x0045003E.

typedef bool Bool;

enum CommandSourceType
{
	CMD_FROM_AI = 2
};

struct Rva0046247DPair
{
	void *first;
	void *second;
};

class Rva0046247D
{
public:
	void rva0046247D(Rva0046247DPair &result);
};

class AICommandInterface
{
public:
	void rva0045003E(int value, CommandSourceType cmdSource);
};

class AIUpdateInterface
{
public:
	char m_pad00[0x20];
	AICommandInterface m_command;
};

class Object
{
public:
	AIUpdateInterface *getAIUpdateInterface()
	{
		return *(AIUpdateInterface **)((char *)this + 0x258);
	}
};

struct ListNode
{
	void *m_next; // +0
	void *m_prev; // +4?
	Object *m_object; // +8
};

#define SLOT8(a,b,c,d,e,f,g,h) virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h();
#define SLOT16(a) SLOT8(a##0,a##1,a##2,a##3,a##4,a##5,a##6,a##7) SLOT8(a##8,a##9,a##A,a##B,a##C,a##D,a##E,a##F)
#define SLOT32(a) SLOT16(a##0) SLOT16(a##1)
#define SLOT64(a) SLOT32(a##0) SLOT32(a##1)

class Rva00473ADF
{
public:
	SLOT64(s0)
	SLOT8(d64_0, d64_1, d64_2, d64_3, d64_4, d64_5, d64_6, d64_7)
	SLOT8(d72_0, d72_1, d72_2, d72_3, d72_4, d72_5, slot78, d79)
	void rva00473ADF();

private:
	char m_pad04[0x184 - 4];
	int m_184; // +0x184
};

// ?rva00473ADF@Rva00473ADF@@QAEXXZ present-unmatched
void Rva00473ADF::rva00473ADF()
{
	if (m_184 != 0)
		slot78();
	Rva0046247DPair pair;
	Rva0046247D *base = (Rva0046247D *)((char *)this - 0x11c);
	base->rva0046247D(pair);
	void *second = pair.second;
	void *head = *(void **)second;
	void *cur = *(void **)head;
	if (cur == head)
		return;
	do {
		Object *obj = ((ListNode *)cur)->m_object;
		AIUpdateInterface *ai = obj->getAIUpdateInterface();
		if (ai)
			ai->m_command.rva0045003E(0, CMD_FROM_AI);
		cur = ((ListNode *)cur)->m_next;
	} while (cur != *(void **)second);
}
