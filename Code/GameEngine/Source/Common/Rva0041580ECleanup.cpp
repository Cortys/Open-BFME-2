// cl: /O1 /MD
// ?rva0041580E@Rva0041580E@@QAEXPAURva0041580ENode@@@Z @0x0041580E 53B chain via rowed ??1Rva0041579E.
// List cleanup recursing on +0xC with same this then destroying +0x10 via rowed
// Rva0041579E dtor and freeing the node, iterating via +8.
// Evidence: self-call at 0x00415820 with [esi+0xC], lea ecx [esi+0x10] call
// rowed 0x004156FC, push esi call rowed _free 0x00030830, loop via [esi+8];
// callers at 0x00415820 (self) 0x00415894; unblocks 0x00415886.
extern "C" void __cdecl free(void *block);

class Rva0041579E
{
public:
	~Rva0041579E();
};

struct Rva0041580ENode
{
	char _00[8];
	Rva0041580ENode *m_next08;
	Rva0041580ENode *m_child0C;
	Rva0041579E m_item10;
};

struct Rva0041580E
{
	void rva0041580E(Rva0041580ENode *node);
};

void Rva0041580E::rva0041580E(Rva0041580ENode *node)
{
	Rva0041580ENode *cur = node;
	while (cur != 0)
	{
		rva0041580E(cur->m_child0C);
		Rva0041580ENode *next = cur->m_next08;
		cur->m_item10.~Rva0041579E();
		free(cur);
		cur = next;
	}
}
