// ?rva0047DEE1@TunnelContain@@QAEPAXPAX@Z
// partial score=0.95 date=2026-09-28
// ?rva0047DEE1@TunnelContain@@QAEPAXPAX@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?rva0047DEE1@TunnelContain@@QAEPAXPAX@Z retail 0x0047DEE1 99 bytes.
// TunnelContain secondary vtable slot 32 (offset 0x80) of 0x00847740.
// Iterates player list via Rva00466398 helper then virtual slot 0x7C and 0x18 test.
// Evidence: vtable slot 32 class ??1TunnelContain, Object::getControllingPlayer
// call, Rva00466398 out-pair call, list walk to head, 0x250 filter load.
// Neighbours share /O1 /DNDEBUG /MD. Honest Rva method name.

class Player;
class Object
{
public:
	Player *getControllingPlayer() const;
};

struct Holder16
{
	void *m_head;
};

struct Out00466398
{
	void *a;
	Holder16 *b;
};
class Rva00466398
{
public:
	void rva00466398(Out00466398 *out);
};

class Res
{
public:
	virtual void r0();
	virtual void r1();
	virtual void r2();
	virtual void r3();
	virtual void r4();
	virtual void r5();
	virtual bool isOk(void *arg);
};

class Filter
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
	virtual void v29();
	virtual void v30();
	virtual Res *v31();
};

struct ObjWith250
{
	char m_pad[0x250];
	Filter *m_filter;
};

struct Node
{
	Node *m_next;
	int m_pad4;
	void *m_val;
};

class TunnelContain
{
public:
	void *rva0047DEE1(void *arg);
private:
	char m_pad[8];
	Object *m_obj;
};

// ?rva0047DEE1@TunnelContain@@QAEPAXPAX@Z present-unmatched
void *TunnelContain::rva0047DEE1(void *arg)
{
	Player *player = m_obj->getControllingPlayer();
	Out00466398 out;
	(*(Rva00466398 **)((char *)player + 0x2e8))->rva00466398(&out);
	Holder16 *h16 = out.b;
	Node *cur = *(Node **)h16->m_head;
	while (cur != (Node *)h16->m_head) {
		ObjWith250 *o = (ObjWith250 *)cur->m_val;
		Filter *f = o->m_filter;
		if (f) {
			Res *r = f->v31();
			if (r && r->isOk(arg))
				return r;
		}
		cur = cur->m_next;
	}
	return 0;
}
