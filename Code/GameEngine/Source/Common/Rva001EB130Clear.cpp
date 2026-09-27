// cl: /O1 /DNDEBUG /MD
// ?rva001EB130@Rva001EB130Holder@@QAEXXZ @0x001EB130 42B: circular list clear.
// Same shape as ?reset@Rva0029FB3BMember@@QAEXXZ at 0x0026549E (42B; /O1
// /DNDEBUG /MD): drains nodes from sentinel at this+0 to freelist then
// reinits sentinel next and prev to itself. Freelist here is 0x009B8FF4
// versus 0x009A60F0 there. Callers at 0x001EB76C 0x00241520 0x0029D7B3
// 0x00423A7F 0x00452959. No donor; honest address names.
class Rva001EB130Holder
{
public:
	void *m_head;
	void rva001EB130();
};
extern void *g_freeList;
void Rva001EB130Holder::rva001EB130()
{
	void *node = ((void **)m_head)[0];
	if (node != m_head) {
		do {
			void *freeHead = g_freeList;
			void *current = node;
			node = ((void **)current)[0];
			((void **)current)[0] = freeHead;
			g_freeList = current;
		} while (node != m_head);
	}
	((void **)m_head)[0] = m_head;
	((void **)m_head)[1] = m_head;
}
