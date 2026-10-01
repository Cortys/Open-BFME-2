// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva00421BF7@Rva00421BF7@@QAEXPAX@Z @0x00421BF7 45B
// Walk +8 chain freeing each node after recursing on its +0xC child:
// while (n) { rva00421BF7(n->m_child); next = n->m_next; free(n); n = next; }
// Evidence: unlock lane; self-call at 0x00421C09; free row 0x00030830;
// caller at 0x00421EF8; neighbours share /O1 flags.
extern "C" void __cdecl free(void *);

struct Rva00421BF7Node
{
	char m_pad[8];
	Rva00421BF7Node *m_next;
	Rva00421BF7Node *m_child;
};

class Rva00421BF7
{
public:
	void rva00421BF7(void *n);
};
void Rva00421BF7::rva00421BF7(void *n)
{
	Rva00421BF7Node *p = (Rva00421BF7Node *)n;
	while (p != 0)
	{
		rva00421BF7(p->m_child);
		Rva00421BF7Node *next = p->m_next;
		free(p);
		p = next;
	}
}
