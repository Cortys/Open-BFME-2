// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// ??1Rva004482FB@@QAE@XZ retail 0x004482FB 87B
// Dtor: release UnicodeString at +0xF64 via rowed 0x00036E70 then destroy 8x0x1D0 array at +0xDC via rowed Rva00447B0E 0x00447B0E then base Rva00382FA7 pin 0x00400A7F. Evidence: unlock lane; caller 0x004482DF deleting dtor; prev Rva004482B7Finish array shape 8x0x1D0; wide release same as sibling 0x00448280.
#include "unicode_string.h"

class Rva00382FA7
{
public:
    virtual ~Rva00382FA7();
    char m_pad[0xDC - 4];
};

class Rva00447B0E
{
public:
    ~Rva00447B0E();
    char m_pad[0x1D0];
};

class Rva004482FB
{
public:
    ~Rva004482FB();
private:
    Rva00382FA7 m_base;
    Rva00447B0E m_items[8];
    char m_gap[8];
    UnicodeString m_wide;
};

Rva004482FB::~Rva004482FB()
{
}
