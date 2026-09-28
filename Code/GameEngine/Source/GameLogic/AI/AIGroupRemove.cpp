// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?remove@AIGroup@@QAE_NPAVObject@@@Z @ 0x0036CF07 108B
// AIGroup::remove: find member in +0x04 STLport list, erase, leaveGroup,
// set dirty at +0x0C, destroy via TheAI at 0x00DFF0F8 when empty.
// Evidence: callers 0x0036CFCB 0x0036D01B plus 0x0036D7E5,
// callees leaveGroup pin 0x0028C01F plus rva002FE712 row 0x002FE712,
// BFME1 AIGroupMembership remove plus ZH AIGroup remove donor shape.
#include <list>
#include <algorithm>

enum ObjectID
{
	INVALID_ID = 0
};

class Object
{
public:
	void leaveGroup();
};

class AIGroup;

class AI
{
public:
	void rva002FE712(AIGroup *group);
};

class AIGroup
{
public:
	bool remove(Object *member);
	bool isEmpty() { return m_memberList.empty(); }

private:
	virtual void *deleteInstance(int flags);
	_STL::list<ObjectID> m_memberList;
	char m_pad[4];
	bool m_dirty;
};

bool AIGroup::remove(Object *member)
{
	_STL::list<ObjectID>::iterator it = _STL::find(m_memberList.begin(), m_memberList.end(), *(ObjectID *)&member);
	if (it == m_memberList.end())
		return false;
	((_STL::list<int> *)&m_memberList)->erase(*(_STL::list<int>::iterator *)&it);
	member->leaveGroup();
	m_dirty = true;
	if (isEmpty()) {
		(*(AI **)0x00DFF0F8)->rva002FE712(this);
		return true;
	}
	return false;
}
