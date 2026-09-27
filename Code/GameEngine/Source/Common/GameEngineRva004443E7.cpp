// cl: /O1 /MD
//
// ?rva004443E7@GameEngine@@QAEXXZ, retail 0x004443E7 37B.
// Calls member at +0x288 slot 1 then global 0xDFE958 slot 0x48 then tail to GameEngine terminateChild.
// Evidence: add ecx 0x288 and call [eax+4]; mov ecx [0xDFE958] test and call [eax+0x48];
// mov ecx [0xDFE710 TheGameEngine] jmp to rowed _bfme_terminateChildProcesses 0x2260F7;
// callers at 0x44459D 0x444E7E 0x444EA4 0x444EE5 0x44666D.

class Member004443E7
{
public:
	virtual void s0();
	virtual void s1();
};

class Global004443E7958View
{
public:
	virtual void g0();
	virtual void g1();
	virtual void g2();
	virtual void g3();
	virtual void g4();
	virtual void g5();
	virtual void g6();
	virtual void g7();
	virtual void g8();
	virtual void g9();
	virtual void g10();
	virtual void g11();
	virtual void g12();
	virtual void g13();
	virtual void g14();
	virtual void g15();
	virtual void g16();
	virtual void g17();
	virtual void g18();
};

#define TheGlobal004443E7958 (*(Global004443E7958View **)0x00DFE958)
#define TheGameEngine004443E7 (*(class GameEngine **)0x00DFE710)

class GameEngine
{
public:
	void rva004443E7();
	void rva00444E69(int unused);

private:
	void _bfme_terminateChildProcesses();
	char m_pad[0x288];
	Member004443E7 m_mem288; // +0x288
	char m_pad28C[0x54B - 0x28C];
	unsigned char m_54B; // +0x54B
	char m_pad54C[0x6A4 - 0x54C];
	int m_6A4; // +0x6A4
};

void GameEngine::rva004443E7()
{
	m_mem288.s1();
	Global004443E7958View *g = TheGlobal004443E7958;
	if (g)
		g->g18();
	GameEngine *e = TheGameEngine004443E7;
	e->_bfme_terminateChildProcesses();
}

void GameEngine::rva00444E69(int unused)
{
	(void)unused;
	if (m_6A4 == 6)
		m_54B = 0;
	else {
		rva004443E7();
		m_6A4 = 0;
	}
}
