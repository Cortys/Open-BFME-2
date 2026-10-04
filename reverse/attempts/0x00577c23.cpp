// ?Rva00577C23AptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAHPA_N@Z
// partial score=0.97 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /MD /EHsc
// ?Rva00577C23AptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAHPA_N@Z, retail 0x00577C23, 125 bytes.
// Apt forward with 1 int plus 1 bool. Builds int AsciiString via rowed
// 0x00222834 and bool text via rowed 0x004E678B, passes their text or empty
// plus zeros as 2 args to thiscall twin rva00222B19 0x00222B19 with argc 2.
// Evidence: chain packet calls just-landed 0x00222B19 plus rowed gets plus
// releaseBuffer 0x00036410 plus empty 0x007BAC1C.
#include "ascii_string.h"

class Rva00222A8BTarget
{
public:
	int rva00222B19(void *level, const char *prefix, const char *function, int argc, const char *a0, void *a1, void *a2, void *a3, void *a4);
};

void __cdecl Rva00222834Get(AsciiString *ret, int val);
char ** __cdecl Rva004E678BGet(char **out, bool flag);

extern const char g_Rva0107301CEmptyString[];

__forceinline const char *GetStr(const AsciiString &s)
{
	char *t = *(char **)(void *)&s;
	return t ? t + 8 : g_Rva0107301CEmptyString;
}

// ?Rva00577C23AptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2PAHPA_N@Z present-unmatched
int __cdecl Rva00577C23AptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, int *pInt, bool *pFlag)
{
	AsciiString intStr;
	Rva00222834Get(&intStr, *pInt);
	char *boolSlot;
	char *boolStr = *Rva004E678BGet(&boolSlot, *pFlag);
	return target->rva00222B19(level, prefix, function, 2, GetStr(intStr), boolStr, 0, 0, 0);
}
