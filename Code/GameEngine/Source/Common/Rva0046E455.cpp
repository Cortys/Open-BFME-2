// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0046E455@Rva0046E455@@QAE?AURva0046E455Iter@@PAURva0046E455Node@@0ABVRva00469BEA@@0@Z 0x0046E455 136B evidence: unlock calls rowed create 0x46AC30 plus rowed Rebalance 0x25490 same shape as rowed 0x46AC52 136B
class Rva00469BEA
{
public:
	int m_key00;
	char m_pad04[16];
};
struct Rva0046E455Node
{
	int _c0;
	Rva0046E455Node *_parent;
	Rva0046E455Node *_left;
	Rva0046E455Node *_right;
	int _key10;
	char _pad14[16];
};
struct Rva0046E455Iter
{
	Rva0046E455Node *node;
	Rva0046E455Iter(Rva0046E455Node *n);
};
// ??0Rva0046E455Iter@@QAE@PAURva0046E455Node@@@Z present-unmatched
inline Rva0046E455Iter::Rva0046E455Iter(Rva0046E455Node *n) : node(n) {}
class Rva0046AC30
{
public:
	void *rva0046AC30(const Rva00469BEA &v);
};
struct Rva0046E455Pair {
	Rva0046E455Node *first;
	bool second;
	Rva0046E455Pair(Rva0046E455Node *f, bool s);
	Rva0046E455Pair(Rva0046E455Iter it, bool s);
};
// ??0Rva0046E455Pair@@QAE@PAURva0046E455Node@@_N@Z present-unmatched
inline Rva0046E455Pair::Rva0046E455Pair(Rva0046E455Node *f, bool s) : first(f), second(s) {}
// ??0Rva0046E455Pair@@QAE@URva0046E455Iter@@_N@Z present-unmatched
inline Rva0046E455Pair::Rva0046E455Pair(Rva0046E455Iter it, bool s) : first(it.node), second(s) {}
namespace _STL {
struct _Rb_tree_node_base {};
	template <typename D> class _Rb_global {
	public:
		static void _Rebalance(_Rb_tree_node_base *x, _Rb_tree_node_base *&root);
		static _Rb_tree_node_base *_M_decrement(_Rb_tree_node_base *x);
	};
}
struct Rva0046E455
{
	Rva0046E455Node *_head;
	unsigned int _size;
	Rva0046E455Iter rva0046E455(Rva0046E455Node *x, Rva0046E455Node *y, const Rva00469BEA &v, Rva0046E455Node *w);
	Rva0046E455Pair rva0046E4DD(const Rva00469BEA &v);
};
Rva0046E455Iter Rva0046E455::rva0046E455(Rva0046E455Node *x, Rva0046E455Node *y, const Rva00469BEA &v, Rva0046E455Node *w)
{
	Rva0046E455Node *z;
	if (y == _head || (w == 0 && (x != 0 || v.m_key00 < y->_key10))) {
		z = (Rva0046E455Node *)((Rva0046AC30 *)this)->rva0046AC30(v);
		y->_left = z;
		if (y == _head) {
			_head->_parent = z;
			_head->_right = z;
		} else if (y == _head->_left) {
			_head->_left = z;
		}
	} else {
		z = (Rva0046E455Node *)((Rva0046AC30 *)this)->rva0046AC30(v);
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
	return Rva0046E455Iter(z);
}
Rva0046E455Pair Rva0046E455::rva0046E4DD(const Rva00469BEA &v)
{
	Rva0046E455Node *header = _head;
	Rva0046E455Node *x = header->_parent;
	Rva0046E455Node *y = header;
	bool comp = true;
	while (x != 0) {
		y = x;
		comp = v.m_key00 < x->_key10;
		x = comp ? x->_left : x->_right;
	}
	Rva0046E455Node *j = y;
	if (comp) {
		if (j == header->_left)
			return Rva0046E455Pair(rva0046E455(y, y, v, 0), true);
		j = (Rva0046E455Node *)_STL::_Rb_global<bool>::_M_decrement((_STL::_Rb_tree_node_base *)y);
	}
	if (j->_key10 < v.m_key00)
		return Rva0046E455Pair(rva0046E455(x, y, v, 0), true);
	return Rva0046E455Pair(j, false);
}
