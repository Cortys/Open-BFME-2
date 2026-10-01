// cl: /O1 /DNDEBUG /MD
// _STL::__uninitialized_fill_n over the 4-byte Rva0036CA00Str handle,
// retail 0x00051AF9 37B.
// Evidence: an unsigned count loop that calls the rowed out-of-line
// _Construct<Rva0036CA00Str> 0x002393AA once per slot with the fill value,
// advancing by 4, and returns the end pointer. Dedicated TU with _Construct
// declared only, so the call stays external as in retail.
class Rva0036CA00Str
{
	void *m_item;
};

namespace _STL
{

struct __false_type {};

template <class T1, class T2>
void _Construct(T1 *p, const T2 &value);

template <class ForwardIter, class Size, class T>
ForwardIter __uninitialized_fill_n(ForwardIter first, Size n, const T &x, const __false_type &)
{
	ForwardIter cur = first;
	for (; n > 0; --n, ++cur)
		_Construct(&*cur, x);
	return cur;
}

}

template Rva0036CA00Str *_STL::__uninitialized_fill_n(Rva0036CA00Str *, unsigned int, const Rva0036CA00Str &, const _STL::__false_type &);
