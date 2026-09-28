// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /EHsc
// stlport

// ??1Rva005DE5B5@@QAE@XZ, RVA 0x005DE5B5, 53B.
// Unlock lane: all callees rowed (vector dtor 0x005DE47B,
// releaseBuffer 0x00036E70, __EH_prolog). Callers at 0x005DE785/
// 0x005DE8B7/0x005DE95B plus jmp at 0x005DE7CC and Unwind funclet.
// Non-virtual dtor destroying vector at +4 then UnicodeString at +0
// (reverse declaration order) under the shipped EH state.
// UnicodeString, BfmeStringRecord and vector models are the neighbour
// TU's (stlport_vector_stringrecord_5ddd40_allocate_copy.cpp) verbatim
// so the member dtor calls land on the rowed bodies.

class UnicodeString;
class Rva005DE5B5;

typedef unsigned short wchar_t;

template <typename T>
class StringBase
{
public:
	__forceinline ~StringBase() { releaseBuffer(); }
protected:
	void releaseBuffer();
private:
	StringBase(const StringBase &);
	friend class Rva005DE5B5;
	friend class UnicodeString;
	void *m_data;
};

class UnicodeString : public StringBase<wchar_t>
{
public:
	UnicodeString(const UnicodeString &);
	__forceinline ~UnicodeString() { releaseBuffer(); }
};
#include <vector>
struct BfmeStringRecord005DDD40 {
    UnicodeString text;
    unsigned int word;
    BfmeStringRecord005DDD40();
    BfmeStringRecord005DDD40(const BfmeStringRecord005DDD40 &);
    BfmeStringRecord005DDD40 &operator=(const BfmeStringRecord005DDD40 &);
};
namespace _STL {
template <> void _Construct<BfmeStringRecord005DDD40, BfmeStringRecord005DDD40>(BfmeStringRecord005DDD40 *, const BfmeStringRecord005DDD40 &);
}

class Rva005DE5B5
{
public:
	~Rva005DE5B5();
	Rva005DE5B5(const Rva005DE5B5 &other);
	void *rva005DE782(unsigned int flags);

private:
	StringBase<wchar_t> m_00;
	_STL::vector<BfmeStringRecord005DDD40, _STL::allocator<BfmeStringRecord005DDD40> > m_04;
	unsigned int m_10;
	unsigned char m_14;
};

Rva005DE5B5::~Rva005DE5B5()
{
}

// Retail 0x005DE56C (73B): Rva005DE5B5 copy ctor. Chain lane: StringBase
// copy 0x00037050 at +0, vector copy ctor 0x005DE0A3 at +4, dword at
// +0x10, byte at +0x14. Total size 0x18, matching the Destroy stride.
// Caller is 0x005DE771 in 0x005DE755.
Rva005DE5B5::Rva005DE5B5(const Rva005DE5B5 &other)
	: m_00(other.m_00), m_04(other.m_04), m_10(other.m_10), m_14(other.m_14)
{
}

// Retail 0x005DE952 (25B): destroy range calling the 0x005DE5B5 dtor per
// 0x18-byte element from start (inclusive) to end (exclusive). Chain lane:
// callee is the just-landed dtor; caller is 0x005DE99F in 0x005DE985.
void Rva005DE952Destroy(Rva005DE5B5 *start, Rva005DE5B5 *end)
{
	for (; start != end; start = (Rva005DE5B5 *)((char *)start + 0x18))
		start->~Rva005DE5B5();
}

void operator delete(void *ptr);

// Retail 0x005DE782 (28B): flag-guarded teardown calling the 0x005DE5B5
// dtor then operator delete, returning this. Chain lane: callees are
// the just-landed dtor plus rowed operator delete 0x0002FD60. Owner
// proven by the dtor call with this; honest address-derived method name
// (non-virtual class, so not a ??_G).
void *Rva005DE5B5::rva005DE782(unsigned int flags)
{
	this->~Rva005DE5B5();
	if (flags & 1)
		::operator delete(this);
	return this;
}
