// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva001DC57C@Rva001DC57C@@QAEXPAV?$list@HV?$allocator@H@_STL@@@_STL@@@Z @0x001DC57C 112B.
// Chain after 0x001DC1B3: guarded copy of four Rva001DC0EC lists at
// +0x24/+0x28/+0x2C/+0x30 into dest list with critical section at +0x38.
// Evidence: caller 0x0035D20C and rowed callee 0x001DC1B3. Honest address name.
#include <list>

struct CRITICAL_SECTION
{
	unsigned char m_data[0x1c];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(
	CRITICAL_SECTION *lock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(
	CRITICAL_SECTION *lock);

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

class Rva001DC0EC
{
public:
	void rva001DC1B3(_STL::list<int, _STL::allocator<int> > *dest);
};

class Rva001DC57C
{
public:
	void rva001DC57C(_STL::list<int, _STL::allocator<int> > *dest);
private:
	unsigned char m_pad00[0x24];
	Rva001DC0EC *m_24;
	Rva001DC0EC *m_28;
	Rva001DC0EC *m_2C;
	Rva001DC0EC *m_30;
	unsigned char m_pad34[4];
	CRITICAL_SECTION m_cs;
};

void Rva001DC57C::rva001DC57C(_STL::list<int, _STL::allocator<int> > *dest)
{
	CriticalSectionLock lock((int)&m_cs);
	if (m_24 != 0)
		m_24->rva001DC1B3(dest);
	if (m_28 != 0)
		m_28->rva001DC1B3(dest);
	if (m_2C != 0)
		m_2C->rva001DC1B3(dest);
	if (m_30 != 0)
		m_30->rva001DC1B3(dest);
}
