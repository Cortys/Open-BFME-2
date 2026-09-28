// cl: /O1
//
// ?rva004070D4@Rva004070D4@@QAEXPAURva004070D4Node@@@Z retail 0x004070D4 45B
// Evidence: unlock lane; same tree-free shape as Rva007590B0 51B but /O1 push-mem plus pop-ecx; callers 0x0040748D plus self; prev CreateAHeroElementCopy same /O1.
struct Rva004070D4Node
{
	char m_pad[8];
	Rva004070D4Node *m_next;
	Rva004070D4Node *m_child;
};

class Rva004070D4
{
public:
	void rva004070D4(Rva004070D4Node *node);
};

extern "C" void __cdecl free(void *block);

void Rva004070D4::rva004070D4(Rva004070D4Node *node)
{
	if (node == 0)
		return;
	Rva004070D4Node *cur = node;
	do {
		rva004070D4(cur->m_child);
		Rva004070D4Node *next = cur->m_next;
		free(cur);
		cur = next;
	} while (cur != 0);
}
