// ?rva003C05DE@ScriptActions@@IAEXABVAsciiString@@_N@Z
// partial score=0.97 date=2026-09-28
// ?rva003C05DE@ScriptActions@@IAEXABVAsciiString@@_N@Z
// partial score=0.97 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc
// Retail RVA 0x003C05DE, 79 bytes.
// ?rva003C05DE@ScriptActions@@IAEXABVAsciiString@@_N@Z
// Honest address name: ScriptActions team method dispatched from FUN_007ca4be
// (caller at 0x003CBE04). Target evidence: getTeamNamed pin 0x003584E9 with
// the by-value AsciiString temp pattern, rowed iterate 0x00263864, rowed
// advance 0x00263526, rowed setScriptStatus 0x00292969 fed with bit 0x20 and
// the bool parameter on every member. Prev doTeamExitAll shares flags;
// doTeamFaceWaypoint shares the team-iterator model.
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

enum ObjectScriptStatusBit
{
    OBJECT_STATUS_SCRIPT_BIT_0x20 = 0x20
};

class Object
{
public:
    void setScriptStatus(ObjectScriptStatusBit bit, Bool set);
};

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

class Team
{
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
    void rva003C05DE(const AsciiString &, Bool);
};

// ?rva003C05DE@ScriptActions@@IAEXABVAsciiString@@_N@Z present-unmatched
void ScriptActions::rva003C05DE(const AsciiString &teamName, Bool flag)
{
    Team *team = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed((AsciiString &)teamName, false);
    if (!team)
        return;
    DLINK_ITERATOR<Object> iter = team->iterate_TeamMemberList();
    Object *obj;
    while (obj = iter.cur()) {
        obj->setScriptStatus(OBJECT_STATUS_SCRIPT_BIT_0x20, flag);
        iter.advance();
    }
}
