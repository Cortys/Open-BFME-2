// ?Rva002213D9Init@@YAXXZ
// partial score=0.93 date=2026-09-29
// ?Rva002213D9Init@@YAXXZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?Rva002213D9Init@@YAXXZ, retail 0x002213D9 69B.
// Function-local static initializer for map<int,void*>: guard test/or,
// map ctor at 0x0033C432, atexit registration. Byte-exact via MSVC static
// init with /EHsc; callees resolve through rows.
#include <map>

// ?Rva002213D9Init@@YAXXZ present-unmatched
void Rva002213D9Init()
{
    static _STL::map<int, void *, _STL::less<int>, _STL::allocator<_STL::pair<const int, void *> > > s_map;
}
