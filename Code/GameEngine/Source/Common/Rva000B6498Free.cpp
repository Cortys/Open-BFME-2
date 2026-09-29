// cl: /O1
// ?rva000B6498@Rva000B6498@@QAEXPAURva000B6498Node@@@Z, retail 0x000B6498, 45 bytes.
// __thiscall method freeing a linked structure: if arg null return; else loop
// recursing on node+0xc then freeing the node via rowed _free 0x00030830 and
// advancing to node+8. Twin of rowed 0x000B646B (same 45B shape). Self call at
// 0x000B64AA; caller 0x000B9332. Honest address name.
extern "C" void __cdecl free(void *block);

struct Rva000B6498Node
{
	int m0;
	int m1;
	struct Rva000B6498Node *m_next;
	struct Rva000B6498Node *m_child;
};

class Rva000B6498
{
public:
	void rva000B6498(struct Rva000B6498Node *n);
};

void Rva000B6498::rva000B6498(struct Rva000B6498Node *n)
{
	if (!n)
		return;
	do
	{
		rva000B6498(n->m_child);
		struct Rva000B6498Node *next = n->m_next;
		free(n);
		n = next;
	} while (n);
}
