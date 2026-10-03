// ?insert@?$vector@PAXV?$allocator@PAX@_STL@@@_STL@@QAEPAPAXPAPAX@Z
// partial score=0.95 date=2026-10-03
// cl: /Od /Ob1 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?insert@?$vector@PAXV?$allocator@PAX@_STL@@@_STL@@QAEPAPAXPAPAX@Z retail
// 0x00029350 (38B). The header's `iterator insert(iterator __position)
// { return insert(__position, _Tp()); }` overload. This explicit instantiation
// reproduces retail's instruction sequence exactly, but MSVC 7.1 allocates a
// 0x6C frame where retail has 0x70, so the saved-this slot differs by 4. The
// two-argument insert it calls is unrowed and pins at 0x000291D0.
#include <vector>

template class _STL::vector<void *, _STL::allocator<void *> >;
