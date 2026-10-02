// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva0043B35D@Rva0043B2E2@@QAEXU?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@0@Z @0x0043B35D 68B via STLPort range erase plus rowed clear
// Evidence: vendor/stlport/stl/_tree.h erase(first last) calls clear on full range else loops via increment plus single erase
// Retail calls clear 0x0043B334 plus increment 0x00024250 plus single erase 0x005530A8 for map int to voidptr
// Same 68B shape as rowed range erase 0x0007300F in Rva0007300FErase.cpp and 0x004ABC85 modulo clear callee
// Owner Rva0043B2E2 header at +0x00 per RvaTreeEraseClearFamily.cpp; unblocks 0x0043B4EC
#include <map>
struct Rva0043B2E2Node {
  unsigned _M_color;
  Rva0043B2E2Node *parent04;
  Rva0043B2E2Node *left08;
  Rva0043B2E2Node *right0C;
};
struct Rva0043B2E2 {
  Rva0043B2E2Node *header00;
  unsigned count04;
  char unknown08[16];
  void rva0043B334();
  typedef _STL::pair<const int, void*> V;
  typedef _STL::_Rb_tree_iterator<V, _STL::_Nonconst_traits<V> > iterator;
  // ?begin@Rva0043B2E2@@QAE?AU?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@XZ present-unmatched
  iterator begin() {
    iterator it;
    it._M_node = (::_STL::_Rb_tree_node_base*)header00->left08;
    return it;
  }
  // ?end@Rva0043B2E2@@QAE?AU?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@XZ present-unmatched
  iterator end() {
    iterator it;
    it._M_node = (::_STL::_Rb_tree_node_base*)header00;
    return it;
  }
  void rva0043B35D(iterator first, iterator last);
  unsigned int rva0043B4EC(const int &key);
};
void Rva0043B2E2::rva0043B35D(iterator first, iterator last) {
  typedef V VV;
  typedef _STL::_Rb_tree<int, VV, _STL::_Select1st<VV>, _STL::less<int>, _STL::allocator<VV> > Tree;
  if (first == begin() && last == end())
    rva0043B334();
  else
    while (first != last)
      ((Tree*)this)->erase(first++);
}
unsigned int Rva0043B2E2::rva0043B4EC(const int &key) {
  typedef _STL::pair<const int, int> V2;
  typedef _STL::_Rb_tree<int, V2, _STL::_Select1st<V2>, _STL::less<int>, _STL::allocator<V2> > TreeIntInt;
  typedef _STL::_Rb_tree_iterator<V2, _STL::_Nonconst_traits<V2> > IterIntInt;
  _STL::pair<IterIntInt, IterIntInt> p = ((TreeIntInt*)this)->equal_range(key);
  unsigned int n = _STL::distance(*(iterator*)&p.first, *(iterator*)&p.second);
  rva0043B35D(*(iterator*)&p.first, *(iterator*)&p.second);
  return n;
}
