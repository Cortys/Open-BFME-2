// cl: /Ireference/shims/bfmelist /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva0018C262@Rva0018C262@@QAEXPAURva0018C262Node@@@Z @ 0x0018C262 45B unlock: recursive node free via rowed _free. Caller 0x0018C316 passes node+4.
extern "C" void __cdecl free(void *block);
struct Rva0018C262Node {
	int m_00;
	int m_04;
	Rva0018C262Node *m_08;
	Rva0018C262Node *m_0C;
};
struct Rva0018C262Head {
	int m_00;
	Rva0018C262Node *m_04;
	Rva0018C262Head *m_08;
	Rva0018C262Head *m_0C;
};
class Rva0018C262 {
public:
	void rva0018C262(Rva0018C262Node *p);
	void rva0018C316();
	Rva0018C262Head *m_head;
	int m_size;
};
void Rva0018C262::rva0018C262(Rva0018C262Node *p)
{
	if (!p)
		return;
	do {
		rva0018C262(p->m_0C);
		Rva0018C262Node *next = p->m_08;
		free(p);
		p = next;
	} while (p);
}
void Rva0018C262::rva0018C316()
{
	if (m_size == 0)
		return;
	rva0018C262(m_head->m_04);
	m_head->m_08 = m_head;
	m_head->m_04 = 0;
	m_head->m_0C = m_head;
	m_size = 0;
}
