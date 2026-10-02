// ?rva0043B429@Rva0043B2E2@@QAE?AU?$pair@U?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@_N@_STL@@ABU?$pair@$$CBHPAX@3@@Z
// partial score=1.0 date=2026-10-02
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva0043B3A1Hidden@Rva0043B2E2@@QAE?AU?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@PAURva0043B2E2Node@@0PBH0@Z @0x0043B3A1 136B ICF twin of rowed insert worker returning iterator for hidden-ret callers
// Evidence: same 136B body as rowed ?rva0043B3A1@Rva0043B2E2@@QAEXAAPAU... via same factory 0x0043B30F plus Rebalance 0x00025490; callers at 0x0043B485/0x0043B48B via insert_unique 0x0043B429
// ?rva0043B429@Rva0043B2E2@@QAE?AU?$pair@U?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@_N@_STL@@ABU?$pair@$$CBHPAX@3@@Z @0x0043B429 134B via STLPort insert_unique plus rowed decrement and ICF insert worker
// Evidence: 134B same shape as rowed unsigned insert_unique 0x00534827 modulo signed setl/jge; callers at 0x0043B648; calls rowed _M_decrement 0x000242C0 plus ICF insert worker 0x0043B3A1
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
  typedef _STL::pair<const int, void*> V;
  typedef _STL::_Rb_tree_iterator<V, _STL::_Nonconst_traits<V> > iterator;
  void *rva0043B30F(const void *src);
  iterator rva0043B3A1Hidden(Rva0043B2E2Node *a, Rva0043B2E2Node *b, const int *v, Rva0043B2E2Node *c);
  _STL::pair<iterator, bool> rva0043B429(const V &v);
};
// ?rva0043B3A1Hidden@Rva0043B2E2@@QAE?AU?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@PAURva0043B2E2Node@@0PBH0@Z present-unmatched
Rva0043B2E2::iterator Rva0043B2E2::rva0043B3A1Hidden(Rva0043B2E2Node *a, Rva0043B2E2Node *b, const int *v, Rva0043B2E2Node *c)
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
	iterator ret;
	ret._M_node = (::_STL::_Rb_tree_node_base *)node;
	return ret;
}
// ?rva0043B429@Rva0043B2E2@@QAE?AU?$pair@U?$_Rb_tree_iterator@U?$pair@$$CBHPAX@_STL@@U?$_Nonconst_traits@U?$pair@$$CBHPAX@_STL@@@2@@_STL@@_N@_STL@@ABU?$pair@$$CBHPAX@3@@Z present-unmatched
_STL::pair<Rva0043B2E2::iterator, bool> Rva0043B2E2::rva0043B429(const V &v)
{
	Rva0043B2E2Node *y = header00;
	Rva0043B2E2Node *x = header00->parent04;
	bool comp = true;
	while (x != 0) {
		y = x;
		comp = _STL::less<int>()(v.first, x->m_key10);
		x = comp ? x->left08 : x->right0C;
	}
	iterator j;
	j._M_node = (::_STL::_Rb_tree_node_base *)y;
	if (comp && y == header00->left08) {
		return _STL::pair<iterator, bool>(rva0043B3A1Hidden(y, y, (const int *)&v, 0), true);
	}
	if (comp)
		--j;
	if (_STL::less<int>()(((Rva0043B2E2Node *)j._M_node)->m_key10, v.first)) {
		return _STL::pair<iterator, bool>(rva0043B3A1Hidden(x, y, (const int *)&v, 0), true);
	}
	return _STL::pair<iterator, bool>(j, false);
}
