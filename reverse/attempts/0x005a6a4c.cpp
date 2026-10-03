// ?rva005A6A4C@Rva005A6A4C@@QAEXXZ
// partial score=0.9 date=2026-10-03
// cl: /O1
// ?rva005A6A4C@Rva005A6A4C@@QAEXXZ @0x005A6A4C 55B. Unlock lane: copies two
// dwords from each of 8 src slots at +0x90C into +0x38/+0x3C of the
// corresponding dst at +0x08 when present; early-out when +0x08 is null.
// Target evidence: loop bounds 8 and offsets 0x08/0x38/0x3C/0x90C, callers
// 0x004FE1CD and 0x004FEDDF.
struct Rva005A6A4CDst
{
	char m_pad[0x38];
	int m_38;
	int m_3C;
};
struct Rva005A6A4CSrc
{
	int m_00;
	int m_04;
};
class Rva005A6A4C
{
public:
	void rva005A6A4C();
private:
	char m_00[8];
	Rva005A6A4CDst **m_08;
	char m_0C[0x900];
	Rva005A6A4CSrc *m_90C[8];
};
// ?rva005A6A4C@Rva005A6A4C@@QAEXXZ present-unmatched
void Rva005A6A4C::rva005A6A4C()
{
	if (m_08 == 0)
		return;
	for (int i = 0; i < 8; ++i)
	{
		Rva005A6A4CDst *d = m_08[i];
		if (d != 0)
		{
			Rva005A6A4CSrc *s = m_90C[i];
			d->m_38 = s->m_00;
			d->m_3C = s->m_04;
		}
	}
}
