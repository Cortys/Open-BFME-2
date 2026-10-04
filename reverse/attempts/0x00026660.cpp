// ?erase@Rva0026660String@@QAEAAV1@II@Z
// partial score=0.93 date=2026-10-04
// ?erase@Rva0026660String@@QAEAAV1@II@Z
// partial score=0.9 date=2026-10-03
// cl: /Od /Ob1 /DNDEBUG /DWIN32 /D_WINDOWS /MD
//
// The /Od instance of _STL::basic_string<char>::erase(size_type, size_type),
// retail 0x00266660 (130B). Evidence: the out-of-range guard calls the rowed
// _M_throw_out_of_range body at 0x00023A40, the fresh-window close calls the
// rowed iterator-pair erase at 0x00012150, and the reference-bound (min) of
// (size() - pos) and count is the lvalue-ternary shape. The vendored STLport
// header inlines the iterator-pair erase into this body, so it cannot
// reproduce the out-of-line call; the /Od class and method names are
// address-derived and the two callees are pinned under this TU's spellings.

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
const T &bfmeMinRef(const T &a, const T &b)
{
	return b < a ? b : a;
}

Rva0026660String &Rva0026660String::erase(unsigned int pos, unsigned int n)
{
	if (pos > size())
		throwOutOfRange();

	// Retail reads size() a second time after the guard, binds the
	// reference-returning min() of n and (size() - pos) to a REFERENCE VARIABLE,
	// and keeps two separate begin() copies in named locals: the erased start
	// and the destination the min() offset is added to. Each of those is a
	// distinct /Od frame slot (this at [ebp-0x1c], the second begin() at
	// [ebp-0x10], the min() result at [ebp-0xc], the first begin() at [ebp-8],
	// size() - pos at [ebp-4] and the lvalue-ternary path slot at [ebp-0x20]),
	// and naming them is what reproduces the retail frame.
	const unsigned int len1 = size() - pos;
	char *toEnd = begin();
	const unsigned int &m = bfmeMinRef(n, len1);
	char *from = begin();
	eraseRange(from + pos, toEnd + pos + m);
	return *this;
}
