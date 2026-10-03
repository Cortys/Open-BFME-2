// ?rva00504138@Rva00504138@@QAEPAVRva00064640Record@@H@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?rva00504138@Rva00504138@@QAEPAVRva00064640Record@@H@Z @ 0x00504138 (45B):
// Tree indexed access over an rb_tree of Rva00064640Record. Empty when
// begin == header returns null; n==0 returns the first value; otherwise
// advances via rowed _M_increment n times returning null on hitting the
// header. Evidence: callee _M_increment rowed; callers at 0x002BE9AE
// 0x003FD311; neighbours Rva00064640Copy and rb_tree_create_nodes.
class Rva00064640Record
{
public:
	unsigned char m_data[28];
};

namespace _STL
{
struct _Rb_tree_node_base;
template <class Dummy> class _Rb_global
{
public:
	static _Rb_tree_node_base *__cdecl _M_increment(_Rb_tree_node_base *);
};
}

struct Rva00504138Node
{
	void *m_base00[4];
	Rva00064640Record m_value10;
};

struct Rva00504138Header
{
	char m_pad00[8];
	Rva00504138Node *m_begin08;
};

class Rva00504138
{
public:
	Rva00064640Record *rva00504138(int n);
private:
	Rva00504138Header *m_header00;
};

// ?rva00504138@Rva00504138@@QAEPAVRva00064640Record@@H@Z present-unmatched
Rva00064640Record *Rva00504138::rva00504138(int n)
{
	Rva00504138Node *cur = m_header00->m_begin08;
	if (cur == (Rva00504138Node *)m_header00)
		return 0;
	for (; n != 0; --n)
	{
		cur = (Rva00504138Node *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)cur);
		if (cur == (Rva00504138Node *)m_header00)
			return 0;
	}
	return &cur->m_value10;
}
