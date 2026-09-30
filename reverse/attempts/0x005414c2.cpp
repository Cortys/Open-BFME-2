// ??$lower_bound@PAUBfmePod28@@U1@@_STL@@YAPAUBfmePod28@@PAU1@0ABU1@@Z
// partial score=0.75 date=2026-09-30
// ??$lower_bound@PAUBfmePod28@@U1@@_STL@@YAPAUBfmePod28@@PAU1@0ABU1@@Z
// partial score=0.75 date=2026-09-30
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ??$lower_bound@PAUBfmePod28@@U1@@_STL@@YAPAUBfmePod28@@PAU1@0ABU1@@Z @0x005414C2 (35B):
// lower_bound over BfmePod28 pointers; builds less<> plus null distance tag
// feeding rowed __lower_bound 0x005413B0. Caller 0x005415EE.
// Evidence: chain lane, callee just landed.
#include <vector>
#include <algorithm>
struct BfmePod28 { int a[7]; __forceinline bool operator<(const BfmePod28 &o) const { return a[0] < o.a[0]; } };
template class _STL::vector<BfmePod28, _STL::allocator<BfmePod28> >;
template BfmePod28 *_STL::__lower_bound<BfmePod28 *, BfmePod28, _STL::less<BfmePod28>, int>(BfmePod28 *, BfmePod28 *, const BfmePod28 &, _STL::less<BfmePod28>, int *);
// NOTE: the worker above is already rowed from stlport_vector_pod28_allocate_copy.cpp; transfer the wrapper only.
// ??$lower_bound@PAUBfmePod28@@U1@@_STL@@YAPAUBfmePod28@@PAU1@0ABU1@@Z present-unmatched
namespace _STL {
template <>
BfmePod28 *lower_bound<BfmePod28 *, BfmePod28>(BfmePod28 *first, BfmePod28 *last, const BfmePod28 &val)
{
	less<BfmePod28> comp = less<BfmePod28>();
	return __lower_bound(first, last, val, comp, (int *)0);
}
}
