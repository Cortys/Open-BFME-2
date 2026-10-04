// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// AIGuard state bodies ported from Zero Hour's GameEngine/Source/GameLogic/AI/
// AIGuard.cpp (GeneralsMD tree vendored under reference/open-bfme-1/inputs/
// reference). Vtables are named by their slot-2 name getters:
//  - AIGuardAttackAggressorState::onExit, retail 0x00542C87 (76 bytes): slot 5
//    of 0x00C69890 (AIGuardAttackAggressorState). The same body is slot 5 of
//    0x00C69780 (AIGuardInnerState) and 0x00C69FA0
//    (AIGuardRetaliateAttackAggressorState): BFME 2's inner state lost ZH's
//    enter-state branch, so the bodies fold. Only this one row claims it.
//  - AIGuardAttackAggressorState::update, retail 0x0054403B (90 bytes): slot 6
//    of 0x00C69890.
//  - AIGuardOuterState::onExit, retail 0x00542CD3 (51 bytes): slot 5 of
//    0x00C697D8 (AIGuardOuterState).
//  - AIGuardReturnState::update, retail 0x00543DF1 (108 bytes): slot 6 of
//    0x00C69830 (AIGuardReturnState). BFME 2 only runs ZH's return scan while
//    the locomotor distance to goal (pinned
//    AIUpdateInterface::getLocomotorDistanceToGoal 0x0026435E, the ZH
//    goal-type switch) is inside the standard guard range.
//  - AIGuardIdleState::update, retail 0x00543E5D (251 bytes): slot 6 of
//    0x00C696D0 (AIGuardIdleState); BFME 2 also checks a guarded team's
//    centre. AI crate id +0x238, AI_GUARD_GET_CRATE 5004 through the machine's
//    setState (vslot 8), m_nextEnemyScanTime +0x20, m_guardeePos +0x24.
//  - AIGuardIdleState::onEnter, retail 0x00542D88 (53 bytes): slot 4 of
//    0x00C696D0; ZH's randomised first scan (GameLogicRandomValue at AIGuard.cpp
//    line 1013 in BFME 2's tree).
//  - AIGuardMachine::getStdGuardRange, retail 0x00542C2A (14 bytes): ZH's
//    static over AI::getAdjustedVisionRangeForObject (pinned 0x002FDD0A, static
//    as in ZH) with OWNERTYPE|MOOD|GUARDINNER.
// BFME2 layout (target evidence): attack sub-state +0x3C (deleted with a
// global-scope delete: vslot 0 with flag 0, then ::operator delete), exit
// conditions centre +0x28; the guard machine keeps the object-to-guard id at
// +0x3C and a team-to-guard id at +0x40 (BFME 2 addition: with no object the
// centre follows the team through the rowed Team::rva0039E5B9). Owner team
// +0x304; setTeamTargetObject is the rowed Team::rva0039D84A. TeamFactory's
// findTeamByID is the pinned 0x0039F761 (prototype walk as in Generals).
typedef bool Bool;
#define NULL 0
typedef float Real;
typedef unsigned int UnsignedInt;
enum ObjectID
{
	INVALID_ID = 0
};
typedef UnsignedInt TeamID;
enum
{
	AI_VISIONFACTOR_OWNERTYPE = 0x01,
	AI_VISIONFACTOR_MOOD = 0x02,
	AI_VISIONFACTOR_GUARDINNER = 0x04
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
struct Coord3D
{
	Real x, y, z;
};
class Object;
class AIUpdateInterface;
class Team
{
public:
	void rva0039D84A(Object *target);
	void setTeamTargetObject(Object *target) { rva0039D84A(target); }
	void rva0039E5B9(Coord3D *pos);
};
class TeamFactory
{
public:
	Team *findTeamByID(TeamID id);
};
extern TeamFactory *TheTeamFactory;
class Object
{
public:
	const Coord3D *getPosition() const { return &m_position; }
	Team *getTeam() { return m_team; }
	AIUpdateInterface *getAI() { return m_ai; }
private:
	unsigned char m_pad00[0x38];
	Coord3D m_position; // +0x38
	unsigned char m_pad44[0x258 - 0x44];
	AIUpdateInterface *m_ai; // +0x258
	unsigned char m_pad25C[0x304 - 0x25C];
	Team *m_team; // +0x304
};
class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
	UnsignedInt getFrame() const { return m_frame; }
private:
	unsigned char m_pad00[0x40];
	UnsignedInt m_frame; // +0x40
};
class AIUpdateInterface
{
public:
	Real getLocomotorDistanceToGoal();
	ObjectID getCrateID() const { return m_crateCreated; }
private:
	unsigned char m_pad00[0x238];
	ObjectID m_crateCreated; // +0x238
};
struct TAiData
{
	unsigned char m_pad00[0x40];
	UnsignedInt m_guardEnemyScanRate; // +0x40
	UnsignedInt m_guardEnemyReturnScanRate; // +0x44
};
class AI
{
public:
	const TAiData *getAiData() const { return m_aiData; }
	static Real getAdjustedVisionRangeForObject(const Object *object, int factorsToConsider);
private:
	unsigned char m_pad00[0x18];
	TAiData *m_aiData; // +0x18
};
extern AI *TheAI;
extern GameLogic *TheGameLogic;
typedef UnsignedInt StateID;
class StateMachine
{
public:
	virtual ~StateMachine();
	virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06();
	virtual void slot07();
	virtual StateReturnType setState(StateID newStateID);
	Object *getOwner() const { return m_owner; }
private:
	unsigned char m_pad04[0x14 - 0x04];
	Object *m_owner; // +0x14
};
class AIGuardMachine : public StateMachine
{
public:
	Object *findTargetToGuardByID() { return TheGameLogic->findObjectByID(m_targetToGuard); }
	Team *findTeamToGuardByID() { return TheTeamFactory->findTeamByID(m_teamToGuard); }
	Bool lookForInnerTarget(void);
	static Real getStdGuardRange(const Object *obj);
private:
	unsigned char m_pad18[0x3C - 0x18];
	ObjectID m_targetToGuard; // +0x3C
	TeamID m_teamToGuard; // +0x40
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
struct ExitConditions
{
	unsigned char m_pad00[0x04];
	Coord3D m_center; // +0x04 (state +0x28)
};
class AIAttackState : public State
{
};
class AIGuardAttackAggressorState : public State
{
public:
	virtual void onExit(StateExitType status);
	virtual StateReturnType update();
private:
	AIGuardMachine *getGuardMachine() { return (AIGuardMachine *)getMachine(); }
	unsigned char m_pad1C[0x24 - 0x1C];
	ExitConditions m_exitConditions; // +0x24
	unsigned char m_pad34[0x3C - 0x34];
	AIAttackState *m_attackState; // +0x3C
};
class AIInternalMoveToState : public State
{
public:
	virtual StateReturnType update();
protected:
	unsigned char m_pad1C[0x4C - 0x1C];
};
class AIGuardReturnState : public AIInternalMoveToState
{
public:
	virtual StateReturnType update();
private:
	AIGuardMachine *getGuardMachine() { return (AIGuardMachine *)getMachine(); }
	UnsignedInt m_nextReturnScanTime; // +0x4C
};
enum
{
	AI_GUARD_GET_CRATE = 5004
};
#define PATHFIND_CELL_SIZE_F 10.0f
#define STATE_SLEEP(n) ((StateReturnType)(n))
int GetGameLogicRandomValue(int low, int high, char *file, int line);
#define AIGUARD_FILE "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\AI\\AIGuard.cpp"
class AIGuardIdleState : public State
{
public:
	virtual StateReturnType onEnter();
	virtual StateReturnType update();
private:
	AIGuardMachine *getGuardMachine() { return (AIGuardMachine *)getMachine(); }
	unsigned char m_pad1C[0x20 - 0x1C];
	UnsignedInt m_nextEnemyScanTime; // +0x20
	Coord3D m_guardeePos; // +0x24
};
class AIGuardOuterState : public State
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x3C - 0x1C];
	AIAttackState *m_attackState; // +0x3C
};

