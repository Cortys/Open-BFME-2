// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ??$__uninitialized_fill_n@PAVUnicodeString@@IV1@@_STL@@YAPAVUnicodeString@@PAV1@IABV1@ABU__false_type@0@@Z retail 0x00054E66 37B
// Evidence: same 37B count-loop plus _Construct shape as other vector fill_n rows; here fills UnicodeString via rowed _Construct 0x00054DF6;
// element and flags match stlport_vector_unicode_reserve.cpp; caller 0x0005B5A3.
#include <vector>

class UnicodeString
{
public:
    UnicodeString();
    UnicodeString(const UnicodeString &);
    ~UnicodeString();
    UnicodeString &operator=(const UnicodeString &);
private:
    void *m_data;
};

namespace _STL {
template <> void _Construct<UnicodeString, UnicodeString>(UnicodeString *, const UnicodeString &);
}

template class _STL::vector<UnicodeString, _STL::allocator<UnicodeString> >;
