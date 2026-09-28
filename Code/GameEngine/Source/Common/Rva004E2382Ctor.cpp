// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva004E2382@@QAE@XZ @ 0x004E2382 (63B).
// Default ctor: AsciiString at +0 nulled plus int at +4 zeroed plus
// set<AsciiString> at +8 via rowed 0x000D3A71 plus vector at +0x14 via
// rowed Vector_base BfmeE16 0x00211E58. Caller 0x004E3E91 builds a temp
// with it then assigns an AsciiString arg to +0 and destroys the temp
// via 0x004E2941. Layout from that caller plus the dtor shape.
#include <set>
#include <vector>

template <typename T> class StringBase {
    friend class AsciiString;
public:
    StringBase() : m_data(0) {}
    StringBase(const StringBase &);
    ~StringBase();
protected:
    void *m_data;
};

class AsciiString : public StringBase<char> {
public:
    AsciiString() {}
    AsciiString(const AsciiString &other);
    ~AsciiString();
};

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL {
template <> struct less<AsciiString> {
    bool operator()(const AsciiString &left, const AsciiString &right) const {
        return left < right;
    }
};
}

struct BfmeE16 { float x, y, z, w; };

class Rva004E2382 {
public:
    Rva004E2382();
private:
    AsciiString m_00;
    int m_04;
    _STL::set<AsciiString> m_08;
    _STL::vector<BfmeE16> m_14;
};

Rva004E2382::Rva004E2382()
    : m_00(), m_04(0), m_08(), m_14()
{
}
