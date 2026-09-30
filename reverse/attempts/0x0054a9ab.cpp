// ?Rva0054A9ABAdjustHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHHMUComp0054A9AB@@@Z
// partial score=0.99 date=2026-09-30
// ?Rva0054A9ABAdjustHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHHMUComp0054A9AB@@@Z
// partial score=0.99 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
//
// ?Rva0054A9ABAdjustHeap@@YAXU?$_Deque_iterator@UBfmeE8@@U?$_Const_traits@UBfmeE8@@@_STL@@@_STL@@HHHMUComp0054A9AB@@@Z @0x0054A9AB (219B):
// Deque adjust_heap sift-down over 8-byte elements with float key at +4; value
// arrives as int+float pair (same 8B as BfmeE8) so the tail constructs the
// push_heap struct via mov+movss fill; inlined less-than on +4 selects larger
// child then tail-calls 5-arg push_heap at 0x0054A5EE (alias pin).
// Callers 0x0054AFAA 0x0054B10F. Evidence: chain lane after 0x0054A5EE.
#include <deque>
struct BfmeE8 { int a; float b; };
struct Comp0054A9AB
{
	int m_dummy;
	bool operator()(const BfmeE8 &a, const BfmeE8 &b) const
	{
		return a.b < b.b;
	}
};
typedef _STL::deque<BfmeE8, _STL::allocator<BfmeE8> >::const_iterator DequeE8CIter;
void __cdecl Rva0054A5EEPushHeap5(DequeE8CIter first, int hole, int top, BfmeE8 value, Comp0054A9AB comp);
void __cdecl Rva0054A9ABAdjustHeap(DequeE8CIter first, int hole, int len, int value_a, float value_b, Comp0054A9AB comp)
{
	int top = hole;
	int secondChild = 2 * hole + 2;
	while (secondChild < len) {
		if (comp(*(first + secondChild), *(first + (secondChild - 1))))
			--secondChild;
		const_cast<BfmeE8 &>(*(first + hole)) = *(first + secondChild);
		hole = secondChild;
		secondChild = 2 * (secondChild + 1);
	}
	if (secondChild == len) {
		const_cast<BfmeE8 &>(*(first + hole)) = *(first + (secondChild - 1));
		hole = secondChild - 1;
	}
	BfmeE8 tmp;
	tmp.b = value_b;
	tmp.a = value_a;
	Rva0054A5EEPushHeap5(first, hole, top, tmp, comp);
}
