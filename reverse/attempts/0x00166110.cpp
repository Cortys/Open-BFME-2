// ??0BfmeRva00166110@@QAE@ABV0@@Z
// partial score=0.8 date=2026-10-03
// cl: /O2 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// STLport 4.5.3 vector<BfmePod36> copy constructor, retail 0x00166110 (175B).
// Near miss: the no-exceptions /O2 instantiation inlines the false_type
// __uninitialized_copy loop with the 33-byte memberwise element copy (8 dwords
// + 1 char, matching retail's copy order) but allocates registers differently
// (this in edi vs retail's ebx) and comes out 142B against retail's 175B.
#include <vector>

struct BfmePod36 {
    int a0, a1, a2, a3, a4, a5, a6, a7;
    char b;
    BfmePod36() {}
    BfmePod36(const BfmePod36 &o)
        : a0(o.a0), a1(o.a1), a2(o.a2), a3(o.a3),
          a4(o.a4), a5(o.a5), a6(o.a6), a7(o.a7), b(o.b) {}
};

template class _STL::vector<BfmePod36, _STL::allocator<BfmePod36 > >;
