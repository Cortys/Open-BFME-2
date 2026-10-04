// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// AIGuardRetaliate state bodies ported from Zero Hour's
// GameEngine/Source/GameLogic/AI/AIGuardRetaliate.cpp (GeneralsMD tree
// vendored under reference/open-bfme-1/inputs/reference). Vtables are named by
// their slot-2 name getters:
//  - AIGuardRetaliateReturnState::onEnter, retail 0x005452CB (200 bytes): slot
//    4 of 0x00C69F38. ZH's randomised return scan (line 248 of BFME 2's
//    AIGuardRetaliate.cpp) and the goal from the machine's position to guard
//    (+0x3C), the ground-movement adjustDestination (pinned), then
//    setAdjustsDestination(true) with its CritterDesync log before the base
//    onEnter. BFME 2 also resets the owner's +0x250 module: its vslot 31
//    result, if any, gets vslot 5 with 0.
//  - AIGuardRetaliateReturnState::update, retail 0x0054574D (221 bytes): slot
//    6 of 0x00C69F38. ZH's return scan through the retaliate machine's
//    lookForInnerTarget (pinned 0x005455E3) before the base update; BFME 2
//    first fails over to its last attacker (owner body vslot 18) when that
//    object is not flagged (+0x438 bit 0), is an enemy (rowed
//    getRelationship), the owner can attack (rowed isAbleToAttack) and the
//    pinned getAbleToAttackSpecificObject(ATTACK_NEW_TARGET, attacker,
//    CMD_FROM_AI) allows it, redirecting through the rowed
//    Object::rva002931F5 for status 0x26 as AIGuardRetaliateState::onEnter
//    does, and storing it as the machine's nemesis (+0x48).
// Layout (target evidence): state goal +0x20, adjusts-destination +0x48,
// m_nextReturnScanTime +0x4C; TAiData m_guardEnemyReturnScanRate +0x44.
typedef bool Bool;
typedef float Real;
typedef unsigned int UnsignedInt;
#define NULL 0
enum ObjectID
{
	INVALID_ID = 0
};
enum Relationship
{
	ENEMIES = 0,
	NEUTRAL,
	ALLIES
};
enum AbleToAttackType
{
	ATTACK_NEW_TARGET = 0
};
enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT,
	CMD_FROM_AI
};
enum CanAttackResult
{
	ATTACKRESULT_NOT_POSSIBLE = 0,
	ATTACKRESULT_INVALID_SHOT,
	ATTACKRESULT_POSSIBLE_AFTER_MOVING,
	ATTACKRESULT_POSSIBLE
};
enum ObjectStatusTypes
{
	OBJECT_STATUS_BFME_26 = 0x26
};
enum StateReturnType
{
	STATE_CONTINUE = 0,
	STATE_SUCCESS = -1,
	STATE_FAILURE = -2
};
struct Coord3D
{
	Real x, y, z;
};
class Object;
class LocomotorSet;
template <int N> class VSlots : public VSlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class VSlots<0>
{
};
// isDoingGroundMovement is AIUpdateInterface vslot 137 (+0x224).
class AIUpdateInterface : public VSlots<137>
{
public:
	virtual Bool isDoingGroundMovement(void) const = 0;
	const LocomotorSet &getLocomotorSet(void) const { return *(const LocomotorSet *)m_locomotorSet; }
private:
	unsigned char m_pad004[0x1CC - 0x04];
	unsigned char m_locomotorSet[4]; // +0x1CC
};
class Rva00545355Target : public VSlots<5>
{
public:
	virtual void bfmeReset(int value) = 0;
};
class Rva00545355Module : public VSlots<31>
{
public:
	virtual Rva00545355Target *bfmeTarget() = 0;
};
class BodyModuleInterface : public VSlots<18>
{
public:
	virtual ObjectID getClearableLastAttacker() const = 0;
};
class Object
{
public:
	ObjectID getID() const { return m_id; }
	BodyModuleInterface *getBodyModule() const { return m_body; }
	Bool testBfme438Bit0() const { return (m_bfme438 & 1) != 0; }
	Relationship getRelationship(const Object *that) const;
	Bool isAbleToAttack() const;
	CanAttackResult getAbleToAttackSpecificObject(AbleToAttackType t, const Object *target, CommandSourceType commandSource) const;
	Bool testStatus(ObjectStatusTypes bit) const;
	Object *rva002931F5(Bool flag);
	AIUpdateInterface *getAI() { return m_ai; }
	Rva00545355Module *getBfme250() { return m_bfme250; }
private:
	unsigned char m_pad00[0x74];
	ObjectID m_id; // +0x74
	unsigned char m_pad78[0x250 - 0x78];
	Rva00545355Module *m_bfme250; // +0x250
	BodyModuleInterface *m_body; // +0x254
	AIUpdateInterface *m_ai; // +0x258
	unsigned char m_pad25C[0x438 - 0x25C];
	unsigned char m_bfme438; // +0x438
};
class Pathfinder
{
public:
	Bool adjustDestination(Object *obj, const LocomotorSet &locomotorSet, Coord3D *dest, const Coord3D *groupDest = NULL);
};
struct TAiData
{
	unsigned char m_pad00[0x44];
	UnsignedInt m_guardEnemyReturnScanRate; // +0x44
};
class AI
{
public:
	Pathfinder *pathfinder() { return m_pathfinder; }
	const TAiData *getAiData() const { return m_aiData; }
private:
	unsigned char m_pad00[0x10];
	Pathfinder *m_pathfinder; // +0x10
	unsigned char m_pad14[0x18 - 0x14];
	TAiData *m_aiData; // +0x18
};
extern AI *TheAI;
class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
	UnsignedInt getFrame() const { return m_frame; }
