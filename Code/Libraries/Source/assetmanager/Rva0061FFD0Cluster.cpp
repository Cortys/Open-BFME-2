// Try-lock/backoff helper that sits after the asset-manager bodies. The
// object's critical section is at +0x68; the guard spins on the DX8 try-lock
// and thread assert (0x0011F600 / 0x00120F50 / 0x0011F520, all rowed), leaves
// and re-enters the section, and releases the DX8 lock once per acquired
// count. The wait between the leave and re-enter is kernel32 Sleep(1). Names
// are address-derived; identity is not recovered. No // cl: line: the
// frameless /O2 shape is the default.

struct CRITICAL_SECTION
{
	unsigned char data[24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);

int bfmeRva0011F600();
bool BFME_DX8_Thread_Assert();
void BFME_DX8_Thread_Lock();

class Rva0061FFD0
{
public:
	char m_pad00[0x68];
	CRITICAL_SECTION m_cs;
	void rva0061FFD0();
};

void Rva0061FFD0::rva0061FFD0()
{
	int count = 0;

	if ((char)bfmeRva0011F600() != 0)
	{
		do
		{
			++count;
		} while (BFME_DX8_Thread_Assert() == 0);
	}

	LeaveCriticalSection(&m_cs);
	Sleep(1);
	EnterCriticalSection(&m_cs);

	while (count != 0)
	{
		BFME_DX8_Thread_Lock();
		--count;
	}
}
