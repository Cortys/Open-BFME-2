// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// stlport
// ?Rva0002C237Get@@YAXPBVINI@@@Z present-unmatched @0x0002C237 144B: GetCurrentDirectoryA + INI::rva0002BFE5 filename + rva0002BBDE line + AsciiString::format into local; callers unclaimed
#include "ascii_string.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentDirectoryA(unsigned long nBufferLength, char *lpBuffer);

extern const char g_00BBDC80[];

class INI
{
public:
	int rva0002BBDE(void) const;
	AsciiString rva0002BFE5(void) const;
};

void __cdecl Rva0002C237Get(INI *ini)
{
	char curdir[260];
	GetCurrentDirectoryA(260, curdir);
	AsciiString dest;
	dest.format(g_00BBDC80, curdir, ini->rva0002BFE5().str(), ini->rva0002BBDE());
}
