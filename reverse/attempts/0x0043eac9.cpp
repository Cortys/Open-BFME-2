// ??$equal@U?$_Bit_iter@U_Bit_reference@_STL@@PAU12@@_STL@@U12@@_STL@@YA_NU?$_Bit_iter@U_Bit_reference@_STL@@PAU12@@0@00@Z
// partial score=0.93 date=2026-09-30
// ??$equal@U?$_Bit_iter@U_Bit_reference@_STL@@PAU12@@_STL@@U12@@_STL@@YA_NU?$_Bit_iter@U_Bit_reference@_STL@@PAU12@@0@00@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// STLport4.5.3 equal for _Bit_iterator used by vector<bool> operator==.
// Evidence: rowed _M_bump_up 0x000660C9 twice plus rowed operator!= 0x00066132 plus EBP frame with 3 iterators; caller 0x0043F14D pushes 3 _Bit_iterators after size check; unblocks 0x0043F14D.
#include <vector>
template bool _STL::equal<_STL::_Bit_iterator, _STL::_Bit_iterator>(_STL::_Bit_iterator, _STL::_Bit_iterator, _STL::_Bit_iterator);
