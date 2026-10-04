// ?rva0036667B@Rva0036667B@@QAEXH@Z
// partial score=0.95 date=2026-10-04
// ?rva0036667B@Rva0036667B@@QAEXH@Z
// partial score=0.95 date=2026-10-03
// ?rva0036667B@Rva0036667B@@QAEXH@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /Oy-
// ?rva0036667B@Rva0036667B@@QAEXH@Z @ 0x0036667B 75B evidence: caller 0x00533BEC offsets +4 +8 +0xc +0x2c word store +8 stride 0x10
struct Rva0036667BEntry
{
	char m_pad[8];
	unsigned short m_value;
	char m_pad2[6];
};

class Rva0036667B
{
public:
	void rva0036667B(int value);
	char m_pad0[4];
	Rva0036667BEntry** m_ppEntries; // +4
	int m_countOuter; // +8
	int m_countInner; // +0xc
	char m_pad1[0x1c]; // +0x10..0x2b
	int m_saved; // +0x2c
};

// ?rva0036667B@Rva0036667B@@QAEXH@Z present-unmatched
void Rva0036667B::rva0036667B(int value)
{
	int v = value;
	value = 0;
	m_saved = v;
	if (m_countOuter <= 0)
		return;
	do
	{
		for (int j = 0; j < m_countInner; ++j)
			m_ppEntries[value][j].m_value = (unsigned short)v;
	} while (++value < m_countOuter);
}
