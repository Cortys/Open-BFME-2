// ?onEnter@AIFollowPathState@@UAE?AW4StateReturnType@@XZ
// partial score=0.95 date=2026-10-04
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// AIFollowPathState::onEnter, retail 0x0034DEF8 (396 bytes): slot 4 of vtable
// 0x00C12BC8, whose slot-2 name getter returns AIFollowPathState. Ported from
// Zero Hour's GameEngine/Source/GameLogic/AI/AIStates.cpp (GeneralsMD tree
// vendored under reference/open-bfme-1/inputs/reference). BFME 2 drops ZH's
// formation-group speed block, and each setAdjustsDestination carries its own
// CritterDesync log line under the global log flag.
// Callees: the goal-path lookups go through the AI's state machine (+0x30) to
// the pinned AIStateMachine::getGoalPathPosition 0x00346FA5 (ZH bounds check
// over the +0x3C Coord3D vector), and setPathExtraDistance is the pinned
// out-of-line Real setter 0x002633F3.
// Layout: AI +0x258 with goal path index +0x194, current locomotor +0x1F0
// (flags +0x44, PRECISE_Z_POS bit 3) and can-path-through-units +0x3BA;
// state id +4 (AI_FOLLOW_EXITPRODUCTION_PATH 7), goal +0x20,
// adjusts-destination +0x48, m_index +0x4C, m_adjustFinal +0x50; the
// PROJECTILE kind bit is the owner template's byte +0x10B mask 0x02.
typedef bool Bool;
typedef float Real;
typedef int Int;
typedef unsigned int UnsignedInt;
typedef UnsignedInt StateID;
#define NULL 0
#define PATHFIND_CELL_SIZE_F 10.0f
enum
{
	AI_FOLLOW_EXITPRODUCTION_PATH = 7
};
enum StateExitType
{
	EXIT_NORMAL = 0
};
enum StateReturnType
{
	STATE_CONTINUE = 0,
	STATE_FAILURE = -2
};
struct Coord3D
{
	Real x, y, z;
};
struct Coord2D
{
	Real x, y;
	Real length() const;
};
struct FprintfTarget
{
	char m_pad[4];
};
extern "C" void fprintf(FprintfTarget *target, const char *format, ...);
extern unsigned char g_00E03745;
extern void *g_00DFEFF0;
#define CRITTER_LOG(msg) \
	if (g_00E03745) \
	{ \
		FprintfTarget *log = (FprintfTarget *)g_00DFEFF0; \
		if (log) \
			fprintf msg; \
	}
