// cl: /O1 /EHsc /MD
// ?rva0042CB81@Rva0042CBB6@@QAEXH@Z @0x0042CB81 53B via conditional counter decrement plus zero-guard clear
// Evidence: layout matches Rva0042CBB6Ctor (+8 +0x30 +0x34 +0x39); callers 5 incl 0x0042CE09 0x0042D0CD; unblocks 0x0042D068
class Rva0042CBB6
{
public:
	void rva0042CB81(int x);
	void rva0042CAEB(int y);
private:
	const void *m_vtable;
	int m_04;
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
	unsigned char m_38;
	unsigned char m_39;
	char m_3A[4];
	unsigned char m_3E;
	unsigned char m_3F;
	unsigned char m_40;
	unsigned char m_41;
	unsigned char m_42;
};

void Rva0042CBB6::rva0042CAEB(int y)
{
	if (m_04 == y)
		m_04 = 0;
}

void Rva0042CBB6::rva0042CB81(int x)
{
	if (x == 0)
		m_08 = 0;
	else {
		int cur = m_08;
		if ((x & cur) != 0)
			m_08 = cur - x;
	}
	if (m_08 < 0)
		m_08 = 0;
	if (m_08 == 0) {
		m_39 = 0;
		m_30 = 0;
		m_34 = 0;
	}
}
