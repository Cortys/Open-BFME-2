// ??0Rva005C8EB3@@QAE@PAX@Z
// partial score=0.97 date=2026-09-30
// ??0Rva005C8EB3@@QAE@PAX@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva005C8EB3@@QAE@PAX@Z @0x005C8EB3 100B
// __thiscall ctor: copies 8 bytes from src at +0/+4, zeros +8, default-builds
// map<int,void*> at +0x2c via rowed 0x0033C432 and vector<BfmeE16> at +0x38
// via rowed Vector_base 0x00211E58 with explicit allocator temp at [ebp+0xb],
// zeros word at +0x44, byte at +0x46, sets 0x80 at +0x47, memsets 32B at +0xc.
// Evidence: callees rowed; caller 0x005C865B; layout size 0x48 matches
// Rva005C87F8Adjust sibling (8-dword array at +0xc, trailing bytes +0x46/+0x47).
#include <map>
#include <vector>

struct BfmeE16
{
	float x;
	float y;
	float z;
	float w;
};

struct Base0C
{
	Base0C(void *src)
	{
		m_00 = ((int *)src)[0];
		m_04 = ((int *)src)[1];
		m_08 = 0;
	}
	~Base0C();
	int m_00;
	int m_04;
	int m_08;
};

class Rva005C8EB3 : public Base0C
{
public:
	Rva005C8EB3(void *src);
private:
	int m_buf[8];
	_STL::map<int, void *, _STL::less<int>, _STL::allocator<_STL::pair<const int, void *> > > m_map;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_vec;
	unsigned short m_44;
	unsigned char m_46;
	signed char m_47;
};

// ??0Rva005C8EB3@@QAE@PAX@Z present-unmatched
Rva005C8EB3::Rva005C8EB3(void *src)
	: Base0C(src)
	, m_vec(_STL::allocator<BfmeE16>())
	, m_44(0)
	, m_46(0)
	, m_47((signed char)0x80)
{
	for (int i = 0; i < 8; i++)
		m_buf[i] = 0;
}
