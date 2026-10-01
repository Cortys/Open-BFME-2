// cl: /O1 /DNDEBUG /MD
// _STL::__copy random-access loops over two 4-byte handle types, retail
// 0x00051BE1 47B and 0x00051C10 47B.
// Evidence: both count (last - first) >> 2 elements and assign each through an
// external operator=, 0x00037150 (the rowed UnicodeString-shaped set) and
// 0x00239099 (the rowed OpaqueRefElement4 assignment). Same recipe as the
// 0x004039E0 sibling in Rva00403927Copy.cpp; dedicated TU so the operator=
// calls stay external.
class Rva00630D00UStr
{
	void *m_data;

public:
	Rva00630D00UStr &operator=(const Rva00630D00UStr &that);
};

struct OpaqueRefElement4
{
	void *referent;
	OpaqueRefElement4 &operator=(const OpaqueRefElement4 &other);
};

namespace _STL
{

struct random_access_iterator_tag {};

template <class InputIter, class OutputIter, class Distance>
OutputIter __copy(InputIter first, InputIter last, OutputIter result, const random_access_iterator_tag &, Distance *)
{
	for (int n = last - first; n > 0; --n)
	{
		*result = *first;
		++first;
		++result;
	}
	return result;
}

}

template Rva00630D00UStr *_STL::__copy(Rva00630D00UStr *, Rva00630D00UStr *, Rva00630D00UStr *, const random_access_iterator_tag &, int *);
template OpaqueRefElement4 *_STL::__copy(OpaqueRefElement4 *, OpaqueRefElement4 *, OpaqueRefElement4 *, const random_access_iterator_tag &, int *);
