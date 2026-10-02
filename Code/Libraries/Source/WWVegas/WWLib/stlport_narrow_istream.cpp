// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport

#include <string>

namespace _STL
{
template <>
void _STLP_alloc_proxy<char*, char, allocator<char> >::deallocate(
        char*, size_t);
}

#include <istream>

template class _STL::basic_istream<char, _STL::char_traits<char> >;
