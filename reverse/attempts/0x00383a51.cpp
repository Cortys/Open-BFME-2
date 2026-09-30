// ?rva00383A51@Rva00383A51@@QAEXPAURva00383A51Node@@0@Z
// partial score=0.9 date=2026-09-30
// ?rva00383A51@Rva00383A51@@QAEXPAURva00383A51Node@@0@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /EHs /MD /Oy-
// ?rva00383A51@Rva00383A51@@QAEXPAURva00383A51Node@@0@Z 0x00383A51 68B
// Rb erase(first,last): if first==begin and last==end clear else loop erase-one via increment.
// Evidence: callees 0x00383A28 clear plus 0x00024250 increment plus 0x00383380 erase-one all rowed; caller 0x00383F53 erase-key.
extern "C" void __cdecl free(void *block);

struct CameraMarker
{
	~CameraMarker();
};

struct Rva00383A51Node
{
	unsigned int m_color;
	Rva00383A51Node *m_parent;
	Rva00383A51Node *m_left;
	Rva00383A51Node *m_right;
};

struct Rva003833BBNode
{
	unsigned int m_color;
	Rva003833BBNode *m_parent;
	Rva003833BBNode *m_left;
	Rva003833BBNode *m_right;
};

class Rva00383A28
{
public:
	void rva00383A28();
};

namespace _STL
{
typedef bool _Rb_tree_Color_type;
struct _Rb_tree_node_base
{
	typedef _Rb_tree_Color_type _Color_type;
	typedef _Rb_tree_node_base* _Base_ptr;
	_Color_type _M_color;
	_Base_ptr _M_parent;
	_Base_ptr _M_left;
	_Base_ptr _M_right;
};
template <class _Dummy> class _Rb_global
{
public:
	static _Rb_tree_node_base* __cdecl _M_increment(_Rb_tree_node_base*);
};
}

struct Rva00383380Node : public _STL::_Rb_tree_node_base
{
};

class Rva00383380
{
public:
	void rva00383380(Rva00383380Node *pos);
};

class Rva00383A51
{
public:
	void rva00383A51(Rva00383A51Node *first, Rva00383A51Node *last);
private:
	Rva003833BBNode *m_header;
	unsigned int m_count;
};

// ?rva00383A51@Rva00383A51@@QAEXPAURva00383A51Node@@0@Z present-unmatched
void Rva00383A51::rva00383A51(Rva00383A51Node *first, Rva00383A51Node *last)
{
	if (first == (Rva00383A51Node *)m_header->m_left && last == (Rva00383A51Node *)m_header)
		((Rva00383A28 *)this)->rva00383A28();
	else
	{
		while (first != last)
		{
			Rva00383A51Node *tmp = first;
			first = (Rva00383A51Node *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)tmp);
			((Rva00383380 *)this)->rva00383380((Rva00383380Node *)tmp);
		}
	}
}
