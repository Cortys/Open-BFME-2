// ?Rva0038350DCopy@@YAXPAXABVRva003829E5@@@Z
// partial score=0.93 date=2026-09-29
// ?Rva0038350DCopy@@YAXPAXABVRva003829E5@@@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /G7 /EHs /MD
// ?Rva0038350DCopy@@YAXPAXABVRva003829E5@@@Z 0x0038350D 45B
// Null-guarded placement copy of Rva003829E5.
// Evidence: calls 0x00382C2D copy ctor; caller 0x00383D41.
#include <new>

struct AsciiUnicodePair
{
	AsciiUnicodePair(const AsciiUnicodePair& other);
};

class Rva003829E5
{
	int m0;
	AsciiUnicodePair m4;
public:
	Rva003829E5(void* a, const AsciiUnicodePair& b);
	Rva003829E5(const Rva003829E5& other);
};

void __cdecl Rva0038350DCopy(void* dst, const Rva003829E5& src)
{
	if (!dst)
		return;
	::new (dst) Rva003829E5(src);
}
