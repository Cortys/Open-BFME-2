// cl: /O1 /GX- /arch:SSE2
// ?rva00358E6A@Rva00358E6A@@QAEXPAUNode00358E6A@@@Z @0x00358E6A
// (53B): rb_tree clear via recursive left plus dtor plus free plus right loop.
// Identity via dtor 0x00358B65 plus free 0x00030830 plus self recursion;
// unblocks 41B; same /O1 /GX- /arch:SSE2 as neighbours.

extern "C" void free(void *p);

class Rva00358B65
{
public:
	~Rva00358B65();
};

struct Node00358E6A
{
	void *m_pad00[2];
	Node00358E6A *m_right;
	Node00358E6A *m_left;
	Rva00358B65 m_value;
};

class Rva00358E6A
{
public:
	void rva00358E6A(Node00358E6A *head);
};

void Rva00358E6A::rva00358E6A(Node00358E6A *head)
{
	if (!head)
		return;
	for (Node00358E6A *n = head; n; )
	{
		rva00358E6A(n->m_left);
		Node00358E6A *r = n->m_right;
		n->m_value.~Rva00358B65();
		free(n);
		n = r;
	}
}
