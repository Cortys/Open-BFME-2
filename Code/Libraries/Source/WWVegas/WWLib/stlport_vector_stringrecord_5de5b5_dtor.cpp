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

class UnicodeString { public: UnicodeString(const UnicodeString &); __forceinline ~UnicodeString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
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

private:
	UnicodeString m_00;
	_STL::vector<BfmeStringRecord005DDD40, _STL::allocator<BfmeStringRecord005DDD40> > m_04;
};

Rva005DE5B5::~Rva005DE5B5()
{
}
