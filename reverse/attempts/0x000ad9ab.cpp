// ?rva000AD9AB@Rva000AD9AB@@QAEXHH_N@Z
// partial score=0.92 date=2026-09-29
// ?rva000AD9AB@Rva000AD9AB@@QAEXHH_N@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /MD
//
// ?rva000AD9AB@Rva000AD9AB@@QAEXHH_N@Z @0x000AD9AB 83B probe v2 unsigned offset
class Rva000AD9AB
{
public:
	void rva000AD9AB(int x, int y, bool set);
private:
	char m_pad00[8];
	int m_08;
	int m_0c;
	char m_pad10[0x34 - 0x10];
	int m_34;
	char m_pad38[0x44 - 0x38];
	unsigned char *m_44;
	unsigned char *m_48;
};
void Rva000AD9AB::rva000AD9AB(int x, int y, bool set)
{
	if (x < 0)
		return;
	if (y < 0)
		return;
	if (y >= m_0c)
		return;
	if (x >= m_08)
		return;
	unsigned int byteOffset = (unsigned int)(m_34 * y + (x >> 3));
	unsigned int dataSize = (unsigned int)(m_48 - m_44);
	if (byteOffset >= dataSize)
		return;
	unsigned char *slot = m_44 + byteOffset;
	unsigned char mask = (unsigned char)1;
	mask <<= (x & 7);
	if (set != false)
		*slot |= mask;
	else
		*slot &= (unsigned char)~mask;
}
