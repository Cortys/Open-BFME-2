// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport

#include <fstream>

// STLport's _locale.h declares const locale& operator=, but the matched
// implementation in stlport_locale.cpp (0x00007160) returns locale&. Both
// spellings return the same reference pointer; bind the vendor spelling used
// by this explicit instantiation to that rowed implementation.
#pragma comment(linker, "/alternatename:??4locale@_STL@@QAEABV01@ABV01@@Z=??4locale@_STL@@QAEAAV01@ABV01@@Z")

template class _STL::basic_fstream<wchar_t, _STL::char_traits<wchar_t> >;
