// ?Rva003F8F2BParse@@YAXPAX0@Z
// partial score=0.95 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /O1 /EHs-c- /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?Rva003F8F2BParse@@YAXPAX0@Z @0x003F8F2B 104B.
// SessionTask::ParseINI factory: null-checks INI and holder, new 0x20 Rva003F8ED6
// from holder+4, initFromINI with table 0x00C373D8, then holder->rva.
// Evidence: chain lane; calls just-landed 0x003F8EA2 plus rowed new 0x0002FDA0
// plus initFromINI 0x0002DE78 plus rva003F7C0C 0x003F7C0C; throw string
// "Invalid data in SessionTask::ParseINI" plus INIException 0x0002F681.
#include <vector>

#include "ascii_string.h"

struct BfmeE16 { float x, y, z, w; };

struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);

struct TargetRefHolder1C
{
	TargetRefHolder1C() : m_ptr(0) {}
	~TargetRefHolder1C() { if (m_ptr) ReleaseTreeHintRef00217D4C((TargetRef00217D4C *)m_ptr); }
	void *m_ptr;
};

struct __declspec(novtable) Base003F8ED6
{
	virtual ~Base003F8ED6() {}
	Base003F8ED6(int x) : m_04(x) {}
	int m_04;
};

class Rva003F8ED6 : public Base003F8ED6
{
public:
	Rva003F8ED6(int x);
	virtual ~Rva003F8ED6();
	int m_08;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_0C;
	AsciiString m_18;
	TargetRefHolder1C m_1C;
};

void *operator new(unsigned int size) throw();
void operator delete(void *p);

struct FieldParse;
extern const struct FieldParse g_00C373D8[];

class INI
{
public:
	void initFromINI(void *what, const struct FieldParse *table);
};

class Rva003F7C0C
{
public:
	void rva003F7C0C(void *v);
	int m_00;
	int m_04;
	char m_08[12];
	void *m_14;
};

class INIException
{
public:
	char *mFailureMessage;
	int mErrorCode;
	INIException(int argCount, const char *format, ...);
	INIException(const INIException &that);
	~INIException();
};

// ?Rva003F8F2BParse@@YAXPAX0@Z present-unmatched
void __cdecl Rva003F8F2BParse(void *ini_, void *holder_)
{
	Rva003F7C0C *holder = (Rva003F7C0C *)holder_;
	INI *ini = (INI *)ini_;
	if (ini == 0 || holder == 0)
		throw INIException(3, "Invalid data in SessionTask::ParseINI");
	Rva003F8ED6 *obj = new Rva003F8ED6(holder->m_04);
	ini->initFromINI(obj, g_00C373D8);
	holder->rva003F7C0C(obj);
}
