// ?Rva00584F6B@Rva00586D8E@@UAE_NH@Z
// partial score=0.93 date=2026-09-27
// ?Rva00584F6B@Rva00586D8E@@UAE_NH@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?Rva00584F6B@Rva00586D8E@@UAE_NH@Z retail 0x00584F6B 84B.
// VSlot 9 (offset 0x24) of vtable 0x0086FD90 (class of ??0Rva00586D8E@@QAE@PAX0@Z).
// Gap between ?Rva00584F37 (slot8) and ?Rva00584FBF (slot10) in Rva00586D8EVSlots.cpp.
// Bounds-checked vec84 (stride 0x54) with field +0x20 vs TheGameLogic frame at 0x00DFE78C+0x40
// OR held array at [ecx+4]+0x188 stride 0x1C field +0x18 >=0. OR-shared-true xor-inc achieved
// via return A||B (84B exact size 34 insns). Remains edi-vs-edx for TheGameLogic plus early
// push-edi and imul placement vs late edx reuse. No callers. Flags match neighbour TU.
#include <vector>

struct BfmeV84 { int m_00; char m_pad04[0x20 - 4]; unsigned int m_20; char m_pad24[84 - 0x20 - 4]; };
struct HeldEntry { char m_pad00[0x18]; int m_18; };
struct HeldBlock { char m_pad00[0x188]; HeldEntry* m_entries; };

struct GameLogicFrame { char m_pad00[0x40]; unsigned int m_frame; unsigned int getFrame() const { return m_frame; } };
#define TheGameLogic (*(GameLogicFrame**)0x00DFE78C)

class Rva005D6FCC
{
public:
	Rva005D6FCC(void* held);
	virtual ~Rva005D6FCC();
	void* m_held;
};

class Rva00586D8E : public Rva005D6FCC
{
public:
	virtual ~Rva00586D8E();
	virtual bool Rva00584F03(int idx);
	virtual bool Rva00584F37(int idx);
	virtual bool Rva00584F6B(int idx);
	virtual void Rva00584FBF(int idx);
	virtual void Rva00584FEB(int idx);
private:
	_STL::vector<BfmeV84> m_vec;
	bool m_flag;
	void* m_other;
};

bool Rva00586D8E::Rva00584F03(int idx)
{
	if (idx < 0 || (unsigned)idx >= m_vec.size())
		return false;
	return m_vec[idx].m_00 == 1;
}

bool Rva00586D8E::Rva00584F37(int idx)
{
	if (idx < 0 || (unsigned)idx >= m_vec.size())
		return false;
	return m_vec[idx].m_00 == 2;
}

// ?Rva00584F6B@Rva00586D8E@@UAE_NH@Z present-unmatched
bool Rva00586D8E::Rva00584F6B(int idx)
{
	if (idx < 0 || (unsigned)idx >= m_vec.size())
		return false;
	HeldBlock* h = (HeldBlock*)m_held;
	return m_vec[idx].m_20 > TheGameLogic->getFrame() || h->m_entries[idx].m_18 >= 0;
}

void Rva00586D8E::Rva00584FBF(int idx)
{
	if (idx < 0)
		return;
	if ((unsigned)idx >= m_vec.size())
		return;
	m_vec[idx].m_00 = 2;
}

void Rva00586D8E::Rva00584FEB(int idx)
{
	if (idx < 0)
		return;
	if ((unsigned)idx >= m_vec.size())
		return;
	m_vec[idx].m_00 = 3;
}
