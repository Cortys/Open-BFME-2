// cl: /O1 /GX- /arch:SSE2
// ?rva00358D62@Rva00358D62@@QAEXPAURva00358D62Node@@@Z @0x00358D62 (53B):
// List clear with recursion on +0xc: for each node recurse on child, destroy
// embedded Rva0027EA49 at +0x10 via rowed dtor, free node via rowed _free,
// step to +0x8 next. Same this preserved in ebx across calls.
// Evidence: self-call 0x00358D74; callees rowed 0x0027EA49 0x00030830;
// callers 0x00358D74 0x00358E0B; unblocks 0x00358DFD.
extern "C" void __cdecl free(void *block);
struct Rva0027EA49
{
	~Rva0027EA49();
	int m_00;
	void *m_04;
};
struct Rva00358D62Node
{
	char m_00[8];
	Rva00358D62Node *m_08;
	Rva00358D62Node *m_0c;
	Rva0027EA49 m_10;
};
class Rva00358D62
{
public:
	void rva00358D62(Rva00358D62Node *node);
};
void Rva00358D62::rva00358D62(Rva00358D62Node *node)
{
	if (node == 0)
		return;
	Rva00358D62Node *cur = node;
	do {
		rva00358D62(cur->m_0c);
		Rva00358D62Node *next = cur->m_08;
		cur->m_10.~Rva0027EA49();
		free(cur);
		cur = next;
	} while (cur != 0);
}
