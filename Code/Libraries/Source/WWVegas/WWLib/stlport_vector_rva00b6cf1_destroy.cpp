// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??$_Destroy@PAURva00B6CF1@@@_STL@@YAXPAURva00B6CF1@@0@Z, retail 0x000BDCD6, 25 bytes.
// Range destroy for the 8-byte Rva00B6CF1 element (two StringBase releases
// at +0/+4, dtor at 0xB6CF1): strides 8 calling that dtor. Same 25B loop
// shape as rowed Rva0048130E _Destroy at 0x00481595 (53B twin dtor at
// 0x48130E, QAE non-virtual, no vptr store). The existing UAE pin at
// 0xB6CF1 carries the wrong virtualness (body stores no vptr); the QAE
// twin pin added beside this TU corrects it per the ICF-twin plus call
// site (BDCD6 calls B6CF1 as 481595 calls 48130E). Emitted via explicit
// _Destroy instantiation over an opaque 8-byte view declaring the twin
// dtor; callers at 0xC03F2/0xC05D6/0xC0647/0xC0804/0xC0986 unblock C03D8.
#include <vector>

#include "ascii_string.h"

struct Rva00B6CF1
{
	~Rva00B6CF1();
	Rva00B6CF1 &operator=(const Rva00B6CF1 &o);

	AsciiString m_s0;
	AsciiString m_s1;
};

template void _STL::_Destroy<Rva00B6CF1 *>(Rva00B6CF1 *, Rva00B6CF1 *);

template _STL::vector<Rva00B6CF1>::~vector();

Rva00B6CF1 &Rva00B6CF1::operator=(const Rva00B6CF1 &o)
{
	m_s0 = o.m_s0;
	m_s1 = o.m_s1;
	return *this;
}
