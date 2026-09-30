// ?rva000AE44B@BfmeGridWM@@QAEXHHPAX@Z
// partial score=0.97 date=2026-09-30
// ?rva000AE44B@BfmeGridWM@@QAEXHHPAX@Z
// partial score=0.97 date=2026-09-30
// cl: /O1
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct BfmeGridCell36 {
	int a[9];
};

class BfmeGridWM
{
public:
	void walk();
	void cell(int x, int y);
	unsigned char rva000AE18D(int x, int y);
	void rva000AE44B(int a1, int a2, void *dest);

private:
	int m_pad0;
	int m_pad1;
	int m_w;
	int m_h;
	char m_pad10[0x10];
	int m_20;
	char m_pad24[0x10];
	int m_34;
	char m_pad38[0x30];
	unsigned char *m_data;
	unsigned char *m_dataEnd;
	char m_pad70[0x30];
	int *m_a0;
	char m_padA4[0x8018];
	BfmeGridCell36 *m_80bc;
	char m_pad80C0[0xA020];
	int m_120e0;
	int m_120e4;
};

void BfmeGridWM::walk()
{
	for (int x = 0; x < m_w - 1; ++x)
		for (int y = 0; y < m_h - 1; ++y)
			cell(x, y);
}

unsigned char BfmeGridWM::rva000AE18D(int x, int y)
{
	if (x < 0 || y < 0 || y >= m_h || x >= m_w)
		return 0;
	int byteIdx = m_34 * y + (x >> 3);
	if ((unsigned int)byteIdx >= (unsigned int)(m_dataEnd - m_data))
		return 0;
	_ReadWriteBarrier();
	unsigned int mask = 1u << (x & 7);
	return (m_data[byteIdx] & mask) != 0;
}

// ?rva000AE44B@BfmeGridWM@@QAEXHHPAX@Z present-unmatched
void BfmeGridWM::rva000AE44B(int a1, int a2, void *dest)
{
	int idx = m_120e4 + a2;
	idx *= m_w;
	idx += m_120e0;
	idx += a1;
	if (idx < 0 || idx >= m_20)
		return;
	int v = m_a0[idx];
	*(BfmeGridCell36 *)dest = m_80bc[v];
}
