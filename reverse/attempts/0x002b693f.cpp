// ?rva002B693F@Rva002B693F@@QAEXPAX@Z
// partial score=0.92 date=2026-10-02
// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?rva002B693F@Rva002B693F@@QAEXPAX@Z @0x002B693F 103B evidence: unlock sibling of 0x002B69A6; same vector at this+0x8c rank at elem+0x34 set-int insert rowed 0x000BC15D and clear rowed 0x00072FE6; extra byte guard at elem+0x3c4 skipping insert when nonzero
#include <set>

class Rva00072FE6
{
public:
	void rva00072FE6();
};

struct Rva002B693FElem
{
	char m_pad[0x34];
	int m_rank34;
	char m_pad38[0x3c4 - 0x38];
	unsigned char m_flag3c4;
};

class Rva002B693F
{
public:
	void rva002B693F(void *arg);
private:
	char m_pad00[0x8c];
	int m_begin8c;
	int m_end90;
	int m_cap94;
};

// ?rva002B693F@Rva002B693F@@QAEXPAX@Z
void Rva002B693F::rva002B693F(void *arg)
{
	void *a = arg;
	((Rva00072FE6 *)a)->rva00072FE6();
	for (unsigned int i = 0; i < (unsigned int)((m_end90 - m_begin8c) >> 2); ++i)
	{
		Rva002B693FElem *elem = ((Rva002B693FElem **)m_begin8c)[i];
		if (elem->m_flag3c4 == 0)
		{
			int rank = elem->m_rank34;
			((_STL::set<int> *)arg)->insert(rank);
		}
	}
}
