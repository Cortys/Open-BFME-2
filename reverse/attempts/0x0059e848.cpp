// ?rva0059E848@Rva0059E848@@QAEXXZ
// partial score=0.9 date=2026-10-03
// cl: /O1 /MD
// ?rva0059E848@Rva0059E848@@QAEXXZ @0x0059E848 25B: single-element vector flush to holder.
// Retail loads [ecx+0x18]-[ecx+0x14], masks low bits, cmp 4, then copies *begin to [holder+4].
// Evidence: caller 0x0059EA05 passes 0x20-byte object after initFromINI table 0x00871178,
// neighbours 0x0059E81F plus 0x0059E872, unblocks 0x0059E9BD.
// ?rva0059E848@Rva0059E848@@QAEXXZ present-unmatched
class Rva0059E848Holder
{
public:
	int m_00;
	int m_val04;
};

class Rva0059E848
{
public:
	void rva0059E848();
private:
	char m_pad00[4];
	Rva0059E848Holder *m_p04;
	char m_pad08[12];
	int m_begin14;
	int m_end18;
	void *m_eos1C;
};

void Rva0059E848::rva0059E848()
{
	if (((m_end18 - m_begin14) & ~3) == 4) {
		int *b = (int *)m_begin14;
		Rva0059E848Holder *h = m_p04;
		h->m_val04 = *b;
	}
}
