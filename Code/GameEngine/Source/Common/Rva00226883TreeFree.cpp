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
};

struct Rva00226883Node
{
	char m_pad[8]; // +0x00..0x07
	Rva00226883Node *m_next; // +0x08 sibling
	Rva00226883Node *m_child; // +0x0C child
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
