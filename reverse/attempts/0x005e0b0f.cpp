// ??1Rva005E0B0F@@UAE@XZ
// partial score=0.95 date=2026-10-03
// cl: /O1 /Ireference/shims/bfme2_ascii /MD /EHsc
//
// ??1Rva005E0B0F@@UAE@XZ @0x005E0B0F 128B
// Dtor with own vtable 0x00877960 and base 0x0086E330. Calls rowed forwarder
// 0x005CB260 on +8 then no-arg int getter pinned 0x005CB265 on +4 compared
// to +0x14 then forwarder on +4 then fastcall Release 0x0007DEEF on +0x14
// then two UnicodeStrings at +0xC +0x10 via 0x00036E70. Precedents
// Rva005E73B2Check and Rva005D3AF2Method for getter plus forwarder shape.
// Evidence: deleting dtors at 0x005CB301 0x005CB31D 0x005CB337 call it.
#include "unicode_string.h"

class Rva005CB260
{
public:
	void rva005CB260();
};

class Rva005CB265
{
public:
	virtual int rva005CB265();
};

struct TargetRef00217D4C
{
	virtual void *destroy(unsigned flags);
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);

class Rva0086E330Base
{
public:
	virtual ~Rva0086E330Base() {}
};

class Rva005E0B0F : public Rva0086E330Base
{
public:
	virtual ~Rva005E0B0F();
private:
	Rva005CB265 *m_04;
	Rva005CB260 *m_08;
	UnicodeString m_0C;
	UnicodeString m_10;
	TargetRef00217D4C *m_14;
};

// ??1Rva005E0B0F@@UAE@XZ present-unmatched
Rva005E0B0F::~Rva005E0B0F()
{
	m_08->rva005CB260();
	TargetRef00217D4C *p = m_14;
	if (p != 0)
	{
		if (m_04->Rva005CB265::rva005CB265() == (int)p)
			((Rva005CB260 *)m_04)->rva005CB260();
	}
	if (m_14 != 0)
		ReleaseTreeHintRef00217D4C(m_14);
}
