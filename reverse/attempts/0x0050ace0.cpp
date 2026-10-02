// ?rva0050ACE0@Made002CC971@@QAEXPAURva0050ACE0Arg@@PBVCoord3D@@@Z
// partial score=0.85 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0050ACE0@Made002CC971@@QAEXPAXPBUCoord3D@@@Z, retail 0x0050ACE0, 183 bytes.
// Made002CC971 vtable slot 6: slave attack order via TheGameLogic findObjectByID, SlaveWatcherBehavior findModule, NetWrapperCommandMsg getDataLength, second findObjectByID, setWeaponLock, AICommandInterface aiAttackPosition.
// Layout: base Rva00507823 0x128 per Made002CC971Ctor; Object+0x258 AI holder with AICommandInterface at +0x20; Player index at +0x54; globals TheGameLogic TheNameKeyGenerator g_Va00E04594 g_00E04590. Evidence: vslot packet slot 6 plus string SlaveWatcherBehavior plus unblocks none listed.
enum ObjectID
{
	OBJECTID_INVALID = 0
};

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

enum WeaponSlotType
{
	WEAPONSLOT_PRIMARY = 0,
	WEAPONSLOT_SECONDARY = 1
};

enum WeaponLockType
{
	WEAPONLOCK_LOCKED = 0,
	WEAPONLOCK_UNLOCKED = 1
};

enum CommandSourceType
{
	COMMANDSOURCE_AI = 2
};

class Coord3D
{
public:
	float x;
	float y;
	float z;
};

class Module
{
public:
	char m_pad[0x20];
};

class NetWrapperCommandMsg
{
public:
	unsigned int getDataLength();
};

class AICommandInterface
{
public:
	void aiAttackPosition(const Coord3D *pos, int i, CommandSourceType src);
};

struct Object258Holder
{
	char m_pad20[0x20];
	AICommandInterface m_ai;
};

class Player
{
public:
	char m_pad54[0x54];
	int m_index;
};

class Object
{
protected:
	const class Module *findModule(NameKeyType key) const;
public:
	char m_pad258[0x258];
	Object258Holder *m_258;
	const Player *getControllingPlayer() const;
	bool setWeaponLock(WeaponSlotType slot, WeaponLockType lock);
	friend class Made002CC971;
};

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern GameLogic *TheGameLogic;
extern NameKeyGenerator *TheNameKeyGenerator;
extern unsigned int g_Va00E04594;
extern int g_00E04590;

struct Rva0050ACE0Guard
{
	Rva0050ACE0Guard() { }
	~Rva0050ACE0Guard() { }
};

class Rva00507823
{
public:
	virtual ~Rva00507823();
	Rva00507823();
private:
	char m_pad04[0x128 - 4];
};

struct Rva0050ACE0Arg
{
	char m_pad[8];
	ObjectID m_id;
};

class Made002CC971 : public Rva00507823
{
public:
	void rva0050ACE0(Rva0050ACE0Arg *arg, const Coord3D *pos);
};

// ?rva0050ACE0@Made002CC971@@QAEXPAURva0050ACE0Arg@@PBVCoord3D@@@Z present-unmatched
void Made002CC971::rva0050ACE0(Rva0050ACE0Arg *arg, const Coord3D *pos)
{
	Object *obj = TheGameLogic->findObjectByID(arg->m_id);
	if (obj == 0)
		return;
	if ((g_Va00E04594 & 1) == 0)
	{
		g_Va00E04594 |= 1;
		g_00E04590 = TheNameKeyGenerator->nameToKey("SlaveWatcherBehavior");
	}
	const Module *mod = obj->findModule((NameKeyType)g_00E04590);
	if (mod == 0)
		return;
	if (obj->m_258 == 0)
		return;
	unsigned int len = ((NetWrapperCommandMsg *)mod)->getDataLength();
	Object *target = TheGameLogic->findObjectByID((ObjectID)len);
	if (target == 0)
		return;
	Object258Holder *holder = target->m_258;
	if (holder == 0)
		return;
	target->setWeaponLock((WeaponSlotType)0, (WeaponLockType)1);
	holder->m_ai.aiAttackPosition(pos, 1, (CommandSourceType)2);
}
