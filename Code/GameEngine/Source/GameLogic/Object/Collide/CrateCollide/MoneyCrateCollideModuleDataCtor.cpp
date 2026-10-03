// cl: /O1 /MD /GX /DNDEBUG
//
// ??0MoneyCrateCollideModuleData@@QAE@XZ, retail 0x002562FA (22 bytes).
// Frameless ctor over the rowed CrateCollide base (0x4BC657): clears
// m_moneyProvided at +0x5C through an AND-zero then installs the folded
// vtable 0x00BF3AC0 via g_00BF3AC0 (SalvageCrate precedent: novtable plus
// explicit store emits no vtable COMDAT, fixing LINK-COMDAT vs
// ModuleFactory's ZH copy). Field identity is the chained buildFieldParse
// table 0x00BEFABC (MoneyProvided only) joined to the ZH
// MoneyCrateCollide.h donor (BFME2 drops the ZH upgrade-boost list). Sole
// raw caller is the ModuleData factory 0x256310 which news 0x60.

class __declspec(novtable) CrateCollideModuleData
{
public:
	CrateCollideModuleData();
	virtual ~CrateCollideModuleData();

private:
	unsigned char m_pad[0x5C - 4];
};

class __declspec(novtable) MoneyCrateCollideModuleData : public CrateCollideModuleData
{
public:
	MoneyCrateCollideModuleData();

private:
	unsigned int m_moneyProvided;	// +0x5C
};

extern const void *const g_00BF3AC0[];

inline MoneyCrateCollideModuleData::MoneyCrateCollideModuleData()
{
	m_moneyProvided = 0;
	*(const void **)this = g_00BF3AC0;
}

// Header inlines that the units including the header emit as select-any
// copies, which plain definitions here collided with. The anchor keeps this
// unit's copies for the rows; it is not retail code.
#pragma inline_depth(0)
// ?_bfmeMoneyCrateCollideModuleDataInlineAnchor@@YAXPAVMoneyCrateCollideModuleData@@@Z absent-from-retail
void _bfmeMoneyCrateCollideModuleDataInlineAnchor(MoneyCrateCollideModuleData *p)
{
    p->MoneyCrateCollideModuleData::MoneyCrateCollideModuleData();
}
#pragma inline_depth()
