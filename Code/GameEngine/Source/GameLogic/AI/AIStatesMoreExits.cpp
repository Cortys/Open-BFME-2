// cl: /O1 /DNDEBUG /MD
//
// Small AI state bodies ported from Zero Hour's GameEngine/Source/GameLogic/
// AI/AIStates.cpp (GeneralsMD tree vendored under reference/open-bfme-1/
// inputs/reference). Each vtable is named by its slot-2 name getter:
//  - AIMoveAndDeleteState::onExit, retail 0x0034A0CB (12 bytes): slot 5 of
//    0x00C12C88 (unlock, then the pinned base onExit as a tail jump).
//  - AIAttackAreaState::onExit, retail 0x0034234C (34 bytes): slot 5 of
//    0x00C11900; attack machine +0x20.
//  - AIHuntState::onExit, retail 0x003421F4 (51 bytes): slot 5 of 0x00C118B0;
//    hunt machine +0x20, then releaseWeaponLock(LOCKED_TEMPORARILY) (pinned
//    Object::releaseWeaponLock 0x0028D8B6: contain vslot then the +0x330
//    weapon set).
//  - AIAttackPursueTargetState::onExit, retail 0x003495FD (20 bytes): slot 5
//    of 0x00C12730; m_isInitialApproach +0x5F.
//  - AIAttackMoveToState::onEnter, retail 0x0034EC7B (96 bytes): slot 4 of
//    0x00C13548 (slot 5 is the rowed onExit). ZH body over the pinned
//    AIMoveToState::onEnter 0x0034C7BD (slot 4 of AIMoveToState's vtable
//    0x00C11EB8); BFME 2 then records the machine's goal object id (+0x20)
//    at +0x6C or, with none, the machine goal position (+0x24) at +0x60
//    (both unnamed). Layout: m_commandSrc +0x50, attack-move machine +0x54
//    (clear vslot 5, setState vslot 8), m_frameToSleepUntil +0x58,
//    m_retryCount +0x5C; getLastCommandSource is AI vslot 143.
// The sub-machines are deleted with a global-scope delete (vslot 0 with flag
// 0, then ::operator delete).
typedef bool Bool;
typedef float Real;
typedef unsigned int UnsignedInt;
typedef UnsignedInt StateID;
#define NULL 0
#define ATTACK_RETRY_COUNT 5
enum StateExitType
{
	EXIT_NORMAL = 0
};
enum StateReturnType
{
	STATE_CONTINUE = 0
};
enum WeaponLockType
{
	NOT_LOCKED = 0,
	LOCKED_TEMPORARILY = 1
};
enum CommandSourceType
{
	CMD_FROM_PLAYER = 0
};
enum
{
	AI_IDLE = 0
};
struct Coord3D
{
	Real x, y, z;
};
template <int N> class VSlots : public VSlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class VSlots<0>
{
};
class AIUpdateInterface : public VSlots<143>
{
public:
	virtual CommandSourceType getLastCommandSource() const = 0;
};
class Object
{
public:
	AIUpdateInterface *getAI() { return m_ai; }
	void releaseWeaponLock(WeaponLockType lockType);
private:
	unsigned char m_pad00[0x258];
	AIUpdateInterface *m_ai; // +0x258
};
class StateMachine
{
public:
	virtual ~StateMachine();
	virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04();
	virtual void clear();
	virtual void slot06(); virtual void slot07();
	virtual StateReturnType setState(StateID newStateID);
	Object *getOwner() const { return m_owner; }
	void unlock() { m_locked = false; }
	UnsignedInt m_pad04[4];
	Object *m_owner; // +0x14
	UnsignedInt m_pad18[2];
	UnsignedInt m_goalObjectID; // +0x20
	Coord3D m_goalPosition; // +0x24
	UnsignedInt m_pad30[2];
	Bool m_locked; // +0x38
};
class State
{
public:
	virtual ~State();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual StateReturnType onEnter();
	virtual void onExit(StateExitType status);
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
	virtual void onExit(StateExitType status);
};
class AIMoveToState : public AIInternalMoveToState
{
public:
	virtual StateReturnType onEnter();
};
class AIMoveAndDeleteState : public AIInternalMoveToState
{
public:
	virtual void onExit(StateExitType status);
};
class AIAttackAreaState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x20 - 0x1C];
	StateMachine *m_attackMachine; // +0x20
};
class AIHuntState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x20 - 0x1C];
	StateMachine *m_huntMachine; // +0x20
};
class AIAttackPursueTargetState : public AIInternalMoveToState
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x5F - 0x1C];
	Bool m_isInitialApproach; // +0x5F
};
class AIAttackMoveToState : public AIMoveToState
{
public:
	virtual StateReturnType onEnter();
private:
	unsigned char m_pad1C[0x50 - 0x1C];
	CommandSourceType m_commandSrc; // +0x50
	StateMachine *m_attackMoveMachine; // +0x54
	UnsignedInt m_frameToSleepUntil; // +0x58
	int m_retryCount; // +0x5C
	Coord3D m_bfmeGoalPosition60; // +0x60
	UnsignedInt m_bfmeGoalObjectID6C; // +0x6C
};

void AIMoveAndDeleteState::onExit( StateExitType status )
{
	getMachine()->unlock();
	AIInternalMoveToState::onExit( status );
}

void AIAttackAreaState::onExit( StateExitType status )
{
	// destroy the hunt machine
	::delete m_attackMachine;
	m_attackMachine = NULL;
}

void AIHuntState::onExit( StateExitType status )
{
	// destroy the hunt machine
	::delete m_huntMachine;
	m_huntMachine = NULL;

	Object *obj = getMachineOwner();
	if (obj)
	{
		obj->releaseWeaponLock(LOCKED_TEMPORARILY);	// release any temporary locks.
	}
}

void AIAttackPursueTargetState::onExit( StateExitType status )
{
	// contained by AIAttackState, so no separate timer
	AIInternalMoveToState::onExit( status );

	m_isInitialApproach = false;	// We only want to allow turreted things to fire at enemies during their
																// first approach
}

StateReturnType AIAttackMoveToState::onEnter()
{
	Object *owner = getMachineOwner();
	AIUpdateInterface *ai = owner->getAI();
	m_attackMoveMachine->clear();
	m_attackMoveMachine->setState( AI_IDLE );
	m_commandSrc = ai->getLastCommandSource();
	m_retryCount = ATTACK_RETRY_COUNT;
	m_frameToSleepUntil = 0;

	StateReturnType ret = AIMoveToState::onEnter();
	StateMachine *machine = getMachine();
	if (machine->m_goalObjectID)
	{
		m_bfmeGoalObjectID6C = machine->m_goalObjectID;
	}
	else
	{
		m_bfmeGoalObjectID6C = 0;
		m_bfmeGoalPosition60 = machine->m_goalPosition;
	}
	return ret;
}
