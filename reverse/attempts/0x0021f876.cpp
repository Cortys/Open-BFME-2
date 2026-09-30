// ??0Rva0021F876@@QAE@ABV0@@Z
// partial score=0.93 date=2026-09-30
// ??0Rva0021F876@@QAE@ABV0@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0021F876@@QAE@ABV0@@Z retail 0x0021F876 125 bytes. Copy ctor
// copying five StringBase<char> plus vector<BfmePod216> with EH states 0-4.
// Evidence: caller 0x0021FA36, rowed vector copy 0x0021F404, pin StringBase
// copy 0x000365F0 via public QAE spelling, unblocks 0x0021FA1A.

#include <vector>

template <typename T> class StringBase
{
public:
	StringBase(const StringBase &other);
	~StringBase();
private:
	T *m_data;
};

struct BfmePod216 { int a[54]; };

class Rva0021F876
{
public:
	Rva0021F876(const Rva0021F876 &other);
private:
	StringBase<char> m_00;
	StringBase<char> m_04;
	StringBase<char> m_08;
	StringBase<char> m_0C;
	StringBase<char> m_10;
	_STL::vector<BfmePod216, _STL::allocator<BfmePod216> > m_14;
};

// ??0Rva0021F876@@QAE@ABV0@@Z present-unmatched
Rva0021F876::Rva0021F876(const Rva0021F876 &other)
	: m_00(other.m_00)
	, m_04(other.m_04)
	, m_08(other.m_08)
	, m_0C(other.m_0C)
	, m_10(other.m_10)
	, m_14(other.m_14)
{
}
