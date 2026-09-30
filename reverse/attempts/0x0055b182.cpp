// ??0Rva0055B182@@QAE@ABV0@@Z
// partial score=0.99 date=2026-09-30
// ??0Rva0055B182@@QAE@ABV0@@Z
// partial score=0.99 date=2026-09-30
// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0055B182@@QAE@ABV0@@Z retail 0x0055B182 166 bytes.
// Copy ctor of 0x2C-byte record with vtable 0x0086B900: ints at +0x04 and
// +0x08 plus StringBase at +0x0C via rowed copy plus int at +0x10 plus two
// list<int> at +0x14 and +0x1C via rowed base ctor and assign plus flags at
// +0x20 and +0x21 and +0x24 and +0x28. Evidence: vtable store plus StringBase
// copy pin plus list base and assign rows plus ret 4. Caller at 0x00573ADE.
// All callees rowed or pinned.
#include <list>

template <typename T>
class StringBase
{
	StringBase(const StringBase &other);
	void releaseBuffer();
	friend class Rva0055B182;
public:
	~StringBase() { releaseBuffer(); }
private:
	void *m_data;
};

class Rva0055B182
{
public:
	virtual ~Rva0055B182();
	Rva0055B182(const Rva0055B182 &other);

private:
	int m_04;
	int m_08;
	StringBase<char> m_0c;
	int m_10;
	_STL::list<int> m_14;
	int m_18;
	_STL::list<int> m_1c;
	bool m_20;
	bool m_21;
	char m_pad22[2];
	int m_24;
	bool m_28;
};

// ??0Rva0055B182@@QAE@ABV0@@Z present-unmatched
Rva0055B182::Rva0055B182(const Rva0055B182 &other)
	: m_04(other.m_04)
	, m_08(other.m_08)
	, m_0c((const StringBase<char> &)other.m_0c)
	, m_10(other.m_10)
	, m_18(other.m_18)
	, m_20(true)
	, m_21(other.m_21)
	, m_24(other.m_24)
	, m_28(other.m_28)
{
	m_14 = other.m_14;
	m_1c = other.m_1c;
}
