// Trivial allocator shims that sit inside the 0x006026E0 run of int-zero
// getters (IntZeroGetters.cpp). The object's first dword after the pad is
// read as a pointer at +0x08, two cdecl callback slots live at +0x54 and
// +0x58, and a flag byte at +0x60. Identity is not recovered: names are
// derived from their addresses. No // cl: line so the frameless /O2 shapes
// match, the same defaults the neighbouring zero getters rely on.

void *operator new[](unsigned n);
void operator delete[](void *p);

class Rva006026E0
{
public:
	char m_pad00[0x8];
	void *m_p08;
	char m_pad0c[0x48];
	void *(__cdecl *m_fn54)(unsigned n);
	void *(__cdecl *m_fn58)(void *p);
	char m_pad5c[0x4];
	unsigned char m_flags60;

	void *alloc(unsigned n);
	void free(void *p);
	int get();
};

void *Rva006026E0::alloc(unsigned n)
{
	if (m_fn54)
		return m_fn54(n);
	return operator new[](n);
}

void Rva006026E0::free(void *p)
{
	if (p)
	{
		if (m_fn58)
			m_fn58(p);
		else
			operator delete[](p);
	}
}

int Rva006026E0::get()
{
	if (m_flags60 & 1)
	{
		m_flags60 |= 2;
		return *(int *)((char *)m_p08 + 8);
	}
	return *(int *)((char *)m_p08 + 8);
}
