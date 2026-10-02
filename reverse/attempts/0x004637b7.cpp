// ?rva004637B7@Rva00463782@@QAEPAPAU_Rb_tree_node_base@_STL@@PAPAU23@PAU23@1PBVRva0046267A@@H@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP=
// stlport
// ?rva004637B7@Rva00463782@@QAEPAPAU_Rb_tree_node_base@_STL@@PAPAU23@PAU23@1PBVRva0046267A@@H@Z 0x004637B7 136B
// Rva0046267A tree insert core: create via rowed 0x4634BA in both the right
// and left branches then link rebalance via rowed 0x25490 count and out.
// Evidence: callees 0x4634BA just landed plus 0x25490 rowed; callers at
// 0x4638A1 plus 0x463EB7; key compare of the Rva int at +0x10 same as the
// 0x46383F walker; prev 0x463782 same class.
#include <map>

class Rva0046267A;

struct Rva004634BANode;

struct Rva004634BANode *__stdcall Rva004634BACreate(const class Rva0046267A &x);

class Rva00463782
{
	_STL::_Rb_tree_node_base *m_header;
	unsigned int m_count;
public:
	_STL::_Rb_tree_node_base **rva004637B7(_STL::_Rb_tree_node_base **out, _STL::_Rb_tree_node_base *x, _STL::_Rb_tree_node_base *pos, const class Rva0046267A *val, int flag);
};

// ?rva004637B7@Rva00463782@@QAEPAPAU_Rb_tree_node_base@_STL@@PAPAU23@PAU23@1PBVRva0046267A@@H@Z present-unmatched
_STL::_Rb_tree_node_base **Rva00463782::rva004637B7(_STL::_Rb_tree_node_base **out, _STL::_Rb_tree_node_base *x, _STL::_Rb_tree_node_base *pos, const class Rva0046267A *val, int flag)
{
	_STL::_Rb_tree_node_base *node;
	if (pos == m_header)
		goto left_insert;
	if (flag != 0)
		goto right_insert;
	if (x != 0)
		goto left_insert;
	if (*(const unsigned *)val < *(const unsigned *)((const char *)pos + 0x10))
		goto left_insert;
right_insert:
	node = (_STL::_Rb_tree_node_base *)Rva004634BACreate(*val);
	pos->_M_right = node;
	if (pos == m_header->_M_right)
		m_header->_M_right = node;
	goto link;
left_insert:
	node = (_STL::_Rb_tree_node_base *)Rva004634BACreate(*val);
	pos->_M_left = node;
	if (pos == m_header) {
		m_header->_M_parent = node;
	} else if (pos == m_header->_M_left) {
		m_header->_M_left = node;
	}
link:
	node->_M_left = 0;
	node->_M_right = 0;
	node->_M_parent = pos;
	_STL::_Rb_global<bool>::_Rebalance(node, m_header->_M_parent);
	++m_count;
	*out = node;
	return out;
}
