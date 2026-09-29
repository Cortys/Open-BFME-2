// ??0LANAPI@@QAE@XZ
// partial score=0.95 date=2026-09-29
// ??0LANAPI@@QAE@XZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??0LANAPI@@QAE@XZ @ 0x00449AB8 (193B).
// LANAPI ctor: stores vtable 0x0083E680, zeroes +0xC..+0x2C, port at +0x30
// from getenv("_EA_RTS_HEADLESS") (5000 or 50000), zeroes +0x34/+0x38/+0x3C,
// flags +0x40/+0x41=1, +0x44/+0x48=0, word +0x4C=0, new Transport at +0x50
// (null-checked), +0x54=-1, +0x58=0, +0x5C=1/+0x5D=0. Calls rowed
// baseConstruct 0x001B4E63, rowed operator new 0x0002FDA0, rowed Transport
// ctor 0x004D4AF2, IAT getenv. Prev LANAPISetIsActive shares flags and layout
// (+0x41 inLobby, +0x44 game, +0x5C active). Callers at 0x00445309/0x0050CF69.
typedef int Int;
typedef bool Bool;

extern "C" __declspec(dllimport) char *getenv(const char *name);

void *operator new(unsigned size) throw();

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork() { baseConstruct(); }
	~BFME2NativeNetwork();
	BFME2NativeNetwork *baseConstruct();
};

class Transport
{
public:
	Transport();
private:
	char m_body[0x41148];
};

class LANAPI : public BFME2NativeNetwork
{
public:
	virtual void slot00() = 0;
	virtual void slot01() = 0;
	virtual void slot02() = 0;
	virtual void slot03() = 0;
	virtual void slot04() = 0;
	virtual void slot05() = 0;
	virtual void slot06() = 0;
	virtual void slot07() = 0;
	virtual void slot08() = 0;
	virtual void slot09() = 0;
	virtual void slot10() = 0;
	virtual void slot11() = 0;
	virtual void slot12() = 0;
	virtual void slot13() = 0;
	virtual void slot14() = 0;
	virtual void slot15() = 0;
	virtual void slot16() = 0;
	virtual void slot17() = 0;
	virtual void slot18() = 0;
	virtual void slot19() = 0;
	virtual void slot20() = 0;
	virtual void slot21() = 0;
	virtual void slot22() = 0;
	virtual void slot23() = 0;
	virtual void slot24() = 0;
	virtual void slot25() = 0;
	virtual void slot26() = 0;
	virtual void slot27() = 0;
	virtual void slot28() = 0;
	virtual void slot29() = 0;
	virtual void slot30() = 0;
	virtual void slot31() = 0;
	virtual void slot32() = 0;
	virtual void slot33() = 0;
	virtual void slot34() = 0;
	virtual void slot35() = 0;
	virtual void slot36() = 0;
	virtual void slot37() = 0;
	virtual void slot38() = 0;
	virtual void slot39() = 0;
	virtual void slot40() = 0;
	virtual void slot41() = 0;
	virtual void slot42() = 0;
	virtual void slot43() = 0;
	virtual void slot44() = 0;
	virtual void slot45() = 0;
	virtual void slot46() = 0;
	virtual void slot47() = 0;
	virtual void slot48() = 0;
	virtual void slot49() = 0;
	virtual void slot50() = 0;
	virtual void slot51() = 0;
	virtual void slot52() = 0;
	virtual void slot53() = 0;
	virtual void slot54() = 0;
	virtual void slot55() = 0;
	virtual void slot56() = 0;
	LANAPI();
	~LANAPI();

private:
	unsigned char m_pad04[8];
	unsigned m_0c;
	unsigned m_10;
	unsigned m_14;
	unsigned m_18;
	unsigned m_1c;
	unsigned m_20;
	unsigned m_24;
	unsigned m_28;
	unsigned m_2c;
	int m_port30;
	unsigned m_34;
	unsigned short m_38;
	unsigned char m_pad3a[2];
	unsigned m_3c;
	unsigned char m_40;
	Bool m_inLobby41;
	unsigned char m_pad42[2];
	void *m_currentGame44;
	unsigned m_48;
	unsigned short m_4c;
	unsigned char m_pad4e[2];
	Transport *m_transport50;
	int m_54;
	unsigned m_58;
	Bool m_isActive5c;
	unsigned char m_5d;
};

// ??0LANAPI@@QAE@XZ present-unmatched
LANAPI::LANAPI()
{
	m_0c = 0;
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
	m_1c = 0;
	m_20 = 0;
	m_24 = 0;
	m_28 = 0;
	m_2c = 0;
	m_port30 = 0x1388 + (getenv("_EA_RTS_HEADLESS") ? 0xafc8 : 0);
	m_34 = 0;
	m_38 = 0;
	m_3c = 0;
	m_40 = 1;
	m_inLobby41 = true;
	m_currentGame44 = 0;
	m_48 = 0;
	m_4c = 0;
	m_54 = -1;
	m_transport50 = 0;
	m_58 = 0;
	m_isActive5c = true;
	m_5d = 0;
	m_transport50 = new Transport;
}
