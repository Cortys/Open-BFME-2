// cl: /O1 /DNDEBUG /MD /EHsc
//
// ScriptActions::doTeamAttackNamed, retail 0x003C3B7D, 141 bytes.
// Target identity: initActionTemplates index 0x33 (51) is TEAM_ATTACK_NAMED;
// executeAction case 0x33 calls VA 0x007C3B7D. The target resolves a team,
// resolves its victim, creates/fills an AIGroup, then calls StringBase compare
// at 0x69B1 against target string xref "Aragorn 2" and emits a special player
// attack before the normal script attack. Target direct calls and helper pins
// support the Team/AIGroup operations.
// Donor facts: BFME1 ScriptActions_doTeamAttackNamed_Thunk.cpp and Zero Hour
// source document the same one-off Aragorn 2 player-source command followed by
// the unconditional script-source groupAttackObject call.

typedef int Int;
typedef bool Bool;

class Object;
class Team;

class StringBaseChar
{
public:
    int compare(const char *) const;
};

template<class T>
class StringBase
{
    friend class AsciiString;
    StringBase(const StringBase &);
public:
    int compare(const T *) const;
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
    int compare(const char *s) const
    {
        return ((const StringBase<char> *)this)->compare(s);
    }
private:
    char *m_text;
};

enum CommandSourceType
{
    CMD_FROM_PLAYER = 0,
    CMD_FROM_SCRIPT = 1
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool);
    Object *getUnitNamed(const AsciiString &);
};

class AIGroup
{
private:
    void groupAttackObjectPrivate(bool, Object *, Int, CommandSourceType);
public:
    void groupAttackObject(Object *victim, Int maxShotsToFire,
                           CommandSourceType cmdSource)
    {
        groupAttackObjectPrivate(false, victim, maxShotsToFire, cmdSource);
    }
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
    void doTeamAttackNamed(const AsciiString &, const AsciiString &);
};

void ScriptActions::doTeamAttackNamed(const AsciiString &teamName,
                                      const AsciiString &unitName)
{
    Team *theTeam = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed(teamName, false);
    if (!theTeam) {
        return;
    }
    Object *theVictim = (*(ScriptEngine **)0x00DFE16C)->getUnitNamed(unitName);
    if (!theVictim) {
        return;
    }
    AIGroup *theGroup = (*(AI **)0x00DFF0F8)->createGroup();
    if (!theGroup) {
        return;
    }
    theTeam->getTeamAsAIGroup(theGroup);
    if (teamName.compare("Aragorn 2") == 0) {
        theGroup->groupAttackObject(theVictim, 0x7fffffff, CMD_FROM_PLAYER);
    }
    theGroup->groupAttackObject(theVictim, 0x7fffffff, CMD_FROM_SCRIPT);
}
