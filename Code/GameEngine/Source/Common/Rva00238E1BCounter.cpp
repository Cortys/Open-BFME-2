// cl: /O1 /MD
// ?rva00238E1B@Rva00238E1B@@QAEHXZ @0x00238E1B 10B post-inc counter at +0x2C returns old value.
// Evidence: unlock lane leaf increment; callers 0x00280176 0x00283642; lea shape not inc.
// ?rva00238E25@Rva00238E1B@@QAEX PAV Rva002714E6 chain: inc +0x2C then registry via 0x00271058 then list push via 0x002714E6.

class Rva00271058
{
public:
	void rva00271058(void *p);
};

class Rva002714E6
{
public:
	void rva002714E6(Rva002714E6 **head);
};

class Rva00238E1B
{
public:
	int rva00238E1B();
	void rva00238E25(Rva002714E6 *node);
private:
	int m_pad[5];
	Rva002714E6 *m_head;
	int m_pad2[5];
	int m_counter;
};
int Rva00238E1B::rva00238E1B()
{
	int t = m_counter;
	m_counter = t + 1;
	return t;
}

void Rva00238E1B::rva00238E25(Rva002714E6 *node)
{
	int old = m_counter;
	m_counter = old + 1;
	((Rva00271058 *)node)->rva00271058((void *)old);
	node->rva002714E6(&m_head);
}
