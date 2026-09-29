// cl: /O1 /MD
// ?rva005312BE@Rva005312BE@@QAEXXZ @ 0x005312BE (66B): __thiscall clears byte at +0x34 of each 0x44-sized entry.
// ?rva00531300@Rva005312BE@@QAEXXZ @ 0x00531300 (66B): same shape sets byte to 1.
// Offsets 0x1BA38/0x1BA3C/0x1BA40 shared with Rva005315B0IntPairField in Disp32IntPairFieldGetters.cpp.
// Callers at 0x002F960C 0x002FA743 0x002FB050 0x002FCA6F 0x002FD573. Owner unknown so honest address name.
class Rva005312BEItem
{
public:
	char m_pad0[0x34];
	unsigned char m_cleared;
	char m_pad1[0x44 - 0x34 - 1];
};
class Rva005312BE
{
public:
	void rva005312BE();
	void rva00531300();
	char m_pad[0x1BA38];
	Rva005312BEItem **m_ppItems;
	int m_outer;
	int m_inner;
};
void Rva005312BE::rva005312BE()
{
	for (int i = 0; i < m_outer; ++i)
	{
		for (int j = 0; j < m_inner; ++j)
			m_ppItems[i][j].m_cleared = 0;
	}
}
void Rva005312BE::rva00531300()
{
	for (int i = 0; i < m_outer; ++i)
	{
		for (int j = 0; j < m_inner; ++j)
			m_ppItems[i][j].m_cleared = 1;
	}
}
