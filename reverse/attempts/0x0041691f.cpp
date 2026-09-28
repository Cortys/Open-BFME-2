// ?push_front@?$list@UBfmeStringRecord00415F34@@V?$allocator@UBfmeStringRecord00415F34@@@_STL@@@_STL@@QAEXABUBfmeStringRecord00415F34@@@Z
// partial score=0.92 date=2026-09-28
// ?push_front@?$list@UBfmeStringRecord00415F34@@V?$allocator@UBfmeStringRecord00415F34@@@_STL@@@_STL@@QAEXABUBfmeStringRecord00415F34@@@Z
// partial score=0.92 date=2026-09-28
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <list>
struct BfmeStringRecord00415F34 { unsigned char m_data[24]; };
bool operator==(const BfmeStringRecord00415F34 &a, const BfmeStringRecord00415F34 &b);
bool operator<(const BfmeStringRecord00415F34 &a, const BfmeStringRecord00415F34 &b);
template void _STL::list<BfmeStringRecord00415F34, _STL::allocator<BfmeStringRecord00415F34> >::push_front(const BfmeStringRecord00415F34 &);
