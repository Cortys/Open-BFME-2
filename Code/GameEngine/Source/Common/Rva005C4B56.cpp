// cl: /O1 /MD
// ?rva005C4B56@Rva005C4B56@@QAEXHHH@Z @0x005C4B56 64B
// Honest address-derived placeholder: method rva005C4B56 in new opaque class
// Rva005C4B56. Unlock lane: landing it makes 0x005C4CC1 and 0x005C4CD4 ready
// plus 0x005C4C69 and 0x005C4C95 waiting on it and 0x00210E5B. Calls virtual
// slot 0x44 twice for bools and slot 0x48 once with bool bool int. Flags at
// +0xB8 via or with set mask and and with not clear mask. Callers share
// +0xAC +0xB0 +0xB8 layout. Prev 0x005C4B1B dtor and next 0x005C4D2F deleting
// dtor in OpaqueSingleInheritanceDtors.cpp. _ReadWriteBarrier between or and
// and stops MSVC folding two flag updates into one load-store with no bytes.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva005C4CC1Sub
{
public:
	char m_pad[0x3C];
	int m_val3C; // +0x3C
};

class Rva005C4B56
{
public:
	virtual ~Rva005C4B56();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual void s16();
	virtual bool s17();
	virtual void s18(bool a, bool b, int c);
	void rva005C4B56(int setBits, int clearBits, int val);
	void rva005C4CC1();
private:
	char m_padAC[0xAC - 4];
	Rva005C4CC1Sub *m_subAC; // +0xAC
	char m_padB8[0xB8 - 0xAC - 4];
	int m_flags; // +0xB8
};

void Rva005C4B56::rva005C4B56(int setBits, int clearBits, int val)
{
	bool first = s17();
	m_flags |= setBits;
	_ReadWriteBarrier();
	m_flags &= ~clearBits;
	bool second = s17();
	s18(first, second, val);
}

void Rva005C4B56::rva005C4CC1()
{
	rva005C4B56(2, 0, m_subAC->m_val3C);
}
