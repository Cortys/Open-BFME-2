// ?erase@Rva0026660String@@QAEAAV1@II@Z
// partial score=0.96 date=2026-10-04
// ?erase@Rva0026660String@@QAEAAV1@II@Z
// cl: /Od /Ob1 /DNDEBUG /DWIN32 /D_WINDOWS /MD

namespace _STL
{
template <class T>
class allocator {};

template <class CharT, class Alloc>
class _String_base
{
public:
	void _M_throw_out_of_range() const;

	CharT *_M_start;
	CharT *_M_finish;
};
} // namespace _STL

class Rva0026660String
{
public:
	char *_M_start;
	char *_M_finish;

	char *eraseRange(char *first, char *last);
	unsigned int size() const { return (unsigned int)(_M_finish - _M_start); }
	char *begin() const { return _M_start; }

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
		((_STL::_String_base<char, _STL::allocator<char> > *)this)->_M_throw_out_of_range();

	const unsigned int len1 = size() - pos;
	char *toEnd = begin();
	const unsigned int &m = bfmeMinRef(n, len1);
	char *from = begin();
	char *from2 = begin();
	eraseRange(from + pos, toEnd + pos + m);
	return *this;
}