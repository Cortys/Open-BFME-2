// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// ?Rva0054A67BSiftUp@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHUBfmeE8@@@Z @0x0054A67B (141B):
// Deque heap sift-up over 8-byte elements with float key at +4, continuing
// while the parent key is above the value (comiss/jbe exit). Same 141B shape
// as sibling Rva0054A5EEPushHeap (which continues while below); rowed
// deque+E8 operator+ at 0x0054A202 four times. Caller 0x0054AB54.
// Evidence: unlock lane, all callees rowed, unblocks 0x0054AA86.
#include <deque>
struct BfmeE8 { int a; float b; };
typedef _STL::deque<BfmeE8, _STL::allocator<BfmeE8> >::const_iterator DequeE8CIter;
void __cdecl Rva0054A67BSiftUp(DequeE8CIter first, int hole, int top, BfmeE8 value){
	int parent = (hole - 1) / 2;
	while (hole > top && (*(first + parent)).b > value.b) {
		const_cast<BfmeE8 &>(*(first + hole)) = *(first + parent);
		hole = parent;
		parent = (hole - 1) / 2;
	}
	const_cast<BfmeE8 &>(*(first + hole)) = value;
}
