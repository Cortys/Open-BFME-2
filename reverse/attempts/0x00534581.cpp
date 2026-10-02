// ??0?$_Rb_tree@HU?$pair@$$CBHH@_STL@@U?$_Select1st@U?$pair@$$CBHH@_STL@@@2@U?$less@H@2@V?$allocator@U?$pair@$$CBHH@_STL@@@2@@_STL@@QAE@ABV01@@Z
// partial score=0.95 date=2026-10-02
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// Map<int,int> tree copy ctor 0x00534581 via _M_copy_005344C8 plus base plus allocator.
// Evidence: unlock lane callees rowed or pinned; callers unblocked 2; neighbours share flags.
#define _M_copy _M_copy_005344C8
#include <map>
typedef _STL::_Rb_tree<int, _STL::pair<const int, int>, _STL::_Select1st<_STL::pair<const int, int> >, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > MapIntIntTree00534581;
template <> MapIntIntTree00534581::_Link_type MapIntIntTree00534581::_M_clone_node(MapIntIntTree00534581::_Link_type);
template MapIntIntTree00534581::_Rb_tree(const MapIntIntTree00534581 &);
#undef _M_copy
