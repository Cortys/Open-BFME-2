// ?bfmeFwdSWA@BfmeThingSWA@@QAEXH@Z
// partial score=0.93 date=2026-10-01
// cl: /Od
//
// ?bfmeFwdSWA@BfmeThingSWA@@QAEXH@Z @0x0002A930 58B.
// Evidence: int arg used as C-string via length then append range with
// forward tag; caller bfmePassSWA in BfmeConv1303.cpp; prev/next /Od.
// ?bfmeFwdSWA@BfmeThingSWA@@QAEXH@Z present-unmatched

namespace _STL
{
struct forward_iterator_tag
{
};

template <class T>
class allocator
{
};

template <class T>
class char_traits
{
};

template <>
class char_traits<char>
{
public:
	static unsigned int length(const char *s);
};

template <class CharT, class Traits, class Alloc>
class basic_string
{
public:
	template <class InputIterator>
	basic_string &append(InputIterator first, InputIterator last, const forward_iterator_tag &tag);
};
}

class BfmeThingSWA : public _STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> >
{
public:
	void bfmeFwdSWA(int a);
};

void BfmeThingSWA::bfmeFwdSWA(int a)
{
	const char *e = (const char *)a + _STL::char_traits<char>::length((const char *)a);
	this->append((char *)(const char *)a, (char *)e, _STL::forward_iterator_tag());
	char pad[0x40];
	(void)pad;
}
