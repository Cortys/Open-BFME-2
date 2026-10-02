// ??4?$vector@UBfmeVectorRecord00319C84@@V?$allocator@UBfmeVectorRecord00319C84@@@_STL@@@_STL@@QAEAAV01@ABV01@@Z
// partial score=0.98 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??4?$vector@UBfmeVectorRecord00319C84@@V?$allocator@UBfmeVectorRecord00319C84@@@_STL@@@_STL@@QAEAAV01@ABV01@@Z retail 0x00319BCA 186B: vector record assign via stlport operator equal 188B near miss extra push 0.
// Evidence: calls 0x00319304 allocate_and_copy and 0x00565A60 clear plus rowed copies 0x0031968A 0x00318D75 and pin Destroy; chain from 0x0031968A.
#include "ascii_string.h"
#include <vector>
struct BfmeVectorRecord00319C84 {
    AsciiString text;
    _STL::vector<AsciiString> names;
    BfmeVectorRecord00319C84();
    BfmeVectorRecord00319C84(const BfmeVectorRecord00319C84 &);
};
namespace _STL {
template <> void _Construct<BfmeVectorRecord00319C84, BfmeVectorRecord00319C84>(BfmeVectorRecord00319C84 *, const BfmeVectorRecord00319C84 &);
}
template _STL::vector<BfmeVectorRecord00319C84, _STL::allocator<BfmeVectorRecord00319C84> > &_STL::vector<BfmeVectorRecord00319C84, _STL::allocator<BfmeVectorRecord00319C84> >::operator=(const _STL::vector<BfmeVectorRecord00319C84, _STL::allocator<BfmeVectorRecord00319C84> > &);
