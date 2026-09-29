// ?Rva003F2BEBDeleteRange@@YA_NPAPAV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@0_N@Z
// partial score=0.91 date=2026-09-29
// ?Rva003F2BEBDeleteRange@@YA_NPAPAV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@0_N@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /Oy- /MD
//
// ?Rva003F2BEBDeleteRange@@YA_NPAPAV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@0_N@Z retail 0x003F2BEB 33B
// Range delete over narrow strings via the rowed scalar delete at
// 0x00423FBD then return the flag byte. Evidence: chain from 0x00423FBD
// plus caller 0x003F2D34 plus LivingWorld neighbours.
namespace _STL
{
template <class T> class char_traits {};
template <class T> class allocator {};
template <class CharT, class Traits, class Alloc> class basic_string
{
public:
	~basic_string();
};
typedef basic_string<char, char_traits<char>, allocator<char> > narrow_string;
}

void __stdcall Rva00423FBDDelete(_STL::narrow_string *p);

bool __cdecl Rva003F2BEBDeleteRange(_STL::narrow_string **begin, _STL::narrow_string **end, bool flag)
{
	for (; begin != end; ++begin)
		Rva00423FBDDelete(*begin);
	return flag;
}
