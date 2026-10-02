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
  int m_key10;
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
  void *rva0043B30F(const void *src);
  void rva0043B3A1(Rva0043B2E2Node *&out, Rva0043B2E2Node *a, Rva0043B2E2Node *b, const int *v, Rva0043B2E2Node *c);
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

// ?rva0043B3A1@Rva0043B2E2@@QAEXAAPAU... @0x0043B3A1 136B: rb-tree insert worker
// for the 0x9C-node tree (chain from 0x0043B30F): position it by header links,
// create the node through pinned member twin of free NewNode 0x0043B30F, link
// it left or right, repair header root/ends, zero links, set parent, rowed
// _Rebalance 0x00025490, bump count and store out. Callers at 0x0043B48B and
// 0x0043B59F. Retail sets ecx=this before the NewNode call so the factory is
// a thiscall member; the free 37B body ignores the dead this in ecx, hence
// the twin pin plus alternatename below per Rva004152E6NewNode precedent.
// Shape follows Rva0018C262::rva0018C33F (138B via rowed factory plus Rebalance).
// ?rva0043B3A1@Rva0043B2E2@@QAEXAAPAU... present-unmatched
void Rva0043B2E2::rva0043B3A1(Rva0043B2E2Node *&out, Rva0043B2E2Node *a, Rva0043B2E2Node *b, const int *v, Rva0043B2E2Node *c)
{
	Rva0043B2E2Node *node;
	if (b != header00 && (c != 0 || (a == 0 && *v >= b->m_key10))) {
		node = (Rva0043B2E2Node *)rva0043B30F(v);
		b->right0C = node;
		Rva0043B2E2Node *root = header00;
		if (b == root->right0C)
			root->right0C = node;
	} else {
		node = (Rva0043B2E2Node *)rva0043B30F(v);
		b->left08 = node;
		Rva0043B2E2Node *root = header00;
		if (b == root) {
			root->parent04 = node;
			header00->right0C = node;
		} else if (b == root->left08) {
			root->left08 = node;
		}
	}
	node->left08 = 0;
	node->right0C = 0;
	node->parent04 = b;
	_STL::_Rb_global<bool>::_Rebalance((_STL::_Rb_tree_node_base *)node, (_STL::_Rb_tree_node_base *&)header00->parent04);
	++count04;
	out = node;
}
// Bind the member-twin call above to the rowed free body: same 0x9C node,
// free body ignores the dead this in ecx per Rva004152E6NewNode precedent.
#pragma comment(linker, "/alternatename:?rva0043B30F@Rva0043B2E2@@QAEPAXPBX@Z=?Rva0043B30FNewNode@@YGPAXPBX@Z")
