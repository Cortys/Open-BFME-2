// ?rva001F8109@Rva001F8109@@QAEXABW4ObjectID@@@Z
// partial score=0.95 date=2026-10-02
// cl: /O1 /G7 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
// stlport
// ?rva001F8109@Rva001F8109@@QAEXABW4ObjectID@@@Z @0x001F8109 73B
// Evidence: const-ref reuses arg slot for find return via rowed 0x0029B694 and member erase via pin at 0x00438539 caller 0x001FBE2B list at +0x4C count at +0x58.
#define _STLP_NO_EXCEPTIONS 1
#include <list>
#include <algorithm>

enum ObjectID
{
	INVALID_OBJECT_ID = 0
};

class Rva001F8109
{
public:
	void rva001F8109(const ObjectID &id);
private:
	unsigned char m_pad00[0x4c];
	_STL::list<ObjectID> m_list;
	unsigned char m_gap[8];
	int m_count;
};

// ?rva001F8109@Rva001F8109@@QAEXABW4ObjectID@@@Z present-unmatched
void Rva001F8109::rva001F8109(const ObjectID &id)
{
	_STL::list<ObjectID>::iterator it = _STL::find(m_list.begin(), m_list.end(), id);
	if (it == m_list.end())
		return;
	m_list.erase(it);
	--m_count;
}
