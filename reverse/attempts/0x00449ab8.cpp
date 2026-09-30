// ??0LANAPI@@QAE@XZ
// partial score=0.81 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHs
// LANAPI::LANAPI @0x00449AB8 193B. Retail unwind map: base (state 0), UnicodeString
// +0x14, AsciiStrings +0x18/+0x1C, then the new Transport guard (state 4);
// /EHs (not /EHsc) is what emits the state-3 store before the extern C getenv.
// The base ctor is out of line at 0x001B4E63 (rowed as baseConstruct): a real
// ctor with a _ReadWriteBarrier before the two zero stores compiles
// byte-identical there, so ??0BFME2NativeNetwork@@QAE@XZ can be pinned there.
// Remaining gap (37 bytes, all one shift): retail keeps or [esi+0x54],-1 after
// the +0x4C word store; cl hoists it right after the getenv select whatever
// the source position, init-list or body, int or unsigned.
extern "C" __declspec(dllimport) char *getenv(const char *name);
void *operator new(unsigned size) throw();
template <class T> class StringBase
{
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};
class AsciiString : public StringBase<char> {};
class UnicodeString : public StringBase<unsigned short> {};
class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork();
	virtual ~BFME2NativeNetwork();
private:
	char m_04;
	int m_08;
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
	LANAPI();
	virtual ~LANAPI();
private:
	int m_0c;
	int m_10;
	UnicodeString m_name;
	AsciiString m_userName;
	AsciiString m_hostName;
	int m_20;
	int m_24;
	int m_28;
	int m_2c;
	int m_actionTimeout;
	int m_34;
	short m_38;
	int m_3c;
	bool m_40;
	bool m_inLobby;
	int m_currentGame;
	int m_48;
	short m_4c;
	Transport *m_transport;
	int m_54;
	int m_58;
	bool m_isActive;
	bool m_5d;
};
LANAPI::LANAPI()
	: m_0c(0), m_10(0), m_20(0), m_24(0), m_28(0), m_2c(0),
	  m_actionTimeout(getenv("_EA_RTS_HEADLESS") ? 50000 : 5000),
	  m_34(0), m_38(0), m_3c(0), m_40(true), m_inLobby(true), m_currentGame(0),
	  m_48(0), m_4c(0), m_transport(0), m_54(-1), m_58(0), m_isActive(true), m_5d(false)
{
	m_transport = new Transport;
}
