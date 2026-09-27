// ?Rva004BA219Construct@@YAXPAVRva004BA1D0@@PBV1@@Z
// partial score=0.93 date=2026-09-27
// ?Rva004BA219Construct@@YAXPAVRva004BA1D0@@PBV1@@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
// ??Rva004BA219Construct@@YAXPAVRva004BA1D0@@PBV1@@Z, retail 0x004BA219 45B: null-guarded placement copy via rowed 0x004BA1D0.
// Evidence: calls rowed copy ctor 0x004BA1D0 plus rowed __EH_prolog; callers at 0x004BA254 0x004BA27F 0x004BA529 0x004BA7F2.
#include <new>

class Rva004BA1D0 {
public:
	Rva004BA1D0(const Rva004BA1D0 &other);
};

void Rva004BA219Construct(Rva004BA1D0 *dest, const Rva004BA1D0 *src)
{
	if (dest)
		::new(dest) Rva004BA1D0(*src);
}
