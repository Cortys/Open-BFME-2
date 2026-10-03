// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva001DC07E@Rva001DC07E@@QAEXXZ @0x001DC07E 73B: wait loop on TheAudio ready with WindowManager Display setFPMode Sleep. Evidence: caller at 0x001DC618; callees rowed rva001DBFEE setFPMode plus pins.
class AudioManager
{
public:
	bool rva001DBFEE();
};

class GameWindowManager
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void unk28();
};

class Display
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void unk30();
};

extern GameWindowManager *TheWindowManager;
extern AudioManager *TheAudio;
extern Display *TheDisplay;
void __cdecl setFPMode();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);

struct CRITICAL_SECTION
{
	unsigned char m_data[0x1c];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(
	CRITICAL_SECTION *lock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(
	CRITICAL_SECTION *lock);

#pragma optimize("t", on)
class CriticalSectionLock
{
public:
	explicit CriticalSectionLock(int lock) : m_lock(lock)
	{
		EnterCriticalSection((CRITICAL_SECTION *)m_lock);
	}
	~CriticalSectionLock()
	{
		LeaveCriticalSection((CRITICAL_SECTION *)m_lock);
	}

	int m_lock;
};
#pragma optimize("", on)

class Rva001DC07E
{
public:
	void rva001DC07E();
	void rva001DC5EC();
private:
	unsigned char m_pad00[0x38];
	CRITICAL_SECTION m_cs;
	unsigned char m_pad54[0x10];
	unsigned long m_64;
	unsigned char m_68;
};

void Rva001DC07E::rva001DC07E()
{
	while (!TheAudio->rva001DBFEE()) {
		TheWindowManager->unk28();
		if (TheAudio->rva001DBFEE())
			continue;
		TheDisplay->unk30();
		setFPMode();
		Sleep(m_64);
	}
}

// ?rva001DC5EC@Rva001DC07E@@QAEXXZ @0x001DC5EC 74B: guarded wait-loop call under lock at +0x38 with reentrancy flag at +0x68. Evidence: same this as callee 0x001DC07E; lock offset matches neighbour 0x001DC57C.
void Rva001DC07E::rva001DC5EC()
{
	CriticalSectionLock lock((int)&m_cs);
	if (m_68 == 0) {
		m_68 = 1;
		rva001DC07E();
		m_68 = 0;
	}
}
