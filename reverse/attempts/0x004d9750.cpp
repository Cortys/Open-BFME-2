// ?rva004D9750@Rva004D9750@@QAEPAXPAXH@Z
// partial score=0.89 date=2026-10-04
// cl: /O1 /MD /Oy-
//
// ?rva004D9750@Rva004D9750@@QAEPAXPAXH@Z @0x004D9750 45B.
// Copy 8-byte element at this[index] into dst via rowed 0x002390CB copy,
// or default-construct rowed Upgrades at dst when index is -1.
// Evidence: callees rowed 0x004CEE6E Upgrades default and 0x002390CB copy;
// caller 0x004D97F8 passes ecx=[esi+0x18] with dst and index; prev/next /O1 /MD.
typedef unsigned int size_t;
inline void *operator new(size_t, void *place)
{
	return place;
}

class CashHackSpecialPowerModuleData
{
public:
	struct Upgrades
	{
		int m_science;
		int m_amount;
		Upgrades();
	};
};

struct Rva002390CB
{
	void *m_00;
	void *m_04;
	Rva002390CB(const Rva002390CB &other);
};

class Rva004D9750
{
public:
	void *rva004D9750(void *dst, int index);
private:
	Rva002390CB m_items[1];
};

// ?rva004D9750@Rva004D9750@@QAEPAXPAXH@Z present-unmatched
void *Rva004D9750::rva004D9750(void *dst, int index)
{
	__assume(dst != 0);
	if (index == -1)
		new (dst) CashHackSpecialPowerModuleData::Upgrades;
	else
		new (dst) Rva002390CB(m_items[index]);
	return dst;
}
