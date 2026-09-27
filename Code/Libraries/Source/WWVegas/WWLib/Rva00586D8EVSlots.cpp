// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// VSlots 7/8/10/11 of vtable 0x0086FD90 (class of ??0Rva00586D8E@@QAE@PAX0@Z).
// Retail 0x00584F03 52B slot7 returns (vec[idx].m_00 == 1).
// Retail 0x00584F37 52B slot8 returns (vec[idx].m_00 == 2).
// Retail 0x00584FBF 44B slot10 sets vec[idx].m_00 = 2.
// Retail 0x00584FEB 44B slot11 sets vec[idx].m_00 = 3.
// All bounds-checked (idx<0 or idx>=size returns). Stride 0x54 proves
// 84-byte elements; BfmeV84 is the size-only stand-in (int at +0).
// Callers: none. Vtable slot0 deleting dtor 0x00586E35.
#include <vector>

struct BfmeV84 { int m_00; char m_pad[80]; };

class Rva005D6FCC
{
public:
	Rva005D6FCC(void *held);
	virtual ~Rva005D6FCC();
	void *m_held;
};

class Rva00586D8E : public Rva005D6FCC
{
public:
	virtual ~Rva00586D8E();
	virtual bool Rva00584F03(int idx);
	virtual bool Rva00584F37(int idx);
	virtual void Rva00584FBF(int idx);
	virtual void Rva00584FEB(int idx);
private:
	_STL::vector<BfmeV84> m_vec; // +8
	bool m_flag; // +0x14
	void *m_other; // +0x18
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
