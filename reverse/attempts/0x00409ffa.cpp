// ??0Rva00409FFA@@QAE@ABVAsciiString@@H@Z
// partial score=0.93 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ??0Rva00409FFA@@QAE@ABVAsciiString@@H@Z @0x00409FFA 93B
// Evidence: unlock lane; 0x9C ctor with vtable C3906C from mov at +0x21;
// StringBase copy at 0x365F0 for AsciiString +0x10; 0x20-dword rep stosd;
// +0x94 is 0x20 count sharing rep count; +0x98 is second arg; +0xC is -1 via OR;
// callers 31B090 31E903 allocate 0x9C then call.
#include <memory>
#include "ascii_string.h"
class Xfer;
class Snapshot {
public:
    __forceinline virtual ~Snapshot() {}
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
};
class Rva00409FFA : public Snapshot {
    unsigned int word04;
    unsigned char flag08;
    unsigned int word0C;
    AsciiString str10;
    unsigned int arr14[32];
    unsigned int word94;
    unsigned int word98;
public:
    Rva00409FFA(const AsciiString &a, int b);
    virtual ~Rva00409FFA();
};
Rva00409FFA::Rva00409FFA(const AsciiString &a, int b)
    : Snapshot(), word04(0), flag08(0), word0C((unsigned int)-1), str10(a), word94(0x20), word98((unsigned int)b)
{
    for (int i = 0; i < 32; ++i)
        arr14[i] = 0;
}
