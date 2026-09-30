// ?rva0013657F@Rva0013657F@@QAEXPAURvaOut13657F@@PBUTreeKey00242F5E@@@Z
// partial score=0.97 date=2026-09-30
// ?rva0013657F@Rva0013657F@@QAEXPAURvaOut13657F@@PBUTreeKey00242F5E@@@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0013657F@Rva0013657F@@QAEXPAURvaOut13657F@@PBUTreeKey00242F5E@@@Z @0x0013657F 134B.
// Insert-unique worker over set<TreeKey00242F5E> nodes (base 0x10 plus 8-byte
// key at +0x10): walks from root remembering parent y and direction comp,
// reuses rowed 0x001364F7 insert and rowed _M_decrement; returns pair
// node+bool through out. Evidence: calls 0x001364F7 just landed by this
// worker with out reused from param slot plus _M_decrement 0x000242C0;
// caller 0x00136642 hinted variant; layout matches Rva001364F7Insert.cpp.
struct TreeKey00242F5E { unsigned m_id; char _pad[4]; };
struct RvaNode1364F7 {
	int _c0;
	RvaNode1364F7 *_parent;
	RvaNode1364F7 *_left;
	RvaNode1364F7 *_right;
	TreeKey00242F5E _key;
};
struct RvaOut13657F {
	RvaNode1364F7 *node;
	bool inserted;
};
class Rva001364F7 {
public:
	void rva001364F7(RvaNode1364F7 *&out, RvaNode1364F7 *a, RvaNode1364F7 *b, const TreeKey00242F5E *v, RvaNode1364F7 *c);
};
namespace _STL {
struct _Rb_tree_node_base {};
template <typename D> class _Rb_global {
public:
	static _Rb_tree_node_base *_M_decrement(_Rb_tree_node_base *__x);
};
}
class Rva0013657F {
public:
	void rva0013657F(RvaOut13657F *out, const TreeKey00242F5E *v);
private:
	RvaNode1364F7 *m_header;
	unsigned m_count;
};

// ?rva0013657F@Rva0013657F@@QAEXPAURvaOut13657F@@PBUTreeKey00242F5E@@@Z present-unmatched
void Rva0013657F::rva0013657F(RvaOut13657F *out, const TreeKey00242F5E *v)
{
	RvaNode1364F7 *header = m_header;
	RvaNode1364F7 *x = header->_parent;
	RvaNode1364F7 *y = header;
	bool comp = true;
	while (x != 0) {
		y = x;
		comp = v->m_id < x->_key.m_id;
		x = comp ? x->_left : x->_right;
	}
	RvaNode1364F7 *j = y;
	if (comp) {
		if (y == header->_left) {
			((Rva001364F7 *)this)->rva001364F7((RvaNode1364F7 *&)v, y, y, v, 0);
			out->node = (RvaNode1364F7 *)v;
			out->inserted = true;
			return;
		}
		j = (RvaNode1364F7 *)_STL::_Rb_global<bool>::_M_decrement((_STL::_Rb_tree_node_base *)y);
	}
	if (j->_key.m_id < v->m_id) {
		((Rva001364F7 *)this)->rva001364F7((RvaNode1364F7 *&)v, x, y, v, 0);
		out->node = (RvaNode1364F7 *)v;
		out->inserted = true;
		return;
	}
	out->node = j;
	out->inserted = false;
}
