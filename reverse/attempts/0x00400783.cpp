// ?Rva00400783Get@@YA?AVAsciiString@@ABV1@_N@Z
// partial score=0.98 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?Rva00400783Get@@YA?AVAsciiString@@ABV1@_N@Z, retail 0x00400783, 277 bytes.
// Portable map-path builder: realMapPathToPortableMapPath from TheGameState
// then optional Rva002DCB9C remap of portable itself when flag byte set,
// then split by "/" via nextToken and rejoin with "\\" find check.
// Callers 0x00400B3E 0x00447CFE unclaimed. Neighbours share GameNetwork flags.
#include "ascii_string.h"

class GameState
{
public:
	AsciiString realMapPathToPortableMapPath(const AsciiString &in) const;
};

extern GameState *TheGameState;

AsciiString __stdcall Rva002DCB9C(const AsciiString &in);

// ?Rva00400783Get@@YA?AVAsciiString@@ABV1@_N@Z present-unmatched
AsciiString __cdecl Rva00400783Get(const AsciiString &mapPath, bool flag)
{
	AsciiString portable = TheGameState->realMapPathToPortableMapPath(mapPath);
	if (flag != false) {
		((StringBase<char> *)&portable)->set(*(const StringBase<char> *)&Rva002DCB9C(portable));
	}
	AsciiString accum;
	if (((const StringBase<char> *)&portable)->getLength() > 0) {
		const char *slash = "/";
		AsciiString token;
		while (true) {
			((StringBase<char> *)&portable)->nextToken((StringBase<char> *)&token, slash);
			if (((const StringBase<char> *)&portable)->find('\\') == NULL)
				break;
			if (((const StringBase<char> *)&accum)->getLength() > 0) {
				char sep = '/';
				((StringBase<char> *)&accum)->concat(&sep, 1);
			}
			((StringBase<char> *)&accum)->concat(*(const StringBase<char> *)&token);
		}
	}
	return accum;
}
