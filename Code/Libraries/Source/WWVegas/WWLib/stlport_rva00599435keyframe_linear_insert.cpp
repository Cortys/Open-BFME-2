// cl: /O1 /GX- /arch:SSE2
// stlport
// STLport __unguarded_linear_insert over 8-byte {float, unsigned} keyframes,
// @0x00599435 49B: the banked attempt wrote it as a free function with a local
// copy of the value and could not explain why retail reloads the value from
// [esp+8] on every iteration and keeps the loop test at the top. Both follow
// from the template: comp(val, *next) takes val by reference, so its address
// escapes into the (inlined) comparator and the stores through last may alias
// it. The four caller dwords are last, the value (two dwords) and the empty
// comparator; eax holds last at ret. Callers 0x5994BC and 0x599A16 (not yet
// rowed) are the insertion-sort siblings of this instantiation. Element and
// comparator names are address-derived; the comparator orders descending by
// the float field.
#include <algorithm>

struct Rva00599435Keyframe
{
	float m_value;
	unsigned int m_frame;
};

struct Rva00599435Compare
{
	bool operator()(const Rva00599435Keyframe &a, const Rva00599435Keyframe &b) const { return a.m_value > b.m_value; }
};

// ??$__unguarded_linear_insert@PAURva00599435Keyframe@@U1@URva00599435Compare@@@_STL@@YAXPAURva00599435Keyframe@@U1@URva00599435Compare@@@Z @0x00599435
template void _STL::__unguarded_linear_insert<Rva00599435Keyframe *, Rva00599435Keyframe, Rva00599435Compare>(Rva00599435Keyframe *, Rva00599435Keyframe, Rva00599435Compare);
