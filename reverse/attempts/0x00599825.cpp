// ?rva00599825@Rva00599825@@QAEXH@Z
// partial score=0.92 date=2026-09-29
// ?rva00599825@Rva00599825@@QAEXH@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /GX- /MD
//
// ?rva00599825@Rva00599825@@QAEXH@Z, retail 0x00599825, 75 bytes.
// Guarded list add: resolve the id via TheGameLogic::findObjectByID, require
// object+0x304 to equal cmp+0x2EC, skip when the id is already in the list
// at +0, else push it. Evidence: rowed findObjectByID 0x00049DC5 and list
// push_back 0x0005548F; TheGameLogic at 0x00DFE78C; unblocks 4.
enum ObjectID
{
	OBJECTID_INVALID = 0
};

class Object
{
public:
	unsigned char m_pad[0x304];
	int m_key;
};

struct Rva599825Cmp
{
	unsigned char m_pad[0x2EC];
	int m_key;
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

namespace _STL
{
template <class T> class allocator
{
};
template <class T, class A = allocator<T> > class list
{
public:
	void push_back(const T &x);
};
}

struct Rva599825Node
{
	Rva599825Node *m_next;
	int m_prev;
	int m_value;
};

class Rva00599825
{
public:
	void rva00599825(int id);
private:
	_STL::list<int> m_ids;
	unsigned char m_pad[0xC - sizeof(_STL::list<int>)];
	Rva599825Cmp *m_cmp;
};

void Rva00599825::rva00599825(int id)
{
	Object *obj = TheGameLogic->findObjectByID((ObjectID)id);
	if (obj == 0)
		return;
	if (obj->m_key != m_cmp->m_key)
		return;
	Rva599825Node *head = *(Rva599825Node **)&m_ids;
	for (Rva599825Node *cur = head->m_next; cur != head; cur = cur->m_next) {
		if (cur->m_value == id)
			return;
	}
	m_ids.push_back(id);
}
