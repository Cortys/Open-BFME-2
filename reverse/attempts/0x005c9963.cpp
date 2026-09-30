// ?rva005C9963@Rva005C9963@@QAEXPAURva005C9963Functor@@@Z
// partial score=0.9 date=2026-09-30
// ?rva005C9963@Rva005C9963@@QAEXPAURva005C9963Functor@@@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva005C9963@Rva005C9963@@QAEXPAURva005C9963Functor@@@Z at 0x005C9963 112B: indexed array visit via functor callback.
// Evidence: array begin/end at +0/+4 with count sar 2, index at +0xC zeroed under exception-safe guard, functor is plain 3-dword callback struct built by caller 0x005C9A64, guard vtable g_00BFB1CC, unblocks 0x005C9A64.

extern const void *const g_00BFB1CC[];

struct Rva005C9963Element
{
	void apply(int arg1, int arg2);
};

struct Rva005C9963Functor
{
	void (Rva005C9963Element::*callback)(int arg1, int arg2);
	int arg1;
	int arg2;
};

struct Rva005C9963Guard
{
	const void *vptr;
	int saved;
	int *addr;
	Rva005C9963Guard(int *a)
	{
		vptr = g_00BFB1CC;
		addr = a;
		saved = *a;
	}
	~Rva005C9963Guard()
	{
		*addr = saved;
	}
};

class Rva005C9963
{
public:
	void rva005C9963(Rva005C9963Functor *functor);
private:
	void **m_arrayBegin; // +0
	void **m_arrayEnd; // +4
	unsigned char m_pad08[4]; // +8
	int m_index; // +0C
};

// ?rva005C9963@Rva005C9963@@QAEXPAURva005C9963Functor@@@Z present-unmatched
void Rva005C9963::rva005C9963(Rva005C9963Functor *functor)
{
	Rva005C9963Guard guard(&m_index);
	m_index = 0;
	int count = ((char *)m_arrayEnd - (char *)m_arrayBegin) >> 2;
	if (count != 0)
	{
		Rva005C9963Functor *f = functor;
		do
		{
			int i = m_index;
			m_index = i + 1;
			Rva005C9963Element *elem = (Rva005C9963Element *)m_arrayBegin[i];
			(elem->*f->callback)(f->arg1, f->arg2);
		} while (m_index < (((char *)m_arrayEnd - (char *)m_arrayBegin) >> 2));
	}
}
