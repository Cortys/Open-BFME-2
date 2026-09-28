// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??$__uninitialized_fill_n@PAUBfmeStringRecord005ED5F3@@IU1@@_STL@@YAPAUBfmeStringRecord005ED5F3@@PAU1@IABU1@ABU__false_type@0@@Z @0x005ED8AC 37B: vector fill helper for 20-byte BfmeStringRecord005ED5F3 (UnicodeString plus 4 words). Evidence: calls rowed _Construct 0x005ED68C; stride 0x14; callers are vector insert paths 0x005ED99F 0x005EDB2B.
#include <vector>
class UnicodeString
{
public:
    UnicodeString(const UnicodeString &other);
    __forceinline ~UnicodeString() { releaseBuffer(); }
protected:
    void releaseBuffer();
private:
    void *m_data;
};
struct BfmeStringRecord005ED5F3
{
    UnicodeString text;
    unsigned int word0;
    unsigned int word1;
    unsigned int word2;
    unsigned int word3;
    BfmeStringRecord005ED5F3();
    BfmeStringRecord005ED5F3(const BfmeStringRecord005ED5F3 &other);
};
namespace _STL {
template <> void _Construct<BfmeStringRecord005ED5F3, BfmeStringRecord005ED5F3>(BfmeStringRecord005ED5F3 *, const BfmeStringRecord005ED5F3 &);
}
template class _STL::vector<BfmeStringRecord005ED5F3, _STL::allocator<BfmeStringRecord005ED5F3> >;
