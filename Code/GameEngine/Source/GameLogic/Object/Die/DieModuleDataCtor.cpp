// cl: /O1 /MD
//
// DieModuleData::DieModuleData, retail 0x006054E7, 29 bytes. Dedicated TU so
// EjectPilotDie.cpp keeps its matched bodies. Base ctor then three zeroed
// pointers at +0x14 and the DieModuleData vtable.

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
	ModuleData();
	virtual ~ModuleData();
	virtual Bool isAiModuleData(void) const;
	virtual const W3DModelDrawModuleData *getAsW3DModelDrawModuleData(void) const;
	virtual const W3DTreeDrawModuleData *getAsW3DTreeDrawModuleData(void) const;
	virtual StaticGameLODLevel getMinimumRequiredGameLOD(void) const;
	virtual void crc(Xfer *xfer);
	virtual void xfer(Xfer *xfer);
	virtual void loadPostProcess(void);

private:
	int _pad[4];
};

class DieModuleData : public ModuleData
{
public:
	DieModuleData();
	virtual ~DieModuleData();

private:
	void *_a;
	void *_b;
	void *_c;
};

inline DieModuleData::DieModuleData()
	: _a(0), _b(0), _c(0)
{
}

// Header inlines that the units including the header emit as select-any
// copies, which plain definitions here collided with. The anchor keeps this
// unit's copies for the rows; it is not retail code.
#pragma inline_depth(0)
// ?_bfmeDieModuleDataInlineAnchor@@YAXPAVDieModuleData@@@Z absent-from-retail
void _bfmeDieModuleDataInlineAnchor(DieModuleData *p)
{
    p->DieModuleData::DieModuleData();
}
#pragma inline_depth()
