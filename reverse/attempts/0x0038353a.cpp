// ?Rva0038353AConstruct@@YAXPAURva00382BF0@@ABU1@@Z
// partial score=0.93 date=2026-09-30
// ?Rva0038353AConstruct@@YAXPAURva00382BF0@@ABU1@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?Rva0038353AConstruct@@YAXPAURva00382BF0@@ABU1@@Z, retail 0x0038353A, 45 bytes.
// _Construct-style placement copy over Rva00382BF0 via its rowed copy ctor
// with null guard. Identity from chain (calls 0x00382BF0 just landed) and
// caller 0x00383D63.
#include <new>

struct Rva00382BF0
{
	Rva00382BF0(const Rva00382BF0 &other);
};

// ?Rva0038353AConstruct@@YAXPAURva00382BF0@@ABU1@@Z present-unmatched
void __cdecl Rva0038353AConstruct(Rva00382BF0 *place, const Rva00382BF0 &value)
{
	if (place)
		new (place) Rva00382BF0(value);
}
