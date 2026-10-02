// cl: /O1 /G7 /EHsc /arch:SSE /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// STLport's two-argument sort over a pointer range of 8-byte elements: sort
// (0x005A97E1, 67B) and the whole family it instantiates, 0x005A9146 ..
// 0x005A9743. Target evidence: the introsort loop at 0x005A975E is one of the
// two callers outside the BfmeE12 deque sort of the median folded at
// 0x005A9215 (rowed in stlport_deque_e12_sort.cpp), and the less-than every
// body inlines is a single comiss on the float at +4. Compiled with the BfmeE12
// sort's flags, this unit's bodies equal retail at the addresses the retail
// calls fix, sort included: its frame and the garbage push for the empty
// less<> argument are the two-argument sort's, not the comparator form's.
//
// The element type is a STAND-IN, as in stlport_deque_e12_sort.cpp: the image
// fixes its size (the stride and the >> 3) and the float key at +4, nothing
// more. BfmeE8 has the layout the deque<BfmeE8> heap helpers
// (Rva0054A5EEPushHeap.cpp) give it. Three bodies retail folded with other
// instantiations are pinned there, not rowed: the median, swap and
// copy_backward.

#include <algorithm>

struct BfmeE8 { int a; float b; };

inline bool operator<(const BfmeE8 &x, const BfmeE8 &y) { return x.b < y.b; }

template void _STL::sort<BfmeE8 *>(BfmeE8 *, BfmeE8 *);
