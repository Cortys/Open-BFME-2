// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??$_Destroy@PAV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@_STL@@YAXPAV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@0@0@Z at retail 0x000798BE (25B).
// Range destroy over 12-byte narrow basic_string via rowed dtor 0x00142D70; stride 0x0C proves element width.
// Callers 0x00079EF1 0x0007A7AA 0x000C0399 are vector clear/dtor bodies awaiting this range.
#include <vector>
namespace _STL {
template <class T> class char_traits {};
template <class CharT, class Traits, class Alloc>
class basic_string {
public:
	~basic_string();
private:
	char m_pad[12];
};
}
template void _STL::_Destroy<_STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> >*>(_STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> >*, _STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> >*);
