// ??0?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@ABV01@IIABV?$allocator@D@1@@Z
// partial score=0.95 date=2026-10-03
// cl: /DNDEBUG /MD /EHsc /Od /Ob2 /D_STLP_USE_STATIC_LIB
// stlport
//
// STLport 4.5.3 basic_string<char> substring constructor
// basic_string(const basic_string &, size_type pos, size_type n,
// const allocator_type &), retail 0x00029FB0, 218 bytes.
//
// BEST ATTEMPT (partial, not landed). Direct transfer of the BFME1
// reconstruction
// (reference/open-bfme-1/game/Libraries/Source/WWVegas/WWLib/
//  stlport_narrow_string_substring_ctor.cpp). Every byte matches the BFME2
// retail body except the final REL32: BFME1's constructor calls the private
// char* _M_range_initialize (AAE, BFME2 0x0000BF90), while BFME2 retail's
// REL32 targets the PUBLIC const char* spelling at 0x000078C0. The frame,
// the out-of-range call (0x00023A40) and the reference-returning min
// pointer-select all match.

#include <string>

namespace _STL
{

template <> template <>
inline void basic_string<char, char_traits<char>, allocator<char> >::
	_M_range_initialize<char *>(char *__f, char *__l,
		const forward_iterator_tag &)
{
	difference_type __n = __l - __f;
	this->_M_allocate_block(__n + 1);
	this->_M_finish = uninitialized_copy(__f, __l, this->_M_start);
	*this->_M_finish = 0;
}

}

// ??0?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@QAE@ABV01@IIABV?$allocator@D@1@@Z
template _STL::basic_string<char, _STL::char_traits<char>,
	_STL::allocator<char> >::basic_string(
	const _STL::basic_string<char, _STL::char_traits<char>,
		_STL::allocator<char> > &,
	unsigned, unsigned, const _STL::allocator<char> &);
