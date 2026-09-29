// ??$__adjust_heap@PAHHHU?$greater@H@_STL@@@_STL@@YAXPAHHHHU?$greater@H@0@@Z
// partial score=0.99 date=2026-09-29
// ??$__adjust_heap@PAHHHU?$greater@H@_STL@@@_STL@@YAXPAHHHHU?$greater@H@0@@Z
// partial score=0.99 date=2026-09-29
// ??$__adjust_heap@PAHHHU?$greater@H@_STL@@@_STL@@YAXPAHHHHU?$greater@H@0@@Z
// partial score=0.99 date=2026-09-29
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// __adjust_heap<int*,int,int,greater<int>> at 0x5E48C2, retail 94 bytes.
// Current: 95 bytes, one byte over, first difference at +0x14 = 0x5E48D6 --
// the loop's jmp before the while test (retail has the 2-byte short form eb 20).
//
// Read from the retail disassembly rather than from a mangled name, which is
// what took six rounds: the 94 bytes are stlport's __adjust_heap line for line,
// including the vendor quirk of spilling topIndex over the len argument slot so
// the __push_heap tail call passes topIndex.
//
// The 15-byte gap that survived four flag sweeps was NOT a flag: retail calls
// the comparison out of line at 0x5e4300, and the default build inlines it. The
// declaration below is what fixes that -- an explicit specialization declared
// and never defined, so calls go out of line. That alone took the body from 79
// bytes to 95. Same outline-the-trivial-member move as _String_base's destructor
// in the num_put and money_get work.
//
// Next lever: the last byte is a jump encoding. Shape the driver or the iterator
// form so the branch stays short; matched heap siblings are the place to look.
#include <algorithm>
#include <functional>

namespace _STL {
template <> bool greater<int>::operator()(const int &a, const int &b) const;
}

void bfmeEmitAdjustHeapGreater(int *first, int *last)
{
	_STL::make_heap(first, last, _STL::greater<int>());
}
