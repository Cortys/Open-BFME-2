// ?rva00358E26@Rva00358D62@@QAEXPAURva00358D62Node@@0@Z
// partial score=0.88 date=2026-09-30
// ?rva00358E26@Rva00358D62@@QAEXPAURva00358D62Node@@0@Z
// partial score=0.88 date=2026-09-30
// cl: /O1 /GX- /arch:SSE2
// stlport
// ?rva00358E26@Rva00358D62@@QAEXPAURva00358D62Node@@0@Z 0x00358E26 68B evidence: chain from rva00358DFD clear; range erase with _M_increment rowed plus Rb_tree Rva0027EA49 erase rowed; prev Rva00358D62Clear
#include <map>
extern "C" void __cdecl free(void *block);
struct Rva0027EA49
{
	~Rva0027EA49();
	int m_00;
	void *m_04;
};
bool operator<(const Rva0027EA49 &a, const Rva0027EA49 &b);
typedef _STL::_Rb_tree<Rva0027EA49, Rva0027EA49, _STL::_Identity<Rva0027EA49>, _STL::less<Rva0027EA49>, _STL::allocator<Rva0027EA49> > Rva0027EA49Tree;
struct Rva00358D62Node
{
	char m_00[8];
	Rva00358D62Node *m_08;
	Rva00358D62Node *m_0c;
	Rva0027EA49 m_10;
};
struct Rva00358D62Header
{
	char m_00[4];
	Rva00358D62Node *m_04;
	Rva00358D62Node *m_08;
	Rva00358D62Node *m_0c;
};
class Rva00358D62
{
public:
	void rva00358DFD();
	void rva00358E26(Rva00358D62Node *first, Rva00358D62Node *last);
private:
	Rva00358D62Header *m_00;
	int m_04;
};

// ?rva00358E26@Rva00358D62@@QAEXPAURva00358D62Node@@0@Z present-unmatched
void Rva00358D62::rva00358E26(Rva00358D62Node *first, Rva00358D62Node *last)
{
	if (first == m_00->m_08 && last == (Rva00358D62Node *)m_00)
	{
		rva00358DFD();
		return;
	}
	while (first != last)
	{
		Rva00358D62Node *cur = first;
		first = (Rva00358D62Node *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)cur);
		reinterpret_cast<Rva0027EA49Tree *>(this)->erase(*reinterpret_cast<Rva0027EA49Tree::iterator *>(&cur));
	}
}
