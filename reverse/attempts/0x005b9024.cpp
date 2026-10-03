// ?Rva005B9024Get@@YIHPBD@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /DNDEBUG /MD
// ?Rva005B9024Get@@YIHPBD@Z @ 0x005B9024 49B: hex-pair to int via 0x-prefixed strtol base 16.
// Evidence: callers 0x00382802 0x0038280B pass eax=esi/edi char pointers and use al sum; callers 0x005B9A17/30/49/61 pass eax pointers and use al bytes; data 0x008193BC "0xff" 5-byte copy via movsd+movsb; IAT strtol base 0x10; ZH GameInfoParseOptions tmp 0xfff strtol 16 donor shape.
#include <cstdlib>

extern "C" long __cdecl strtol(const char *str, char **end, int base);

// ?Rva005B9024Get@@YIHPBD@Z present-unmatched
int __fastcall Rva005B9024Get(const char *p)
{
	unsigned char c0 = p[0];
	char c1 = p[1];
	char buf[5] = "0xff";
	buf[2] = c0;
	buf[3] = c1;
	return strtol(buf, 0, 16);
}
