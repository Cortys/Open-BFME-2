// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ScriptActions::doNamedAttackTeam, retail 0x003C841F, 99 bytes.
// Target identity: initActionTemplates index 0x31 (49) is NAMED_ATTACK_TEAM;
// executeAction case 0x31 calls VA 0x007C841F. Target resolves the named unit
// and team through pinned lookup routines, reads AIUpdateInterface at Object+
// 0x258, leaves the prior group, then calls pinned aiAttackTeam through the
// command subobject at +0x20 with max shots 0x7FFFFFFF and source 1.
// Donor facts: BFME1 ScriptActions.cpp identifies doNamedAttackTeam and uses
// the same validation, leaveGroup, and aiAttackTeam sequence. The target body
// contains no separate chooseLocomotorSet call, so this follows target bytes.

// The donor AsciiString stores one StringBase<char> pointer. The inline copy
// constructor is carried locally so this handler uses the matched retail
// StringBase copy routine without depending on broader headers.
#include "ascii_string.h"


class Team;
class Object;
enum CommandSourceType { CMD_FROM_SCRIPT = 1 };

class AICommandInterface
{
public:
    void aiAttackTeam(const Team *, int, CommandSourceType);
};

class AIUpdateInterface
{
public:
    char m_pad00[0x20];
    AICommandInterface m_commandInterface;
};

class ScriptEngine
{
public:
    Object *getUnitNamed(const AsciiString &);
    Team *getTeamNamed(AsciiString, bool = false);
};
extern ScriptEngine *TheScriptEngine;

class Object
{
public:
    void leaveGroup();
    // Retail-measured AIUpdate at +0x258; direct member so this TU emits
    // no COMDAT copy of Object::getAIUpdateInterface, whose kept copy
    // (e.g. Player.cpp via ZH Object.h) reads +0x19C and differs.
    unsigned char m_pad[0x258];
    AIUpdateInterface *m_aiUpdate; // +0x258
};

class ScriptActions
{
protected:
    void doNamedAttackTeam(const AsciiString &, const AsciiString &);
};

void ScriptActions::doNamedAttackTeam(const AsciiString &unitName, const AsciiString &teamName)
{
    Object *theSrcUnit = TheScriptEngine->getUnitNamed(unitName);
    if (!theSrcUnit) {
        return;
    }
    const Team *theTeam = TheScriptEngine->getTeamNamed(teamName);
    if (!theTeam) {
        return;
    }
    AIUpdateInterface *aiUpdate = theSrcUnit->m_aiUpdate;
    if (!aiUpdate) {
        return;
    }
    theSrcUnit->leaveGroup();
    aiUpdate->m_commandInterface.aiAttackTeam(theTeam, 0x7fffffff, CMD_FROM_SCRIPT);
}
