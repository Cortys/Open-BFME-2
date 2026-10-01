// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// Rva0021F876 copy ctor, retail 0x0021F876 125 bytes. Copy ctor
// copying five StringBase<char> plus vector<BfmePod216> with EH states 0-4.
// Evidence: caller 0x0021FA36, rowed vector copy 0x0021F404, pin StringBase
// copy 0x000365F0 via public QAE spelling, unblocks 0x0021FA1A.
// The strings are AsciiString members with an inline copy ctor: retail forms
// each member address before pushing the source (the banked attempt called
// StringBase's copy ctor directly and pushed first).

#include <vector>

class AsciiString;

template <typename T> class StringBase
{
public:
	~StringBase();
private:
	StringBase(const StringBase &other);
	T *m_data;
	friend class AsciiString;
};
class AsciiString
{
public:
	AsciiString(const AsciiString &o) : m_data(o.m_data) {}
private:
	StringBase<char> m_data;
};

struct BfmePod216 { int a[54]; };

class Rva0021F876
{
public:
	Rva0021F876(const Rva0021F876 &other);
private:
	AsciiString m_00;
	AsciiString m_04;
	AsciiString m_08;
	AsciiString m_0C;
	AsciiString m_10;
	_STL::vector<BfmePod216, _STL::allocator<BfmePod216> > m_14;
};

Rva0021F876::Rva0021F876(const Rva0021F876 &other)
	: m_00(other.m_00)
	, m_04(other.m_04)
	, m_08(other.m_08)
	, m_0C(other.m_0C)
	, m_10(other.m_10)
	, m_14(other.m_14)
{
}
