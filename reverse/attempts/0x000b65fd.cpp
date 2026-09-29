// ?rva000B65FD@Rva000B65FD@@QAEHXZ
// partial score=0.93 date=2026-09-29
// ?rva000B65FD@Rva000B65FD@@QAEHXZ
// partial score=0.93 date=2026-09-29
// cl: /O1
// ?rva000B65FD@Rva000B65FD@@QAEHXZ, retail 0x000B65FD, 23B.
// Base at +8 plus nullable word at +4 of object reached via double
// dereference at +0xC. Callers 0x000B956A 0x000BDC8F. Honest address name.
struct Rva000B65FDAux
{
	char m_pad00[4];
	unsigned short m_word04;
};

class Rva000B65FD
{
public:
	int rva000B65FD();
private:
	char m_pad00[8];
	int m_base08;
	Rva000B65FDAux **m_pp0C;
};

// ?rva000B65FD@Rva000B65FD@@QAEHXZ present-unmatched
int Rva000B65FD::rva000B65FD()
{
	int base = m_base08;
	Rva000B65FDAux *p = *m_pp0C;
	int v = p ? p->m_word04 : 0;
	return base + v;
}
