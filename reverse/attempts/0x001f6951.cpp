// ?Rva001F6951Pad@@YAAAV?$basic_ostream@DV?$char_traits@D@_STL@@@_STL@@AAV12@I@Z
// partial score=0.9 date=2026-09-27
// ?Rva001F6951Pad@@YAAAV?$basic_ostream@DV?$char_traits@D@_STL@@@_STL@@AAV12@I@Z
// partial score=0.9 date=2026-09-27
// cl: /O1 /G7 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
// stlport
// ?Rva001F6951Pad@@YAAAV?$basic_ostream@DV?$char_traits@D@_STL@@@_STL@@AAV12@I@Z @0x001F6951 (29B):
// Free __cdecl ostream pad: writes N spaces via rowed basic_ostream::put
// @0x001F6537, returns the stream. Retail test/jbe guard for N==0 (unsigned
// <=0 gives 0x76), dec/jne loop, hidden from writeINI callers (0x0055B6A6 etc
// pad the key field before " = "). Unblocks 21 functions. Honest-address name.

#include <ostream>

// ?Rva001F6951Pad@@YAAAV?$basic_ostream@DV?$char_traits@D@_STL@@@_STL@@AAV12@I@Z present-unmatched
_STL::basic_ostream<char, _STL::char_traits<char> > &__cdecl Rva001F6951Pad(
	_STL::basic_ostream<char, _STL::char_traits<char> > &os, unsigned int n)
{
	if (n <= 0)
		return os;
	do {
		os.put(' ');
	} while (--n);
	return os;
}
