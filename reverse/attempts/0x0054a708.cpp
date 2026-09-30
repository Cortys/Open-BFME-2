// ?Rva0054A708PushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@URva00549DCB@@@Z
// partial score=0.98 date=2026-09-30
// ?Rva0054A708PushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@URva00549DCB@@@Z
// partial score=0.98 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// ?Rva0054A708PushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@URva00549DCB@@@Z @0x0054A708 (146B):
// Deque heap sift-up over 8-byte elements with WORD comparator 0x00549DCB.
// Same shape as sibling Rva0054A67BSiftUp (141B float-key sift-up) but the
// float compare is a comp(parent.ptr,value.ptr) call; rowed deque+E8
// operator+ at 0x0054A202 four times. Caller 0x0054AB61 adjust-heap.
// Evidence: unlock lane, all callees rowed, unblocks 0x0054AB61.
#include <deque>
struct Bar00549DCB {
	char pad[0x5da];
	unsigned short key;
};
struct Foo00549DCB {
	int unk0;
	Bar00549DCB *bar;
};
struct Rva00549DCB {
	bool rva00549DCB(Foo00549DCB * const &a, Foo00549DCB * const &b) const;
};
struct BfmeE8 { Foo00549DCB *ptr; int b; };
typedef _STL::deque<BfmeE8, _STL::allocator<BfmeE8> >::const_iterator DequeE8CIter;
// ?Rva0054A708PushHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@URva00549DCB@@@Z present-unmatched
void __cdecl Rva0054A708PushHeap(DequeE8CIter first, int hole, int top, BfmeE8 value, Rva00549DCB comp){
	int parent = (hole - 1) / 2;
	while (hole > top && comp.rva00549DCB((*(first + parent)).ptr, value.ptr)) {
		const_cast<BfmeE8 &>(*(first + hole)) = *(first + parent);
		hole = parent;
		parent = (hole - 1) / 2;
	}
	const_cast<BfmeE8 &>(*(first + hole)) = value;
}
