// cl: /O1 /MD
//
// ?rva001FF6D7@Rva001FF6D7@@QAEXXZ @0x001FF6D7 20B
// Unlock lane: if m_ptr null return else prepend node to global list at
// 0x009B9448 (node->next = global; global = node). Caller 0x001FF75D.
// Unwind funclet 0x0076C22E jmps here.
extern void *Global_009B9448;

class Rva001FF6D7
{
public:
	void rva001FF6D7();

private:
	void *m_ptr;
};

void Rva001FF6D7::rva001FF6D7()
{
	void *node = m_ptr;
	if (node == 0)
		return;
	*(void **)node = Global_009B9448;
	Global_009B9448 = node;
}
