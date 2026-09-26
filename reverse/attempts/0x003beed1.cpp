// ?doTeamSetRepulsor@ScriptActions@@IAEXABVAsciiString@@_N@Z
// partial score=0.82 date=2026-09-26
// cl: /O1 /Oy- /DNDEBUG /MD /EHsc
//
// ScriptActions::doTeamSetRepulsor, retail 0x003BEED1, 79 bytes.
// Target evidence: initActionTemplates names action index 0xEC (236)
// TEAM_SET_REPULSOR; executeAction's case 0xEC calls VA 0x007BEED1.
// Target body: copies the team name, calls pinned getTeamNamed at 0x3584E9,
// obtains an iterator through the 49-byte function at 0x263864, repeatedly
// sets status 8 on its current object, and advances via matched 0x263526.
// Donor facts: BFME1 ScriptActions.cpp maps this action to doTeamSetRepulsor
// and iterates Team::iterate_TeamMemberList() to set OBJECT_STATUS_REPULSOR.

class AsciiString
{
public:
    AsciiString(const AsciiString &);
private:
    int m_string;
};
class Object;
class Team;

enum ObjectStatusTypes { OBJECT_STATUS_REPULSOR = 8 };

template<class T>
class Rva001705A0DlinkIterator
{
public:
    typedef T *(T::*GetNextFunc)() const;
    Rva001705A0DlinkIterator(T *, GetNextFunc);
    bool done() const { return m_cur == 0; }
    T *cur() const { return m_cur; }
    void advance();
private:
    T *m_cur;
    GetNextFunc m_getNext;
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool = false);
};

class Object
{
public:
    void setStatus(ObjectStatusTypes, bool);
};

class Team
{
public:
    Rva001705A0DlinkIterator<Object> iterate_TeamMemberList() const;
};

class ScriptActions
{
protected:
    void doTeamSetRepulsor(const AsciiString &, bool);
};

void ScriptActions::doTeamSetRepulsor(const AsciiString &teamName, bool repulsor)
{

    Team *theSrcTeam = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed(teamName);
    if (!theSrcTeam) {
        return;
    }
    Rva001705A0DlinkIterator<Object> iter = theSrcTeam->iterate_TeamMemberList();
    Object *obj = iter.cur();
    while (obj) {
        obj->setStatus(OBJECT_STATUS_REPULSOR, repulsor);
        iter.advance();
        obj = iter.cur();
    }
}
