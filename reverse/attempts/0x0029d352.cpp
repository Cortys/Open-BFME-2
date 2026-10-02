// ??0Rva0029D3B0@@QAE@XZ
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /EHs /MD /DNDEBUG /arch:SSE
//
// ??1Rva0029D3B0@@UAE@XZ @0x0029D3B0 75B.
// Dtor storing vtable 0x007FD1C0, releasing DisplayString slot via
// TheDisplayStringManager slot 15 when +0xC is set, then wide releaseBuffer
// on the UnicodeString at +8. Evidence: vtable store, rowed slot 15 target
// via TheDisplayStringManager, rowed wide releaseBuffer 0x00036E70.

#include "unicode_string.h"

class DisplayString;

class DisplayStringManager
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
	virtual DisplayString *newDisplayString();
	virtual void slot15(void *p);
};

extern DisplayStringManager *TheDisplayStringManager;

class DisplayString
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
};

class Rva0029D3B0
{
public:
	Rva0029D3B0();
	virtual ~Rva0029D3B0();
	int m_04; // +4
	UnicodeString m_08; // +8
	void *m_0C; // +0xC DisplayString*
	float m_10; // +0x10
	float m_14; // +0x14
	float m_18; // +0x18
	int m_1C; // +0x1C
	int m_20; // +0x20
};

Rva0029D3B0::~Rva0029D3B0()
{
	if (m_0C != 0)
		TheDisplayStringManager->slot15(m_0C);
	m_0C = 0;
}

// ??0Rva0029D3B0@@QAE@XZ present-unmatched
Rva0029D3B0::Rva0029D3B0()
{
	m_04 = 0;
	m_20 = 0;
	m_1C = 0;
	m_10 = 0.0f;
	m_14 = 0.0f;
	m_18 = 0.0f;
	m_08.clear();
	m_0C = TheDisplayStringManager->newDisplayString();
}
