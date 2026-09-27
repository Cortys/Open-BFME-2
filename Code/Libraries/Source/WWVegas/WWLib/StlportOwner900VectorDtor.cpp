// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// Target vector<Owner900> dtor at 0x004CB996/63 and _M_clear at 0x004CB9D5/30 via rowed _Destroy 0x004CB97E and _free 0x30830.
#include "OwnedRecord900.h"
template class _STL::vector<BfmeRecordOwner900, _STL::allocator<BfmeRecordOwner900> >;
