// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
// ?Rva0002C63CAsciiNocaseLess@@YG_NABVAsciiString@@0@Z @0x0002C63C 25B
// Case-insensitive AsciiString tree ordering for the INI macro map family.
// Callees rowed: ?compareNoCase@?$StringBase@D@@QBEHABV1@@Z at 0x00006A00.
// Callers: _M_insert/find paths at 0x0002C686 0x0002C71B 0x0002C908 0x003ED732.
// Precedent: ?Rva0006038D4CStrLess@@YG_NPBD0@Z at 0x006038D4 (strcmp stdcall less).

#include "ascii_string.h"


bool __stdcall Rva0002C63CAsciiNocaseLess(const AsciiString &left, const AsciiString &right)
{
    return (left.compareNoCase(right) < 0) || false;
}
