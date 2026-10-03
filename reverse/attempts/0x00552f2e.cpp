// ?rva00552F2E@Rva00552F2E@@QAEXXZ
// partial score=0.88 date=2026-10-03
// cl: /O1 /MD
// ?rva00552F2E@Rva00552F2E@@QAEXXZ 0x00552F2E 20B: thiscall zero loop over 8 dwords; callers 0x0055744C 0x007B4751
class Rva00552F2E
{
public:
	int m_a[4];
	int m_b[4];
	void rva00552F2E();
};

// ?rva00552F2E@Rva00552F2E@@QAEXXZ present-unmatched
void Rva00552F2E::rva00552F2E()
{
	for (int i = 0; i < 4; i++)
	{
		m_b[i] = 0;
		m_a[i] = 0;
	}
}
