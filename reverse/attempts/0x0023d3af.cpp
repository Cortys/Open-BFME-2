// ?rva0023D3AF@Rva0023D3AF@@QAEXH@Z
// partial score=0.9 date=2026-09-29
// ?rva0023D3AF@Rva0023D3AF@@QAEXH@Z
// partial score=0.9 date=2026-09-29
// cl: /O1 /MD
// ?rva0023D3AF@Rva0023D3AF@@QAEXH@Z — RVA 0x0023D3AF, 184B.
// Conditional history save plus full snapshot copy: if flag +0x1A4 set, save
// +0x164/+0x174/+0x184 into +0x18C/+0x190/+0x194, else init those from
// +0x14/+0x24/+0x34; then copy +0x8..+0x34 into +0x158..+0x184, store arg at
// +0x188, set +0x1A4/+0x1A5=1 and +0x1A6=0.
// Evidence: retail mov bytes; no calls; callers at 0x2459E1 0x28D42A 0x296622 0x3905E3 0x45BEEC 0x464CCC.

class Rva0023D3AF
{
public:
	void rva0023D3AF(int arg);
	char m_00[8];
	int m_08;
	int m_0C;
	int m_10;
	int m_14;
	int m_18;
	int m_1C;
	int m_20;
	int m_24;
	int m_28;
	int m_2C;
	int m_30;
	int m_34;
	char m_38[0x120];
	int m_158;
	int m_15C;
	int m_160;
	int m_164;
	int m_168;
	int m_16C;
	int m_170;
	int m_174;
	int m_178;
	int m_17C;
	int m_180;
	int m_184;
	int m_188;
	int m_18C;
	int m_190;
	int m_194;
	char m_198[0xC];
	unsigned char m_1A4;
	unsigned char m_1A5;
	unsigned char m_1A6;
};

void Rva0023D3AF::rva0023D3AF(int arg)
{
	int *hist = &m_18C;
	int t;
	if (m_1A4)
	{
		int *p = &m_158;
		hist[0] = p[3];
		hist[1] = p[7];
		t = p[11];
	}
	else
	{
		hist[0] = m_14;
		hist[1] = m_24;
		t = m_34;
	}
	hist[2] = t;
	m_1A5 = 1;
	m_158 = m_08;
	m_15C = m_0C;
	m_160 = m_10;
	m_164 = m_14;
	{
		int *d = &m_168;
		d[0] = m_18;
		d[1] = m_1C;
		d[2] = m_20;
		d[3] = m_24;
	}
	{
		int *e = &m_178;
		e[0] = m_28;
		e[1] = m_2C;
		e[2] = m_30;
		e[3] = m_34;
	}
	m_188 = arg;
	m_1A4 = 1;
	m_1A6 = 0;
}
