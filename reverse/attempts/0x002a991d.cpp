// ??0Rva002A991D@@QAE@XZ
// partial score=0.96 date=2026-09-29
// ??0Rva002A991D@@QAE@XZ
// partial score=0.96 date=2026-09-29
// cl: /O1 /arch:SSE /MD
//
// ??0Rva002A991D@@QAE@XZ retail 0x002A991D 82B. Ctor over two 0x1C members via
// rowed Rva0024C7B3Member ctor plus redundant memset zeroing, three zero
// floats at +0x38/+0x3C/+0x40, int zero at +0x44, FLT_MAX at +0x48 from pool
// 0x00BBB8E0. Evidence: rowed callees plus FLT_MAX pool plus callers
// 0x002AB185/0x002AB1DE stacking a 0x4C temp. Honest address name.
#pragma function(memset)
extern "C" void *memset(void *dst, int value, unsigned int size);

#define Gbl00BBB8E0 (*(const float *)0x00BBB8E0)

class Rva0024C7B3Member
{
public:
	Rva0024C7B3Member();
	unsigned char m_data[0x1C];
};

class Rva002A991D
{
public:
	Rva002A991D();
private:
	Rva0024C7B3Member m_00;
	Rva0024C7B3Member m_1C;
	float m_38;
	float m_3C;
	float m_40;
	int m_44;
	float m_48;
};

// ??0Rva002A991D@@QAE@XZ present-unmatched
Rva002A991D::Rva002A991D()
{
	memset(&m_00, 0, 0x1C);
	memset(&m_1C, 0, 0x1C);
	m_38 = 0.0f;
	m_3C = 0.0f;
	m_40 = 0.0f;
	const float f = Gbl00BBB8E0;
	m_44 = 0;
	m_48 = f;
}
