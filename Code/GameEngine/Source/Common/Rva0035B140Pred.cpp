// ?rva0035B140@Rva0035B140@@QAE_NXZ retail 0x0035B140 36B
// Predicate returning true for m_14 in 0x18/0x20/0x26/0x17 else bit 9 of
// m_1c. Evidence: unlock lane plus 4 callers plus ecx-first thiscall shape
// with honest address name.

class Rva0035B140
{
public:
	bool rva0035B140();

private:
	char m_pad[0x14];
	int m_14;
	int m_18;
	unsigned int m_1c;
};

bool Rva0035B140::rva0035B140()
{
	if (m_14 == 0x18 || m_14 == 0x20 || m_14 == 0x26 || m_14 == 0x17)
		return true;
	return ((m_1c >> 9) & 1) != 0;
}
