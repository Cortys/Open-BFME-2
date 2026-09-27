// ?doTeamEnableStealth@ScriptActions@@IAEXABVAsciiString@@_N@Z
// partial score=0.91 date=2026-09-27
// ?doTeamEnableStealth@ScriptActions@@IAEXABVAsciiString@@_N@Z
// partial score=0.91 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
// ?doTeamEnableStealth@ScriptActions@@IAEXABVAsciiString@@_N@Z @0x003C058A 84B
// Chain from Object::setScriptStatus 0x00292969: team-member loop setting
// UNSTEALTHED bit 8 with !enabled. BFME1 donor ScriptActions.cpp
// doTeamEnableStealth establishes semantics and traversal; sibling
// doTeamFaceWaypoint precedent supplies AsciiString/EH/iterator ABI and flags.
// Caller 0x003CBDB7 in FUN_007ca4be; getTeamNamed pin 0x3584E9 and
// iterate 0x263864 plus advance 0x263526 pins resolve the calls.

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
typedef bool Bool;
class Object;
template<class OBJCLASS> class DLINK_ITERATOR
{
private:
    OBJCLASS *m_cur;
    unsigned char m_targetAbiState[20];
public:
    void advance();
    Bool done() const { return m_cur == 0; }
    OBJCLASS *cur() const { return m_cur; }
};

enum ObjectScriptStatusBit
{
	OBJECT_STATUS_SCRIPT_UNSTEALTHED = 0x08
};

class Object
{
public:
    void setScriptStatus( ObjectScriptStatusBit bit, Bool set );
};

class Team
{
    void *m_vptr;
    void *m_prototype;
    void *m_id;
    Object *m_head;
public:
    DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
};
class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, Bool);
};
class ScriptActions
{
protected:
    void doTeamEnableStealth(const AsciiString &, Bool);
};
extern ScriptEngine *TheScriptEngine;

// ?doTeamEnableStealth@ScriptActions@@IAEXABVAsciiString@@_N@Z present-unmatched
void ScriptActions::doTeamEnableStealth(const AsciiString &teamName, Bool enabled)
{
    Team *team = TheScriptEngine->getTeamNamed((AsciiString &)teamName, false);
    if (!team) return;
    for (DLINK_ITERATOR<Object> iter = team->iterate_TeamMemberList(); !iter.done(); iter.advance()) {
        iter.cur()->setScriptStatus(OBJECT_STATUS_SCRIPT_UNSTEALTHED, !enabled);
    }
}
