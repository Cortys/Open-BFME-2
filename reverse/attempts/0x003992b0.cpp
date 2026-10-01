// ?rva003992B0@Rva0039834C@@QAEPAURvaInsertOut@@PAU2@PBURva0039627D@@@Z
// partial score=0.98 date=2026-10-01
// ?rva003992B0@Rva0039834C@@QAEPAURvaInsertOut@@PAU2@PBURva0039627D@@@Z
// partial score=0.98 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0039834C@Rva0039834C@@QAEXAAPAURvaNode0039834C@@PAU2@1PBURva0039627D@@1@Z @0x0039834C 136B evidence: chain lane calls rowed alloc 0x00397CC9 plus Rebalance 0x00025490 plus signed key at plus10; caller 0x00399312 unblocks 0x003992B0; sibling Rva001364F7Insert same 136B shape; factory called as thiscall member per two retail mov ecx edi so pinned twin member at same address ICF with free row.
// Proven blocker note: retail passes this in ecx to the node factory (push v then mov ecx edi then call) so the factory is __thiscall; the ledger rows it as free __stdcall with identical 34B body that ignores ecx. Calling the rowed free name omits both movs (132B vs 136B). Twin member pin at 0x00397CC9 keeps the bytes and the correct target address.
struct Rva0039627D {
	int m_key;
	unsigned char m_body[12];
};
struct RvaNode0039834C {
	int _c0;
	RvaNode0039834C *_parent;
	RvaNode0039834C *_left;
	RvaNode0039834C *_right;
	int _key10;
	unsigned char _pad14[12];
};
namespace _STL {
struct _Rb_tree_node_base {};
template <typename D> class _Rb_global {
public:
	static void _Rebalance(_Rb_tree_node_base *x, _Rb_tree_node_base *&root);
	static _Rb_tree_node_base *_M_decrement(_Rb_tree_node_base *x);
};
}
struct RvaInsertOut {
	RvaNode0039834C *node;
	bool inserted;
};
struct Rva0039834C {
	RvaNode0039834C *m_root;
	unsigned m_count;
	void *rva00397CC9(const Rva0039627D &src);
	void rva0039834C(RvaNode0039834C *&out, RvaNode0039834C *a, RvaNode0039834C *b, const Rva0039627D *v, RvaNode0039834C *c);
	RvaInsertOut *rva003992B0(RvaInsertOut *out, const Rva0039627D *v);
};
void Rva0039834C::rva0039834C(RvaNode0039834C *&out, RvaNode0039834C *a, RvaNode0039834C *b, const Rva0039627D *v, RvaNode0039834C *c)
{
	RvaNode0039834C *node;
	if (b != m_root && (c != 0 || (a == 0 && v->m_key >= b->_key10))) {
		node = (RvaNode0039834C *)rva00397CC9(*v);
		b->_right = node;
		RvaNode0039834C *root = m_root;
		if (b == root->_right)
			root->_right = node;
	} else {
		node = (RvaNode0039834C *)rva00397CC9(*v);
		b->_left = node;
		RvaNode0039834C *root = m_root;
		if (b == root) {
			root->_parent = node;
			m_root->_right = node;
		} else if (b == root->_left) {
			root->_left = node;
		}
	}
	node->_left = 0;
	node->_right = 0;
	node->_parent = b;
	_STL::_Rb_global<bool>::_Rebalance((_STL::_Rb_tree_node_base *)node, (_STL::_Rb_tree_node_base *&)m_root->_parent);
	++m_count;
	out = node;
}

// ?rva003992B0@Rva0039834C@@QAEPAURvaInsertOut@@PAU2@PBURva0039627D@@@Z present-unmatched
// @0x003992B0 134B chain from worker 0x0039834C: signed-key find-or-insert over Rva0039834C. Descends with setl on value key vs node key at +0x10, decrements on the non-leftmost taken branch via rowed _M_decrement 0x000242C0, returns existing with false when the neighbour key already covers the value, else inserts through the worker reusing the value-arg slot as the node out and returns it with true.
RvaInsertOut *Rva0039834C::rva003992B0(RvaInsertOut *out, const Rva0039627D *v)
{
	RvaNode0039834C *header = m_root;
	RvaNode0039834C *x = header->_parent;
	RvaNode0039834C *y = header;
	bool comp = true;
	if (x != 0) {
		do {
			y = x;
			comp = v->m_key < x->_key10;
			x = comp ? x->_left : x->_right;
		} while (x != 0);
	}
	RvaNode0039834C *j = y;
	if (comp) {
		if (y == header->_left) {
			rva0039834C((RvaNode0039834C *&)v, y, y, v, 0);
			out->node = (RvaNode0039834C *)v;
			out->inserted = true;
			return out;
		}
		j = (RvaNode0039834C *)_STL::_Rb_global<bool>::_M_decrement((_STL::_Rb_tree_node_base *)j);
	}
	if (j->_key10 < v->m_key) {
		rva0039834C((RvaNode0039834C *&)v, x, y, v, 0);
		out->node = *(RvaNode0039834C **)&v;
		out->inserted = true;
		return out;
	}
	out->node = j;
	out->inserted = false;
	return out;
}
