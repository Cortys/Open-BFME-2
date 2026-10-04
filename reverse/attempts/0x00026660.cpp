// ?erase@Rva0026660String@@QAEAAV1@II@Z
// partial score=0.95 date=2026-10-04
// cl: /Od /Ob1 /DNDEBUG /DWIN32 /D_WINDOWS /MD
//
// ?erase@Rva0026660String@@QAEAAV1@II@Z
// @0x00266660 (130B): the /Od instance of _STL::basic_string<char>::erase
// (size_type, size_type).
//
// Evidence: the out-of-range guard calls the rowed _M_throw_out_of_range body
// at 0x00023A40, the fresh-window close calls the rowed iterator-pair erase at
// 0x00012150, and the reference-bound (min) of (size() - pos) and count is the
// lvalue-ternary shape. The vendored STLport header inlines the iterator-pair
// erase into this body, so it cannot reproduce the out-of-line call; the /Od
// class and method names are address-derived and the two callees are pinned
// under this TU's spellings.
//
// THE MIN MUST BE __forceinline. Declared as an ordinary function template it
// is emitted out of line, and the caller then calls it: the reference-bound
// min() disappears behind a call, both of its operands spill to frame slots,
// and the whole body collapses to 121B with 54 of 121 bytes exact. Inlined, it
// becomes the `mov edx,[ebp-4]; cmp edx,[ebp+0xc]; jae` lvalue-ternary retail
// has, and the body grows to the register-cached tail -- 82 of 130 exact, with
// `sub esp,0x20` now matching retail's frame exactly.
//
// Retail re-reads size() after the _M_throw_out_of_range guard into its own
// slot, binds the reference-returning min() to a REFERENCE VARIABLE, and keeps
// THREE separate begin() copies in named locals: the erased start, a second
// destination copy, and the one the min() offset is added to. Those four
// values are what reproduce the 0x20 frame -- this at [ebp-0x1c], the
// lvalue-ternary path slot at [ebp-0x20], the min() result at [ebp-0xc], the
// first begin() at [ebp-8], size()-pos at [ebp-4], the extra begin() at
// [ebp-0x10] and this again as the min's second operand base at [ebp-0x18].

class Rva0026660String
{
public:
	char *m_start;
	char *m_finish;
	char *m_end;

	void throwOutOfRange() const;
	char *eraseRange(char *first, char *last);
	unsigned int size() const { return (unsigned int)(m_finish - m_start); }
	char *begin() const { return m_start; }

	Rva0026660String &erase(unsigned int pos, unsigned int n);
};

template <class T>
__forceinline const T &bfmeMinRef(const T &a, const T &b)
{
	return b < a ? b : a;
}

// ?erase@Rva0026660String@@QAEAAV1@II@Z present-unmatched
Rva0026660String &Rva0026660String::erase(unsigned int pos, unsigned int n)
{
	if (pos > size())
		throwOutOfRange();

	const unsigned int len1 = size() - pos;
	char *toEnd = begin();
	const unsigned int &m = bfmeMinRef(n, len1);
	char *from = begin();
	char *from2 = begin();
	eraseRange(from + pos, toEnd + pos + m);
	return *this;
}
