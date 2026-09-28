// cl: /O1 /DNDEBUG /MD
//
// ?rva002C7492@Rva002C7492@@QAEXPBV1@@Z @0x002C7492, 25B.
// 19-dword OR-merge: this[i] |= other[i]. Retail computes other-this once
// then loops with mov esi [eax+ecx] / or [ecx] esi over 0x13 dwords.
// Evidence: this is the 76-byte (0x4C) temp at [ebp-0x4C] in 0x002C777E and
// 0x0034707A copied via WeaponTemplateSetHead copy ctor at 0x00045455;
// arg is the 19-dword mask built by 0x002C760B. Same family as
// Rva00263546Overlap.cpp (19-dword overlap with sub eax ecx shape) and
// Rva00271C8ALoop.cpp (19-dword merge with push 0x13 pop dec-jne).

class Rva002C7492
{
public:
	void rva002C7492(const Rva002C7492 *other);

private:
	int m_mask[19];
};

void Rva002C7492::rva002C7492(const Rva002C7492 *other)
{
	for (unsigned i = 0; i < 19; ++i) {
		m_mask[i] |= other->m_mask[i];
	}
}
