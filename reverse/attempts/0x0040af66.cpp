// ??0Rva0040AF66@@QAE@ABV0@@Z
// partial score=0.98 date=2026-09-30
// ??0Rva0040AF66@@QAE@ABV0@@Z
// partial score=0.98 date=2026-09-30
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0040AF66@@QAE@ABV0@@Z retail 0x0040AF66 141 bytes. Copy ctor with int
// plus two vector<ScienceType> plus two FixedStorage plus two StringBase plus
// ints and byte. Evidence: caller 0x0040B197, rowed vector 0x0054878E, rowed
// FixedStorage 0x0004543D, pin StringBase 0x000365F0, unblocks 0x0040B17B.

#include <vector>

template <typename T> class StringBase
{
public:
	StringBase(const StringBase &other);
	~StringBase();
private:
	T *m_data;
};

enum ScienceType { SCIENCE_NONE = 0 };

struct BfmeFixedStorage0004543D
{
	char m_pad[0x1C];
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other);
};

class Rva0040AF66
{
public:
	Rva0040AF66(const Rva0040AF66 &other);
private:
	int m_00;
	_STL::vector<ScienceType, _STL::allocator<ScienceType> > m_04;
	_STL::vector<ScienceType, _STL::allocator<ScienceType> > m_10;
	BfmeFixedStorage0004543D m_1C;
	BfmeFixedStorage0004543D m_38;
	StringBase<char> m_54;
	StringBase<char> m_58;
	int m_5C;
	int m_60;
	unsigned char m_64;
};

// ??0Rva0040AF66@@QAE@ABV0@@Z present-unmatched
Rva0040AF66::Rva0040AF66(const Rva0040AF66 &other)
	: m_00(other.m_00)
	, m_04(other.m_04)
	, m_10(other.m_10)
	, m_1C(other.m_1C)
	, m_38(other.m_38)
	, m_54(other.m_54)
	, m_58(other.m_58)
	, m_5C(0)
	, m_60(0)
	, m_64(other.m_64)
{
}
