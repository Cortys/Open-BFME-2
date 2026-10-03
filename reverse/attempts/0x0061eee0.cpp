// ??0ShdDefFactoryClass@@QAE@XZ
// partial score=0.9 date=2026-10-03
// cl: /Ob0 /EHsc
//
// 0x0061EDA0 neighbourhood cluster.  The bodies carry BFME1 donor identities
// (reference/open-bfme-1/game/Libraries/Source/assetmanager/assetmanager_base.cpp
// for the flag-stage sequence), but the BFME2 tail diverges, so the row keeps an
// address-derived method name on the donor class.

class BfmeFlagStageSequence
{
public:
	virtual void bfmeSlot00();
	virtual void bfmeSlot04();
	virtual void bfmeSlot08();
	virtual void bfmeSlot0C();
	virtual void bfmeSlot10();
	virtual void bfmeStage4();
	virtual void bfmeStage5();
	virtual void bfmeStage6();
	virtual void bfmeSlot20();
	virtual void *bfmeStage7(unsigned int finalStage);
	virtual bool bfmeCanAdvanceStages();

	void rva0061EDA0();

private:
	volatile unsigned int m_flags;
};

// ?rva0061EDA0@BfmeFlagStageSequence@@QAEXXZ
void BfmeFlagStageSequence::rva0061EDA0()
{
	if (bfmeCanAdvanceStages()) {
		m_flags = (m_flags & 0xFF04FFFF) | 0x00040000;
		bfmeStage4();
		m_flags = (m_flags & 0xFF05FFFF) | 0x00050000;
		bfmeStage5();
		m_flags = (m_flags & 0xFF06FFFF) | 0x00060000;
		bfmeStage6();
		m_flags = (m_flags & 0xFF07FFFF) | 0x00070000;
	}
	operator delete(bfmeStage7(0));
}

// The BFME2 constructor sets the class vtable (DIR32, masked) after the
// SubsystemInterface base ctor and allocates a 0x200-byte object through the
// rowed operator new; the object constructor is the unknown callee 0x624DB0.

class SubsystemInterface
{
public:
	SubsystemInterface();
	virtual void baseSlot();
};

class Rva00624DB0
{
public:
	Rva00624DB0();

private:
	char m_pad[0x200];
};

class ShdDefFactoryClass : public SubsystemInterface
{
public:
	ShdDefFactoryClass();
	virtual void vtableSlot0();

private:
	char m_gap[8];
	Rva00624DB0 *m_field0c;
};

// ??0ShdDefFactoryClass@@QAE@XZ
ShdDefFactoryClass::ShdDefFactoryClass()
	: SubsystemInterface()
{
	Rva00624DB0 *object = new Rva00624DB0();
	m_field0c = object;
}
