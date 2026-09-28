// cl: /O1 /MD /EHsc
// ??1Rva00355D66@@UAE@XZ @0x00355D66 73B
// Intermediate dtor in the Gen_004902A0 family (base dtor rowed at 0x00355C77,
// base ctor unrowed at 0x00355C60, own ctor at 0x00355D4E with vtable 0x00814E5C).
// Evidence: stores vtable 0x00814E5C at [this], releases member +8 via
// TheWindowManager (0x00DFEF1C) slot 0x8C when non-null, clears +8, then calls
// base dtor; deleting dtor at 0x00355FDD calls here; EH prolog with scope
// 0x00B7D529 shared with sibling 0x00355CD8.

class Gen_004902A0
{
public:
	virtual ~Gen_004902A0() throw();
	Gen_004902A0 *m_next;
};

class GameWindow;

class GameWindowManager
{
public:
	virtual void pad00();
	virtual void pad01();
	virtual void pad02();
	virtual void pad03();
	virtual void pad04();
	virtual void pad05();
	virtual void pad06();
	virtual void pad07();
	virtual void pad08();
	virtual void pad09();
	virtual void pad10();
	virtual void pad11();
	virtual void pad12();
	virtual void pad13();
	virtual void pad14();
	virtual void pad15();
	virtual void pad16();
	virtual void pad17();
	virtual void pad18();
	virtual void pad19();
	virtual void pad20();
	virtual void pad21();
	virtual void pad22();
	virtual void pad23();
	virtual void pad24();
	virtual void pad25();
	virtual void pad26();
	virtual void pad27();
	virtual void pad28();
	virtual void pad29();
	virtual void pad30();
	virtual void pad31();
	virtual void pad32();
	virtual void pad33();
	virtual void pad34();
	virtual void managerSlot35(GameWindow *w);
};

extern GameWindowManager *TheWindowManager;

class Rva00355D66 : public Gen_004902A0
{
public:
	virtual ~Rva00355D66();
private:
	GameWindow *m_win;
	bool m_flag;
};

Rva00355D66::~Rva00355D66()
{
	if (m_win)
		TheWindowManager->managerSlot35(m_win);
	m_win = 0;
}

// ??1Rva00355DC5@@UAE@XZ @0x00355DC5 15B
// Derived dtor (vtable 0x00814E74) tail-jumping to base 0x00355D66.
// Evidence: clears +0x10 then stores vtable then jmp base; deleting dtor at
// 0x00356066 calls here; chain of 0x00355D66.
class Rva00355DC5 : public Rva00355D66
{
public:
	virtual ~Rva00355DC5();
private:
	int m_extra;
};

Rva00355DC5::~Rva00355DC5()
{
	m_extra = 0;
}
