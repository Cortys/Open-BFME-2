// cl: /O1 /DNDEBUG /MD /GX
//
// ?aiForceAttackObject@AICommandInterface@@QAEXPAVObject@@HW4CommandSourceType@@@Z,
// retail 0x0036F05A, 110 bytes, plus
// ?aiAttackPosition@AICommandInterface@@QAEXPBUCoord3D@@HW4CommandSourceType@@@Z,
// retail 0x0029599A, 117 bytes. Dedicated TU for the two SpawnBehavior
// slave-loop callees.
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/
// AICommandInterfaceAttackCommands.cpp, AICommandInterface::aiForceAttackObject
// plus aiAttackPosition): build the parameter block on the stack, drop the
// victim or position plus the shot count into their slots, then aiDoCommand
// at vtable slot 0. BFME2 deltas: the command ids are 0x0C and 0x0E, the
// block constructor is the opaque 0x351BD0 pin (cmd plus source, builds the
// +0x20 coordinate vector among the zeroed slots), and block teardown is an
// inline coordinate-buffer free through the C++-linkage free pinned at
// 0x00030830 (pin note: that decoration is what carries the unwind state).

typedef int Int;
typedef float Real;

struct Coord3D
{
	Real x;
	Real y;
	Real z;
};

class Object;
class Waypoint;
class PolygonTrigger;

enum AICommandType
{
	AICMD_IDLE = 5,
	AICMD_FOLLOW_WAYPOINT_PATH = 0x06,
	AICMD_FORCE_ATTACK_OBJECT = 0x0C,
	AICMD_ATTACK_POSITION = 0x0E,
	AICMD_ATTACK_AREA = 0x23,
	AICMD_FACE_OBJECT = 0x26,
	AICMD_FACE_POSITION = 0x27,
	AICMD_WANDER_IN_PLACE = 0x2C,
	AICMD_BFME_3D = 0x3D
};

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT = 1,
	CMD_FROM_AI = 2
};

void free(void *block);

struct AICommandParms
{
	AICommandParms(AICommandType cmd, CommandSourceType cmdSource);
	~AICommandParms() { if (m_coordsStart) free(m_coordsStart); }

	AICommandType m_cmd; // +0x00
	CommandSourceType m_cmdSource; // +0x04
	Coord3D m_pos; // +0x08
	Object *m_obj; // +0x14
	Object *m_otherObj; // +0x18
	const void *m_team; // +0x1C
	void *m_coordsStart; // +0x20, coordinate vector buffer
	void *m_coordsFinish; // +0x24
	void *m_coordsEnd; // +0x28
	const Waypoint *m_waypoint; // +0x2C
	const void *m_polygon; // +0x30
	Int m_intValue; // +0x34
	char m_tailPad[0xC0 - 0x38]; // +0x38..+0xBF, retail block size
};

class AICommandInterface
{
public:
	virtual void aiDoCommand(const AICommandParms *parms) = 0;

	void aiIdle(CommandSourceType cmdSource);
	void aiForceAttackObject(Object *victim, Int maxShotsToFire, CommandSourceType cmdSource);
	void aiAttackPosition(const Coord3D *pos, Int maxShotsToFire, CommandSourceType cmdSource);
	void aiFacePosition(const Coord3D *pos, Int cmdSource);
	void aiFaceObject(Object *target, CommandSourceType cmdSource);
	void aiWanderInPlace(CommandSourceType cmdSource);
	void rva003C7653(Object *target, CommandSourceType cmdSource);
	void aiBfmeObjectCommand3D(Object *obj, CommandSourceType cmdSource);
	void aiFollowWaypointPath(const Waypoint *waypoint, CommandSourceType cmdSource);
	void aiAttackArea(const PolygonTrigger *areaToGuard, CommandSourceType cmdSource);
};

// ?aiIdle@AICommandInterface@@QAEXW4CommandSourceType@@@Z @0x1E8A38
void AICommandInterface::aiIdle(CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_IDLE, cmdSource);
	aiDoCommand(&parms);
}

// ?aiForceAttackObject@AICommandInterface@@QAEXPAVObject@@HW4CommandSourceType@@@Z @0x36F05A
void AICommandInterface::aiForceAttackObject(Object *victim, Int maxShotsToFire, CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_FORCE_ATTACK_OBJECT, cmdSource);
	parms.m_obj = victim;
	parms.m_intValue = maxShotsToFire;
	aiDoCommand(&parms);
}

// ?aiAttackPosition@AICommandInterface@@QAEXPBUCoord3D@@HW4CommandSourceType@@@Z @0x29599A
void AICommandInterface::aiAttackPosition(const Coord3D *pos, Int maxShotsToFire, CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_ATTACK_POSITION, cmdSource);
	parms.m_pos = *pos;
	parms.m_intValue = maxShotsToFire;
	aiDoCommand(&parms);
}

