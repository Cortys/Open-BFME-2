// cl: /Ireference/shims/bfmelist /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva0018C262@Rva0018C262@@QAEXPAURva0018C262Node@@@Z @ 0x0018C262 45B unlock: recursive node free via rowed _free. Caller 0x0018C316 passes node+4.
extern "C" void __cdecl free(void *block);
struct Rva0018C262Node {
	int m_00;
	int m_04;
	Rva0018C262Node *m_08;
	Rva0018C262Node *m_0C;
};
class Rva0018C262 {
public:
	void rva0018C262(Rva0018C262Node *p);
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
