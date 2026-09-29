// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ??$__push_heap@PAHHHVRva00422CA8@@@_STL@@YAXPAHHHHVRva00422CA8@@@Z
// retail 0x00423349, 77 bytes. Heap sift-up over int sort keys with the
// rowed thiscall comparator Rva00422CA8 (member operator()(int,int),
// defined in Rva00422CA8Cmp.cpp): parent = (hole-1)/2, then while the hole
// is above top and comp(*parent, value) holds, move the parent down.
// Evidence: caller 0x00423A10 in the 94B push_heap wrapper 0x004239BF;
// callees rowed to 0x00422CA8; unblocks 0x004239BF. Same STLport sift-up
// spelling as stlport_push_heap_s4sortelem8.cpp.

class Rva00422CA8
{
public:
	bool operator()(int a, int b) const;
};

namespace _STL
{

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __push_heap(RandomAccessIterator first, Distance holeIndex,
	Distance topIndex, Tp val, Compare comp)
{
	Distance parent = (holeIndex - 1) / 2;
	while (holeIndex > topIndex)
	{
		Tp tmp = *(first + parent);
		if (!comp(tmp, val))
			break;
		*(first + holeIndex) = *(first + parent);
		holeIndex = parent;
		parent = (holeIndex - 1) / 2;
	}
	*(first + holeIndex) = val;
}

template void __push_heap<int *, int, int,
	Rva00422CA8>(int *, int, int, int, Rva00422CA8);

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __adjust_heap(RandomAccessIterator first, Distance holeIndex,
	Distance len, Tp val, Compare comp)
{
	Distance topIndex = holeIndex;
	Distance secondChild = 2 * holeIndex + 2;
	while (secondChild < len)
	{
		if (comp(*(first + secondChild), *(first + (secondChild - 1))))
			--secondChild;
		*(first + holeIndex) = *(first + secondChild);
		holeIndex = secondChild;
		secondChild = 2 * (secondChild + 1);
	}
	if (secondChild == len)
	{
		*(first + holeIndex) = *(first + (secondChild - 1));
		holeIndex = secondChild - 1;
	}
	__push_heap(first, holeIndex, topIndex, val, comp);
}

template void __adjust_heap<int *, int, int,
	Rva00422CA8>(int *, int, int, int, Rva00422CA8);

template <class RandomAccessIter, class Tp, class Compare>
void __pop_heap(RandomAccessIter first, RandomAccessIter last,
	RandomAccessIter result, Tp val, Compare comp)
{
	*result = *first;
	__adjust_heap(first, 0, (int)(last - first), val, comp);
}

template void __pop_heap<int *, int,
	Rva00422CA8>(int *, int *, int *, int, Rva00422CA8);

}
