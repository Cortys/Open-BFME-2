// ?Rva006D89E0Pop@@YAXXZ
// partial score=0.98 date=2026-10-01
// ?Rva006D89E0Pop@@YAXXZ
// partial score=0.98 date=2026-10-01
// cl: /O2 /MD
// ?Rva006D89E0Pop@@YAXXZ @0x006D89E0 size 55 — free function draining global g_00E18028 list.
// Evidence: retail reads VA 0x00E18028 twice, virtual calls at +0x2C (no args) and +0x38 (int 1),
// saves [ecx+8] then stores it back to the global. Callers at 0x006CFAB0, 0x006E6E20, 0x006E6F80.
class Rva006D89E0Node
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
	virtual void virt2C();
	virtual void v12();
	virtual void v13();
	virtual void virt38(int v);
	void *m_pad4;
	Rva006D89E0Node *m_next;
};

extern Rva006D89E0Node *g_00E18028;

// ?Rva006D89E0Pop@@YAXXZ present-unmatched
void __cdecl Rva006D89E0Pop()
{
	Rva006D89E0Node *p = g_00E18028;
	if (p == 0)
		return;
	Rva006D89E0Node *next;
	do
	{
		next = p->m_next;
		p->virt2C();
		Rva006D89E0Node *q = g_00E18028;
		if (q != 0)
			q->virt38(1);
		p = next;
		g_00E18028 = p;
	} while (next != 0);
}
