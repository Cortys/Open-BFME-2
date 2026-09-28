// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?push_back@?$vector@VUnicodeString@@V?$allocator@VUnicodeString@@@_STL@@@_STL@@QAEXABVUnicodeString@@@Z retail 0x0005CBE7 55B
// Evidence: unlock lane; callees rowed _Construct 0x00054DF6 and _M_insert_overflow 0x0005B538; callers 0x0005CD41 0x0005DB6C 0x00386B7B; same 55B shape as AsciiString push_back 0x00143170.
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

template void _STL::vector<UnicodeString, _STL::allocator<UnicodeString> >::push_back(const UnicodeString &);
