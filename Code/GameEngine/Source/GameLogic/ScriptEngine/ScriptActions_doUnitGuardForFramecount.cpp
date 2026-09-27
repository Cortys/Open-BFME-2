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

class ScriptActions
{
protected:
	void doUnitGuardForFramecount(const AsciiString &unitName, int framecount, bool seconds);
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
