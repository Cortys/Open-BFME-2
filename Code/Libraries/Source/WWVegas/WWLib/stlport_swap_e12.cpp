// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??$swap@UBfmeE12@@@_STL@@YAXAAUBfmeE12@@0@Z at retail 0x004219CD 39 bytes.
// Donor vendor/stlport/stl/_algobase.h swap; callers 0x0051C86D 0x005877D6 0x005D5CF4 0x00422270.
// BfmeE12 names only the 12-byte element size.
#include <deque>
struct BfmeE12 { float x, y, z; };
template void _STL::swap<BfmeE12>(BfmeE12&, BfmeE12&);
