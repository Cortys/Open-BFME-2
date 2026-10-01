// cl: /DNDEBUG /MD
// ?rva006CFFE0@Rva008951B0Owner@@QAEXABVRva008951B0Handle@@@Z, retail 0x006CFFE0 (92B).
// Owner list remove beside Rva008951B0Find: unlinks the node named by the handle
// and returns its 8-byte store through the rowed freeBlock 0x006DB270 via pool
// g_pChainBlockAllocator 0x00E176E8. Head hit caches next past the free call,
// otherwise walks via +4 for the predecessor whose next matches, swings it over
// the target, then frees. ret 4 plus handle deref proves thiscall taking const Handle&.
// Evidence: callees rowed; callers at 0x006D27E8; neighbours share /DNDEBUG /MD.
class Rva006DB270
{
public:
	void freeBlock(void *block, int blockSize);
};
extern Rva006DB270 *g_pChainBlockAllocator;

class Rva008951B0Entry
{
public:
	Rva008951B0Entry *m_bfmeNext_placeholder;
};

class Rva008951B0Node
{
public:
	Rva008951B0Entry *m_bfmeEntry;
	Rva008951B0Node *m_bfmeNext;
};

class Rva008951B0Handle
{
public:
	Rva008951B0Node *m_bfmeNode;
};

class Rva008951B0Owner
{
public:
	void rva006CFFE0(const Rva008951B0Handle &h);
	Rva008951B0Node *m_bfmeHead;
};

void Rva008951B0Owner::rva006CFFE0(const Rva008951B0Handle &h)
{
	Rva008951B0Node *target = h.m_bfmeNode;
	Rva008951B0Node *head = m_bfmeHead;
	if (target == head) {
		if (!head)
			return;
		Rva008951B0Node *next = head->m_bfmeNext;
		g_pChainBlockAllocator->freeBlock(head, 8);
		m_bfmeHead = next;
		return;
	}
	while (head) {
		if (head->m_bfmeNext == target)
			break;
		head = head->m_bfmeNext;
	}
	Rva008951B0Node *victim = head->m_bfmeNext;
	if (victim) {
		head->m_bfmeNext = victim->m_bfmeNext;
	}
	g_pChainBlockAllocator->freeBlock(victim, 8);
}
