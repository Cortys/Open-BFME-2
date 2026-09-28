// cl: /O1 /DNDEBUG /MD
// ?rva00239380@Rva00239380Holder@@QAEXXZ @0x00239380 42B: circular list clear.
// Same shape as ?rva001EB130@Rva001EB130Holder@@QAEXXZ at 0x001EB130 (42B; /O1
// /DNDEBUG /MD): drains nodes from sentinel at this+0 to freelist then
// reinits sentinel next and prev to itself. Freelist here is 0x009BA5E8.
// Callers at 0x002399E0 0x00239AF7 0x0029BDF5 0x002A3916 0x0030F277 plus
// jmp at 0x00239944. No donor; honest address names.
class Rva00239380Holder
{
public:
	void *m_head;
	void rva00239380();
};
extern void *g_freeList00239380;
void Rva00239380Holder::rva00239380()
{
	void *node = ((void **)m_head)[0];
	if (node != m_head) {
		do {
			void *freeHead = g_freeList00239380;
			void *current = node;
			node = ((void **)current)[0];
			((void **)current)[0] = freeHead;
			g_freeList00239380 = current;
		} while (node != m_head);
	}
	((void **)m_head)[0] = m_head;
	((void **)m_head)[1] = m_head;
}
