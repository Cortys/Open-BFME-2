// ?_M_fill_insert@?$vector@UBfmeStringRecord005DDD40@@V?$allocator@UBfmeStringRecord005DDD40@@@_STL@@@_STL@@QAEXPAUBfmeStringRecord005DDD40@@IABU3@@Z
// partial score=0.95 date=2026-09-28
// ?_M_fill_insert@?$vector@UBfmeStringRecord005DDD40@@V?$allocator@UBfmeStringRecord005DDD40@@@_STL@@@_STL@@QAEXPAUBfmeStringRecord005DDD40@@IABU3@@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /EHsc
// stlport

// ?_M_fill_insert@?$vector@UBfmeStringRecord005DDD40@@V?$allocator@UBfmeStringRecord005DDD40@@@_STL@@@_STL@@QAEXPAUBfmeStringRecord005DDD40@@IABU3@@Z, RVA 0x005DE651, 260B.
// Chain lane: vector<BfmeStringRecord005DDD40> fill insert; callees all rowed
// (copy ctor 0x005DDD40, uninit copy 0x005DDDCA, copy_backward 0x005DDD5B,
// fill 0x005DD6F7, uninit_fill_n 0x005DE088, releaseBuffer 0x00036E70,
// overflow twin 0x005DE4BA of rowed 0x00381B7B). Callers at 0x005DE812/0x005DE79E.
// Ret 0x0C with pos/count/value args. Explicit instantiation inlines the two
// tiny dispatch wrappers (extra push 0 / extra lea-push); /Ob0 keeps them out
// of line but stops the __x_copy dtor folding to releaseBuffer. So follow the
// AsciiStringVectorAssign precedent: hand-written spec following <_vector.c>
// line for line, with noinline forwarders for the two wrappers. Models verbatim
// from neighbour TU stlport_vector_stringrecord_5de5b5_dtor.cpp.
class UnicodeString;
typedef unsigned short wchar_t;
template <typename T>
class StringBase
{
public:
	__forceinline ~StringBase() { releaseBuffer(); }
protected:
	void releaseBuffer();
private:
	StringBase(const StringBase &);
	void *m_data;
};
class UnicodeString : public StringBase<wchar_t>
{
public:
	UnicodeString(const UnicodeString &);
	__forceinline ~UnicodeString() { releaseBuffer(); }
};
#include <vector>
struct BfmeStringRecord005DDD40 {
    UnicodeString text;
    unsigned int word;
    BfmeStringRecord005DDD40();
    BfmeStringRecord005DDD40(const BfmeStringRecord005DDD40 &);
    BfmeStringRecord005DDD40 &operator=(const BfmeStringRecord005DDD40 &);
};
namespace _STL {
template <> void _Construct<BfmeStringRecord005DDD40, BfmeStringRecord005DDD40>(BfmeStringRecord005DDD40 *, const BfmeStringRecord005DDD40 &);

// Retail calls the dispatch layers out of line. noinline forwarders keep them
// out of line as retail has them; bodies are verbatim generic.
template <>
__declspec(noinline) BfmeStringRecord005DDD40 *__copy_backward_ptrs<BfmeStringRecord005DDD40 *, BfmeStringRecord005DDD40 *>(BfmeStringRecord005DDD40 *__first, BfmeStringRecord005DDD40 *__last, BfmeStringRecord005DDD40 *__result, const __false_type &)
{
	return __copy_backward(__first, __last, __result, random_access_iterator_tag(), (int *)0);
}

template <>
__declspec(noinline) BfmeStringRecord005DDD40 *uninitialized_fill_n<BfmeStringRecord005DDD40 *, unsigned int, BfmeStringRecord005DDD40>(BfmeStringRecord005DDD40 *__first, unsigned int __n, const BfmeStringRecord005DDD40 &__x)
{
	return __uninitialized_fill_n(__first, __n, __x, __false_type());
}

// ?_M_fill_insert@?$vector@UBfmeStringRecord005DDD40@@V?$allocator@UBfmeStringRecord005DDD40@@@_STL@@@_STL@@QAEXPAUBfmeStringRecord005DDD40@@IABU3@@Z present-unmatched
template <>
void vector<BfmeStringRecord005DDD40, allocator<BfmeStringRecord005DDD40> >::_M_fill_insert(
	BfmeStringRecord005DDD40 *__position, size_type __n, const BfmeStringRecord005DDD40 &__x)
{
	if (__n != 0) {
		if (size_type(this->_M_end_of_storage._M_data - this->_M_finish) >= __n) {
			BfmeStringRecord005DDD40 __x_copy = __x;
			const size_type __elems_after = this->_M_finish - __position;
			pointer __old_finish = this->_M_finish;
			if (__elems_after > __n) {
				__uninitialized_copy(this->_M_finish - __n, this->_M_finish, this->_M_finish, _IsPODType());
				this->_M_finish += __n;
				__copy_backward_ptrs(__position, __old_finish - __n, __old_finish, _TrivialAss());
				_STLP_STD::fill(__position, __position + __n, __x_copy);
			}
			else {
				uninitialized_fill_n(this->_M_finish, __n - __elems_after, __x_copy);
				this->_M_finish += __n - __elems_after;
				__uninitialized_copy(__position, __old_finish, this->_M_finish, _IsPODType());
				this->_M_finish += __elems_after;
				_STLP_STD::fill(__position, __old_finish, __x_copy);
			}
		}
		else
			_M_insert_overflow(__position, __x, _IsPODType(), __n);
	}
}
}
