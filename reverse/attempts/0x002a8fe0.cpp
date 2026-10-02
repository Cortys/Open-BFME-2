// ?rva002A8FE0@Rva002A8FE0@@QAEXXZ
// partial score=0.9 date=2026-10-02
// cl: /O1 /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// ?rva002A8FE0@Rva002A8FE0@@QAEXXZ @ 0x002A8FE0 (73B). Leaf array-of-lists
// clear calling rowed ?Rva002A8D2DFree@@YGXPAURva002A8D2DNode@@@Z at 0x002A8D2D.
// Start at +4 end at +8 count=(end-start)>>2; each slot frees its Node chain
// via m_next at +0 then clears the slot; size at +0x10 cleared. Evidence:
// callers at 0x002A91F2 0x002A924D and jmp 0x002A91D8; Free TU names sole
// caller as this loop.
struct Rva002A8D2DNode
{
	void *m_next;
};

void __stdcall Rva002A8D2DFree(struct Rva002A8D2DNode *p);

class Rva002A8FE0
{
public:
	void rva002A8FE0();
private:
	char m_0[4];
	struct Rva002A8D2DNode **m_start;
	struct Rva002A8D2DNode **m_end;
	char m_c[4];
	int m_10;
};

// ?rva002A8FE0@Rva002A8FE0@@QAEXXZ present-unmatched
void Rva002A8FE0::rva002A8FE0()
{
	if ((((char *)m_end - (char *)m_start) >> 2) == 0) {
		m_10 = 0;
		return;
	}
	for (int i = 0; i < (((char *)m_end - (char *)m_start) >> 2); ++i) {
		struct Rva002A8D2DNode *node = m_start[i];
		while (node) {
			struct Rva002A8D2DNode *next = (struct Rva002A8D2DNode *)node->m_next;
			Rva002A8D2DFree(node);
			node = next;
		}
		m_start[i] = 0;
	}
	m_10 = 0;
}
