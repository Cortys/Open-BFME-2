// cl: /O1 /G7 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@UBfmePod24@@V?$allocator@UBfmePod24@@@_STL@@@_STL@@IAEXPAUBfmePod24@@ABU3@ABU__false_type@2@I_N@Z @0x000BCFF9 189B via G7 imul
// Evidence: pin ?_M_insert_overflow Pod24 @0x000BCFF9; caller push_back in stlport_pod_vector_bodies.cpp;
// callees allocate 0x00395944 __uninitialized_copy 0x000B4153 _Construct 0x000B413D fill_n 0x000B4179 free 0x00030830 all rowed;
// retail imul 0x18 needs /G7 (pod40 precedent), default /O1 strength-reduces to lea.
#include <vector>
struct BfmePod24 { int a[6]; };
inline bool operator==(const BfmePod24 &x, const BfmePod24 &y) { return x.a[0] == y.a[0]; }
inline bool operator<(const BfmePod24 &x, const BfmePod24 &y) { return x.a[0] < y.a[0]; }
template class _STL::vector<BfmePod24, _STL::allocator<BfmePod24> >;
