// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??1BridgeBehavior@@UAE@XZ, retail 0x00457113, 150 bytes (pinned; rowed
// deleting wrapper 0x00457536). The Zero Hour destructor body carries over:
// look up each of the four tower IDs through getTowerID (rowed 0x004565A5,
// called on the +0x20 BridgeBehaviorInterface subobject) and destroy any
// tower still alive. BFME2 deltas (target evidence): six vtables at
// +0x00/+0x0C/+0x10/+0x20/+0x24/+0x28, and a pool member at +0x100 released
// through the pinned PoolMember::Rva00268902 after the loop. Retail's unwind
// map holds the base 0x0024A797 (state 0) and that member (state 1, through
// the 0x00268AFF jmp), with no store between the loop and the release, as
// in BroadcastStealthUpdateDtor.cpp. Base layout as in Rva0024A797Derived.cpp.
class Object;
enum ObjectID { INVALID_ID = 0 };
enum BridgeTowerType { BRIDGE_TOWER_FROM_LEFT = 0, BRIDGE_MAX_TOWERS = 4 };

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
	void destroyObject(Object *obj);
};

extern GameLogic *TheGameLogic;

class Rva0024A797
{
public:
	virtual ~Rva0024A797();
private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class UpdateModuleInterfaceData
{
public:
	virtual void f2();
private:
	int m_14;
	int m_18;
	int m_1C;
};

class BridgeBehaviorInterface
{
public:
	virtual ObjectID getTowerID(BridgeTowerType towerType) = 0;
};

class DamageModuleInterface
{
public:
	virtual void onDamage() = 0;
};

class DieModuleInterface
{
public:
	virtual void onDie() = 0;
};

class PoolMember
{
public:
	~PoolMember() { Rva00268902(); }
	void Rva00268902() throw();
private:
	void *m_ptr;
};

class BridgeBehavior : public Rva0024A797, public MiBase1, public UpdateModuleInterfaceData,
	public BridgeBehaviorInterface, public DamageModuleInterface, public DieModuleInterface
{
public:
	virtual ~BridgeBehavior();
	virtual ObjectID getTowerID(BridgeTowerType towerType);
	virtual void onDamage();
	virtual void onDie();
private:
	char m_pad2C[0x100 - 0x2C];
	PoolMember m_100;
};

BridgeBehavior::~BridgeBehavior()
{
	for (int i = 0; i < BRIDGE_MAX_TOWERS; ++i)
	{
		Object *tower = TheGameLogic->findObjectByID(getTowerID((BridgeTowerType)i));
		if (tower)
			TheGameLogic->destroyObject(tower);
	}
}
