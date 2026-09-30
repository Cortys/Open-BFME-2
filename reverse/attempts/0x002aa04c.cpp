// ?rva002AA04C@Rva002AA04C@@QAEHXZ
// partial score=0.97 date=2026-09-30
// cl: /O1
// ?rva002AA04C@Rva002AA04C@@QAEHXZ @0x002AA04C 66B.
// Multi-gate player-area predicate: virtual slot 0x40 check on the global
// at 0x00E03138 must be false, byte at this+0x734 must be 0, InGameUI
// (0x00DFEDF0) byte at +0x8C5 must be 0, GameLogic (0x00DFE78C) byte at
// +0x70 must be nonzero and dword at +0x40 must be nonzero. Evidence:
// retail immediates and jcc chain, TheGameLogic/TheInGameUI VAs from
// sibling TUs, slot 0x40 virtual shape. Honest address name.
class Rva002AA04C
{
public:
	int rva002AA04C();
private:
	char m_pad0[0x734];
	unsigned char m_734;
};

class Rva002AA04CCheckArg;
class Rva002AA04CUnknown
{
public:
	virtual void d00();
	virtual void d01();
	virtual void d02();
	virtual void d03();
	virtual void d04();
	virtual void d05();
	virtual void d06();
	virtual void d07();
	virtual void d08();
	virtual void d09();
	virtual void d10();
	virtual void d11();
	virtual void d12();
	virtual void d13();
	virtual void d14();
	virtual void d15();
	virtual bool check(Rva002AA04C *p);
};
extern Rva002AA04CUnknown *g_00E03138;

struct Rva002AA04CInGameUI
{
	char m_pad0[0x8c5];
	unsigned char m_8c5;
};
extern Rva002AA04CInGameUI *g_00DFEDF0;

struct Rva002AA04CGameLogic
{
	char m_pad0[0x40];
	unsigned int m_40;
	char m_pad1[0x70 - 0x44];
	unsigned char m_70;
};
extern Rva002AA04CGameLogic *g_00DFE78C;

// ?rva002AA04C@Rva002AA04C@@QAEHXZ present-unmatched
int Rva002AA04C::rva002AA04C()
{
	if (!g_00E03138->check(this)
		&& m_734 == 0
		&& g_00DFEDF0->m_8c5 == 0
		&& g_00DFE78C->m_70 != 0
		&& g_00DFE78C->m_40 > 0)
		return true;
	return false;
}