// ?aiFacePosition@AICommandInterface@@QAEXPBUCoord3D@@H@Z, retail 0x003C7782, 108 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/AICommandInterfaceFaceCommands.cpp
// aiFacePosition at AICMD 0x47 plus m_pos at +0x08 plus slot-0 aiDoCommand.
// BFME2 delta is AICMD 0x27 plus the 0xC0 block via opaque 0x351BD0 ctor plus inline free at 0x30830.
// Callers at 0x003C9A75 and 0x003C9B92 pass Waypoint location plus source 1.
void AICommandInterface::aiFacePosition(const Coord3D *pos, Int cmdSource)
{
	AICommandParms parms(AICMD_FACE_POSITION, (CommandSourceType)cmdSource);
	parms.m_pos = *pos;
	aiDoCommand(&parms);
}

// ?aiFaceObject@AICommandInterface@@QAEXPAVObject@@W4CommandSourceType@@@Z, retail 0x003C771D, 101 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/AICommandInterfaceFaceCommands.cpp
// aiFaceObject at AICMD 0x26 plus m_obj at +0x14 plus slot-0 aiDoCommand.
// BFME2 same id 0x26 plus the 0xC0 block via opaque 0x351BD0 ctor plus inline free at 0x30830.
// Callers at 0x003C9A18 and 0x003C9AFE pass named Object plus source 1.
void AICommandInterface::aiFaceObject(Object *target, CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_FACE_OBJECT, cmdSource);
	parms.m_obj = target;
	aiDoCommand(&parms);
}

// ?aiWanderInPlace@AICommandInterface@@QAEXW4CommandSourceType@@@Z, retail 0x003C7853, 92 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/AICommandInterfaceStandingOrders.cpp
// aiWanderInPlace at AICMD 0x2C with no field store plus slot-0 aiDoCommand.
// BFME2 same id 0x2C plus the 0xC0 block via opaque 0x351BD0 ctor plus inline free at 0x30830.
// Caller at 0x003C8BB3 passes source 1 through AIUpdateInterface+0x20.
void AICommandInterface::aiWanderInPlace(CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_WANDER_IN_PLACE, cmdSource);
	aiDoCommand(&parms);
}

// ?rva003C7653@AICommandInterface@@QAEXPAVObject@@W4CommandSourceType@@@Z, retail 0x003C7653, 101 bytes.
// Same 101B object shape as aiFaceObject in this TU: AICMD 0x49 plus m_obj at +0x14 plus slot-0 aiDoCommand.
// BFME1 has no 0x49 command; class proven by callers through AIUpdateInterface+0x20 with source 1.
// Callers at 0x003C7982 0x003C9666 0x003C999C 0x004BB658 0x005AD79B plus 3 more.
void AICommandInterface::rva003C7653(Object *target, CommandSourceType cmdSource)
{
	AICommandParms parms((AICommandType)0x49, cmdSource);
	parms.m_obj = target;
	aiDoCommand(&parms);
}

// ?aiBfmeObjectCommand3D@AICommandInterface@@QAEXPAVObject@@W4CommandSourceType@@@Z, retail 0x00470447, 101 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/AICommandInterfaceBfmeObjectCommands.cpp
// aiBfmeObjectCommand3D at 0x00240680 with AICMD 0x3D plus m_obj at +0x14 plus slot-0 aiDoCommand.
// BFME2 delta is the 0xC0 block via opaque 0x351BD0 ctor plus inline free at 0x30830.
// Placement is the HordeContain page with caller at 0x00472BB3.
void AICommandInterface::aiBfmeObjectCommand3D(Object *obj, CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_BFME_3D, cmdSource);
	parms.m_obj = obj;
	aiDoCommand(&parms);
}

// retail 0x0036EC82, 101 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/AICommandInterfaceFollowPathCommands.cpp
// aiFollowWaypointPath at AICMD 0x06 plus m_waypoint at +0x2C plus slot-0 aiDoCommand.
// BFME2 delta is the 0xC0 block via opaque 0x351BD0 ctor plus inline free at 0x30830.
// Callers at 0x0036FA44 and 0x003C8767 plus 0x003C928D.
void AICommandInterface::aiFollowWaypointPath(const Waypoint *waypoint, CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_FOLLOW_WAYPOINT_PATH, cmdSource);
	parms.m_waypoint = waypoint;
	aiDoCommand(&parms);
}

// ?aiAttackArea@AICommandInterface@@QAEXPBVPolygonTrigger@@W4CommandSourceType@@@Z, retail 0x0036F136, 101 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/AI/AICommandInterfaceAttackCommands.cpp
// aiAttackArea at AICMD 0x23 plus m_polygon at +0x30 plus slot-0 aiDoCommand.
// BFME2 same id 0x23 plus the 0xC0 block via opaque 0x351BD0 ctor plus inline free at 0x30830.
// Callers at 0x00370543 plus ScriptActions doNamedAttackArea at 0x003C83A1 and doNamedAttackAreaForSeconds at 0x003C83FD.
void AICommandInterface::aiAttackArea(const PolygonTrigger *areaToGuard, CommandSourceType cmdSource)
{
	AICommandParms parms(AICMD_ATTACK_AREA, cmdSource);
	parms.m_polygon = areaToGuard;
	aiDoCommand(&parms);
}
