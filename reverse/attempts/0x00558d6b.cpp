// ?rva00558D6B@Rva00558D6B@@QAEPAXXZ
// partial score=0.96 date=2026-10-01
// cl: /G7 /O1 /GX- /MD
// ?rva00558D6B@Rva00558D6B@@QAEPAXXZ @0x00558D6B 25B: Placement init calls Rva00553890 0x00553890 ctor with same local address twice then returns this. Evidence: chain lane calls just-landed 0x00553890 plus caller 0x00558F3D plus same-address double lea shape.
#include <new>
class Rva00553890
{
public:
	Rva00553890(unsigned a, unsigned b);
};
class Rva00558D6B
{
	Rva00553890 m_00;
public:
	void *rva00558D6B();
};
// ?rva00558D6B@Rva00558D6B@@QAEPAXXZ present-unmatched
void *Rva00558D6B::rva00558D6B()
{
	__assume(this != 0);
	unsigned char tmp;
	unsigned char tmp2;
	new (this) Rva00553890((unsigned)&tmp, (unsigned)&tmp2);
	return this;
}
