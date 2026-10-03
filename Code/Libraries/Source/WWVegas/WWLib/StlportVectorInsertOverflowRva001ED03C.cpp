// cl: /G7 /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@VRva001ED03C@@V?$allocator@VRva001ED03C@@@_STL@@@_STL@@IAEXPAVRva001ED03C@@ABV3@ABU__false_type@2@I_N@Z @0x001ED476 183B.
// STLport vector<Rva001ED03C> growth path; same 183B shape as rowed 0x001ED13A for 36-byte element.
// Evidence: callees rowed 0x005DFB2C 0x001ED21E 0x001ED1F1 0x001ED244 0x001ED3A2; caller 0x001ED576; imul 0x24 stride.
#define _STLP_NO_EXCEPTIONS 1
#include <vector>

class Rva001ED03C
{
	char m_body[0x24];
public:
	Rva001ED03C(const Rva001ED03C &that);
	~Rva001ED03C();
};

namespace _STL
{
template <> void _Construct<Rva001ED03C, Rva001ED03C>(Rva001ED03C *, const Rva001ED03C &);
}

template void _STL::vector<Rva001ED03C>::_M_insert_overflow(
    Rva001ED03C *, const Rva001ED03C &, const _STL::__false_type &, unsigned int, bool);
// ?push_back@?$vector@VRva001ED03C@@V?$allocator@VRva001ED03C@@@_STL@@@_STL@@QAEXABVRva001ED03C@@@Z @0x001ED549 55B.
// STLport vector<Rva001ED03C>::push_back over growth path 0x001ED476.
// Evidence: callees rowed 0x001ED1F1 0x001ED476; caller 0x001ED5F3; add 0x24 stride.
template void _STL::vector<Rva001ED03C>::push_back(const Rva001ED03C &);
