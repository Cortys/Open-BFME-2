// ?rva003C9E4E@ScriptActions@@IAEXABVAsciiString@@0@Z
// partial score=0.99 date=2026-09-29
// ?rva003C9E4E@ScriptActions@@IAEXABVAsciiString@@0@Z
// partial score=0.99 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// Retail RVA 0x003C9E4E, 253 bytes.
// ?rva003C9E4E@ScriptActions@@IAEXABVAsciiString@@0@Z
// Honest address name: two-team ScriptActions method dispatched from FUN_007ca4be
// (caller at 0x003CE58F), no BFME1 donor found. Target evidence: two rowed
// getTeamNamed pin calls 0x003584E9, rowed iterate 0x00263864, rowed advance
// 0x00263526, rowed rva0036F19B 0x0036F19B (AICMD 0x13 object command).
// First loop selects the minimum-float member of the second team via the
// +0x254 float interface (slot +0x14); second loop issues rva0036F19B with
// that target to qualified members of the first team. Prev doTeamFaceWaypoint
// shares flags and the team-iterator model.
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
struct Coord3D { float x, y, z; };
class Object;
class Team;
enum CommandSourceType { CMD_FROM_SCRIPT = 1 };
template<class OBJCLASS> class DLINK_ITERATOR
{
private:
    OBJCLASS *m_cur;
    unsigned char m_targetAbiState[20];
public:
    void advance();
    Bool done() const { return !m_cur; }
    OBJCLASS *cur() const { return m_cur; }
};
struct ObjectFlags
{
    char m_pad[0x108];
    unsigned char m_flag108;
    unsigned char m_flag109;
};
class FloatIface14
{
public:
    virtual void _0() = 0;
    virtual void _1() = 0;
    virtual void _2() = 0;
    virtual void _3() = 0;
    virtual void _4() = 0;
    virtual float getFloat14() = 0;
};
class AICommandInterface
{
public:
    void rva0036F19B(Object *target, CommandSourceType cmdSource);
};
class AIUpdateInterface
{
public:
    char pad[0x20];
    AICommandInterface command;
};
class Object
{
public:
    char m_pad0[4];
    ObjectFlags *m_flags;
    char m_pad8[0x38 - 8];
    Coord3D m_position;
    char m_pad44[0x254 - 0x44];
    FloatIface14 *m_unk254;
    AIUpdateInterface *m_ai;
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
    void rva003C9E4E(const AsciiString &, const AsciiString &);
};
extern ScriptEngine *TheScriptEngine;
extern float g_Va00BBB8D8;
// ?rva003C9E4E@ScriptActions@@IAEXABVAsciiString@@0@Z present-unmatched
void ScriptActions::rva003C9E4E(const AsciiString &teamAName, const AsciiString &teamBName)
{
    Team *teamA = TheScriptEngine->getTeamNamed((AsciiString &)teamAName, false);
    Team *teamB = TheScriptEngine->getTeamNamed((AsciiString &)teamBName, false);
    float best;
    Object *bestObj;
    if (!teamA)
        return;
    best = g_Va00BBB8D8;
    bestObj = 0;
    {
        DLINK_ITERATOR<Object> iter = teamB->iterate_TeamMemberList();
        while (!iter.done()) {
            Object *obj = iter.cur();
            if (obj->m_flags->m_flag108 & 0x80) {
                FloatIface14 *iface = obj->m_unk254;
                if (iface && iface->getFloat14() < best) {
                    bestObj = obj;
                    best = iface->getFloat14();
                }
            }
            iter.advance();
        }
    }
    if (!bestObj)
        return;
    {
        DLINK_ITERATOR<Object> iter = teamA->iterate_TeamMemberList();
        while (!iter.done()) {
            Object *obj = iter.cur();
            if (obj->m_flags->m_flag109 & 0x40) {
                AIUpdateInterface *ai = obj->m_ai;
                if (ai)
                    ai->command.rva0036F19B(bestObj, CMD_FROM_SCRIPT);
            }
            iter.advance();
        }
    }
}
