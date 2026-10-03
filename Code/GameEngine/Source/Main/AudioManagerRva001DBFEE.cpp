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
private:
	char m_pad00[0x24];
	Rva001DBDA4 *m_24;
	char m_pad28[0x10];
	AudioLock m_38;
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
