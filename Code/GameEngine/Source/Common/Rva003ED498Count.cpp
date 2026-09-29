// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
// ?Rva003ED498Count@@YAXPBX@Z @ 0x003ED498 77B
// Free bit-count walker over global RB-tree at 0x00A02E50 via rowed _M_increment 0x00024250.
// For each node tests bit m_14 in caller vector bitset and incs m_18; callers 0x003ED658/0x003ED989 pass this.
// Neighbour StringRecordCopyBFME2.cpp shares /O1 /EHsc STLport flags and vector idioms.

namespace _STL
{
typedef bool _Rb_tree_Color_type;
struct _Rb_tree_node_base
{
	_Rb_tree_Color_type _M_color;
	_Rb_tree_node_base *_M_parent;
	_Rb_tree_node_base *_M_left;
	_Rb_tree_node_base *_M_right;
};
template <class Dummy> class _Rb_global
{
public:
	static _Rb_tree_node_base *__cdecl _M_increment(_Rb_tree_node_base *);
};
}

struct BitRange
{
	unsigned const *m_begin;
	unsigned const *m_end;
};
struct TreeNode
{
	_STL::_Rb_tree_node_base m_base;
	int m_10;
	unsigned m_14;
	unsigned m_18;
};
extern _STL::_Rb_tree_node_base *g_00A02E50;
void __cdecl Rva003ED498Count(void const *arg)
{
	_STL::_Rb_tree_node_base *n = g_00A02E50->_M_left;
	if (n == g_00A02E50)
		return;
	BitRange const *r = (BitRange const *)arg;
	do
	{
		TreeNode *tn = (TreeNode *)n;
		unsigned bits = tn->m_14;
		unsigned const *begin = r->m_begin;
		unsigned const *finish = r->m_end;
		unsigned count = (unsigned)(finish - begin);
		unsigned words = bits >> 5;
		if (count > words)
		{
			unsigned mask = 1u << (bits & 31);
			if ((begin[words] & mask) != 0)
				++tn->m_18;
		}
		n = _STL::_Rb_global<bool>::_M_increment(n);
	} while (n != g_00A02E50);
}
