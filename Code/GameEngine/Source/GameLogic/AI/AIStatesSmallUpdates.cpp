// cl: /O1 /DNDEBUG /MD
//
// AIDeadState::update, retail 0x0033FF05 (38 bytes): slot 6 of vtable
// 0x00C11318, whose slot-2 name getter returns AIDeadState (slot 5 is the
// rowed AIDeadState::onExit). BFME2 body (target evidence): the owner's AI, if
// any, gets AIUpdateInterface vslot 136 (+0x220), then the owner is marked
// effectively dead (pinned Object::setEffectivelyDead) and the state continues.
// AIFollowWaypointPathExactState::update, retail 0x0034A167 (28 bytes): slot 6
// of vtable 0x00C12A08 (name getter AIFollowWaypointPathExactState), the Zero
// Hour body: setCanPathThroughUnits(true) on the AI (byte +0x3BA), then the
// pinned base AIInternalMoveToState::update 0x00347460 (tail jump).
// AIFollowWaypointPathExactState::onExit, retail 0x0034A121 (70 bytes): slot 5
// of vtable 0x00C12A08 (name getter AIFollowWaypointPathExactState), the Zero
// Hour body: base onExit, then if AI and current locomotor, setCompletedWaypoint,
// clear canPathThroughUnits and allowInvalidPosition.
typedef bool Bool;
enum StateExitType
{
	EXIT_NORMAL = 0
};
enum StateReturnType
{
	STATE_CONTINUE = 0
};
template <int N> class AIDeadStateAISlots : public AIDeadStateAISlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class AIDeadStateAISlots<0>
{
};
class Locomotor
{
public:
	enum LocoFlag
	{
		IS_BRAKING = 0,
		ALLOW_INVALID_POSITION,
	};
	void setAllowInvalidPosition(Bool b)
	{
		if (b)
			m_flags |= (1 << ALLOW_INVALID_POSITION);
		else
			m_flags &= ~(1 << ALLOW_INVALID_POSITION);
	}
private:
	unsigned char m_pad00[0x44];
	unsigned int m_flags; // +0x44
};
class Waypoint;
// AIUpdateInterface: vslot 136 (+0x220) is called on a dead owner's AI.
class AIUpdateInterface : public AIDeadStateAISlots<136>
{
public:
	virtual void rva0033FF05Slot136() = 0;
	void setCompletedWaypoint(const Waypoint *wp);
	Locomotor *getCurLocomotor() { return m_curLocomotor; }
	void setCanPathThroughUnits(Bool b) { m_canPathThroughUnits = b; }
private:
	unsigned char m_pad004[0x1F0 - 0x04];
	Locomotor *m_curLocomotor; // +0x1F0
	unsigned char m_pad1F4[0x3BA - 0x1F4];
	Bool m_canPathThroughUnits; // +0x3BA
};
class Object
{
public:
	AIUpdateInterface *getAI() { return m_ai; }
	void setEffectivelyDead(bool dead);
private:
	unsigned char m_pad000[0x258];
	AIUpdateInterface *m_ai; // +0x258
};
class StateMachine
{
public:
	Object *getOwner() const { return m_owner; }
private:
	unsigned char m_pad00[0x14];
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
	virtual StateReturnType update();
protected:
	Object *getMachineOwner() const { return m_machine->getOwner(); }
	unsigned char m_pad04[0x18 - 0x04];
	StateMachine *m_machine; // +0x18
};
class AIDeadState : public State
{
public:
	virtual StateReturnType update();
};
StateReturnType AIDeadState::update()
{
	Object *obj = getMachineOwner();
	AIUpdateInterface *ai = obj->getAI();
	if (ai)
		ai->rva0033FF05Slot136();
	obj->setEffectivelyDead(true);
	return STATE_CONTINUE;
}
class AIInternalMoveToState : public State
{
public:
	virtual void onExit(StateExitType status);
	virtual StateReturnType update();
};
class AIFollowWaypointPathExactState : public AIInternalMoveToState
{
public:
	virtual void onExit(StateExitType status);
	virtual StateReturnType update();
private:
	unsigned char m_padExact[0x4C - sizeof(AIInternalMoveToState)];
	const Waypoint *m_lastWaypoint; // +0x4C
};
void AIFollowWaypointPathExactState::onExit(StateExitType status)
{
	AIInternalMoveToState::onExit(status);

	AIUpdateInterface *ai = getMachineOwner()->getAI();
	if (ai && ai->getCurLocomotor())
	{
		ai->setCompletedWaypoint(m_lastWaypoint);
		ai->setCanPathThroughUnits(false);
		ai->getCurLocomotor()->setAllowInvalidPosition(false);
	}
}
StateReturnType AIFollowWaypointPathExactState::update()
{
	AIUpdateInterface *ai = getMachineOwner()->getAI();
	if (ai)
		ai->setCanPathThroughUnits(true);
	return AIInternalMoveToState::update();
}
