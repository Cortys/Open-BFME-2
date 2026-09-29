// cl: /O1 /EHsc /MD
// ?rva0021C459@Rva0021C459@@QAEXPAUNode0021C459@@@Z @0x0021C459 53B recurse-right via +0xC walk-left via +0x8 clear value at +0x10 via rowed 0x005B804E free 0x00030830.
// Evidence: unlock lane all callees rowed; same 53B shape as rowed erase 0x0021C3B2 but with Unicode StringBase clear; prev-row WideConcatPair proves Unicode family; next-row hero tree proves page.
template <typename T> class StringBase {
public:
	void clear();
private:
	void *m_data;
};
struct Node0021C459 {
	unsigned char m_pad[8];
	Node0021C459 *m_left;
	Node0021C459 *m_right;
	StringBase<unsigned short> m_value;
};
class Rva0021C459 {
public:
	void rva0021C459(Node0021C459 *node);
};
extern "C" void free(void *ptr);
void Rva0021C459::rva0021C459(Node0021C459 *node)
{
	if (node == 0)
		return;
	while (true) {
		rva0021C459(node->m_right);
		Node0021C459 *next = node->m_left;
		node->m_value.clear();
		free(node);
		node = next;
		if (node == 0)
			break;
	}
}
