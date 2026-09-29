// ?rva000B65FD@Rva000B65FD@@QAEHXZ
// partial score=0.91 date=2026-09-29
// ?rva000B65FD@Rva000B65FD@@QAEHXZ
// partial score=0.91 date=2026-09-29
// cl: /O1
//
// ?rva000B65FD@Rva000B65FD@@QAEHXZ retail 0x000B65FD 23B.
// Evidence: m_8 plus nullable ptr-chase word at +4; callers 0x000B956A 0x000BDC8F.
struct Rva000B65FDInner
{
	char m_pad[4];
	unsigned short m_4;
};
class Rva000B65FD
{
public:
	int rva000B65FD();
private:
	char m_pad[8];
	int m_8;
	Rva000B65FDInner **m_C;
};

int Rva000B65FD::rva000B65FD()
{
	Rva000B65FDInner *p = *m_C;
	int base = m_8;
	return base + (p != 0 ? p->m_4 : 0);
}
