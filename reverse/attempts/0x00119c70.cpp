// ?erase@?$vector@VProxyClass@@V?$allocator@VProxyClass@@@_STL@@@_STL@@QAEPAVProxyClass@@PAV3@0@Z
// partial score=0.78 date=2026-09-28
// cl: /O2 /Oy
// stlport
//
// ?erase@?$vector@VProxyClass@@V?$allocator@VProxyClass@@@_STL@@@_STL@@QAEPAVProxyClass@@PAV3@0@Z
// target candidate 0x00119C70, 76 bytes. Target Ghidra shows range-copy
// helper 0x00119AD0 moving 0x74-byte records via the already matched
// ProxyClass assignment at 0x00118E50, then destroys vacated elements through
// 0x00118800. ProxyClass's 0x74-byte layout and ref-counted first member are
// established by Render2DClassReset.cpp; the competing Coord2D vector pin is
// removed because its 12-byte element cannot explain the 0x74-byte copy loop.

class ProxyClass
{
	public:
	~ProxyClass();
	ProxyClass &operator=(ProxyClass const &other);

	private:
	unsigned char m_bytes[0x74];
};

namespace _STL
{
struct __false_type {};
struct random_access_iterator_tag {};

template<class T> class allocator {};

template<class T, class Allocator> class vector
{
public:
	typedef T *iterator;
	iterator erase(iterator first, iterator last);
private:
	iterator m_start;
	iterator m_finish;
	iterator m_endOfStorage;
};

template<class InputIter, class OutputIter, class Distance>
OutputIter __copy(InputIter first, InputIter last, OutputIter result,
	const random_access_iterator_tag &tag, Distance *extra);

template<class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type &tag)
{
	__false_type local;
	return __copy(first, last, result,
		reinterpret_cast<const random_access_iterator_tag &>(local), (int *)0);
}

template<class ForwardIter> void _Destroy(ForwardIter first, ForwardIter last);
}

_STL::vector<ProxyClass, _STL::allocator<ProxyClass> >::iterator
_STL::vector<ProxyClass, _STL::allocator<ProxyClass> >::erase(iterator first,
	iterator last)
{
	iterator result = _STL::__copy_ptrs(last, m_finish, first, _STL::__false_type());
	for (; result != m_finish; ++result)
		result->~ProxyClass();
	m_finish = result;
	return first;
}
