// ?Rva0021642FCall@@YAHPAX0PBDPBM@Z
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /DNDEBUG /MD /EHsc
// stlport
// ?Rva0021642FCall@@YAHPAX0PBDPBM@Z @0x0021642F 103B float-keyed Apt invoke with AsciiString temp.
// Evidence: float deref at +0x14 via rowed Rva002228E8Get 0x002228E8 to AsciiString at ebp-0x10; str chars or g_Rva0107301CEmptyString; rowed invoke 0x00222A8B with this at +8 level at +0xC func at +0x10 argc 1; rowed releaseBuffer 0x00036410; caller 0x0021716D.
#include "ascii_string.h"

AsciiString Rva002228E8Get(float val);

class Rva00222A8BTarget
{
public:
	int invoke(void *level, const char *function, int argc, const char *a0,
		void *a1, void *a2, void *a3, void *a4);
};

extern const char g_Rva0107301CEmptyString[];

// ?Rva0021642FCall@@YAHPAX0PBDPBM@Z present-unmatched
int __cdecl Rva0021642FCall(void *target, void *level, const char *func, const float *val)
{
	AsciiString s = Rva002228E8Get(*val);
	const char *p = s.str();
	return ((Rva00222A8BTarget *)target)->invoke(level, func, 1, p, 0, 0, 0, 0);
}
