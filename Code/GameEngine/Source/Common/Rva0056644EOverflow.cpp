// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?_M_insert_overflow@?$vector@URva0056644EElement@@V?$allocator@URva0056644EElement@@@_STL@@@_STL@@IAEXPAURva0056644EElement@@ABU3@ABU__false_type@2@I_N@Z retail 0x0056644E 180B
// Evidence: chain lane; calls allocate 0x002226BE plus copy 0x0052C9AD plus Construct 0x0052C404 plus fill 0x0056574B plus scrap 0x0056612F; caller push_back 0x00566575 55B; sar 4 stride 0x10; prev Pod40 same-shape push_back plus next Rva00566AB7 same flags.
#include <vector>

struct Rva0056644EElement {
	char opaque[16];
	Rva0056644EElement(const Rva0056644EElement &);
	Rva0056644EElement &operator=(const Rva0056644EElement &);
	~Rva0056644EElement();
};

namespace _STL {
template <> void _Construct<Rva0056644EElement, Rva0056644EElement>(
	Rva0056644EElement *, const Rva0056644EElement &);
}

template void _STL::vector<Rva0056644EElement>::_M_insert_overflow(
	Rva0056644EElement *, const Rva0056644EElement &,
	const _STL::__false_type &, unsigned int, bool);
