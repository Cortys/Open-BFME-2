// cl: /O1 /MD /arch:SSE
// ??0Rva004530ED@@QAE@XZ @ 0x004530D0 29B: default ctor zeroing 20-byte record. Evidence: caller 0x00453B48 inits stack local via this; next row 0x004530ED copy ctor same class; xorps plus movss shape proves float members.
class Rva004530ED
{
public:
	Rva004530ED();
private:
	int m_00;
	float m_04;
	float m_08;
	float m_0C;
	float m_10;
};

Rva004530ED::Rva004530ED()
{
	m_00 = 0;
	m_04 = 0;
	m_08 = 0;
	m_0C = 0;
	m_10 = 0;
}
