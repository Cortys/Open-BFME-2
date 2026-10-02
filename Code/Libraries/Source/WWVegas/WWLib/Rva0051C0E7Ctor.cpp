// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /EHsc /arch:SSE /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// ??0Rva0051C0E7@@QAE@XZ @0x0051C0E7 82B: default ctor, two ints + AsciiString[8] via ehvec plus 8B tail memset; evidence callees 0x0048BA39 clear/dtor 0x00326BE6 UnicodeString/AsciiString ctor 0x00629512 ehvec 0x006291AE memset caller 0x005202C8
#include "ascii_string.h"

void *__cdecl ji_006291ae(void *dest, int val, unsigned int count) throw();
#pragma comment(linker, "/alternatename:?ji_006291ae@@YAPAXPAXHI@Z=?ji_006291ae@@YAXXZ")

class EmptyBase0051C0E7 {
public:
	EmptyBase0051C0E7() : m_00(0) {}
	~EmptyBase0051C0E7();
	int m_00;
};

class Rva0051C0E7 : public EmptyBase0051C0E7 {
	int m_04;
	AsciiString m_08[8];
	char m_28[8];
public:
	Rva0051C0E7();
};

Rva0051C0E7::Rva0051C0E7() : m_04(0)
{
	ji_006291ae(m_28, 0, 8);
}
