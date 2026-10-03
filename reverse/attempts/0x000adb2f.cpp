// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z
// partial score=0.98 date=2026-10-03
// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z
// partial score=0.93 date=2026-09-30
// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD
// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z @0x000ADB2F 90B
// Bitmap set-clear via pitch at +0x34 base at +0x38 end at +0x3C bounds width
// at +0x8 height at +0xC. Caller 0x000ADDC2 unclaimed; unblocks 0x000ADCE3.
class Rva000ADB2F
{
public:
	void rva000ADB2F(int x, int y, bool set);
private:
	char m_pad0[8];
	int m_8;
	int m_c;
	char m_pad1[0x34 - 0x10];
	int m_34;
	volatile unsigned int m_38;
	unsigned int m_3C;
};

// ?rva000ADB2F@Rva000ADB2F@@QAEXHH_N@Z present-unmatched
void Rva000ADB2F::rva000ADB2F(int x, int y, bool set)
{
	if (x < 0 || y < 0)
		return;
	if (y >= m_c || x >= m_8)
		return;
	unsigned int off = (unsigned int)(m_34 * y + (x >> 3));
	unsigned int size = m_3C;
	size -= m_38;
	if (off >= size)
		return;
	unsigned char *base = (unsigned char *)m_38;
	unsigned char *slot = base + off;
	unsigned char b = *slot;
	unsigned char bit = (unsigned char)(1u << (x & 7));
	if (set)
		b |= bit;
	else
		b &= (unsigned char)~bit;
	*slot = b;

}
