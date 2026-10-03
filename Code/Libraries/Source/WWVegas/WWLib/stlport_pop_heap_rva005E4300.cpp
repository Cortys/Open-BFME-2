// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ??$__pop_heap@PAHHURva005E4300Cmp@@@_STL@@YAXPAH00HURva005E4300Cmp@@@Z @0x005E4A5F 41B
// STL heap pop over int sort keys with the pinned thiscall comparator
// Rva005E4300Cmp at 0x005E4300; calls the rowed __adjust_heap 0x005E48C2.
// Evidence: same 41B shape as 0x00423EF7 and 0x002074D4 precedents; callees rowed.
struct Rva005E4300Cmp
{
	bool operator()(int a, int b) const;
};

namespace _STL
{

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __adjust_heap(RandomAccessIterator first, Distance holeIndex,
	Distance len, Tp val, Compare comp);

template <class RandomAccessIter, class Tp, class Compare>
void __pop_heap(RandomAccessIter first, RandomAccessIter last,
	RandomAccessIter result, Tp val, Compare comp)
{
	*result = *first;
	__adjust_heap(first, 0, (int)(last - first), val, comp);
}

template void __pop_heap<int *, int,
	Rva005E4300Cmp>(int *, int *, int *, int, Rva005E4300Cmp);

}
