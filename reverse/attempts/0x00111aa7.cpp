// ??0Rva00111AA7@@QAE@PBDH@Z
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /Os /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS
//
// ??0Rva00111AA7@@QAE@PBDH@Z, retail 0x00111AA7, 40 bytes. Ctor with StringBase
// at +0 from const char*, int at +4, 16B zero at +8, int zero at +0x18.
// Evidence: calls StringBase PBD row 0x37BA0, sets +4 from arg2, and [0x18],0
// plus stosd x4 for +8, returns this with ret 8; callers at 0xB07A8/0xB07DD/
// 0x10237A/0x1023A6 (all UNCLAIMED), prev TileData ctor /O1, next StringRecord
// copy /O1; __thiscall ctor (reads ecx, ret 8) so honest Rva ctor name.
#include "ascii_string.h"
#include <string.h>
#pragma intrinsic(memset)

class Rva00111AA7
{
public:
	Rva00111AA7(const char *s, int x);
private:
	AsciiString m_str; // +0
	int m_04; // +4
	unsigned char m_08[16]; // +8..+0x18
	int m_18; // +0x18
};

// ??0Rva00111AA7@@QAE@PBDH@Z @0x00111AA7
Rva00111AA7::Rva00111AA7(const char *s, int x)
	: m_str(s), m_04(x)
{
	m_18 = 0;
	memset(m_08, 0, sizeof(m_08));
}
