// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?Rva00411112Get@@YAPAXPBVAsciiString@@@Z, retail 0x00411112 (25B).
// Chain over rowed ?rva00056F61@Rva00056F61@@QAEPAXPBVAsciiString@@@Z: lookup
// AsciiString key in the global bucket table at 0x00E0300C, returning the
// dword at node+8 or null. Caller at 0x00412140 tests for null.

#include "ascii_string.h"

class Rva00056F61
{
public:
	void *rva00056F61(const AsciiString *key);
};

void * __cdecl Rva00411112Get(const AsciiString *key)
{
	void *node = ((Rva00056F61 *)0x00E0300C)->rva00056F61(key);
	if (node != 0)
		return *(void **)((char *)node + 8);
	return 0;
}
