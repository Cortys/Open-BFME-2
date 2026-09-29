// ?rva004530ED@Rva004530ED@@QAEXPBV1@@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /MD
// ?rva004530ED@Rva004530ED@@QAEXPBV1@@Z at 0x004530ED (32B).
// Struct copy: +0 via edx, +4..+0xF via inlined memcpy 12, +0x10 via ecx.
// Evidence: movsd x3 shape, 5 callers, unblocks 2.

#include <string.h>
#pragma intrinsic(memcpy)

class Rva004530ED
{
public:
	void rva004530ED(const Rva004530ED *rhs);
private:
	int m_00;
	int m_04[3];
	int m_10;
};

// ?rva004530ED@Rva004530ED@@QAEXPBV1@@Z present-unmatched
void Rva004530ED::rva004530ED(const Rva004530ED *rhs)
{
	Rva004530ED *dst = this;
	dst->m_00 = rhs->m_00;
	memcpy(dst->m_04, rhs->m_04, 12);
	dst->m_10 = rhs->m_10;
}
