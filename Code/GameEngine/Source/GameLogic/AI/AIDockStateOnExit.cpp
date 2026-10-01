// cl: /O1 /DNDEBUG /MD
//
// AIDockState::onExit, retail 0x00341723 (77 bytes): slot 5 of vtable
// 0x00C11368, whose slot-2 name getter returns AIDockState.
// Donor: BFME1 game/GameEngine/Source/GameLogic/AI/AIDockState.cpp
// (open-bfme-1 068db38bb4), the Zero Hour AIStates.cpp onExit: halt the dock
// machine (vslot 15), delete it, clear it, then reset the AI's
// can-path-through-units byte and ignoreObstacle(NULL).
// BFME2 deltas (target evidence): the dock machine is at +0x20 (BFME1 +0x24),
// the owner at machine+0x14, the AI at Object+0x258 and its byte at +0x3BA.
// The deletion is a global-scope delete: retail calls vslot 0 with flag 0
// (destroy only) and then ::operator delete on its result, passing NULL when
// the pointer is NULL, which ::delete on a virtual-destructor class emits.
enum StateReturnType
{
	STATE_CONTINUE = 0,
	STATE_SUCCESS = -1,
	STATE_FAILURE = -2
};
enum StateExitType
{
	EXIT_NORMAL = 0
};
class Object;
class AIUpdateInterface
{
public:
	void ignoreObstacle(const Object *obstacle);
	unsigned char m_pad[0x3BA];
	unsigned char m_canPathThroughUnits; // +0x3BA
};
class Object
{
public:
	AIUpdateInterface *getAI() { return m_ai; }
	unsigned char m_objectFields00[0x258];
	AIUpdateInterface *m_ai; // +0x258
};
class StateMachine
{
public:
	virtual void slot00();
	Object *getOwner() { return m_owner; }
	unsigned char m_machineFields04[0x10];
	Object *m_owner; // +0x14
};
class AIDockMachine
{
public:
	virtual ~AIDockMachine();
	virtual void slot04();
	virtual void slot08();
	virtual void slot0c();
	virtual void slot10();
	virtual void slot14();
	virtual void slot18();
	virtual StateReturnType initDefaultState();
	virtual StateReturnType setState(int id);
	virtual void slot24();
	virtual void slot28();
	virtual void slot2c();
	virtual void slot30();
	virtual void slot34();
	virtual void setGoalObject(Object *goalObject);
	virtual void halt();
};
class State
{
public:
	virtual ~State();
protected:
	unsigned char m_stateFields04[0x14];
	StateMachine *m_machine; // +0x18
	unsigned char m_stateFields1C[4];
};
class AIDockState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	AIDockMachine *m_dockMachine; // +0x20
};
void AIDockState::onExit(StateExitType status)
{
	if (m_dockMachine)
	{
		m_dockMachine->halt();
		::delete m_dockMachine;
		m_dockMachine = 0;
	}
	AIUpdateInterface *ai = m_machine->m_owner->m_ai;
	if (ai)
	{
		ai->m_canPathThroughUnits = 0;
		ai->ignoreObstacle(0);
	}
}
