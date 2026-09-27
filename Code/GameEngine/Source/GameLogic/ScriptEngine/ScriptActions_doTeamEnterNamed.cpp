// cl: /O1 /DNDEBUG /MD /EHsc
//
// ScriptActions::doTeamEnterNamed, retail 0x003BEF8D, 109 bytes.
// Target identity: initActionTemplates index 0x36 (54) is TEAM_ENTER_NAMED;
// executeAction case 0x36 calls VA 0x007BEF8D. Target resolves the team through
// getTeamNamed at 0x3584E9, resolves the destination through the opaque
// by-value name helper at 0x358752, creates/fills an AIGroup, then calls pinned
// AIGroup::groupEnter at 0x370198 with the destination and command source 1.
// Donor facts: BFME1 ScriptActions.cpp maps this action to doTeamEnterNamed
// and performs the same team/destination/group-entry sequence. The destination
// lookup helper keeps its address-derived name because its exact identity is
// unresolved; the group-enter identity is supported independently by target
// ABI and donor semantics.

template<class T>
class StringBase
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

class Object;
class Team;
enum CommandSourceType { CMD_FROM_SCRIPT = 1 };

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool);
};

class Rva00358752Opaque
{
public:
    Object *lookupUnitByValue(AsciiString);
};

class AIGroup
{
public:
    void groupEnter(Object *, CommandSourceType);
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
    void doTeamEnterNamed(const AsciiString &, const AsciiString &);
};

void ScriptActions::doTeamEnterNamed(const AsciiString &teamName,
                                     const AsciiString &unitDestName)
{
    Team *theSrcTeam = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed(teamName, false);
    if (!theSrcTeam) {
        return;
    }
    Object *theTransport = ((Rva00358752Opaque *)*(ScriptEngine **)0x00DFE16C)
        ->lookupUnitByValue(unitDestName);
    if (!theTransport) {
        return;
    }
    AIGroup *theGroup = (*(AI **)0x00DFF0F8)->createGroup();
    theSrcTeam->getTeamAsAIGroup(theGroup);
    theGroup->groupEnter(theTransport, CMD_FROM_SCRIPT);
}
