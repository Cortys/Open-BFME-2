// ??4Rva001F9C73@@QAEAAV0@ABURva001F9C73Src@@@Z
// partial score=0.9 date=2026-09-30
// ??4Rva001F9C73@@QAEAAV0@ABURva001F9C73Src@@@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??4Rva001F9C73@@QAEAAV0@ABURva001F9C73Src@@@Z @0x001F9C73 69B (ours 68B).
// Operator= assigning base Rva001F41AF at +0 then reconstructing const
// Rva001F8C5B member at +4 from vector at arg+4. Caller 0x001FA65F.
// 0 reg/mem diffs; left: retail branchless src guard (mov eax edi / add edi 4
// / neg / sbb / and / push) vs ours placement-new branch (mov [ebp+8] ecx /
// test ecx / je / add edi 4 / push edi). Honest address name.
#include <vector>

struct Rva001F41AFHelper {
	virtual void f0();
	virtual void *clone();
};

class Rva001F41AF
{
public:
	Rva001F41AFHelper *m_ptr;
	Rva001F41AF &operator=(const Rva001F41AF &other);
};

class Rva001F8C5B
{
public:
	Rva001F8C5B(const _STL::vector<void *> &src);
};

struct Rva001F9C73Src {
	Rva001F41AF base;
	_STL::vector<void *> vec;
};

class Rva001F9C73 : public Rva001F41AF
{
public:
	Rva001F9C73 &operator=(const Rva001F9C73Src &src);
private:
	const Rva001F8C5B m_v;
};

// ??4Rva001F9C73@@QAEAAV0@ABURva001F9C73Src@@@Z present-unmatched
Rva001F9C73 &Rva001F9C73::operator=(const Rva001F9C73Src &src)
{
	Rva001F41AF::operator=(src.base);
	new (const_cast<Rva001F8C5B *>(&m_v)) Rva001F8C5B(src.vec);
	return *this;
}
