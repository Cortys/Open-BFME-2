// ?rva0033BFA6@Rva0033BFA6@@QAE?AURva0033BFA6Iter@@PAURva0033BFA6Node@@0ABURva0033BFA6Key@@0@Z
// partial score=0.97 date=2026-09-29
// ?rva0033BFA6@Rva0033BFA6@@QAE?AURva0033BFA6Iter@@PAURva0033BFA6Node@@0ABURva0033BFA6Key@@0@Z
// partial score=0.97 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0033BFA6@Rva0033BFA6@@QAE?AURva0033BFA6Iter@@PAU1@0ABU1@0@Z present-unmatched
struct Rva002CF120;
void *__stdcall Rva002CF84DCreate(const Rva002CF120 *src);
namespace _STL {
	struct _Rb_tree_node_base {};
	template <typename D> class _Rb_global {
	public:
		static void _Rebalance(_Rb_tree_node_base *x, _Rb_tree_node_base *&root);
	};
}
struct Rva0033BFA6Key {
	int lo;
	int hi;
};
struct Rva0033BFA6Node {
	int _c0;
	Rva0033BFA6Node *_parent;
	Rva0033BFA6Node *_left;
	Rva0033BFA6Node *_right;
	Rva0033BFA6Key _key;
};
struct Rva0033BFA6Comp {
	bool operator()(const void *a, const void *b) const;
};
struct Rva0033BFA6Iter {
	Rva0033BFA6Node *node;
};
struct Rva0033BFA6 {
	Rva0033BFA6Node *_head;
	int _size;
	Rva0033BFA6Comp _comp;
	Rva0033BFA6Iter rva0033BFA6(Rva0033BFA6Node *x, Rva0033BFA6Node *y, const Rva0033BFA6Key &v, Rva0033BFA6Node *w);
};
Rva0033BFA6Iter Rva0033BFA6::rva0033BFA6(Rva0033BFA6Node *x, Rva0033BFA6Node *y, const Rva0033BFA6Key &v, Rva0033BFA6Node *w)
{
	Rva0033BFA6Node *z;
	if (y == _head || (w == 0 && (x != 0 || _comp((const void *)&v, (const void *)&y->_key)))) {
		z = (Rva0033BFA6Node *)Rva002CF84DCreate((const Rva002CF120 *)&v);
		y->_left = z;
		if (y == _head) {
			_head->_parent = z;
			_head->_right = z;
		} else if (y == _head->_left) {
			_head->_left = z;
		}
	} else {
		z = (Rva0033BFA6Node *)Rva002CF84DCreate((const Rva002CF120 *)&v);
		y->_right = z;
		if (y == _head->_right) {
			_head->_right = z;
		}
	}
	z->_parent = y;
	z->_left = 0;
	z->_right = 0;
	_STL::_Rb_global<bool>::_Rebalance((_STL::_Rb_tree_node_base *)z, (_STL::_Rb_tree_node_base *&)_head->_parent);
	++_size;
	Rva0033BFA6Iter it;
	it.node = z;
	return it;
}
