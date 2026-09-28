// ?rva00625790@Rva00625790@@QAEPAV1@PAV1@@Z
// partial score=0.98 date=2026-09-28
// ?rva00625790@Rva00625790@@QAEPAV1@PAV1@@Z
// partial score=0.98 date=2026-09-28
// ?rva00625790@Rva00625790@@QAEPAV1@PAV1@@Z, retail 0x00625790 46B.
// Tail-append to an intrusive singly-linked list with the link at +4.
// Returns this for chaining. Evidence: caller at 0x0026DBE6 links a stack
// node at ebp-0x28 into a head at ebp-0x48; caller at 0x00272B53 chains four
// appends via mov ecx,eax with four pushed node addresses; layout vptr at
// +0 and link at +4 matches neighbouring Rva009F2AB0Mask walk; no donor.

class Rva00625790
{
public:
	virtual void unused0();

	Rva00625790 *m_next04; // +4

	Rva00625790 *rva00625790(Rva00625790 *node);
};

// ?rva00625790@Rva00625790@@QAEPAV1@PAV1@@Z present-unmatched
Rva00625790 *Rva00625790::rva00625790(Rva00625790 *node)
{
	if (m_next04)
	{
		Rva00625790 *next = m_next04;
		Rva00625790 *cur;
		do
		{
			cur = next;
			next = cur->m_next04;
		}
		while (next);
		cur->m_next04 = node;
	}
	else
	{
		m_next04 = node;
	}
	return this;
}
