// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
//
// ?rva004D1C81@Rva004D1C81@@QAE?AURva004D1C81Iter@@PAURva004D1C81Node@@0ABURva004D1C81Key@@0@Z retail 0x004D1C81 138B
// _M_insert worker for map<unsigned short,int> (pair<const unsigned short,int> value, WORD key at +0x10).
// Real _M_insert for this GH tree already rowed at 0x00157130 (175B, different flags); this 138B /O1 copy
// is the WWLib out-of-line copy called by insert_unique 0x0046ABA6. Calls honest node factory 0x004DCC62
// (0x18 node, pair construct) plus rowed _Rebalance 0x00025490. Shape matches honest precedent
// Rva0046AC52.cpp and WORD-key precedent stlport_rb_tree_BfmeStringRecord004D05B8_insert.cpp
// (mov cx cmp jb). Callers 0x0046AC0C 0x0046E38E.
struct Rva004D1C81;
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
		friend struct ::Rva004D1C81;
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
class Rva004DCC62
{
public:
	void *rva004DCC62(const void *src);
};
struct Rva004D1C81Node {
	int _c0;
	Rva004D1C81Node *_parent;
	Rva004D1C81Node *_left;
	Rva004D1C81Node *_right;
	unsigned short _key10;
	unsigned short _pad12;
	int _val14;
};
struct Rva004D1C81Key {
	unsigned short key;
	int val;
};
struct Rva004D1C81Iter {
	Rva004D1C81Node *node;
	Rva004D1C81Iter(Rva004D1C81Node *n);
};
// ??0Rva004D1C81Iter@@QAE@PAURva004D1C81Node@@@Z present-unmatched
inline Rva004D1C81Iter::Rva004D1C81Iter(Rva004D1C81Node *n) : node(n) {}
struct Rva004D1C81 {
	Rva004D1C81Node *_head;
	unsigned int _size;
	Rva004D1C81Iter rva004D1C81(Rva004D1C81Node *x, Rva004D1C81Node *y, const Rva004D1C81Key &v, Rva004D1C81Node *w);
};
Rva004D1C81Iter Rva004D1C81::rva004D1C81(Rva004D1C81Node *x, Rva004D1C81Node *y, const Rva004D1C81Key &v, Rva004D1C81Node *w)
{
	Rva004D1C81Node *z;
	if (y == _head || (w == 0 && (x != 0 || v.key < y->_key10))) {
		z = (Rva004D1C81Node *)((Rva004DCC62 *)this)->rva004DCC62((const void *)&v);
		y->_left = z;
		if (y == _head) {
			_head->_parent = z;
			_head->_right = z;
		} else if (y == _head->_left) {
			_head->_left = z;
		}
	} else {
		z = (Rva004D1C81Node *)((Rva004DCC62 *)this)->rva004DCC62((const void *)&v);
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
	return Rva004D1C81Iter(z);
}