private:
	unsigned char m_pad00[0x40];
	UnsignedInt m_frame; // +0x40
};
extern GameLogic *TheGameLogic;
int GetGameLogicRandomValue(int low, int high, char *file, int line);
#define AIGUARDRETALIATE_FILE "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\Ai\\AIGuardRetaliate.cpp"
struct FprintfTarget
{
	char m_pad[4];
};
extern "C" void fprintf(FprintfTarget *target, const char *format, ...);
extern unsigned char g_00E03745;
extern void *g_00DFEFF0;
class StateMachine
{
public:
	Object *getOwner() const { return m_owner; }
private:
	unsigned char m_pad00[0x14];
	Object *m_owner; // +0x14
};
class AIGuardRetaliateMachine : public StateMachine
{
public:
	const Coord3D *getPositionToGuard(void) const { return &m_positionToGuard; }
	void setNemesisID(ObjectID id) { m_nemesisToAttack = id; }
	Bool lookForInnerTarget(void);
private:
	unsigned char m_pad18[0x3C - 0x18];
	Coord3D m_positionToGuard; // +0x3C
	ObjectID m_nemesisToAttack; // +0x48
};
class State
{
public:
	virtual ~State();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual StateReturnType onEnter();
	virtual void onExit(int status);
	virtual StateReturnType update();
protected:
	StateMachine *getMachine() const { return m_machine; }
	Object *getMachineOwner() const { return m_machine->getOwner(); }
	unsigned char m_pad04[0x18 - 0x04];
	StateMachine *m_machine; // +0x18
};
class AIInternalMoveToState : public State
{
public:
	virtual StateReturnType onEnter();
	virtual StateReturnType update();
protected:
	void setAdjustsDestination(Bool b) { m_adjustsDestination = b; }
	unsigned char m_pad1C[0x20 - 0x1C];
	Coord3D m_goalPosition; // +0x20
	unsigned char m_pad2C[0x48 - 0x2C];
	Bool m_adjustsDestination; // +0x48
	unsigned char m_pad49[0x4C - 0x49];
};
class AIGuardRetaliateReturnState : public AIInternalMoveToState
{
public:
	virtual StateReturnType onEnter();
	virtual StateReturnType update();
private:
	AIGuardRetaliateMachine *getGuardMachine() { return (AIGuardRetaliateMachine *)getMachine(); }
	UnsignedInt m_nextReturnScanTime; // +0x4C
};

//--------------------------------------------------------------------------------------
StateReturnType AIGuardRetaliateReturnState::onEnter( void )
{
	UnsignedInt now = TheGameLogic->getFrame();
	m_nextReturnScanTime = now + GetGameLogicRandomValue(0, TheAI->getAiData()->m_guardEnemyReturnScanRate, AIGUARDRETALIATE_FILE, 248);

	m_goalPosition = *getGuardMachine()->getPositionToGuard();

	AIUpdateInterface *ai = getMachineOwner()->getAI(); 
	if (ai && ai->isDoingGroundMovement()) 
	{
		TheAI->pathfinder()->adjustDestination(getMachineOwner(), ai->getLocomotorSet(), &m_goalPosition);
	}
	Rva00545355Module *module = getMachineOwner()->getBfme250();
	if (module)
	{
		Rva00545355Target *target = module->bfmeTarget();
		if (target)
			target->bfmeReset(0);
	}
	if (g_00E03745)
	{
		FprintfTarget *log = (FprintfTarget *)g_00DFEFF0;
		if (log)
			fprintf(log, "CritterDesync: setAdjustDestination(TRUE) 4");
	}
	setAdjustsDestination(true);
	return AIInternalMoveToState::onEnter();
}

//--------------------------------------------------------------------------------------
StateReturnType AIGuardRetaliateReturnState::update( void )
{
	Object *owner = getMachineOwner();
	BodyModuleInterface *body = owner ? owner->getBodyModule() : NULL;
	if (owner && body)
	{
		Object *attacker = TheGameLogic->findObjectByID(body->getClearableLastAttacker());
		if (attacker && !attacker->testBfme438Bit0() && owner->getRelationship(attacker) == ENEMIES && owner->isAbleToAttack())
		{
			CanAttackResult result = owner->getAbleToAttackSpecificObject(ATTACK_NEW_TARGET, attacker, CMD_FROM_AI);
			if (result == ATTACKRESULT_POSSIBLE || result == ATTACKRESULT_POSSIBLE_AFTER_MOVING)
			{
				if (attacker->testStatus(OBJECT_STATUS_BFME_26) && attacker->rva002931F5(false))
					attacker = attacker->rva002931F5(false);
				getGuardMachine()->setNemesisID(attacker->getID());
				return STATE_FAILURE;
			}
		}
	}

	UnsignedInt now = TheGameLogic->getFrame();
	if (now >= m_nextReturnScanTime)
	{
		m_nextReturnScanTime = now + TheAI->getAiData()->m_guardEnemyReturnScanRate;
		if (getGuardMachine()->lookForInnerTarget()) 
			return STATE_FAILURE; // early termination because we found a target.
	}

	// Just let the return movement finish.
	return AIInternalMoveToState::update();
}
