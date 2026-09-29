// ?bfmeUpdate@BfmeCellFC@@QAEXH_NH@Z
// partial score=0.99 date=2026-09-29
// ?bfmeUpdate@BfmeCellFC@@QAEXH_NH@Z
// partial score=0.99 date=2026-09-29
// cl: /GX
// ?bfmeUpdate@BfmeCellFC@@QAEXH_NH@Z @0x006C15E0 101B (ours 102B).
// BfmeCellFC paint helper; only or-esi left (retail or esi,-1 + mov via esi
// vs ours mov immediate). Byte cmp fixed via m_bfmeKind compare.
class BfmeCellFC
{
public:
	BfmeCellFC();
	~BfmeCellFC();
	unsigned char m_bfmeKind;
	unsigned char m_bfmeGap[3];
	int m_bfmeValue;
	int m_bfmeExtra;
	void bfmeUpdate(int amount, bool absolute, int mode);
};

void BfmeCellFC::bfmeUpdate(int amount, bool absolute, int mode)
{
	if (mode != -1)
	{
		if (amount != 0x80)
			goto update;
		if (mode != m_bfmeExtra)
			return;
	}
update:
	if (!absolute)
		amount += m_bfmeKind;
	if (amount < 0)
		amount = 0;
	else if (amount > 0xFF)
		amount = 0xFF;
	m_bfmeKind = (unsigned char)amount;
	if (m_bfmeKind == 0x80)
	{
		mode = -1;
		m_bfmeExtra = mode;
		m_bfmeValue = 0;
		return;
	}
	m_bfmeValue = m_bfmeKind > 0x80 ? 1 : 2;
	m_bfmeExtra = mode;
}
