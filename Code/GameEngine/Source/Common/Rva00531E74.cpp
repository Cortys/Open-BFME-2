// cl: /O1 /MD /G7
// ?rva00531E74@Rva00531E74@@QAEXXZ @ 0x00531E74 (49B): __thiscall collect bucket chains 0..4000 onto list at +0x3E84 then clear buckets.
// Callers at 0x005320C4 0x00533C38. Owner unknown so honest address name.
struct Rva00531E74Node
{
	Rva00531E74Node *m_next;
};
class Rva00531E74
{
public:
	void rva00531E74();
	Rva00531E74Node *m_buckets[4002];
};
void Rva00531E74::rva00531E74()
{
	Rva00531E74Node **p = &m_buckets[4001];
	if (p == (Rva00531E74Node **)this)
		return;
	do
	{
		--p;
		Rva00531E74Node *head = *p;
		if (head != 0)
		{
			do
			{
				Rva00531E74Node *next = head->m_next;
				head->m_next = m_buckets[4001];
				m_buckets[4001] = head;
				head = next;
			} while (head != 0);
		}
		*p = 0;
	} while (p != (Rva00531E74Node **)this);
}
