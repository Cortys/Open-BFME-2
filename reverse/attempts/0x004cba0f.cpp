// ?_M_insert_overflow@?$vector@UBfmePod900@@V?$allocator@UBfmePod900@@@_STL@@@_STL@@IAEXPAUBfmePod900@@ABU3@ABU__false_type@2@I_N@Z
// partial score=0.99 date=2026-09-30
// ?_M_insert_overflow@?$vector@UBfmePod900@@V?$allocator@UBfmePod900@@@_STL@@@_STL@@IAEXPAUBfmePod900@@ABU3@ABU__false_type@2@I_N@Z
// partial score=0.99 date=2026-09-30
// cl: /G7 /arch:SSE /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?_M_insert_overflow@?$vector@UBfmePod900@@V?$allocator@UBfmePod900@@@_STL@@@_STL@@IAEXPAUBfmePod900@@ABU3@ABU__false_type@2@I_N@Z,
// retail 0x004CBA0F, 191 bytes. Dedicated TU.
//
// STLport 4.5.3 vector<BfmePod900>::_M_insert_overflow, the growth path of the
// push_back matched in stlport_pod_large_bodies.cpp. Follows the pod40
// precedent (stlport_vector_pod40_overflow.cpp, same U-prefix shape): /G7 for
// the imul homing, virtual dtor so _M_clear stays out-of-line, _Construct
// declared-only, explicit member instantiation. Element is 900 bytes
// (vptr + 224 ints) to match the 0x384 stride in retail.
#define _STLP_NO_EXCEPTIONS 1
#include <vector>

struct BfmePod900
{
	virtual ~BfmePod900();
	int a[224];
};
inline bool operator==(const BfmePod900 &x, const BfmePod900 &y) { return x.a[0] == y.a[0]; }
inline bool operator<(const BfmePod900 &x, const BfmePod900 &y) { return x.a[0] < y.a[0]; }

namespace _STL
{
template <> void _Construct<BfmePod900, BfmePod900>(BfmePod900 *, const BfmePod900 &);
}

template void _STL::vector<BfmePod900>::_M_insert_overflow(
	BfmePod900 *,
	const BfmePod900 &,
	const _STL::__false_type &,
	unsigned int,
	bool);
