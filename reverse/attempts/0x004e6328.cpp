// ?rva004E6328@Rva004E6328@@QAEXPAUICoord2D@@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD
// ?rva004E6273@Rva004E6273@@QAEXXZ @ 0x004E6273 (34B): guarded virtual call through +0x10 target slot 0x38 with (m_index m_other 1 1). Early-out when target null or index negative. Unblocks 0x004E63DB thunk which does mov ecx-[ecx] then jmp here. Caller is jmp at 0x004E63DD.
struct Rva004E6273Target
{
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
	virtual void meth(int a, int b, int c, int d);
	virtual void getSize(int *a, int *b);
};
struct Rva004E6273
{
	char m_lead[0x10];
	Rva004E6273Target *m_ptr;
	int m_index;
	int m_other;
	void rva004E6273();
};
void Rva004E6273::rva004E6273()
{
	if (m_ptr == 0)
		return;
	int idx = m_index;
	if (idx < 0)
		return;
	m_ptr->meth(idx, m_other, 1, 1);
}

class Rva004E63DB
{
public:
	void rva004E63DB();
private:
	Rva004E6273 *m_ptr;
};

void Rva004E63DB::rva004E63DB()
{
	m_ptr->rva004E6273();
}

// ?rva004E6328@Rva004E6328@@QAEXPAUICoord2D@@@Z @ 0x004E6328 (179B): position from arg or mouse, adjust by size/−2 and −20, clamp to tactical view dims. Evidence: contiguous gap between 0x004E6273 and 0x004E63DB same TU same // cl, TheMouse+0x4F0C ICoord2D precedent InGameUI_handleRadiusCursor, TheTacticalView getWidth/getHeight slots, caller 0x004E6455.
struct ICoord2D
{
	int x;
	int y;
};

class Mouse
{
public:
	unsigned char m_pad[0x4F0C];
	ICoord2D m_pos;
};

extern Mouse *TheMouse;

class TacticalView
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual int getW();
	virtual void s16();
	virtual int getH();
};

extern TacticalView *TheTacticalView;

class Rva004E6328
{
public:
	void rva004E6328(ICoord2D *p);
private:
	char m_lead[0x10];
	Rva004E6273Target *m_ptr;
	ICoord2D m_c;
};

// ?rva004E6328@Rva004E6328@@QAEXPAUICoord2D@@@Z present-unmatched
void Rva004E6328::rva004E6328(ICoord2D *p)
{
	if (p != 0)
		m_c = *p;
	else
		m_c = TheMouse->m_pos;
	int h;
	int t1;
	int zero;
	m_ptr->getSize((int *)&p, &h);
	zero = 0;
	m_c.x += (*(int *)&p) / -2;
	m_c.y += -20 - h;
	t1 = TheTacticalView->getW() - (*(int *)&p);
	int *pp1 = (t1 < m_c.x) ? &t1 : &m_c.x;
	if (*pp1 < 0)
		pp1 = &zero;
	int v1 = *pp1;
	zero = 0;
	m_c.x = v1;
	int t2 = TheTacticalView->getH() - h;
	int *pp2 = (t2 < m_c.y) ? &t2 : &m_c.y;
	if (*pp2 < 0)
		pp2 = &zero;
	m_c.y = *pp2;
}
