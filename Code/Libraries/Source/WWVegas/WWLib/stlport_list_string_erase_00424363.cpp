// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

// ?erase@?$list@V?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@V?$allocator@V?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@2@@_STL@@QAE?AU?$_List_iterator@V?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@U?$_Nonconst_traits@V?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@2@@2@U32@@Z
// retail 0x00424363, 42 bytes. list<basic_string<char>>::erase single-iterator
// via rowed basic_string dtor 0x0007FAB3 plus _free 0x00030830. Evidence:
// unlock lane; caller 0x004246E7 in 0x004246D7; unblocks 0x004246D7.
#include <list>
#include <string>

template class _STL::list<_STL::basic_string<char> >;
