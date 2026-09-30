// cl: /O1 /G7 /EHsc /arch:SSE /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??$__unguarded_partition@U?$_Deque_iterator@UBfmeE12@@U?$_Nonconst_traits@UBfmeE12@@@_STL@@@_STL@@UBfmeE12@@UBfmeE12Cmp00422291@@@_STL@@YA?AU?$_Deque_iterator@UBfmeE12@@U?$_Nonconst_traits@UBfmeE12@@@_STL@@@0@U10@0UBfmeE12@@UBfmeE12Cmp00422291@@@Z @0x00422217 (122B):
// __unguarded_partition over deque<BfmeE12> iterators with BfmeE12 pivot by
// value plus comparator; retail compares the float at +4 with comiss,
// calls _M_decrement, _M_increment, iterator operator< and BfmeE12 swap.
// Evidence: unlock lane, all callees rowed, caller 0x00424AE0, neighbours
// share // cl: with deque_e12_sort.
//
// ??$__push_heap@U?$_Deque_iterator@UBfmeE12@@U?$_Nonconst_traits@UBfmeE12@@@_STL@@@_STL@@HUBfmeE12@@UBfmeE12Cmp00422291@@@_STL@@YAXU?$_Deque_iterator@UBfmeE12@@U?$_Nonconst_traits@UBfmeE12@@@_STL@@@0@HHUBfmeE12@@UBfmeE12Cmp00422291@@@Z @0x004222F9 (126B):
// __push_heap sift-up over deque<BfmeE12>; parent (hole-1)/2, comiss on y,
// operator+ rowed, 12B shifts, final store. Caller 0x00422C5A.
// Evidence: unlock lane, all callees rowed, unblocks 0x00422B98.
#include <algorithm>
#include <deque>
struct BfmeE12 { float x, y, z; };
struct BfmeE12Cmp00422291
{
	__forceinline bool operator()(const BfmeE12 &a, const BfmeE12 &b) const { return a.y < b.y; }
};
template _STL::_Deque_iterator<BfmeE12, _STL::_Nonconst_traits<BfmeE12> > _STL::__unguarded_partition<_STL::_Deque_iterator<BfmeE12, _STL::_Nonconst_traits<BfmeE12> >, BfmeE12, BfmeE12Cmp00422291>(_STL::_Deque_iterator<BfmeE12, _STL::_Nonconst_traits<BfmeE12> >, _STL::_Deque_iterator<BfmeE12, _STL::_Nonconst_traits<BfmeE12> >, BfmeE12, BfmeE12Cmp00422291);
template void _STL::__push_heap<_STL::_Deque_iterator<BfmeE12, _STL::_Nonconst_traits<BfmeE12> >, int, BfmeE12, BfmeE12Cmp00422291>(_STL::_Deque_iterator<BfmeE12, _STL::_Nonconst_traits<BfmeE12> >, int, int, BfmeE12, BfmeE12Cmp00422291);
