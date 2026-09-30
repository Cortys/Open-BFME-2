// cl: /G7 /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?rva0021EA74@Rva0021EA74@@QAEHABUBfmeStringRecord00219A68@@@Z @0x0021EA74 95B: find-or-add returning index for BfmeStringRecord00219A68 vector at +0x168; find compares first dword only via rowed BfmePod20 find 0x2198AD; push_back via rowed 0x21E6D3; caller parseCreateAHeroBling 0x21ED9C passes global 0xDFE344 plus stack record.
#define _STLP_NO_EXCEPTIONS 1
#include <vector>
#include <algorithm>
template <typename T> class StringBase {
    friend class AsciiString;
    StringBase(const StringBase &);
    __forceinline ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
public:
    void set(const StringBase &);
private:
    void *m_data;
};
class AsciiString : private StringBase<char> {
public:
    __forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    __forceinline ~AsciiString() {}
    AsciiString &operator=(const AsciiString &other);
};
struct BfmeStringRecord00219A68 {
    unsigned int word0; AsciiString text0, text1; unsigned int word1, word2;
    BfmeStringRecord00219A68(const BfmeStringRecord00219A68 &o);
};
struct BfmePod20 {
    unsigned int key;
    unsigned char pad[16];
};
__forceinline bool operator==(const BfmePod20 &a, const BfmePod20 &b) { return a.key == b.key; }
namespace _STL {
template <> void _Construct<BfmeStringRecord00219A68, BfmeStringRecord00219A68>(BfmeStringRecord00219A68 *, const BfmeStringRecord00219A68 &);
}
class Rva0021EA74 {
    char m_pad[0x168];
public:
    _STL::vector<BfmeStringRecord00219A68> m_vec168;
    int rva0021EA74(const BfmeStringRecord00219A68 &rec);
};
int Rva0021EA74::rva0021EA74(const BfmeStringRecord00219A68 &rec)
{
    unsigned int size = m_vec168.size();
    unsigned int key = rec.word0;
    BfmePod20 *first = (BfmePod20 *)m_vec168.begin();
    BfmePod20 *last = (BfmePod20 *)m_vec168.end();
    BfmePod20 *found = _STL::find(first, last, *(const BfmePod20 *)&key);
    if (found == last) {
        m_vec168.push_back(rec);
    } else {
        size = (unsigned int)(found - first);
    }
    return (int)size;
}
