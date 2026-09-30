// ??0Rva001EB15A@@QAE@ABU0@@Z
// partial score=0.96 date=2026-09-29
// ??0Rva001EB15A@@QAE@ABU0@@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva001EB15A@@QAE@ABU0@@Z, retail 0x001EB15A, 89 bytes.
// Copy ctor: copies three dwords at +0/+4/+8, wide StringBase at +0xC via
// rowed 0x00037050, narrow StringBase at +0x10 via pinned 0x000365F0, byte
// at +0x14. Evidence: twin StringBase calls, EH state 0 between them,
// callers 0x001EB79E 0x002E13F6 0x0037E9F0, subobject at +0x94 of 119B caller.
typedef unsigned short WideChar;

template <typename T>
class StringBase
{
public:
	StringBase<T> &operator=(const StringBase<T> &src);
	~StringBase();
private:
	StringBase(const StringBase<T> &src);
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
	friend struct Rva001EB15A;
};

struct Rva001EB15A
{
	int m_00;
	int m_04;
	int m_08;
	StringBase<WideChar> m_wstr0C;
	StringBase<char> m_str10;
	unsigned char m_14;
	Rva001EB15A(const Rva001EB15A &o);
};

// ??0Rva001EB15A@@QAE@ABU0@@Z present-unmatched
Rva001EB15A::Rva001EB15A(const Rva001EB15A &o)
	: m_00(o.m_00)
	, m_04(o.m_04)
	, m_08(o.m_08)
	, m_wstr0C(o.m_wstr0C)
	, m_str10(o.m_str10)
	, m_14(o.m_14)
{
}
