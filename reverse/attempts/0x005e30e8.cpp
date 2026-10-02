// ?Rva005E30E8AptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAVRva005E2D74@@@Z
// partial score=0.97 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
//
// ?Rva005E30E8AptCall@@YAHPAV1PAXPBD1PAVRva005E2D74@@@Z, retail 0x005E30E8 99B free cdecl.
// Level-gated AptCall via Rva005E2D74::rva005E306D string plus rowed 0x00222B19.
// Evidence: rowed rva005E306D 0x005E306D plus rowed AptCall 0x00222B19 plus
// empty fallback g_Rva0107301CEmptyString plus caller 0x005E314B, neighbours
// Rva005E2D74.cpp and Rva005D2F96Build.cpp same page.
//
#include "ascii_string.h"

class Rva00222A8BTarget;
class Rva005E2D74
{
public:
	AsciiString rva005E306D();
};

int __stdcall Rva00222B19AptCall(void *level, const char *prefix, const char *function, int argc, const char *a0, void *a1, void *a2, void *a3, void *a4);

// ?Rva005E30E8AptCall present-unmatched
int __cdecl Rva005E30E8AptCall(Rva00222A8BTarget *target, void *level, const char *mid, const char *function, Rva005E2D74 *obj)
{
	AsciiString tmp = obj->rva005E306D();
	const char *s = tmp.str();
	return Rva00222B19AptCall(level, mid, function, 1, s, 0, 0, 0, 0);
}
