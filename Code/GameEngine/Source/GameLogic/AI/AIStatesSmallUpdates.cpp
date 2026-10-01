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
// AIUpdateInterface: vslot 136 (+0x220) is called on a dead owner's AI.
class AIUpdateInterface : public AIDeadStateAISlots<136>
{
public:
	virtual void rva0033FF05Slot136() = 0;
	void setCanPathThroughUnits(Bool b) { m_canPathThroughUnits = b; }
private:
	unsigned char m_pad004[0x3BA - 0x04];
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
	virtual StateReturnType update();
};
class AIFollowWaypointPathExactState : public AIInternalMoveToState
{
public:
	virtual StateReturnType update();
};
StateReturnType AIFollowWaypointPathExactState::update()
{
	AIUpdateInterface *ai = getMachineOwner()->getAI();
	if (ai)
		ai->setCanPathThroughUnits(true);
	return AIInternalMoveToState::update();
}
