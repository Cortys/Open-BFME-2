// ?rva004C55FC@GrabPassengerSpecialPower@@QAEHXZ
// partial score=0.97 date=2026-10-04
// ?rva004C55FC@GrabPassengerSpecialPower@@QAEHXZ
// partial score=0.95 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHsc

class Thing;
class ModuleData;

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h
class BehaviorModule
{
public:
	virtual void behaviorModuleAnchor();

private:
	unsigned char m_data[8];
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h
class SpecialPowerModuleInterface
{
public:
	virtual void specialPowerModuleInterfaceAnchor();
};

class ModuleInterface
{
public:
	virtual void moduleInterfaceAnchor();
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h
class SpecialPowerModule : public BehaviorModule,
	public SpecialPowerModuleInterface,
	public ModuleInterface
{
public:
	SpecialPowerModule( Thing *thing, const ModuleData *moduleData );

protected:
	virtual ~SpecialPowerModule();
};

class GrabPassengerSpecialPower : public SpecialPowerModule
{
public:
	GrabPassengerSpecialPower( Thing *thing, const ModuleData *moduleData );
	int rva004C55FC();

protected:
	virtual ~GrabPassengerSpecialPower();
};

GrabPassengerSpecialPower::GrabPassengerSpecialPower( Thing *thing, const ModuleData *moduleData )
	: SpecialPowerModule( thing, moduleData )
{
}

// ??1GrabPassengerSpecialPower@@MAE@XZ present-unmatched
GrabPassengerSpecialPower::~GrabPassengerSpecialPower()
{
}

class Object
{
public:
	int rva0028B7C8() const;
	void rva0028AE6D();
private:
	char m_pad[0x11C];
public:
	union {
		unsigned int m_flags11C;
		unsigned char m_flags11C_byte[4];
	};
};

// ?rva004C55FC@GrabPassengerSpecialPower@@QAEHXZ present-unmatched
// slot 29 of 0x0085D93C (GrabPassengerSpecialPower); callers none; callees rowed rva0028B7C8 rva0028AE6D
// Target evidence: vtable slot 29; neighbours 0x004C5571 0x004C5671; returns 0x3FFFFFFF 0x40000000 1 with +0x2C +0x2D flags and Object +0x11C bit30
int GrabPassengerSpecialPower::rva004C55FC()
{
	if (*(unsigned char *)((char *)this + 0x2C) == 0)
	{
		if (*(unsigned char *)((char *)this + 0x2D) == 0)
			return 0x3FFFFFFF;
	}
	if ((unsigned char)(*(Object **)((char *)this - 8))->rva0028B7C8() != 0)
	{
		if (*(unsigned char *)((char *)this + 0x2C) == 0)
			return 1;
		*(unsigned char *)((char *)this + 0x2C) = 0;
		if (((*((Object **)((char *)this - 8)))->m_flags11C_byte[3] & 0x40) == 0)
			return 0x3FFFFFFF;
		(*((Object **)((char *)this - 8)))->m_flags11C_byte[3] &= (unsigned char)0xBF;
		(*((Object **)((char *)this - 8)))->rva0028AE6D();
		return 0x3FFFFFFF;
	}
	if (*(unsigned char *)((char *)this + 0x2D) == 0)
		return 1;
	if (*(unsigned char *)((char *)this + 0x2C) != 0)
		return 1;
	unsigned int mask = 0x40000000;
	*(unsigned char *)((char *)this + 0x2D) = 0;
	*(unsigned char *)((char *)this + 0x2C) = 1;
	if (((*((Object **)((char *)this - 8)))->m_flags11C & mask) != 0)
		return 1;
	(*((Object **)((char *)this - 8)))->m_flags11C |= mask;
	(*((Object **)((char *)this - 8)))->rva0028AE6D();
	return 1;
}
