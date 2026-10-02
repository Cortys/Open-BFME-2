// cl: /O1 /MD /GX /DNDEBUG
//
// ??0MoneyCrateCollideModuleData@@QAE@XZ, retail 0x002562FA (22 bytes).
// Frameless ctor over the rowed CrateCollide base (0x4BC657): clears
// m_moneyProvided at +0x5C through an AND-zero (the natural /O1 emission for
// the single-store shape, probe-proven against init-list which is identical)
// then installs the folded vtable 0x00BF3AC0 through the ??_7 pin (Devastate
// precedent: virtual classes with declared-only virtual dtors and no source
// store). Field identity is the chained buildFieldParse table 0x00BEFABC
// (MoneyProvided only) joined to the ZH MoneyCrateCollide.h donor (BFME2
// drops the ZH upgrade-boost list). Sole raw caller is the ModuleData
// factory 0x256310 which news 0x60.

class Xfer;
class W3DModelDrawModuleData;
class W3DTreeDrawModuleData;
enum StaticGameLODLevel { STATIC_GAME_LOD_LOW = 0 };
typedef bool Bool;

class Snapshot
{
protected:
	virtual void crc(Xfer *xfer) = 0;
	virtual void xfer(Xfer *xfer) = 0;
	virtual void loadPostProcess(void) = 0;
};

class ModuleData : public Snapshot
{
public:
	virtual ~ModuleData() {}
	virtual Bool isAiModuleData(void) const { return false; }
	virtual const W3DModelDrawModuleData *getAsW3DModelDrawModuleData(void) const { return 0; }
	virtual const W3DTreeDrawModuleData *getAsW3DTreeDrawModuleData(void) const { return 0; }
	virtual StaticGameLODLevel getMinimumRequiredGameLOD(void) const { return (StaticGameLODLevel)0; }
public:
	virtual void crc(Xfer *xfer) {}
	virtual void xfer(Xfer *xfer) {}
	virtual void loadPostProcess(void) {}
};

class CrateCollideModuleData : public ModuleData
{
public:
	CrateCollideModuleData();
	virtual ~CrateCollideModuleData();

private:
	unsigned char m_pad[0x5C - 4];
};

class MoneyCrateCollideModuleData : public CrateCollideModuleData
{
public:
	MoneyCrateCollideModuleData();
	virtual ~MoneyCrateCollideModuleData();

private:
	unsigned int m_moneyProvided;	// +0x5C
};

inline MoneyCrateCollideModuleData::MoneyCrateCollideModuleData()
{
	m_moneyProvided = 0;
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
