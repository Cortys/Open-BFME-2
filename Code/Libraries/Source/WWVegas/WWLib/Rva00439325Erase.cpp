// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
//
// ?rva00439325@Rva00439325@@QAEXPAURva00439325Node@@@Z @0x00439325 59B.
// Rb erase: rebalance-for-erase then destroy Rva0023D377 value at +16 and free.
// Evidence: chain lane (calls landed 0x0023D377); same 59B shape as landed
// Rva00383F9CErase 0x00383F9C (rebalance 0x00025620 plus dtor plus _free);
// caller 0x0043963C; neighbours share flags.
extern "C" void __cdecl free(void *block);

namespace _STL
{
typedef bool _Rb_tree_Color_type;
struct _Rb_tree_node_base
{
	typedef _Rb_tree_Color_type _Color_type;
	typedef _Rb_tree_node_base *_Base_ptr;
	_Color_type _M_color;
	_Base_ptr _M_parent;
	_Base_ptr _M_left;
	_Base_ptr _M_right;
};
template <class _Dummy> class _Rb_global
{
public:
	static _Rb_tree_node_base *__cdecl _Rebalance_for_erase(
		_Rb_tree_node_base *__z, _Rb_tree_node_base *&__root,
		_Rb_tree_node_base *&__leftmost, _Rb_tree_node_base *&__rightmost);
};
}

struct Rva00438FC5
{
	~Rva00438FC5();
};

struct Rva0023D377
{
	unsigned int m_00;
	Rva00438FC5 m_04;
	~Rva0023D377();
};

struct Rva00439325Node : public _STL::_Rb_tree_node_base
{
	Rva0023D377 m10;
};

class Rva00439325
{
	_STL::_Rb_tree_node_base *m_header;
	int m_count;
public:
	void rva00439325(Rva00439325Node *pos);
};

void Rva00439325::rva00439325(Rva00439325Node *pos)
{
	_STL::_Rb_tree_node_base *toDelete = _STL::_Rb_global<bool>::_Rebalance_for_erase(
		pos, m_header->_M_parent, m_header->_M_left, m_header->_M_right);
	((Rva00439325Node *)toDelete)->m10.~Rva0023D377();
	if (toDelete)
		free(toDelete);
	--m_count;
}
