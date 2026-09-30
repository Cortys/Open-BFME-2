// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??$__median@PAHVRva00204BB8@@@_STL@@YAPAHPAH00VRva00204BB8@@@Z @0x002057D5 107B: median-of-three over int sort keys with rowed thiscall comparator Rva00204BB8.
// Evidence: caller 0x0020C04C passes (first, mid, last-1, comp) in introsort_loop shape; 5 calls to rowed 0x00204BB8; same branch shape as Rva00440AB0Median 107B and _STL median 0x00423134.
class Rva00204BB8
{
public:
	bool operator()(int a, int b) const;
};

namespace _STL
{

template <class RandomAccessIter, class Compare>
RandomAccessIter __median(RandomAccessIter a, RandomAccessIter b, RandomAccessIter c, Compare comp)
{
	if (comp(*a, *b)) {
		if (comp(*b, *c))
			return b;
		else if (comp(*a, *c))
			return c;
		else
			return a;
	} else {
		if (comp(*a, *c))
			return a;
		else if (comp(*b, *c))
			return c;
		else
			return b;
	}
}

template int *__median<int *, Rva00204BB8>(int *, int *, int *, Rva00204BB8);

}
