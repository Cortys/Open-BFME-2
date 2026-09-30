// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ScriptActions::doTeamExitAll, retail 0x003BEFFA, 75 bytes.
// Target identity: initActionTemplates index 0x38 (56) is TEAM_EXIT_ALL;
// executeAction case 0x38 calls VA 0x007BEFFA. Target resolves the team via
// getTeamNamed at 0x3584E9, creates an AIGroup via 0x2FEC4B, fills it through
// Team::getTeamAsAIGroup at 0x3A0F62, and calls pinned groupEvacuate at
// 0x3702B9 with command source 1.
// Donor facts: BFME1 ScriptActions.cpp maps TEAM_EXIT_ALL to doTeamExitAll and
// performs the same team/group evacuation sequence.

#include "ascii_string.h"


class Team;
enum CommandSourceType { CMD_FROM_SCRIPT = 1 };

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool);
};

class AIGroup
{
public:
    void groupEvacuate(CommandSourceType);
};

class AI
{
public:
    AIGroup *createGroup();
};

class Team
{
public:
    void getTeamAsAIGroup(AIGroup *);
};

class ScriptActions
{
protected:
    void doTeamExitAll(const AsciiString &);
};

void ScriptActions::doTeamExitAll(const AsciiString &teamName)
{
    Team *theTeamOfTransports = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed(teamName, false);
    if (!theTeamOfTransports) {
        return;
    }
    AIGroup *theGroup = (*(AI **)0x00DFF0F8)->createGroup();
    theTeamOfTransports->getTeamAsAIGroup(theGroup);
    theGroup->groupEvacuate(CMD_FROM_SCRIPT);
}
