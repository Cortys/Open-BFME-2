// ?rva004CFB8B@Rva004CFB8B@@QAEXVAsciiString@@@Z
// partial score=0.97 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /Oy- /DNDEBUG /MD /GX
// ?rva004CFB8B@Rva004CFB8B@@QAEXVAsciiString@@@Z @ 0x004CFB8B 55B
// Thiscall AsciiString by-value setter at +0x1D8 via rowed set 0x000366F0
// plus releaseBuffer 0x00036410 with EH prolog. Reads ecx first (thiscall).
// Evidence: callers 0x004CFE98 0x004D3644 0x004FF157, callees rowed,
// neighbours AsciiStringRvoGetters and ConnectionManagerPlayerPredicates.
#include "ascii_string.h"

class Rva004CFB8B
{
public:
	void rva004CFB8B(AsciiString arg);

private:
	char m_pad00[0x1D8];
	AsciiString m_1D8;
};

// ?rva004CFB8B@Rva004CFB8B@@QAEXVAsciiString@@@Z present-unmatched
void Rva004CFB8B::rva004CFB8B(AsciiString arg)
{
	((StringBase<char> &)m_1D8).set((const StringBase<char> &)arg);
}
