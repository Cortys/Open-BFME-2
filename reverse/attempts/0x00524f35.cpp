// ?rva00524F35@Rva00524F35@@QAEXH@Z
// partial score=0.95 date=2026-09-29
// ?rva00524F35@Rva00524F35@@QAEXH@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /G7 /MD
// ?rva00524F35@Rva00524F35@@QAEXH@Z @0x00524F35 37B
// Init setter: stores int arg at +0, 0 at +4, -1 at +8/+0xc/+0x10,
// 0 bytes at +0x14/+0x15/+0x16. Frameless ret 4. Unlocks 0x00527378.
// Evidence: or -1 trio then mov arg xor-zero stores, caller 0x00527512.
struct Rva00524F35
{
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	unsigned char m_14;
	unsigned char m_15;
	unsigned char m_16;
	void rva00524F35(int v);
};
// ?rva00524F35@Rva00524F35@@QAEXH@Z present-unmatched
void Rva00524F35::rva00524F35(int v)
{
	int t = v;
	m_08 = -1;
	m_0c = -1;
	m_10 = -1;
	m_00 = t;
	m_04 = 0;
	m_14 = 0;
	m_15 = 0;
	m_16 = 0;
}
