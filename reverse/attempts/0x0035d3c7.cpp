// ?Rva0035D3C7@Rva0035D352@@UAEXH@Z
// partial score=0.9 date=2026-09-26
// ?Rva0035D3C7@Rva0035D352@@UAEXH@Z
// partial score=0.90 date=2026-09-26
// cl: /O1 /MD /arch:SSE
//
// Opaque single-inheritance destructors tail-calling Rva001DBAC3::~
// Rva001DBAC3 at 0x001DBAC3 (pinned opaque leaf base dtor: vtable store
// plus ret; identity unproven). Each class below stores its own vtable
// (DIR32 auto-patches) and tail-calls the base destructor; the base itself
// is only declared here (defined nowhere -- it resolves via the pin),
// because a same-TU definition would capture the call locally instead of at
// the ledger address. Owner identities are unproven (opaque Rva names). One
// ledger row per destructor, landed one commit at a time.
// vslot 0x0035D1C6 (?Rva0035D1C6@Rva0035D0D1@@UAEXXZ, 33B, slot 5 offset 0x14
// of vtable 0x008163D8): if (!m_1c) { m_20 = 1.0f; slot4(); } m_24 = 1.
// Evidence: vtable 0x008163D8 slots 0x35D1F0/0x35D133/0x35D14A/0x35D1BD/
// 0x35D2B2/0x35D1C6/0x35D1E7; INI StartFrame +0x10 EndFrame +0x14
// ViewsToFade +0x18 LeaveSilent +0x1C; float 1.0f at 0x00BBB8D8.

class Rva001DBAC3
{
public:
	virtual ~Rva001DBAC3();
};

class Rva0035D0D1 : public Rva001DBAC3
{
public:
	virtual ~Rva0035D0D1();
	virtual void slot1(int); // 0x0035D133 slot 1
	virtual void slot2(int); // 0x0035D14A slot 2
	virtual void slot3(); // 0x0035D1BD slot 3 shared
	virtual void slot4(); // 0x0035D2B2 slot 4
	virtual void Rva0035D1C6(); // 0x0035D1C6 slot 5
	virtual void slot6(); // 0x0035D1E7 slot 6 shared
private:
	char m_pad[0x18];
	bool m_1c;
	char m_pad2[3];
	float m_20;
	bool m_24;
};

Rva0035D0D1::~Rva0035D0D1()
{
}

void Rva0035D0D1::Rva0035D1C6()
{
	if (!m_1c) {
		m_20 = 1.0f;
		slot4();
	}
	m_24 = true;
}

class AudioManager
{
public:
	virtual void _pad00() = 0;
	virtual void _pad01() = 0;
	virtual void _pad02() = 0;
	virtual void _pad03() = 0;
	virtual void _pad04() = 0;
	virtual void _pad05() = 0;
	virtual void _pad06() = 0;
	virtual void _pad07() = 0;
	virtual void _pad08() = 0;
	virtual void _pad09() = 0;
	virtual void _pad10() = 0;
	virtual void _pad11() = 0;
	virtual void _pad12() = 0;
	virtual void _pad13() = 0;
	virtual void _pad14() = 0;
	virtual void _pad15() = 0;
	virtual void _pad16() = 0;
	virtual void _pad17() = 0;
	virtual void _pad18() = 0;
	virtual void _pad19() = 0;
	virtual void _pad20() = 0;
	virtual void _pad21() = 0;
	virtual void _pad22() = 0;
	virtual void _pad23() = 0;
	virtual void _pad24() = 0;
	virtual void _pad25() = 0;
	virtual void _pad26() = 0;
	virtual void _pad27() = 0;
	virtual void _pad28() = 0;
	virtual void _pad29() = 0;
	virtual void _pad30() = 0;
	virtual void _pad31() = 0;
	virtual void _pad32() = 0;
	virtual void _pad33() = 0;
	virtual void _pad34() = 0;
	virtual void _pad35() = 0;
	virtual void _pad36() = 0;
	virtual void _pad37() = 0;
	virtual void _pad38() = 0;
	virtual void _pad39() = 0;
	virtual void _pad40() = 0;
	virtual void _pad41() = 0;
	virtual void _pad42() = 0;
	virtual void _pad43() = 0;
	virtual void _pad44() = 0;
	virtual void _pad45() = 0;
	virtual void _pad46() = 0;
	virtual void _pad47() = 0;
	virtual void _pad48() = 0;
	virtual void _pad49() = 0;
	virtual void _pad50() = 0;
	virtual void _pad51() = 0;
	virtual void _pad52() = 0;
	virtual void _pad53() = 0;
	virtual void _pad54() = 0;
	virtual void _pad55() = 0;
	virtual void _pad56() = 0;
	virtual void _pad57() = 0;
	virtual void _pad58() = 0;
	virtual void _pad59() = 0;
	virtual void _pad60() = 0;
	virtual void _pad61() = 0;
	virtual void _pad62() = 0;
	virtual void _pad63() = 0;
	virtual void _pad64() = 0;
	virtual void _pad65() = 0;
	virtual void _pad66(bool flag) = 0;
};

#define TheAudio (*(AudioManager *const *)0x00DFE6E8)

class Rva0035D352 : public Rva001DBAC3
{
public:
	virtual ~Rva0035D352();
	virtual void slot1();
	virtual void Rva0035D3C7(int index);
private:
	char m_pad4[4];
	bool m_8;
	bool m_9;
	char m_padA[2];
	char m_padC[4];
	int m_10;
	int m_14;
	bool m_18;
	bool m_19;
};

Rva0035D352::~Rva0035D352()
{
}

// vslot 0x0035D3C7 (?Rva0035D3C7@Rva0035D352@@UAEXH@Z, 119B, slot 2 offset 0x8
// of vtable 0x00816478): range-select silence via TheAudio (data 0x009FE6E8)
// pad slots 0x104/0x108; sets +0x8 in range, +0x19 tracks silence state.
// Evidence: vtable 0x00816478 slot 2 plus sibling slot-2 range-select shape
// ?Rva0035DD08@Rva0035DCF9@@UAEXH@Z plus AudioManager pad-slot precedent.
// ?Rva0035D3C7@Rva0035D352@@UAEXH@Z present-unmatched
void Rva0035D352::Rva0035D3C7(int index)
{
	bool flag = m_9;
	if (index < m_10)
		return;
	if (index > m_14)
		return;
	if (flag) {
		if (index == m_14)
			goto SET;
		if (m_10 == m_14)
			goto SET;
		if (flag)
			goto CLEAR;
	} else {
		if (index == m_10)
			goto SET;
		if (m_10 != m_14)
			goto CLEAR;
	}
SET:
	if (m_19) {
		if (m_18)
			TheAudio->_pad66(false);
		else
			TheAudio->_pad66(true);
		m_19 = false;
	}
	m_8 = true;
	return;
CLEAR:
	if (m_19)
		return;
	TheAudio->_pad65();
	m_19 = true;
}
