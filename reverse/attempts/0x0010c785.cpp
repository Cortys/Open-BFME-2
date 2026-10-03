// ??1Rva0010C785@@UAE@XZ
// partial score=0.88 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHs /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc /Ireference/shims/bfmelist
// ??1Rva0010C785@@UAE@XZ retail 0x0010C785 133 bytes.
// Virtual dtor with EH prolog calling three same-this cleanups then releasing
// ref member at +0x20 and deleting member at +0x24C plus UnicodeString at +0x24.
// Evidence: pin ??1Rva0010C785@@UAE@XZ plus caller deleting dtor 0x0010C828.
#include "unicode_string.h"

class BfmeThing928F
{
public:
	void bfmeOne928F();
	void bfmeTwo928F();
};

class Rva00109DCF
{
public:
	void rva00109DCF();
};

class Rva00109BEB
{
public:
	virtual ~Rva00109BEB();
};

struct Rva0010C785Ref
{
	virtual void Release();
	int m_ref;
};

extern const void *const g_00BCF9C4[];
extern const void *const g_00BCF994[];

class __declspec(novtable) Rva0010C785
{
public:
	virtual ~Rva0010C785();
private:
	char m_pad04[0x20 - 4];
	Rva0010C785Ref *m_20;
	UnicodeString m_24;
	char m_padAfter24[0x24C - 0x24 - 4];
	Rva00109BEB *m_24C;
};

extern void __cdecl operator delete(void *p);

// ??1Rva0010C785@@UAE@XZ present-unmatched
Rva0010C785::~Rva0010C785()
{
	*(const void **)this = g_00BCF9C4;
	((BfmeThing928F *)this)->bfmeOne928F();
	((BfmeThing928F *)this)->bfmeTwo928F();
	((Rva00109DCF *)this)->rva00109DCF();
	Rva0010C785Ref *p20 = m_20;
	if (p20 != 0)
	{
		if (--p20->m_ref == 0)
			p20->Release();
		m_20 = 0;
	}
	Rva00109BEB *p24C = m_24C;
	if (p24C != 0)
	{
		p24C->~Rva00109BEB();
		::operator delete(p24C);
	}
	m_24C = 0;
	m_24.debugIgnoreLeaks();
	*(const void **)this = g_00BCF994;
}
