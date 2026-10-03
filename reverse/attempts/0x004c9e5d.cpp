// ??0Rva004C9E5D@@QAE@PBHM@Z
// partial score=0.96 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ??0Rva004C9E5D@@QAE@PBHM@Z, retail 0x004C9E5D, 55 bytes.
// 2-arg ctor sibling of Rva004C9E94 95B ctor: int at +0 from *p, zero at +4,
// float at +8, default Rva0042526Member at +0xC/+0x58, byte 0 at +0xA4.
// Evidence: ret 8 return-this, movss, callees rowed 0x00042526, caller 0x004CA53C.
// ??0Rva004C9E5D@@QAE@PBHM@Z present-unmatched
class Rva0042526Member
{
public:
	Rva0042526Member();
private:
	unsigned char m_pad[0x4C];
};

class Rva004C9E5D
{
public:
	Rva004C9E5D(const int *p, float f);
private:
	int m_0;
	int m_1;
	float m_2;
	Rva0042526Member m_3;
	Rva0042526Member m_4;
	unsigned char m_5;
};

Rva004C9E5D::Rva004C9E5D(const int *p, float f)
	: m_0(*p), m_1(0), m_2(f), m_3(), m_4(), m_5(0)
{
}
