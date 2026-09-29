// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable
// stlport
//
// hashtable<string, unsigned int>::resize at retail 0x0060CD36 (194B).
// String-keyed rehash: old bucket count from +4/+8, _M_next_size growth,
// fresh vector<void*> then per-node __stl_string_hash div new_n rechain,
// swap and free. Callers 0x0060D1BD (insert_unique shape); neighbours
// 0x0060CD16 (string bkt_num) and 0x0060CFFF (_Construct pair<string,I>).

#include <string>
#include <hash_map>

template class _STL::hash_map<_STL::string, unsigned int,
	_STL::hash<_STL::string>, _STL::equal_to<_STL::string>,
	_STL::allocator<_STL::pair<const _STL::string, unsigned int> > >;
