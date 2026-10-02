// ?Rva005252CDAptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAHPAPAX@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
//
// ?Rva005252CDAptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAHPAPAX@Z retail 0x005252CD 107 bytes.
// Free __cdecl Apt forwarder via rowed Rva00222834Get plus thiscall twin
// rva00222B19 plus str() empty fallback. Evidence: rowed 0x00222834 plus rowed
// 0x00222B19; callers 0x0052A804 0x005FFF62 with TheRva00222A8BTarget plus
// level at +4 plus prefix at +8; prev RvaSmallVtableCtors next stlport_list_create_nodes same dir.
#include "ascii_string.h"

class Rva00222A8BTarget
{
public:
	int rva00222B19(void *level, const char *prefix, const char *function, int argc, const char *a0, void *a1, void *a2, void *a3, void *a4);
};

AsciiString Rva00222834Get(int val);

// ?Rva005252CDAptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAHPAPAX@Z present-unmatched
int __cdecl Rva005252CDAptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, int *pInt, void **ppA1)
{
	AsciiString tmp = Rva00222834Get(*pInt);
	const char *s = tmp.str();
	void *a1 = *ppA1;
	return target->rva00222B19(level, prefix, function, 2, s, a1, 0, 0, 0);
}
