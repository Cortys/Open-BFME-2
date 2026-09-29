// cl: /O1 /DNDEBUG /MD
// ?rva0056F43E@Rva0056F43E@@QAEXPAX@Z @0x0056F43E 53B
// Recursive list/tree cleanup: recurse on [node+0xc], iterate on [node+8],
// clear the Unicode string at [node+0x10], then free the node.
// Unlocks 0x0056F503.
// Evidence: push ebx/esi/edi shape with self-call, StringBase<G>::clear call,
// _free call, ret 4; caller 0x0056F503 passes [eax+4] with same this.
template <typename T>
class StringBase
{
public:
	void clear();
private:
	void *m_data;
};
extern "C" void __cdecl free(void *p);
struct Rva0056F43E
{
	int m_00;
	int m_04;
	void *m_08;
	void *m_0c;
	StringBase<unsigned short> m_10;
	void rva0056F43E(void *node);
};
void Rva0056F43E::rva0056F43E(void *p)
{
	Rva0056F43E *node = (Rva0056F43E *)p;
	if (!node)
		return;
	do {
		rva0056F43E(node->m_0c);
		Rva0056F43E *next = (Rva0056F43E *)node->m_08;
		node->m_10.clear();
		free(node);
		node = next;
	} while (node);
}
