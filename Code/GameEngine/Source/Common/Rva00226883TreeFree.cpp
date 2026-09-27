// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX /arch:SSE
//
// ?rva00226883@Rva00226883@@QAEXPAX@Z, retail 0x00226883 45B.
// Tree free twin of 0x00226829: recursive child at +0x0C then free node and iterate sibling at +0x08.
// Evidence: self-recursive call at 0x226895; free row at 0x30830; caller 0x2299AD;
// identical shape to Rva00226829TreeFree.cpp; prev Rva00226856 row.

extern "C" void __cdecl free(void *block);

class Rva00226883
{
public:
	void rva00226883(void *node);
	void rva0022999F();

private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

struct Rva00226883Node
{
	char m_pad[8]; // +0x00..0x07
	Rva00226883Node *m_next; // +0x08 sibling
	Rva00226883Node *m_child; // +0x0C child
};

struct Rva00226883Head
{
	char m_pad00[4]; // +0x00
	Rva00226883Node *m_first; // +0x04
	Rva00226883Head *m_next; // +0x08
	Rva00226883Head *m_child; // +0x0C
};

void Rva00226883::rva00226883(void *node)
{
	if (!node)
		return;
	Rva00226883Node *cur = (Rva00226883Node *)node;
	do {
		rva00226883(cur->m_child);
		Rva00226883Node *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur);
}

void Rva00226883::rva0022999F()
{
	if (m_04Flag == 0)
		return;
	Rva00226883Head *h = (Rva00226883Head *)m_00Head;
	rva00226883(h->m_first);
	((Rva00226883Head *)m_00Head)->m_next = (Rva00226883Head *)m_00Head;
	((Rva00226883Head *)m_00Head)->m_first = 0;
	((Rva00226883Head *)m_00Head)->m_child = (Rva00226883Head *)m_00Head;
	m_04Flag = 0;
}
