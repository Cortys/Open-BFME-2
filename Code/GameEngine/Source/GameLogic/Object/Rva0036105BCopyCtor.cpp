// cl: /O1 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva0036105B@@QAE@ABV0@@Z @0x0036105B 209B
// Copy ctor for the 148-byte science-cluster record sharing the layout of
// ??0Rva00360F55@@QAE@XZ at 0x00360F55. Two AsciiString vectors at +0x00
// and +0x0C via the rowed copy at 0x000BC07E, four int vectors at +0x18
// +0x24/+0x30/+0x3C via the rowed copy at 0x002CFAB9, two
// BfmeFixedStorage0004543D at +0x48/+0x64 via the rowed copy at
// 0x0004543D, then ints/byte at +0x80/+0x84/+0x88/+0x8C/+0x90. EH states
// 0-4 plus SEH, ret 4. One caller at 0x0036148C. Honest address-derived
// class (same 148B layout as 0x360F55 but unproven same identity).
#include <vector>

template <typename T>
class StringBase
{
    void *m_data;
    void releaseBuffer();

protected:
    ~StringBase()
    {
        releaseBuffer();
    }
};

class AsciiString : private StringBase<char>
{
public:
    ~AsciiString()
    {
    }
};

class BfmeFixedStorage0004543D
{
public:
    BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other) throw();

private:
    unsigned char m_data[0x1C];
};

class Rva0036105B
{
public:
    Rva0036105B(const Rva0036105B &other);

private:
    _STL::vector<AsciiString, _STL::allocator<AsciiString> > m_00;
    _STL::vector<AsciiString, _STL::allocator<AsciiString> > m_0C;
    _STL::vector<unsigned int, _STL::allocator<unsigned int> > m_18;
    _STL::vector<unsigned int, _STL::allocator<unsigned int> > m_24;
    _STL::vector<unsigned int, _STL::allocator<unsigned int> > m_30;
    _STL::vector<unsigned int, _STL::allocator<unsigned int> > m_3C;
    BfmeFixedStorage0004543D m_48;
    BfmeFixedStorage0004543D m_64;
    int m_80;
    int m_84;
    unsigned char m_88;
    char m_pad89[3];
    int m_8C;
    int m_90;
};

Rva0036105B::Rva0036105B(const Rva0036105B &other)
    : m_00(other.m_00)
    , m_0C(other.m_0C)
    , m_18(other.m_18)
    , m_24(other.m_24)
    , m_30(other.m_30)
    , m_3C(other.m_3C)
    , m_48(other.m_48)
    , m_64(other.m_64)
    , m_80(other.m_80)
    , m_84(other.m_84)
    , m_88(other.m_88)
    , m_8C(other.m_8C)
    , m_90(other.m_90)
{
}
