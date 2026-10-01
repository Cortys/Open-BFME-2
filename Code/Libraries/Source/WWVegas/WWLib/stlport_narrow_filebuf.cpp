// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport

#include <fstream>

// STLport 4.5.3 src/fstream.cpp: the page size the mmap path rounds to,
// .data VA 0x00DA6CC8, retail initial value 4096.
size_t _STL::_Filebuf_base::_M_page_size = 4096;

template class _STL::basic_filebuf<char, _STL::char_traits<char> >;
