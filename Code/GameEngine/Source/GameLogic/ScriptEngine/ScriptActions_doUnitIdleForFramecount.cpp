// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /arch:SSE
// Retail RVA 0x003C9311, 82 bytes.
// ?doUnitIdleForFramecount@ScriptActions@@IAEXABVAsciiString@@H_N@Z
// BFME1 donor reference/open-bfme-1/game/GameEngine/Source/GameLogic/ScriptEngine/ScriptActions.cpp doUnitIdleForFramecount
// BFME2 deltas: bool seconds param with factor at 0x00DBA4E4 selecting setSequentialTimer frames like doUnitGuardForFramecount sibling.
// Evidence: rowed getUnitNamed 0x003588E7 plus AsciiString pin, rowed aiIdle 0x001E8A38, rowed setSequentialTimer Object overload 0x00203FCF.
// TheScriptEngine at 0x00DFE16C. AIUpdateInterface at Object+0x258 with command at +0x20. Caller at 0x003CE271.
extern int g_Va00DBA4E4;

#include "ascii_string.h"

enum CommandSourceType { CMD_FROM_SCRIPT = 1 };

class AICommandInterface
{
public:
	void aiIdle(CommandSourceType cmdSource);
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
	// Retail-measured AIUpdate at +0x258; direct member so this TU emits
	// no COMDAT copy of Object::getAIUpdateInterface, whose kept copy
	// (e.g. Player.cpp via ZH Object.h) reads +0x19C and differs.
	unsigned char m_pad[0x258];
	AIUpdateInterface *m_aiUpdate; // +0x258
};

class ScriptEngine
{
public:
	Object *getUnitNamed(const AsciiString &name);
	void setSequentialTimer(Object *obj, int frames);
};
extern ScriptEngine *TheScriptEngine;

class ScriptActions
{
protected:
	void doUnitIdleForFramecount(const AsciiString &unitName, int framecount, bool seconds);
};

void ScriptActions::doUnitIdleForFramecount(const AsciiString &unitName, int framecount, bool seconds)
{
	Object *object = TheScriptEngine->getUnitNamed(unitName);
	if (!object)
		return;
	AIUpdateInterface *ai = object->m_aiUpdate;
	if (!ai)
		return;
	ai->m_command.aiIdle(CMD_FROM_SCRIPT);
	if (seconds)
		TheScriptEngine->setSequentialTimer(object, framecount * g_Va00DBA4E4);
	else
		TheScriptEngine->setSequentialTimer(object, framecount);
}
