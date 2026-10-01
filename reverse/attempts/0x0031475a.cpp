// ?rva0031475A@GameWindow@@QAEHXZ
// partial score=0.94 date=2026-10-01
// ?rva0031475A@GameWindow@@QAEHXZ
// partial score=0.94 date=2026-10-01
// cl: /O1 /G7 /DNDEBUG /MD /EHsc
// ?rva0031475A@GameWindow@@QAEHXZ @0x0031475A 128B. GameWindow reparent-or-relink with manager list and child notify.
// Evidence: calls rowed Rva002C0BD7Remove 0x002C0BD7 plus rva002C0B92 0x002C0B92 plus rva002C0A89 0x002C0A89; virtual manager slots 0x94 and 0xE0; child slots 0x18 and 0x1C; TheWindowManager 0x009FEF1C; members +0x200 +0x210 +0x1F8.
class GameWindow;

class GameWindowManager
{
public:
#define V(n) virtual void pad##n();
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
	V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
	V(32) V(33) V(34) V(35) V(36)
#undef V
	virtual GameWindow *slot37();
#define W(n) virtual void wpad##n();
	W(38) W(39) W(40) W(41) W(42) W(43) W(44) W(45) W(46) W(47) W(48) W(49) W(50) W(51) W(52) W(53) W(54) W(55)
#undef W
	virtual void slot56(GameWindow *a, GameWindow *b);
};

extern GameWindowManager *TheWindowManager;

class Rva002C0A89
{
public:
	void rva002C0A89(GameWindow *win);
	void rva002C0B92(GameWindow *win);
};

void __stdcall Rva002C0BD7Remove(GameWindow *win);

class ChildNode
{
public:
	virtual void c0();
	virtual void c1();
	virtual void c2();
	virtual void c3();
	virtual void c4();
	virtual void c5();
	virtual void c6(GameWindow *w);
	virtual void c7(GameWindow *w);
};

class GameWindow
{
public:
	int rva0031475A();
private:
	unsigned char _pad0[0x1F8];
public:
	GameWindow *m_next; // +0x1F8
private:
	unsigned char _pad1FC[0x200 - 0x1FC];
public:
	GameWindow *m_parent; // +0x200
private:
	unsigned char _pad204[0x210 - 0x204];
public:
	ChildNode *m_child210; // +0x210
};

// ?rva0031475A@GameWindow@@QAEHXZ present-unmatched
int GameWindow::rva0031475A()
{
	GameWindow *parent = m_parent;
	if (parent)
	{
		Rva002C0BD7Remove(this);
		TheWindowManager->slot56(this, parent);
	}
	else
	{
		GameWindow *cur = TheWindowManager->slot37();
		for (;;)
		{
			if (cur == this)
				break;
			if (!cur)
				return -3;
			cur = cur->m_next;
		}
		((Rva002C0A89 *)TheWindowManager)->rva002C0B92(this);
		((Rva002C0A89 *)TheWindowManager)->rva002C0A89(this);
	}
	ChildNode *child = m_child210;
	if (child)
	{
		child->c7(this);
		child->c6(this);
	}
	return 0;
}