StateReturnType AIGuardAttackAggressorState::update( void )
{
	if (m_attackState==NULL) return STATE_SUCCESS;
	// if the position has moved (IE we're guarding an object), move with it.
	AIGuardMachine *guard = getGuardMachine();
	Object* targetToGuard = guard->findTargetToGuardByID();
	Team* teamToGuard = guard->findTeamToGuardByID();
	if (targetToGuard)
	{
		m_exitConditions.m_center = *targetToGuard->getPosition();
	}
	else if (teamToGuard)
	{
		teamToGuard->rva0039E5B9(&m_exitConditions.m_center);
	}

	return m_attackState->update();
}

void AIGuardAttackAggressorState::onExit( StateExitType status )
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

void AIGuardOuterState::onExit( StateExitType status )
{
	if (m_attackState)
	{
		m_attackState->onExit(status);
		::delete m_attackState;
		m_attackState = NULL;
	}
}

/*static*/ Real AIGuardMachine::getStdGuardRange(const Object* obj)
{
	Real visionRange = TheAI->getAdjustedVisionRangeForObject(obj,
		AI_VISIONFACTOR_OWNERTYPE | AI_VISIONFACTOR_MOOD | AI_VISIONFACTOR_GUARDINNER);

	return visionRange;
}

StateReturnType AIGuardReturnState::update( void )
{
	Object *obj = getMachineOwner();
	AIUpdateInterface *ai = obj->getAI();
	if (ai && ai->getLocomotorDistanceToGoal() < AIGuardMachine::getStdGuardRange(obj))
	{
		UnsignedInt now = TheGameLogic->getFrame();
		if (now >= m_nextReturnScanTime)
		{
			m_nextReturnScanTime = now + TheAI->getAiData()->m_guardEnemyReturnScanRate;
			if (getGuardMachine()->lookForInnerTarget())
				return STATE_FAILURE; // early termination because we found a target.
		}
	}

	// Just let the return movement finish.
	return AIInternalMoveToState::update();
}

