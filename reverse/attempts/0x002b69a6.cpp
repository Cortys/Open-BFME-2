// ?rva002B69A6@Rva002B69A6@@QAEXPAX@Z
// partial score=0.91 date=2026-10-02
// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?rva002B69A6@Rva002B69A6@@QAEXPAX@Z @0x002B69A6 94B evidence: unlock callee of 0x002B77F7; vector at this+0x8c rank at elem+0x34; clears arg via rowed 0x00072FE6 then set-int insert rowed 0x000BC15D
#include <set>

class Rva00072FE6
{
public:
	void rva00072FE6();
};

struct Rva002B69A6Elem
{
	char m_pad[0x34];
	int m_rank;
};

class Rva002B69A6
{
public:
	void rva002B69A6(void *arg);
private:
	char m_pad00[0x8c];
	Rva002B69A6Elem **m_begin8c;
	Rva002B69A6Elem **m_end90;
	Rva002B69A6Elem **m_cap94;
};

// ?rva002B69A6@Rva002B69A6@@QAEXPAX@Z
void Rva002B69A6::rva002B69A6(void *arg)
{
	((Rva00072FE6 *)arg)->rva00072FE6();
	for (unsigned int i = 0; i < (unsigned int)(m_end90 - m_begin8c); ++i)
	{
		int rank = m_begin8c[i]->m_rank;
		((_STL::set<int> *)arg)->insert(rank);
	}
}
