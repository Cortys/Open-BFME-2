// ??0Rva0035E00F@@QAE@XZ
// partial score=0.9 date=2026-09-30
// ??0Rva0035E00F@@QAE@XZ
// partial score=0.90 date=2026-09-30
// cl: /O1 /MD
// ??0Rva0035E00F@@QAE@XZ @ 0x0035E206 86B: derived ctor calling base ??0Rva001DBAA4
// at 0x001DBAA4. Layout from FamilyTailDtors1DBAC3.cpp (Rva0035E00F: base
// members +4/+8/+9/+0xA/+0xC, derived +0x10/+0x14/+0x28/+0x4C window) plus the
// zeroed ranges the body touches. Caller at 0x0035E29A proves ctor shape;
// vtable 0x00816594 same as dtor 0x0035E25C slot family.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class Rva001DBAA4
{
public:
	virtual ~Rva001DBAA4();
	Rva001DBAA4();
	int m_4;
	bool m_8;
	bool m_9;
	bool m_A;
	int m_C;
};
class Rva0035E00F : public Rva001DBAA4
{
public:
	virtual ~Rva0035E00F();
	Rva0035E00F();
	int m_10;
	int m_14;
	int m_18;
	int m_1C;
	int m_20;
	int m_24;
	int m_28;
	int m_2C;
	int m_30;
	int m_34;
	int m_38;
	int m_3C;
	int m_40;
	int m_44;
	int m_48;
	int m_4C;
};
// ??0Rva0035E00F@@QAE@XZ present-unmatched
Rva0035E00F::Rva0035E00F() : m_10(0), m_14(5)
{
	_ReadWriteBarrier();
	m_18 = 0;
	m_1C = 0;
	m_20 = 0;
	m_24 = 0;
	m_28 = -1;
	m_2C = 0;
	m_30 = 0;
	m_34 = 0;
	m_38 = 0;
	m_3C = 0;
	m_40 = 0;
	m_44 = 0;
	m_48 = 0;
	m_4C = 0;
	m_C = 0;
	m_4 = m_14;
	m_9 = true;
}
