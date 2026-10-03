// cl: /O1
// stlport
//
// ??$__find@U?$_Rb_tree_iterator@HU?$_Const_traits@H@_STL@@@_STL@@H@_STL@@YA?AU?$_Rb_tree_iterator@HU?$_Const_traits@H@_STL@@@0@U10@0ABHABUinput_iterator_tag@0@@Z @0x0054E7C3 39B
// ??$find@U?$_Rb_tree_iterator@HU?$_Const_traits@H@_STL@@@_STL@@H@_STL@@YA?AU?$_Rb_tree_iterator@HU?$_Const_traits@H@_STL@@@0@U10@0ABH@Z @0x0054E82C 32B
// _STL::find / __find over set<int> const iterators (linear scan via rowed _M_increment 0x00024250).
// Evidence: retail loop cmp [eax+0x10] vs [edx] then increment matches input-iterator __find;
// forwarder at 0x0054E82C pushes dummy tag via lea [ebp+0xB] and calls 0x0054E7C3; chain 0x0054E86D
// calls find(begin at [header+8] end header) and tests != end; callers rowed; prev/next share /O1.
#include <set>

template _STL::set<int, _STL::less<int>, _STL::allocator<int> >::iterator _STL::find(_STL::set<int, _STL::less<int>, _STL::allocator<int> >::iterator, _STL::set<int, _STL::less<int>, _STL::allocator<int> >::iterator, const int &);
