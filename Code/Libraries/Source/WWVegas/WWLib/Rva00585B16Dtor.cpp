// cl: /O1 /G7 /arch:SSE /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ??1Rva00585B16@@QAE@XZ @0x00585B16 8B tail-jmp to rowed deque dtor;
// callers at 0x00585D24 0x00586B9B and Unwind funclets; unlock.
#include <deque>
struct BfmeE12 { float x, y, z; };
class Rva00585B16
{
public:
	Rva00585B16();
	~Rva00585B16();
private:
	int m_0;
	float m_4;
	float m_8;
	float m_C;
	char m_pad10[12];
	unsigned char m_1C;
	char m_pad1D[3];
	int m_20;
	int m_24;
	_STL::deque<BfmeE12, _STL::allocator<BfmeE12 > > m_deque;
	int m_50;
};
Rva00585B16::~Rva00585B16()
{
}
Rva00585B16::Rva00585B16()
	: m_0(0)
	, m_1C(1)
	, m_20(0)
	, m_24(0)
	, m_deque()
	, m_50(0)
{
	m_4 = 0.0f;
	m_8 = 0.0f;
	m_C = 0.0f;
}