class Locomotor
{
public:
	enum LocoFlag
	{
		IS_BRAKING = 0,
		ALLOW_INVALID_POSITION,
		MAINTAIN_POS_IS_VALID,
		PRECISE_Z_POS
	};
	void setUsePreciseZPos(Bool b)
	{
		if (b)
			m_flags |= (1 << PRECISE_Z_POS);
		else
			m_flags &= ~(1 << PRECISE_Z_POS);
	}
private:
	unsigned char m_pad00[0x44];
	unsigned int m_flags; // +0x44
};
class AIStateMachine
{
public:
	const Coord3D *getGoalPathPosition(Int i) const;
};
class AIUpdateInterface
{
public:
	AIStateMachine *getStateMachine() const { return m_stateMachine; }
	const Coord3D *friend_getGoalPathPosition(Int index) const { return getStateMachine()->getGoalPathPosition(index); }
	void friend_setCurrentGoalPathIndex(Int index) { m_currentGoalPathIndex = index; }
	void setCanPathThroughUnits(Bool b) { m_canPathThroughUnits = b; }
	Locomotor *getCurLocomotor() { return m_curLocomotor; }
	void setPathExtraDistance(Real dist);
private:
	unsigned char m_pad000[0x30];
	AIStateMachine *m_stateMachine; // +0x30
	unsigned char m_pad034[0x194 - 0x34];
	Int m_currentGoalPathIndex; // +0x194
	unsigned char m_pad198[0x1F0 - 0x198];
	Locomotor *m_curLocomotor; // +0x1F0
	unsigned char m_pad1F4[0x3BA - 0x1F4];
	Bool m_canPathThroughUnits; // +0x3BA
};
class ThingTemplate
{
public:
	Bool isKindOfProjectile() const { return (m_kindOf[3] & 0x02) != 0; }
private:
	unsigned char m_pad00[0x108];
	unsigned char m_kindOf[4]; // +0x108 (PROJECTILE: byte +0x10B mask 0x02)
};
class Object
{
public:
	AIUpdateInterface *getAI() { return m_ai; }
	Bool isKindOfProjectile() const { return m_template->isKindOfProjectile(); }
private:
	unsigned char m_pad00[0x04];
	const ThingTemplate *m_template; // +0x04
	unsigned char m_pad08[0x258 - 0x08];
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
	StateID getID() const { return m_ID; }
protected:
	Object *getMachineOwner() const { return m_machine->getOwner(); }
	StateID m_ID; // +0x04
	unsigned char m_pad08[0x18 - 0x08];
	StateMachine *m_machine; // +0x18
};
class AIInternalMoveToState : public State
{
public:
	virtual StateReturnType onEnter();
protected:
	unsigned char m_pad1C[0x20 - 0x1C];
	Coord3D m_goalPosition; // +0x20
	unsigned char m_pad2C[0x48 - 0x2C];
	Bool m_adjustsDestination; // +0x48
};
class AIFollowPathState : public AIInternalMoveToState
{
public:
	virtual StateReturnType onEnter();
private:
	Int m_index; // +0x4C
	Bool m_adjustFinal; // +0x50
};

StateReturnType AIFollowPathState::onEnter()
{
	Object *obj = getMachineOwner();
	AIUpdateInterface *ai = obj->getAI();

	m_index = 0;
	const Coord3D *pos = ai->friend_getGoalPathPosition( 0 );

	if (pos == NULL)
		return STATE_FAILURE;

	// set initial movement goal
	m_goalPosition = *pos;
	const Coord3D *nextPos = ai->friend_getGoalPathPosition( 1 );
	m_adjustFinal = true;

	//Assign this value to the AIUpdateInterface so object's can access this value while
	//determine which waypoints to plot in the waypoint renderer.
	ai->friend_setCurrentGoalPathIndex( 0 );

	if (getID() == AI_FOLLOW_EXITPRODUCTION_PATH) {
		ai->setCanPathThroughUnits(true);
		CRITTER_LOG((log, "CritterDesync: setAdjustDestination(FALSE) 39"));
		m_adjustsDestination = false;
		m_adjustFinal = true;
	}
	StateReturnType ret = AIInternalMoveToState::onEnter();
	if (nextPos)
	{
		Coord2D delta;
		delta.x = nextPos->x - pos->x;
		delta.y = nextPos->y - pos->y;
		Real offset = delta.length();
		const Coord3D *followingPos = ai->friend_getGoalPathPosition( m_index+2 );
		if (followingPos) offset += 4*PATHFIND_CELL_SIZE_F;
		ai->setPathExtraDistance(offset);
		// We are in the middle of a path, so don't set the final goal location yet.
		CRITTER_LOG((log, "CritterDesync: setAdjustDestination(FALSE) 40"));
		m_adjustsDestination = false;
	}
	else
	{
		CRITTER_LOG((log, "CritterDesync: setAdjustDestination(m_adjustFinal=%s) 41", m_adjustFinal ? "TRUE" : "FALSE"));
		m_adjustsDestination = m_adjustFinal;
		ai->setPathExtraDistance(0);

		// urg. hacky. if we are a projectile on the last segment, turn on precise z-pos.
		if (obj->isKindOfProjectile())
		{
			if (ai && ai->getCurLocomotor())
				ai->getCurLocomotor()->setUsePreciseZPos(true);
		}
	}
	return ret;
}
