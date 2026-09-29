// cl: /O1 /DNDEBUG /MD

// ??0Rva002111C8@@QAE@ABV0@@Z, RVA 0x002111C8, 27B. Unlock lane: copy ctor
// copy-constructing the 12B RvaSmartPtr12 member at +0 through rowed
// ??0RvaSmartPtr12@@QAE@ABV0@@Z at 0x0004CC19 then copying the dword at
// +0x0C; returns this, ret 4, no vtable. Caller at 0x00211E07 in 0x00211DFB.
// Owner unknown so honest address-derived name; member size 12B puts m_0c at
// +0x0C per the retail offsets.
class RvaSmartPtr12
{
public:
	RvaSmartPtr12(const RvaSmartPtr12 &o);
private:
	char m_data[12];
};

class Rva002111C8
{
public:
	Rva002111C8(const Rva002111C8 &o);
private:
	RvaSmartPtr12 m_00;
	int m_0c;
};

Rva002111C8::Rva002111C8(const Rva002111C8 &o)
	: m_00(o.m_00), m_0c(o.m_0c)
{
}
