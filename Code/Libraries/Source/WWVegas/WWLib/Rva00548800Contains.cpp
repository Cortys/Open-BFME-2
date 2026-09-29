// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva00548800@Rva00548800@@QAE_NABV?$list@PAVCreateAHeroData@@V?$allocator@PAVCreateAHeroData@@@_STL@@@_STL@@@Z @0x00548800 59B contains-check of list nodes via rowed find 0x0020E873.
// Evidence: __thiscall bool ret 4 single list arg; callers 0x0035541D 0x00548167; this+4 +8 as vector first last; arg list nodes with data at +8.
#define _STLP_NO_EXCEPTIONS 1
#include <vector>
#include <algorithm>
#include <list>

class CreateAHeroData;

typedef _STL::list<CreateAHeroData *> ListHeroPtr;
typedef _STL::vector<CreateAHeroData *> VecHeroPtr;

class Rva00548800
{
public:
	bool rva00548800(const ListHeroPtr *list);
private:
	int m_00;
	VecHeroPtr m_vec04;
};

bool Rva00548800::rva00548800(const ListHeroPtr *list)
{
	ListHeroPtr::_Node *sentinel = (ListHeroPtr::_Node *)list->_M_node._M_data;
	ListHeroPtr::_Node *node = (ListHeroPtr::_Node *)sentinel->_M_next;
	while (node != sentinel)
	{
		if (_STL::find(m_vec04.begin(), m_vec04.end(), (CreateAHeroData *)node->_M_data) == m_vec04.end())
			return false;
		node = (ListHeroPtr::_Node *)node->_M_next;
	}
	return true;
}
