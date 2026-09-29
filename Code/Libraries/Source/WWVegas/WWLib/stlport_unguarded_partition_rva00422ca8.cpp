// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ??$__unguarded_partition@PAHHVRva00422CA8@@@_STL@@YAPAHPAH0HVRva00422CA8@@@Z
// retail 0x004231A0, 73 bytes. Quicksort partition over int sort keys with
// the rowed thiscall comparator Rva00422CA8 (member operator()(int,int),
// defined in Rva00422CA8Cmp.cpp): scan up while comp(*first,pivot), scan
// down while comp(pivot,*last), swap on cross, return the split.
// Evidence: caller 0x004253C9 passes (first,last,pivot,comp) in the median /
// partition / recurse quicksort shape; callees both rowed to 0x00422CA8.

class Rva00422CA8
{
public:
	bool operator()(int a, int b) const;
};

namespace _STL
{

template <class ForwardIter1, class ForwardIter2>
__forceinline void iter_swap(ForwardIter1 left, ForwardIter2 right)
{
	int temporary = *left;
	*left = *right;
	*right = temporary;
}

template <class RandomAccessIter, class Tp, class Compare>
RandomAccessIter __unguarded_partition(RandomAccessIter first,
	RandomAccessIter last, Tp pivot, Compare comp)
{
	while (true)
	{
		while (comp(*first, pivot))
			++first;
		--last;
		while (comp(pivot, *last))
			--last;
		if (!(first < last))
			return first;
		iter_swap(first, last);
		++first;
	}
}

template int *__unguarded_partition<int *, int,
	Rva00422CA8>(int *, int *, int, Rva00422CA8);

}
