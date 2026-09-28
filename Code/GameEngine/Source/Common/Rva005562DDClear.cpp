// cl: /O1 /MD
//
// ?rva005562DD@Rva005562DD@@QAEXXZ @0x005562DD 41B
// Chain lane: clears the container by tearing down the node list at
// m_head+4 through the landed 0x00556050 body, then reinitialises the head
// as an empty sentinel (next/prev point to self) and zeroes the count.
// Derived from Rva00556050 so the teardown call keeps its rowed mangling.
// Caller 0x00557BFE.

struct Rva00556050Node;

class Rva00556050
{
public:
	void rva00556050(Rva00556050Node *head);
};

struct Rva005562DDHead
{
	int m_pad0;
	Rva00556050Node *m_list; // +4
	Rva005562DDHead *m_next; // +8
	Rva005562DDHead *m_prev; // +0xc
};

class Rva005562DD : private Rva00556050
{
public:
	void rva005562DD();

private:
	Rva005562DDHead *m_head; // +0
	int m_count; // +4
};

void Rva005562DD::rva005562DD()
{
	if (m_count == 0)
		return;
	rva00556050(m_head->m_list);
	m_head->m_next = m_head;
	m_head->m_list = 0;
	m_head->m_prev = m_head;
	m_count = 0;
}
