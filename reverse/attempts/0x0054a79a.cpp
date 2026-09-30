// ?Rva0054A79APushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@UComp0054A0D8@@@Z
// partial score=0.97 date=2026-09-30
// ?Rva0054A79APushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@UComp0054A0D8@@@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// ?Rva0054A79APushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@UComp0054A0D8@@@Z @0x0054A79A (146B):
// Deque push_heap sift-up with Comp0054A0D8 comparator (twin of free Cmp
// 0x00549DF2, lea ecx shape). Same parent/hole loop as sibling
// Rva0054A67BSiftUp but while comp(parent,value) instead of float compare.
// Rowed deque+E8 operator+ at 0x0054A202 four times. Caller 0x0054AD12.
// Evidence: unlock lane, all callees rowed, unblocks 0x0054AC40.
#include <deque>
struct BfmeE8 { int a; int b; };
typedef _STL::deque<BfmeE8, _STL::allocator<BfmeE8> >::const_iterator DequeE8CIter;
struct Comp0054A0D8
{
	int m_dummy;
	unsigned char cmp(void *a1, void *a2);
};
// ?Rva0054A79APushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@UComp0054A0D8@@@Z present-unmatched
void __cdecl Rva0054A79APushHeap(DequeE8CIter first, int hole, int top, BfmeE8 value, Comp0054A0D8 comp)
{
	int parent = (hole - 1) / 2;
	while (hole > top && comp.cmp((first + parent)._M_cur, &value)) {
		const_cast<BfmeE8 &>(*(first + hole)) = *(first + parent);
		hole = parent;
		parent = (hole - 1) / 2;
	}
	const_cast<BfmeE8 &>(*(first + hole)) = value;
}
