// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva0046AC52@Rva0046AC52@@QAE?AURva0046AC52Iter@@PAURva0046AC52Node@@0ABURva0046AC52Key@@0@Z retail 0x0046AC52 136B
// Evidence: unlock lane; rowed _M_create_node uintbool 0x002D464E plus _Rebalance 0x00025490 plus inlined less uint; callers 0x002D569F 0x0046E5CD plus rowed uintbool create 0x002D464E plus Rebalance 0x00025490.
struct Rva0046AC52;
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
		friend struct ::Rva0046AC52;
	protected:
		_Link_type _M_create_node(const value_type &v);
	};
	template <typename D> class _Rb_global {
	public:
		static void _Rebalance(_Rb_tree_node_base *x, _Rb_tree_node_base *&root);
		static _Rb_tree_node_base *_M_decrement(_Rb_tree_node_base *x);
		static _Rb_tree_node_base *_M_increment(_Rb_tree_node_base *x);
	};
}
struct Rva0046AC52Node {
	int _c0;
	Rva0046AC52Node *_parent;
	Rva0046AC52Node *_left;
	Rva0046AC52Node *_right;
	int _key10;
	bool _val14;
	char _pad15[3];
};
struct Rva0046AC52Key {
	int key;
	bool val;
	char _pad[3];
};
struct Rva0046AC52Iter {
	Rva0046AC52Node *node;
	Rva0046AC52Iter(Rva0046AC52Node *n);
};
// ??0Rva0046AC52Iter@@QAE@PAURva0046AC52Node@@@Z present-unmatched
inline Rva0046AC52Iter::Rva0046AC52Iter(Rva0046AC52Node *n) : node(n) {}
struct Rva0046AC52Pair {
	Rva0046AC52Node *first;
	bool second;
	char _pad[3];
	Rva0046AC52Pair(Rva0046AC52Node *f, bool s);
	Rva0046AC52Pair(Rva0046AC52Iter it, bool s);
};
// ??0Rva0046AC52Pair@@QAE@PAURva0046AC52Node@@_N@Z present-unmatched
inline Rva0046AC52Pair::Rva0046AC52Pair(Rva0046AC52Node *f, bool s) : first(f), second(s) {}
// ??0Rva0046AC52Pair@@QAE@URva0046AC52Iter@@_N@Z present-unmatched
inline Rva0046AC52Pair::Rva0046AC52Pair(Rva0046AC52Iter it, bool s) : first(it.node), second(s) {}
struct Rva0046AC52 {
	Rva0046AC52Node *_head;
	unsigned int _size;
	Rva0046AC52Iter rva0046AC52(Rva0046AC52Node *x, Rva0046AC52Node *y, const Rva0046AC52Key &v, Rva0046AC52Node *w);
	Rva0046AC52Pair rva00407668(const Rva0046AC52Key &v);
	Rva0046AC52Iter rva00407C7F(Rva0046AC52Iter position, const Rva0046AC52Key &v);
};
typedef _STL::_Rb_tree<unsigned int, _STL::pair<const unsigned int, bool>, _STL::_Select1st<_STL::pair<const unsigned int, bool> >, _STL::less<unsigned int>, _STL::allocator<_STL::pair<const unsigned int, bool> > > UIntBoolTree075E0;
Rva0046AC52Iter Rva0046AC52::rva0046AC52(Rva0046AC52Node *x, Rva0046AC52Node *y, const Rva0046AC52Key &v, Rva0046AC52Node *w)
{
	Rva0046AC52Node *z;
	if (y == _head || (w == 0 && (x != 0 || v.key < y->_key10))) {
		z = (Rva0046AC52Node *)((UIntBoolTree075E0 *)this)->_M_create_node((const UIntBoolTree075E0::value_type &)v);
		y->_left = z;
		if (y == _head) {
			_head->_parent = z;
			_head->_right = z;
		} else if (y == _head->_left) {
			_head->_left = z;
		}
	} else {
		z = (Rva0046AC52Node *)((UIntBoolTree075E0 *)this)->_M_create_node((const UIntBoolTree075E0::value_type &)v);
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
	return Rva0046AC52Iter(z);
}
