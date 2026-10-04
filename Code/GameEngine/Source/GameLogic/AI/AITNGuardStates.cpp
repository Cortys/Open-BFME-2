// cl: /O1 /DNDEBUG /MD
//
// AITNGuard (tunnel-network guard) state bodies ported from Zero Hour's
// GameEngine/Source/GameLogic/AI/AITNGuard.cpp (GeneralsMD tree vendored under
// reference/open-bfme-1/inputs/reference). Vtables are named by their slot-2
// name getters:
//  - AITNGuardInnerState::onExit, retail 0x00545BB7 (51 bytes): slot 5 of
//    0x00C6A140; attack sub-state +0x2C.
//  - AITNGuardOuterState::onExit, retail 0x00545BEA (51 bytes): slot 5 of
//    0x00C6A198; attack sub-state +0x28.
//  - AITNGuardReturnState::update, retail 0x00545C4D (93 bytes): slot 6 of
//    0x00C6A1F0, over the pinned AIEnterState::update 0x0035455A.
//  - AITNGuardAttackAggressorState::onExit, retail 0x00545CF7 (76 bytes):
//    slot 5 of 0x00C6A298; attack sub-state +0x28.
// BFME2 layout (target evidence): the attack sub-state is deleted with a
// global-scope delete (vslot 0 with flag 0, then ::operator delete); owner
// team +0x304, object id +0x74, player tunnel tracker +0x2E8, guard machine
// nemesis id +0x48. setTeamTargetObject is the rowed Team::rva0039D84A;
// Team::getTeamTargetObject (0x003A105B) and TunnelTracker::getCurNemesis
// (0x004F5684) are pinned ZH-shaped bodies.
typedef bool Bool;
typedef unsigned int UnsignedInt;
#define NULL 0
enum ObjectID
{
	INVALID_ID = 0
};
enum StateExitType
{
	EXIT_NORMAL = 0
};
enum StateReturnType
{
	STATE_CONTINUE = 0,
	STATE_SUCCESS = -1,
	STATE_FAILURE = -2
};
class Object;
class Team
{
public:
	void rva0039D84A(Object *target);
	void setTeamTargetObject(Object *target) { rva0039D84A(target); }
	Object *getTeamTargetObject();
};
class TunnelTracker
{
public:
	Object *getCurNemesis();
};
class Player
{
public:
	TunnelTracker *getTunnelSystem() { return m_tunnelSystem; }
private:
	unsigned char m_pad00[0x2E8];
	TunnelTracker *m_tunnelSystem; // +0x2E8
};
class Object
{
public:
	ObjectID getID() const { return m_id; }
	Team *getTeam() { return m_team; }
	Player *getControllingPlayer() const;
private:
	unsigned char m_pad00[0x74];
	ObjectID m_id; // +0x74
	unsigned char m_pad78[0x304 - 0x78];
	Team *m_team; // +0x304
};
class StateMachine
{
public:
	Object *getOwner() const { return m_owner; }
private:
	unsigned char m_pad00[0x14];
	Object *m_owner; // +0x14
};
class AITNGuardMachine : public StateMachine
{
public:
	void setNemesisID(ObjectID id) { m_nemesisToAttack = id; }
private:
	unsigned char m_pad18[0x48 - 0x18];
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
	virtual void onExit(StateExitType status);
	virtual StateReturnType update();
protected:
	StateMachine *getMachine() const { return m_machine; }
	Object *getMachineOwner() const { return m_machine->getOwner(); }
	unsigned char m_pad04[0x18 - 0x04];
	StateMachine *m_machine; // +0x18
};
class AIAttackState : public State
{
};
class AIEnterState : public State
{
public:
	virtual StateReturnType update();
};
class AITNGuardInnerState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x2C - 0x1C];
	AIAttackState *m_attackState; // +0x2C
};
class AITNGuardOuterState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x28 - 0x1C];
	AIAttackState *m_attackState; // +0x28
};
class AITNGuardReturnState : public AIEnterState
{
public:
	virtual StateReturnType update();
private:
	AITNGuardMachine *getGuardMachine() { return (AITNGuardMachine *)getMachine(); }
};
class AITNGuardAttackAggressorState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x28 - 0x1C];
	AIAttackState *m_attackState; // +0x28
};

void AITNGuardInnerState::onExit( StateExitType status )
{
	if (m_attackState)
	{
		m_attackState->onExit(status);
		::delete m_attackState;
		m_attackState = NULL;
	}
}

void AITNGuardOuterState::onExit( StateExitType status )
{
	if (m_attackState)
	{
		m_attackState->onExit(status);
		::delete m_attackState;
		m_attackState = NULL;
	}
}

StateReturnType AITNGuardReturnState::update( void )
{
	Player *ownerPlayer = getMachineOwner()->getControllingPlayer();
	if (getMachineOwner()->getTeam()) {
		Object *teamVictim = getMachineOwner()->getTeam()->getTeamTargetObject();
		if (teamVictim)	{
			getGuardMachine()->setNemesisID(teamVictim->getID());
			return STATE_FAILURE; // Fail to return goes to inner attack state.
		}
	}
	// Check tunnel for target.
	TunnelTracker *tunnels = NULL;
	if (ownerPlayer) {
		tunnels = ownerPlayer->getTunnelSystem();
	}

	if (tunnels) {
		Object *nemesis = tunnels->getCurNemesis();
		if (nemesis) {
			getGuardMachine()->setNemesisID(nemesis->getID());
			return STATE_FAILURE; // Fail to return goes to inner attack state.
		}
	}

	// Just let the return movement finish.
	StateReturnType ret = AIEnterState::update();
	if (ret==STATE_CONTINUE) return STATE_CONTINUE;
	return STATE_SUCCESS;
}

void AITNGuardAttackAggressorState::onExit( StateExitType status )
{
	Object *obj = getMachineOwner();
	if (m_attackState)
	{
		m_attackState->onExit(status);
		::delete m_attackState;
		m_attackState = NULL;
	}

	if (obj->getTeam())
	{
		obj->getTeam()->setTeamTargetObject(NULL); // clear the target.
	}
}
