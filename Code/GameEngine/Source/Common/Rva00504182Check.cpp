// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva00504182@Rva00504182@@QAE_NI@Z @ 0x00504182 (32B):
// If count==0 return true else max Record.m_18 < value via _M_decrement.
// Evidence: cmp [ecx+4] 0 je true; push [ecx] call _M_decrement rowed;
// mov eax [eax+0x28] cmp [esp+8] pop ecx sbb neg ret 4; Record m_18 +0x18.
class Rva00064640Record
{
public:
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	float m_10;
	float m_14;
	unsigned int m_18;
};
struct Rva00504182Node
{
	void *m_parent;
	void *m_left;
	void *m_right;
	int m_color;
	Rva00064640Record m_rec;
};
namespace _STL
{
struct _Rb_tree_node_base;
template <class _Dummy> class _Rb_global
{
public:
	static _Rb_tree_node_base *_M_decrement(_Rb_tree_node_base *__x);
};
}
class Rva00504182
{
public:
	bool rva00504182(unsigned int v);
private:
	Rva00504182Node *m_head;
	int m_count;
};
bool Rva00504182::rva00504182(unsigned int v)
{
	if (m_count == 0)
		return true;
	Rva00504182Node *n = (Rva00504182Node *)_STL::_Rb_global<bool>::_M_decrement((_STL::_Rb_tree_node_base *)m_head);
	return n->m_rec.m_18 < v;
}
