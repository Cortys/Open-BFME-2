// cl: /O1 /DNDEBUG /MD
//
// Derived AI state onExit overrides chaining to the rowed
// AIInternalMoveToState::onExit 0x003473A4, transferred from Zero Hour
// AIStates.cpp. Each class is identified by its vtable's slot-2 name getter
// (the state's own name literal) and the matching ZH body.
// AIAttackMoveToState::onExit, retail 0x0034A011 (28 bytes): slot 5 of vtable
// 0x00C13548 (name getter 0x00345CFA, AIAttackMoveToState; the same class as
// the placeholder rows Rva00345CAB); m_attackMoveMachine at +0x54 is set to
// AI_IDLE through StateMachine virtual slot 8, then the inherited
// AIMoveToState::onExit (not overridden, so the base 0x003473A4).
// AIFollowWaypointPathState::onExit, retail 0x0034A0D7 (46 bytes): slot 5 of
// vtable 0x00C12930 (name getter 0x00342BF6); base onExit, then clears the
// current locomotor's precise-z flag (bit 3 of Locomotor+0x44, the ZH
// PRECISE_Z_POS position; AI+0x1F0 is the current locomotor). BFME2 drops the
// ZH setUltraAccurate(false) call.
// AIAttackFollowWaypointPathState::onEnter/onExit, retail 0x0034F1C4 (29
// bytes) and 0x0034A19F (28 bytes): slots 4/5 of vtable 0x00C13638 (name getter
// AIAttackFollowWaypointPathState, a class BFME1 rows by ctor, dtor and
// update); m_attackFollowMachine at +0x68 (BFME1 +0x6C) is cleared and set to
// AI_IDLE before the base onEnter (pinned 0x0034ED7B, tail jump), and set to
// AI_IDLE before the base onExit, as Zero Hour AIAttackMoveToState does with
// its attack-move machine. Machine slots 5/8 are clear/setState.
enum StateExitType
{
	EXIT_NORMAL = 0
};
enum StateReturnType
{
	STATE_CONTINUE = 0
};
typedef unsigned int StateID;
enum
{
	AI_IDLE = 0
};
class Locomotor
{
public:
	enum LocoFlag
	{
		PRECISE_Z_POS = 3
	};
	void setUsePreciseZPos(bool u) { setFlag(PRECISE_Z_POS, u); }
private:
	void setFlag(LocoFlag f, bool b)
	{
		if (b)
			m_flags |= (1 << f);
		else
			m_flags &= ~(1 << f);
	}
	unsigned char m_pad00[0x44];
	unsigned int m_flags; // +0x44
};
class AIUpdateInterface
{
public:
	Locomotor *getCurLocomotor() { return m_curLocomotor; }
private:
	unsigned char m_pad000[0x1F0];
	Locomotor *m_curLocomotor; // +0x1F0
};
class Object
{
public:
	AIUpdateInterface *getAI() { return m_ai; }
private:
	unsigned char m_pad000[0x258];
	AIUpdateInterface *m_ai; // +0x258
};
class StateMachine
{
public:
	virtual ~StateMachine();
	virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04();
	virtual void clear();
	virtual void slot06();
	virtual void slot07();
	virtual StateReturnType setState(StateID newStateID);
	Object *getOwner() const { return m_owner; }
private:
	unsigned char m_pad04[0x14 - 0x04];
	Object *m_owner; // +0x14
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
protected:
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
};
class AIAttackMoveToState : public AIMoveToState
{
public:
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x54 - 0x1C];
	StateMachine *m_attackMoveMachine; // +0x54
};
void AIAttackMoveToState::onExit(StateExitType status)
{
	m_attackMoveMachine->setState(AI_IDLE);
	AIMoveToState::onExit(status);
}
class AIFollowWaypointPathState : public AIInternalMoveToState
{
public:
	virtual StateReturnType onEnter();
	virtual void onExit(StateExitType status);
};
void AIFollowWaypointPathState::onExit(StateExitType status)
{
	AIInternalMoveToState::onExit(status);

	// turn off precision-z-pos when we exit, just in case.
	AIUpdateInterface *ai = getMachineOwner()->getAI();
	if (ai && ai->getCurLocomotor())
		ai->getCurLocomotor()->setUsePreciseZPos(false);
}
class AIAttackFollowWaypointPathState : public AIFollowWaypointPathState
{
public:
	virtual StateReturnType onEnter();
	virtual void onExit(StateExitType status);
private:
	unsigned char m_pad1C[0x68 - 0x1C];
	StateMachine *m_attackFollowMachine; // +0x68
};
StateReturnType AIAttackFollowWaypointPathState::onEnter()
{
	m_attackFollowMachine->clear();
	m_attackFollowMachine->setState(AI_IDLE);
	return AIFollowWaypointPathState::onEnter();
}
void AIAttackFollowWaypointPathState::onExit(StateExitType status)
{
	m_attackFollowMachine->setState(AI_IDLE);
	AIFollowWaypointPathState::onExit(status);
}
