// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva001DBFEE@AudioManager@@QAE_NXZ @0x001DBFEE 46B
//
// Guarded AudioManager predicate: EnterCriticalSection on the lock at +0x38,
// delegate to Rva001DBDA4::rva001DBD83 through the pointer at +0x24 (true when
// absent), LeaveCriticalSection, return the result. Identity from caller
// 0x001DC07E which loads TheAudio into ecx for both calls; callee row
// ?rva001DBD83@Rva001DBDA4@@QBE_NXZ; offsets from retail lea/mov.
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

class Rva001DBDA4
{
public:
	bool rva001DBD83() const;
	void rva001DBE17();
	void rva001DBE51();
};

struct AudioLock
{
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
};

class AudioManager
{
public:
	bool rva001DBFEE();
	void rva001DBE6E();
	void rva001DBFD1();
private:
	char m_pad00[0x24];
	Rva001DBDA4 *m_24;
	Rva001DBDA4 *m_28;
	Rva001DBDA4 *m_2C;
	Rva001DBDA4 *m_30;
	char m_pad34[0x4];
	AudioLock m_38;
	char m_pad50[0x19];
	bool m_69;
};

bool AudioManager::rva001DBFEE()
{
	EnterCriticalSection(&m_38);
	bool b;
	if (m_24)
		b = m_24->rva001DBD83();
	else
		b = true;
	LeaveCriticalSection(&m_38);
	return b;
}

// Retail 0x001DBE6E 72B: AudioManager slot 9 release of four Rva001DBDA4 lists plus clear byte at +0x69.
// Evidence: vtable 0x007DBC30 slot 9 of AudioManager ctor; rowed rva001DBE17 callee; offsets +0x24 +0x28 +0x30 +0x2C +0x69; neighbours 0x001DBE51 and 0x001DBFEE.
void AudioManager::rva001DBE6E()
{
	if (m_24)
	{
		m_24->rva001DBE17();
		m_24 = 0;
	}
	if (m_28)
	{
		m_28->rva001DBE17();
		m_28 = 0;
	}
	if (m_30)
	{
		m_30->rva001DBE17();
		m_30 = 0;
	}
	if (m_2C)
	{
		m_2C->rva001DBE17();
		m_2C = 0;
	}
	m_69 = false;
}

// Retail 0x001DBFD1 29B: AudioManager slot 12 apply rva001DBE51 to lists at +0x30 then +0x2C.
// Evidence: vtable 0x007DBC30 slot 12 of AudioManager ctor; rowed rva001DBE51 callee; offsets +0x30 +0x2C.
void AudioManager::rva001DBFD1()
{
	if (m_30)
		m_30->rva001DBE51();
	if (m_2C)
		m_2C->rva001DBE51();
}
