// cl: /O1
// ?rva0044E5E7@Rva0044E5E7@@QAE_NXZ @0x0044E5E7 38B
// Predicate over +0x30 +0x04-subject +0x7D: unlock lane; callers at
// 0x0045221D 0x004522B5 in 0x00451FA2; prev DispByteFieldSetters next
// Rva0044E633FilteredFind; returns true only when +0x30==4 and sub +0x84!=0
// with +0x7D gate when sub +0xA8 set.
class Sub0044E5E7
{
public:
	char m_pad00[0x84];
	int m_84;
	char m_pad88[0xA8 - 0x88];
	unsigned char m_a8;
};

class Rva0044E5E7
{
public:
	bool rva0044E5E7();
private:
	char m_pad00[4];
	Sub0044E5E7 *m_ptr04;
	char m_pad08[0x30 - 0x08];
	int m_30;
	char m_pad34[0x7D - 0x34];
	unsigned char m_7D;
};

bool Rva0044E5E7::rva0044E5E7()
{
	Sub0044E5E7 *sub = m_ptr04;
	if (m_30 != 4)
		goto fail;
	if (sub->m_a8 != 0)
	{
		if (m_7D != 0)
			goto fail;
	}
	if (sub->m_84 != 0)
		return true;
fail:
	return false;
}
