// ?rva0044E689@Rva0044E689@@QAEHXZ
// partial score=0.9 date=2026-09-28
// ?rva0044E689@Rva0044E689@@QAEHXZ
// partial score=0.90 date=2026-09-28
// cl: /O1
struct Inner08
{
	char m_pad[0x258];
	int m_val258;
};

class Rva0044E689
{
public:
	char m_pad0[8];
	Inner08 *m_ptr08;
	char m_padC[0x7E - 0x0C];
	unsigned char m_byte7E;
	unsigned char m_byte7F;
	int rva0044E689();
};

int Rva0044E689::rva0044E689()
{
	if (m_ptr08->m_val258 == 0)
		return 0;
	if (m_byte7E != 0)
	{
		if (m_byte7F != 0)
			return 0;
	}
	return 1;
}
