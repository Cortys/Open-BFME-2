// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
//
// hash_map<int, list<BfmePod264>>: its pair copy (0x0028A02F) calls the rowed list<BfmePod264> copy constructor (stlport_pod_list_bodies.cpp, whose bfmelist layout shim this unit shares), and its node constructor (0x0028A096) zeroes the next link and places the pair at +4.
// The key is a 32-bit int-hashed type; int stands in, as in
// stlport_pod_hash_bodies.cpp, whose whole-class instantiation this follows.

#include <hash_map>
#include <list>

struct BfmePod264 { int a[66]; };
inline bool operator==(const BfmePod264 &x, const BfmePod264 &y) { return x.a[0] == y.a[0]; }
inline bool operator<(const BfmePod264 &x, const BfmePod264 &y) { return x.a[0] < y.a[0]; }

template class _STL::hash_map<int, _STL::list<BfmePod264>, _STL::hash<int>, _STL::equal_to<int>, _STL::allocator<_STL::pair<const int, _STL::list<BfmePod264> > > >;
