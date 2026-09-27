// ?Rva00030DD0AddRef@@YAHPAURva00030DD0Lock@@@Z @ 0x00030DD0 21B
// Critical-section addref: enters the +0x00 section and increments the +0x18
// refcount, returning the new count. Evidence: IAT EnterCriticalSection at
// 0x00BBA200, CRITICAL_SECTION layout (0x18 bytes) with int at +0x18, callers
// at 0x0003186B 0x00033D6F 0x006C1AAF 0x006C1E4A, counterpart release
// (dec + LeaveCriticalSection) at 0x00030DF0. Honest address-derived name:
// identity unproven from 21 bytes. No // cl: line (defaults match the
// frameless push/call/inc shape, CriticalSectionDeleteWrapper precedent).
struct Rva00030DD0Lock
{
	unsigned char m_cs[0x18];
	int m_ref;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *cs);

int Rva00030DD0AddRef(Rva00030DD0Lock *lock)
{
	EnterCriticalSection(lock);
	return ++lock->m_ref;
}