StateReturnType AIGuardIdleState::onEnter( void )
{
	// first time thru, use a random amount so that everyone doesn't scan on the same frame,
	// to avoid "spikes".
	UnsignedInt now = TheGameLogic->getFrame();
	m_nextEnemyScanTime = now + GetGameLogicRandomValue(0, TheAI->getAiData()->m_guardEnemyScanRate, AIGUARD_FILE, 1013);

	return STATE_CONTINUE;
}

StateReturnType AIGuardIdleState::update( void )
{
	UnsignedInt now = TheGameLogic->getFrame();
	if (now < m_nextEnemyScanTime)
		return STATE_SLEEP(m_nextEnemyScanTime - now);

	m_nextEnemyScanTime = now + TheAI->getAiData()->m_guardEnemyScanRate;

	AIGuardMachine *guard = getGuardMachine();
	Object *owner = guard->getOwner();
	AIUpdateInterface *ai = owner->getAI();
	// Check to see if we have created a crate we need to pick up.
	if (ai->getCrateID() != INVALID_ID)
	{
		guard->setState(AI_GUARD_GET_CRATE);
		return STATE_SLEEP(m_nextEnemyScanTime - now);
	}

	// if anyone is in the inner area, return success.
	if (guard->lookForInnerTarget())
	{
		return STATE_SUCCESS;	// Transitions to AIGuardInnerState.
	}

	// See if the object (or team) we are guarding moved.
	Object* targetToGuard = guard->findTargetToGuardByID();
	Team* teamToGuard = guard->findTeamToGuardByID();
	if (targetToGuard || teamToGuard)
	{
		Coord3D pos;
		if (targetToGuard)
			pos = *targetToGuard->getPosition();
		else
			teamToGuard->rva0039E5B9(&pos);
		Real delta = m_guardeePos.x-pos.x;
		if (delta*delta > 4*PATHFIND_CELL_SIZE_F*PATHFIND_CELL_SIZE_F) {
			m_guardeePos = pos;
			return STATE_FAILURE; // goes to AIGuardReturnState.
		}
		delta = m_guardeePos.y-pos.y;
		if (delta*delta > 4*PATHFIND_CELL_SIZE_F*PATHFIND_CELL_SIZE_F) {
			m_guardeePos = pos;
			return STATE_FAILURE; // goes to AIGuardReturnState.
		}
	}
	return STATE_SLEEP(m_nextEnemyScanTime - now);
}
