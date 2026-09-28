// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva004075E0@Rva004075E0@@QAE?AURva004075E0Iter@@PAURva004075E0Node@@0ABURva004075E0Key@@0@Z retail 0x004075E0 136B
// Evidence: unlock lane; rowed _M_create_node uintbool 0x002D464E plus _Rebalance 0x00025490 plus inlined less uint; callers 0x004076CA 0x00407CE9; prev Rva004074B6 next Rva004076EE same /O1.
struct Rva004075E0;
namespace _STL {
	template <typename T> class allocator {};
	template <typename T> struct _Select1st {};
	template <typename T> struct less {};
	template <typename A, typename B> struct pair { A first; B second; };
	struct _Rb_tree_node_base {};
	template <typename V> struct _Rb_tree_node {};
	template <typename K, typename V, typename KOV, typename C, typename A>
	class _Rb_tree {
	public:
		typedef V value_type;
		typedef _Rb_tree_node<V> *_Link_type;
		friend struct ::Rva004075E0;
	protected:
		_Link_type _M_create_node(const value_type &v);
	};
	template <typename D> class _Rb_global {
	public:
		static void _Rebalance(_Rb_tree_node_base *x, _Rb_tree_node_base *&root);
	};
}
struct Rva004075E0Node {
	int _c0;
	Rva004075E0Node *_parent;
	Rva004075E0Node *_left;
	Rva004075E0Node *_right;
	unsigned int _key10;
	bool _val14;
	char _pad15[3];
};
struct Rva004075E0Key {
	unsigned int key;
	bool val;
	char _pad[3];
};
struct Rva004075E0Iter {
	Rva004075E0Node *node;
	Rva004075E0Iter(Rva004075E0Node *n);
};
// ??0Rva004075E0Iter@@QAE@PAURva004075E0Node@@@Z present-unmatched
inline Rva004075E0Iter::Rva004075E0Iter(Rva004075E0Node *n) : node(n) {}
struct Rva004075E0 {
	Rva004075E0Node *_head;
	int _size;
	Rva004075E0Iter rva004075E0(Rva004075E0Node *x, Rva004075E0Node *y, const Rva004075E0Key &v, Rva004075E0Node *w);
};
typedef _STL::_Rb_tree<unsigned int, _STL::pair<const unsigned int, bool>, _STL::_Select1st<_STL::pair<const unsigned int, bool> >, _STL::less<unsigned int>, _STL::allocator<_STL::pair<const unsigned int, bool> > > UIntBoolTree075E0;
Rva004075E0Iter Rva004075E0::rva004075E0(Rva004075E0Node *x, Rva004075E0Node *y, const Rva004075E0Key &v, Rva004075E0Node *w)
{
	Rva004075E0Node *z;
	if (y == _head || (w == 0 && (x != 0 || v.key < y->_key10))) {
		z = (Rva004075E0Node *)((UIntBoolTree075E0 *)this)->_M_create_node((const UIntBoolTree075E0::value_type &)v);
		y->_left = z;
		if (y == _head) {
			_head->_parent = z;
			_head->_right = z;
		} else if (y == _head->_left) {
			_head->_left = z;
		}
	} else {
		z = (Rva004075E0Node *)((UIntBoolTree075E0 *)this)->_M_create_node((const UIntBoolTree075E0::value_type &)v);
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
	return Rva004075E0Iter(z);
}
