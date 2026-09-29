// cl: /O1 /MD
// ?rva004FF582@Rva004FF582@@QAEXPAURva004FF582Node@@@Z at 0x004FF582 (53B).
// Tree/list free: recurse on child +0xC, destroy Rva004FF2F4 at +0x10, _free node, iterate via next +8.
// Evidence: chain lane, callees rowed self plus ??1Rva004FF2F4 0x004FF2F4 plus _free 0x00030830, caller 0x004FF729.
class Rva004FF2F4 {
public:
	~Rva004FF2F4();
};
extern "C" void free(void *);

struct Rva004FF582Node {
	char m_00[8];
	Rva004FF582Node *m_next;
	Rva004FF582Node *m_child;
	Rva004FF2F4 m_10;
};

class Rva004FF582 {
public:
	void rva004FF582(Rva004FF582Node *node);
};

void Rva004FF582::rva004FF582(Rva004FF582Node *node)
{
	if (!node)
		return;
	do {
		rva004FF582(node->m_child);
		Rva004FF582Node *next = node->m_next;
		node->m_10.~Rva004FF2F4();
		free(node);
		node = next;
	} while (node);
}
