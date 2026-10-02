// ?Rva007410ECInvoke@@YAHPAVRva00222A8BTarget@@PAXPBD2PAI@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ?Rva007410ECInvoke@@YAHPAVRva00222A8BTarget@@PAXPBD2PAI@Z @0x007410EC 102B
// Forwards level/prefix/function plus stringified *valPtr as a0 to rowed AptCall.
// Evidence: chain via rowed 0x0022288E Get and 0x00222B19 AptCall plus releaseBuffer
// 0x00036410; caller 0x007412EB; prev 0x00740EA1.
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};
#include "ascii_string.h"

extern const char g_Rva0107301CEmptyString[];
AsciiString Rva0022288EGet(unsigned int val);

class Rva00222A8BTarget
{
public:
	int rva00222B19(void *level, const char *prefix, const char *function, int argc, const char *a0, void *a1, void *a2, void *a3, void *a4);
};

// ?Rva007410ECInvoke@@YAHPAVRva00222A8BTarget@@PAXPBD2PAI@Z present-unmatched
int __cdecl Rva007410ECInvoke(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, unsigned int *valPtr)
{
	const AsciiString tmp = Rva0022288EGet(*valPtr);
	const BfmeStringData<char> *h = *(const BfmeStringData<char> *const *)&tmp;
	const char *a0 = h ? (const char *)&h->text[0] : g_Rva0107301CEmptyString;
	return target->rva00222B19(level, prefix, function, 1, a0, 0, 0, 0, 0);
}
