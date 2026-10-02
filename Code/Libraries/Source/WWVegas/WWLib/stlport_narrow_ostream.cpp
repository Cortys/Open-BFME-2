// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport

#include <string>

namespace _STL
{
template <>
basic_string<char, char_traits<char>, allocator<char> >::~basic_string();

template <>
void _STLP_alloc_proxy<char*, char, allocator<char> >::deallocate(
        char*, size_t);
}

#include <ostream>

template class _STL::basic_ostream<char, _STL::char_traits<char> >;
