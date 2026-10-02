// ?rva0044EE07@Rva0044EE07@@QAEXXZ
// partial score=0.97 date=2026-10-02
// cl: /O1 /DNDEBUG /MD
// ?rva0044EE07@Rva0044EE07@@QAEXXZ @0x0044EE07 121B: bitfield init via rowed 0x0044E9C7 then rowed 0x001E42F2, conditional bitset via rowed 0x0028F59A ctor plus second 0x001E42F2, zero +0x84; evidence callees all rowed, callers 0x004500A3 0x004502CE, neighbours same flags.
class Rva0044E9C7
{
public:
	Rva0044E9C7 *rva0044E9C7(int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g, unsigned int h, unsigned int i, unsigned int j, unsigned int k, unsigned int l, unsigned int m, unsigned int n, unsigned int o);
	unsigned int m_bits[19];
};

struct Rva001E42F2
{
	void rva001E42F2(const int *x);
};

struct Rva0028F59A
{
	Rva0028F59A(int unused, int bit);
	unsigned int m_bits[19];
};

struct Inner0044EE07
{
	char m_pad[0x18];
	int m_18;
	int m_1c;
};

class Rva0044EE07
{
public:
	void rva0044EE07();
private:
	char m_00[4];
	Inner0044EE07 *m_04;
	Rva001E42F2 *m_08;
	char m_0c[0x84 - 0x0c];
	int m_84;
};

// ?rva0044EE07@Rva0044EE07@@QAEXXZ present-unmatched
void Rva0044EE07::rva0044EE07()
{
	Rva001E42F2 *dst = m_08;
	{
		Rva0044E9C7 tmp1;
		dst->rva001E42F2((const int *)tmp1.rva0044E9C7(0, 0x60, 0x5e, 0x29, 0x76, 0x5f, 0x84, 0x61, 0x62, 0x63, 0x249, 0x24a, 0x24b, 0x6e, 0x6f));
	}
	Inner0044EE07 *p = m_04;
	int v = p->m_18;
	if (v == -1)
		return;
	if (p->m_1c != 0)
		return;
	{
		Rva0028F59A tmp2(0, v);
		dst->rva001E42F2((const int *)&tmp2);
	}
	m_84 = 0;
}
