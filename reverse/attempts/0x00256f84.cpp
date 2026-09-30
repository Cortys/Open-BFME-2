// ?rva00256F84@Rva00256F84@@QAEXXZ
// partial score=0.97 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
// ?rva00256F84@Rva00256F84@@QAEXXZ @0x00256F84 49B
// Intrusive list clear through a sentinel head at +0: first link pinned for
// the empty test, head re-read each iteration, rowed StringBase-tail dtor
// 0x00255D17 on node+8 plus rowed _free 0x00030830, then circular reinit
// through fresh head loads with the loop-exit node. Evidence: unlock lane;
// caller 0x002572DA in 0x002572D7; callee rows.
extern "C" void _free(void *p);
class Rva00255D17
{
public: ~Rva00255D17();
};
struct Rva00256F84Node
{
	Rva00256F84Node *m_next;
	int m_04;
	Rva00255D17 m_str08;
};
struct Rva00256F84Head
{
	Rva00256F84Node *m_next;
	Rva00256F84Node *m_prev;
};
class Rva00256F84
{
public:
	void rva00256F84();
private:
	Rva00256F84Head *m_head00;
};
// ?rva00256F84@Rva00256F84@@QAEXXZ
void Rva00256F84::rva00256F84()
{
	Rva00256F84Head *head = m_head00;
	Rva00256F84Node *node = head->m_next;
	if (node == (Rva00256F84Node *)head)
		return;
	while (node != (Rva00256F84Node *)m_head00)
	{
		Rva00256F84Node *cur = node;
		node = node->m_next;
		cur->m_str08.~Rva00255D17();
		_free(cur);
	}
	Rva00256F84Head *a = m_head00;
	a->m_next = (Rva00256F84Node *)a;
	Rva00256F84Head *b = m_head00;
	b->m_prev = (Rva00256F84Node *)b;
}
