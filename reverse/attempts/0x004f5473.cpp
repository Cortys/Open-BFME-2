// ?rva004F5473@Rva004F54BF@@QAE_NPAVObject@@_N@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHsc
// stlport
// ?rva004F54BF@Rva004F54BF@@QAEXW4ObjectID@@H@Z, retail 0x004F54BF, 75 bytes.
// Removes an ObjectID from list at +0x10 via rowed find 0x0029B694 and rowed ObjectID erase (pin at 0x00438539 folded onto int erase), then dec count at +0x18.
// Layout: pad 0x10, list at +0x10, count at +0x18 (list size 8). Evidence: leaf packet with 2 unclaimed callers; TunnelContain caller 0x0047DC88 passes through ObjectID plus second int arg; ret 8 is thiscall 2 args with second unused.
// Precedent Rva002A1111.cpp for find plus Rva0029BA28.cpp for list erase.
#include <list>

enum ObjectID
{
	OBJECTID_NONE = 0
};

namespace _STL
{
template <class _InputIter, class _Tp>
_InputIter find(_InputIter __first, _InputIter __last, const _Tp &__val);
}

class Rva004F54BF
{
public:
	void rva004F54BF(ObjectID val, int dummy);
	bool rva004F5473(class Object *obj, bool flag);
private:
	char m_pad[0x10];
	_STL::list<ObjectID> m_list;
	int m_14;
	int m_count;
};

void Rva004F54BF::rva004F54BF(ObjectID val, int dummy)
{
	_STL::list<ObjectID>::iterator it = _STL::find(m_list.begin(), m_list.end(), val);
	if (it == m_list.end())
		return;
	m_list.erase(it);
	--m_count;
}

enum ObjectStatusTypes
{
	OBJECT_STATUS_26 = 0x26
};

struct Rva004F5473Inner
{
	char m_pad[0x109];
	unsigned char m_flag109;
};

class Object
{
public:
	bool testStatus(ObjectStatusTypes status) const;
	char m_pad0[4];
	Rva004F5473Inner *m_04;
};

class GlobalData
{
public:
	char m_pad[0xa98];
	int m_limitA98;
};

extern GlobalData *TheWritableGlobalData;

// ?rva004F5473@Rva004F54BF@@QAE_NPAVObject@@_N@Z present-unmatched
bool Rva004F54BF::rva004F5473(Object *obj, bool flag)
{
	if (obj != 0) {
		if ((obj->m_04->m_flag109 & 0x10) == 0) {
			if (!flag)
				return true;
			if (obj->testStatus(OBJECT_STATUS_26))
				return true;
			return m_count < TheWritableGlobalData->m_limitA98;
		}
	}
	return false;
}
