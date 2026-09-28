// cl: /O1 /MD
// stlport
// ??$_Destroy@PAURva00395D77@@@_STL@@YAXPAURva00395D77@@0@Z @0x00399336 25B
// Range destroy over 12-byte elements via rowed dtor at 0x00395D77.
// Stride 0xC matches BfmeStringRecord00395E75 layout (two AsciiStrings plus word via copy at 0x395E75).
// Rowed Rva00395D77 dtor destroys the leading string pair; tail word is trivial.
// Callers are owning ranges at 0x39977A 0x3997CD 0x399800.
// Same 25B loop shape as rowed _Destroy at 0x331FF1 and 0x40DCF1.
#include <vector>

struct Rva00395D77
{
	~Rva00395D77();
	unsigned char m_data[12];
};

template void _STL::_Destroy<Rva00395D77 *>(Rva00395D77 *, Rva00395D77 *);
