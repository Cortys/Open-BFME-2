// ?rva00463E4D@Rva00463782@@QAEPAPAU_Rb_tree_node_base@_STL@@PAPAU23@PAU23@PBVRva0046267A@@@Z
// partial score=0.95 date=2026-10-04
// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP=
// stlport
// ?rva00463E4D@Rva00463782@@QAEPAPAU_Rb_tree_node_base@_STL@@PAPAU23@PAU23@PBVRva0046267A@@@Z @0x00463E4D 294B: _Rb_tree insert_unique with hint for Rva0046267A set.
// Evidence: callees _M_increment 0x00024250 plus _M_decrement 0x000242C0 plus rva004637B7 0x004637B7 plus rva0046383F 0x0046383F all rowed; caller 0x00464431; prev/next share flags and node layout with value at +0x10.
#include <map>

class Rva0046267A
{
public:
	unsigned int m_key;
};

struct Rva004634BANode;

struct Rva0046383FOut
{
	_STL::_Rb_tree_node_base *node;
	bool inserted;
};

class Rva00463782
{
	_STL::_Rb_tree_node_base *m_header;
	unsigned int m_count;
public:
	_STL::_Rb_tree_node_base **rva004637B7(_STL::_Rb_tree_node_base **out, _STL::_Rb_tree_node_base *x, _STL::_Rb_tree_node_base *pos, const class Rva0046267A *val, int flag);
	_STL::_Rb_tree_node_base *rva0046383F(struct Rva0046383FOut *out, const class Rva0046267A *val);
	_STL::_Rb_tree_node_base **rva00463E4D(_STL::_Rb_tree_node_base **out, _STL::_Rb_tree_node_base *pos, const class Rva0046267A *val);
};

_STL::_Rb_tree_node_base **Rva00463782::rva00463E4D(_STL::_Rb_tree_node_base **out, _STL::_Rb_tree_node_base *pos, const Rva0046267A *v)
{
	if (pos == m_header->_M_left) {
		if (m_count <= 0) {
			Rva0046383FOut tmp;
			rva0046383F(&tmp, v);
			*out = tmp.node;
			return out;
		}
		if (*(const unsigned int *)v < *(const unsigned int *)((const char *)pos + 0x10)) {
			*rva004637B7(out, pos, pos, v, 0);
			return out;
		} else {
			bool comp_pos_v = *(const unsigned int *)((const char *)pos + 0x10) < *(const unsigned int *)v;
			if (comp_pos_v == false) {
				*out = pos;
				return out;
			}
			_STL::_Rb_tree_node_base *after = _STL::_Rb_global<bool>::_M_increment(pos);
			if (after == m_header) {
				*rva004637B7(out, 0, pos, v, 1);
				return out;
			}
			if (*(const unsigned int *)v < *(const unsigned int *)((const char *)after + 0x10)) {
				if (pos->_M_right == 0) {
					*rva004637B7(out, 0, pos, v, 1);
					return out;
				} else {
					*rva004637B7(out, after, after, v, 0);
					return out;
				}
			} else {
				Rva0046383FOut tmp;
				rva0046383F(&tmp, v);
				*out = tmp.node;
				return out;
			}
		}
	} else if (pos == m_header) {
		_STL::_Rb_tree_node_base *right = m_header->_M_right;
		if (*(const unsigned int *)((const char *)right + 0x10) < *(const unsigned int *)v) {
			*rva004637B7(out, 0, right, v, 1);
			return out;
		} else {
			Rva0046383FOut tmp;
			rva0046383F(&tmp, v);
			*out = tmp.node;
			return out;
		}
	} else {
		_STL::_Rb_tree_node_base *before = _STL::_Rb_global<bool>::_M_decrement(pos);
		bool comp_v_pos = *(const unsigned int *)v < *(const unsigned int *)((const char *)pos + 0x10);
		if (comp_v_pos && *(const unsigned int *)((const char *)before + 0x10) < *(const unsigned int *)v) {
			if (before->_M_right == 0) {
				*rva004637B7(out, 0, before, v, 1);
				return out;
			} else {
				*rva004637B7(out, pos, pos, v, 0);
				return out;
			}
		} else {
			_STL::_Rb_tree_node_base *after = _STL::_Rb_global<bool>::_M_increment(pos);
			bool comp_pos_v = !comp_v_pos;
			if (!comp_v_pos)
				comp_pos_v = *(const unsigned int *)((const char *)pos + 0x10) < *(const unsigned int *)v;
			if ((!comp_v_pos) && comp_pos_v && (after == m_header || *(const unsigned int *)v < *(const unsigned int *)((const char *)after + 0x10))) {
				if (pos->_M_right == 0) {
					*rva004637B7(out, 0, pos, v, 1);
					return out;
				} else {
					*rva004637B7(out, after, after, v, 0);
					return out;
				}
			} else {
				if (comp_v_pos == comp_pos_v) {
					*out = pos;
					return out;
				} else {
					Rva0046383FOut tmp;
					rva0046383F(&tmp, v);
					*out = tmp.node;
					return out;
				}
			}
		}
	}
}
