// ?m@T_007ea5e0@@QAEXXZ
// partial score=0.96 date=2026-09-29
// ?m@T_007ea5e0@@QAEXXZ
// partial score=0.96 date=2026-09-29
// cl: /O2
// 0x007EA550 / 0x007EA590: FESL servicehub.cpp eight-slot owner table.
// The pinger at 0x00803260 already names these members.

struct Rva007EB810Diag
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void fail(const char *expr, const char *file, int line);
};

extern Rva007EB810Diag *Rva007EB810Get();

class Rva00803080;

class Rva007EAServiceList
{
public:
	void add(Rva00803080 *owner);
	void remove(Rva00803080 *owner);

private:
	char m_pad[0x10];
	Rva00803080 *m_slots[8];
};

void Rva007EAServiceList::add(Rva00803080 *owner)
{
	for (int i = 0; i < 8; ++i)
	{
		if (m_slots[i] == 0)
		{
			m_slots[i] = owner;
			return;
		}
	}
	Rva007EB810Get()->fail(
		"false",
		"\\views\\feslbuild_main\\jabba\\fesl\\source\\servicehub.cpp",
		679);
}

void Rva007EAServiceList::remove(Rva00803080 *owner)
{
	for (int i = 0; i < 8; ++i)
	{
		if (m_slots[i] == owner)
		{
			m_slots[i] = 0;
			return;
		}
	}
	Rva007EB810Get()->fail(
		"false",
		"\\views\\feslbuild_main\\jabba\\fesl\\source\\servicehub.cpp",
		694);
}

int __cdecl Rva00656B60Get();
void __cdecl Rva007F8C90();

struct GetObj
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	virtual void v3();
	virtual void v4();
};

struct SlotObj
{
	virtual void f(int v);
};

class T_007ea5e0
{
public:
	void m();

private:
	char m_pad[8];
	unsigned char m_08;
	char m_pad09[7];
	void *m_slots[8];
};

// ?m@T_007ea5e0@@QAEXXZ @0x00657590 (87B): service list notify that gets three
// singletons via 0x00656B60 calling virtuals +0xC +0x8 +0x10 then notifies
// eight +0x10 slots via slot 0 with middle result then tails to 0x00665310
// when +0x8 bit 2 is clear. Evidence: caller 0x006669F3 plus LINK BONUS name;
// +0x10 slots match Rva007EAServiceList; /O2 matches siblings.
void T_007ea5e0::m()
{
	T_007ea5e0 *self = this;
	((GetObj *)Rva00656B60Get())->v3();
	int v = ((GetObj *)Rva00656B60Get())->v2();
	for (int i = 0; i < 8; ++i) {
		void *slot = self->m_slots[i];
		if (slot != 0)
			((SlotObj *)slot)->f(v);
	}
	((GetObj *)Rva00656B60Get())->v4();
	if ((self->m_08 & 2) != 0)
		return;
	Rva007F8C90();
}
