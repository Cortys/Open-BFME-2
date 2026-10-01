// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
// Target GUI-string global: startup 0x007B52E6 uses "UpgradeUnitButton",
// constructs the address-named object at VA0x00E06900 through rowed5E16DA,
// and registers the cleanup at0x007B9A05. Its application class name is unknown.
// Constructor and destructor ABI reuse the existing recovered Rva005E16DA
// bodies; their four post-vptr words cover the observed 20-byte object.
// The constructor's existing int declaration is a one-word ABI view. Retail
// passes the ADDRESS of an AsciiString temporary, not an integer identifier.

#include "ascii_string.h"
extern "C" int __cdecl atexit(void (__cdecl *callback)());

class Rva005E16DA {
public:
    Rva005E16DA(int argumentWord);
    virtual ~Rva005E16DA();
private:
    unsigned int opaqueWords[4];
};

extern Rva005E16DA g_rva00E06900;

void rva007B9A05()
{
    g_rva00E06900.~Rva005E16DA();
}

void rva007B52E6()
{
    {
        AsciiString label("UpgradeUnitButton");
        // MSVC's explicit constructor invocation also backs the shared
        // AsciiString adapter. This is static storage, with no allocation.
        g_rva00E06900.Rva005E16DA::Rva005E16DA(reinterpret_cast<int>(&label));
    }
    atexit(rva007B9A05);
}

extern Rva005E16DA g_rva00E068EC;
// Exact callback address registered by startup7B5299; mov-this/tail-jump
// spans7B99FB..7B9A04 and reaches the same rowed destructor5E16FD.
void rva007B99FB()
{
    g_rva00E068EC.~Rva005E16DA();
}
