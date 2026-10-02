// ?erase@?$vector@UBfmeVectorRecord0002154F3@@V?$allocator@UBfmeVectorRecord0002154F3@@@_STL@@@_STL@@QAEPAUBfmeVectorRecord0002154F3@@PAU3@0@Z
// partial score=0.98 date=2026-10-02
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?erase@?$vector@UBfmeVectorRecord0002154F3@@V?$allocator@UBfmeVectorRecord0002154F3@@@_STL@@@_STL@@QAEPAUBfmeVectorRecord0002154F3@@PAU3@0@Z @0x002157DB 51B range erase.
// Evidence: chain lane, neighbours 0x0021579C dtor and 0x0021580E _M_clear in same TU, callees rowed 0x0021570D copy and 0x00215783 Destroy, size 51 matches other vector range erases.
struct BfmeVectorRecord0002154F3;
namespace _STL {
struct __false_type {
};
template <class InputIter, class OutputIter> OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result, const __false_type &tag);
template <class T> class allocator {
};
template <class T, class A> class vector {
public:
	typedef T *iterator;
	iterator erase(iterator first, iterator last);
private:
	iterator _M_start;
	iterator _M_finish;
	iterator _M_end;
};
template <class ForwardIter> void _Destroy(ForwardIter first, ForwardIter last);
}
// ?erase@?$vector@UBfmeVectorRecord0002154F3@@V?$allocator@UBfmeVectorRecord0002154F3@@@_STL@@@_STL@@QAEPAUBfmeVectorRecord0002154F3@@PAU3@0@Z present-unmatched
_STL::vector<BfmeVectorRecord0002154F3, _STL::allocator<BfmeVectorRecord0002154F3> >::iterator _STL::vector<BfmeVectorRecord0002154F3, _STL::allocator<BfmeVectorRecord0002154F3> >::erase(iterator first, iterator last)
{
	__false_type tag;
	iterator result = _STL::__copy_ptrs(last, _M_finish, first, tag);
	_STL::_Destroy(result, _M_finish);
	_M_finish = result;
	return first;
}
