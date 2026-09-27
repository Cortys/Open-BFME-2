// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// Retail RVA 0x003C9298, 121 bytes.
// ?doUnitGuardForFramecount@ScriptActions@@IAEXABVAsciiString@@H_N@Z
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptActionsUnitGuardForFramecount.cpp
// doUnitGuardForFramecount at AICMD 0x1E via rowed aiGuardPosition 0x0036F46A plus inline free at 0x30830.
// BFME2 deltas: float Coord3D with SSE movss order x y z (no barrier) plus the 0xC0 block via opaque 0x351BD0 ctor.
// Factor at 0x00DBA4E4 is 5 from the data image; TheScriptEngine at 0x00DFE16C.
// Callers at 0x003CE24E. Prev doNamedFollowWaypointsExact / next doNamedFaceNamed. Honest GuardMode Int layout.
template<class T> class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase &);
};
class AsciiString
{
public:
	AsciiString(const AsciiString &that)
	{
		((StringBase<char> *)this)->StringBase<char>::StringBase(
			*(const StringBase<char> *)&that);
	}
	~AsciiString();
private:
	char *m_text;
};

struct Coord3D { float x, y, z; };
class Object;
class Waypoint
{
public:
	const Coord3D *location() const { return (const Coord3D *)((const char *)this + 0x0c); }
};
enum GuardMode { GUARDMODE_NORMAL = 0 };
enum CommandSourceType { CMD_FROM_SCRIPT = 1 };

class AICommandInterface
{
public:
	void aiGuardPosition(const Coord3D *pos, GuardMode guardMode, CommandSourceType cmdSource);
};

class AIUpdateInterface
{
public:
	char m_pad00[0x20];
	AICommandInterface m_command;
};

class Object
{
public:
	AIUpdateInterface *getAIUpdateInterface()
	{
		return *(AIUpdateInterface **)((char *)this + 0x258);
	}
	void leaveGroup();
private:
	char m_pad00[0x38];
public:
	Coord3D m_position;
private:
	char m_pad01[0x258 - 0x44];
};

class ScriptEngine
{
public:
	Object *getUnitNamed(const AsciiString &name);
	void setSequentialTimer(Object *obj, int frames);
};

class TerrainLogicByValue
{
public:
	virtual void _0()=0; virtual void _1()=0; virtual void _2()=0; virtual void _3()=0;
	virtual void _4()=0; virtual void _5()=0; virtual void _6()=0; virtual void _7()=0;
	virtual void _8()=0; virtual void _9()=0; virtual void _10()=0; virtual void _11()=0;
	virtual void _12()=0; virtual void _13()=0; virtual void _14()=0; virtual void _15()=0;
	virtual void _16()=0; virtual void _17()=0; virtual void _18()=0; virtual void _19()=0;
	virtual void _20()=0; virtual void _21()=0; virtual void _22()=0; virtual void _23()=0;
	virtual void _24()=0; virtual void _25()=0; virtual void _26()=0; virtual void _27()=0;
	virtual void _28()=0; virtual void _29()=0; virtual void _30()=0; virtual void _31()=0;
	virtual void _32()=0; virtual void _33()=0;
	virtual Waypoint *getWaypointByName(const AsciiString &) = 0;
};

class ScriptActions
{
protected:
	void doUnitGuardForFramecount(const AsciiString &unitName, int framecount, bool seconds);
	void doUnitGuardPosition(const AsciiString &unitName, const AsciiString &waypointName);
	void doNamedGuard(const AsciiString &unitName);
};

void ScriptActions::doUnitGuardForFramecount(const AsciiString &unitName, int framecount, bool seconds)
{
	Object *object = (*(ScriptEngine **)0x00DFE16C)->getUnitNamed(unitName);
	if (!object)
		return;
	AIUpdateInterface *ai = object->getAIUpdateInterface();
	if (!ai)
		return;
	Coord3D position;
	position.x = object->m_position.x;
	position.y = object->m_position.y;
	position.z = object->m_position.z;
	ai->m_command.aiGuardPosition(&position, GUARDMODE_NORMAL, CMD_FROM_SCRIPT);
	if (seconds)
		(*(ScriptEngine **)0x00DFE16C)->setSequentialTimer(object, framecount * *(int *)0x00DBA4E4);
	else
		(*(ScriptEngine **)0x00DFE16C)->setSequentialTimer(object, framecount);
}

// ?doUnitGuardPosition@ScriptActions@@IAEXABVAsciiString@@0@Z, retail 0x003C8964, 109 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptActions_doUnitGuardPosition.cpp
// doUnitGuardPosition at AICMD 0x1E via rowed aiGuardPosition 0x0036F46A.
// BFME2 deltas: float Coord3D with SSE movss from Waypoint+0x0C plus TheTerrainLogic slot 0x88.
// Caller at 0x003CB676. Prev doNamedFollowWaypointsExact / next doUnitGuardForFramecount.
void ScriptActions::doUnitGuardPosition(const AsciiString &unitName, const AsciiString &waypointName)
{
	Waypoint *way = (*(TerrainLogicByValue **)0x00DFEC50)->getWaypointByName(waypointName);
	Object *object = (*(ScriptEngine **)0x00DFE16C)->getUnitNamed(unitName);
	if (!object)
		return;
	AIUpdateInterface *ai = object->getAIUpdateInterface();
	if (!ai)
		return;
	if (!way)
		return;
	Coord3D position;
	position.x = way->location()->x;
	position.y = way->location()->y;
	position.z = way->location()->z;
	ai->m_command.aiGuardPosition(&position, GUARDMODE_NORMAL, CMD_FROM_SCRIPT);
}

// ?doNamedGuard@ScriptActions@@IAEXABVAsciiString@@@Z, retail 0x003C886A, 97 bytes.
// BFME1 donor reference/open-bfme-1/Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptActionsNamedUnitProperties.cpp
// doNamedGuard at AICMD 0x1E via rowed aiGuardPosition 0x0036F46A plus pinned leaveGroup 0x0028C01F.
// BFME2 deltas: float Coord3D with SSE movss order x y z from Object+0x38 (no Int barrier).
// Caller at 0x003CB585. Prev doNamedFollowWaypointsExact / next doUnitGuardPosition.
void ScriptActions::doNamedGuard(const AsciiString &unitName)
{
	Object *object = (*(ScriptEngine **)0x00DFE16C)->getUnitNamed(unitName);
	if (!object)
		return;
	AIUpdateInterface *ai = object->getAIUpdateInterface();
	if (!ai)
		return;
	object->leaveGroup();
	Coord3D position;
	position.x = object->m_position.x;
	position.y = object->m_position.y;
	position.z = object->m_position.z;
	ai->m_command.aiGuardPosition(&position, GUARDMODE_NORMAL, CMD_FROM_SCRIPT);
}
