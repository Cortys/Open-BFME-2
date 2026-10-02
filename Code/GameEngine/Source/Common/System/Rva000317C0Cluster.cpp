// Companion of Rva00031790 in memory_pool.cpp: the release half of the
// lock-holder setter. It reads the held critical section at +0, drops the use
// count at +0x18 and leaves the section. The class is address-derived because
// the near file's owner is likewise unproven; LeaveCriticalSection reaches this
// unit through the same dllimport IAT slot as the neighbours.
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);

class Rva000317C0
{
public:
	void *m_0000;
	void rva000317c0();
};

void Rva000317C0::rva000317c0()
{
	char *held = (char *)m_0000;
	if (held != 0)
	{
		int count = *(volatile int *)(held + 0x18);
		*(volatile int *)(held + 0x18) = count - 1;
		LeaveCriticalSection(held);
	}
}
