// cl: /Ireference/shims/bfme2_ascii /O1
// ?rva004FBC02@Rva004FBC02@@QAEXPBURva004FBC02Src@@@Z 0x004FBC02 21: copies 12 bytes
// from arg to +0x18 and sets byte at +0x24 to 1. Evidence: callers 0x002BA331 and
// 0x002BA7E1 pass a pointer; no other callees.

struct Rva004FBC02Src
{
	int m_0;
	int m_4;
	int m_8;
};

class Rva004FBC02
{
private:
	char m_pad[0x18];
	Rva004FBC02Src m_18;
	unsigned char m_24;
public:
	void rva004FBC02(const Rva004FBC02Src *src);
};

void Rva004FBC02::rva004FBC02(const Rva004FBC02Src *src)
{
	m_18 = *src;
	m_24 = 1;
}
