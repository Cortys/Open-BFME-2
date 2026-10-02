// ??4?$_Rb_tree@HU?$pair@$$CBHH@_STL@@U?$_Select1st@U?$pair@$$CBHH@_STL@@@2@U?$less@H@2@V?$allocator@U?$pair@$$CBHH@_STL@@@2@@_STL@@QAEAAV01@ABV01@@Z
// partial score=0.96 date=2026-10-02
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ??4?$_Rb_tree@HU?$pair@$$CBHH@_STL@@U?$_Select1st@U?$pair@$$CBHH@_STL@@@2@U?$less@H@2@V?$allocator@U?$pair@$$CBHH@_STL@@@2@@_STL@@QAEAAV01@ABV01@@Z @0x00418E78 115B: _Rb_tree<int,int> operator= via rowed clear 0x0022C432 and rowed _M_copy 0x00418E05; evidence callers 0x0041902A 0x0041911E, neighbours stlport_map_int_int_copy_00418E05.
#define _M_copy _M_copy_00418E05
#include <map>

typedef _STL::_Rb_tree<int, _STL::pair<const int, int>, _STL::_Select1st<_STL::pair<const int, int> >, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > MapIntIntTree00418E78;

class Rva002294D0
{
public:
	void rva0022C432();
};

struct RbNode00418E78
{
	int m_color;
	RbNode00418E78 *m_parent;
	RbNode00418E78 *m_left;
	RbNode00418E78 *m_right;
};

struct RbHead00418E78
{
	int m_color;
	RbNode00418E78 *m_parent;
	RbNode00418E78 *m_left;
	RbNode00418E78 *m_right;
};

struct RvaLayout00418E78
{
	RbHead00418E78 *m_head;
	unsigned int m_count;
};

template <>
MapIntIntTree00418E78::_Link_type MapIntIntTree00418E78::_M_copy(MapIntIntTree00418E78::_Link_type, MapIntIntTree00418E78::_Link_type);

// ??4?$_Rb_tree@HU?$pair@$$CBHH@_STL@@U?$_Select1st@U?$pair@$$CBHH@_STL@@@2@U?$less@H@2@V?$allocator@U?$pair@$$CBHH@_STL@@@2@@_STL@@QAEAAV01@ABV01@@Z present-unmatched
template <>
MapIntIntTree00418E78 &MapIntIntTree00418E78::operator=(const MapIntIntTree00418E78 &x)
{
	RvaLayout00418E78 *me = (RvaLayout00418E78 *)this;
	const RvaLayout00418E78 *other = (const RvaLayout00418E78 *)&x;
	if (me != other) {
		((Rva002294D0 *)this)->rva0022C432();
		me->m_count = 0;
		if (other->m_head->m_parent == 0) {
			me->m_head->m_parent = 0;
			me->m_head->m_left = (RbNode00418E78 *)me->m_head;
			me->m_head->m_right = (RbNode00418E78 *)me->m_head;
		}
		else {
			typedef MapIntIntTree00418E78::_Link_type Link;
			Link root = this->_M_copy((Link)other->m_head->m_parent, (Link)me->m_head);
			me->m_head->m_parent = (RbNode00418E78 *)root;
			RbNode00418E78 *cur = (RbNode00418E78 *)root;
			RbNode00418E78 *left = cur->m_left;
			while (left != 0) {
				cur = left;
				left = cur->m_left;
			}
			me->m_head->m_left = cur;
			cur = (RbNode00418E78 *)root;
			RbNode00418E78 *right = cur->m_right;
			while (right != 0) {
				cur = right;
				right = cur->m_right;
			}
			me->m_head->m_right = cur;
		}
		me->m_count = other->m_count;
	}
	return *this;
}
#undef _M_copy
