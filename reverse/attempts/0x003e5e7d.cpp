// ?evaluateTeamInsideAreaPartially@ScriptConditions@@IAE_NPAVParameter@@00@Z
// partial score=0.72 date=2026-09-26
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// Target 0x003E5E7D, 130 bytes. Identity follows the target's getTeamNamed,
// trigger-area lookup, then someInsideSomeOutside/allInside short-circuit.
typedef bool Bool;

template <class T> class StringBase
{
    friend class AsciiString;
private:
    StringBase(const StringBase &);
    ~StringBase();
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

class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    unsigned char m_beforeInt[8];
    int m_int;
    float m_real;
    AsciiString m_string;
    unsigned char m_afterString[8];
};

class PolygonTrigger;
class Team
{
public:
    Bool someInsideSomeOutside(PolygonTrigger *, unsigned int);
    Bool allInside(PolygonTrigger *, unsigned int);
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString name, Bool create);
    PolygonTrigger *getQualifiedTriggerAreaByName(AsciiString name);
};

class ScriptConditions
{
protected:
    Bool evaluateTeamInsideAreaPartially(Parameter *, Parameter *, Parameter *);
};

#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)

Bool ScriptConditions::evaluateTeamInsideAreaPartially(
    Parameter *teamParm, Parameter *triggerParm, Parameter *typeParm)
{
    Team *team = TheScriptEngine->getTeamNamed(teamParm->getString(), false);
    AsciiString triggerName = triggerParm->getString();
    PolygonTrigger *trigger = TheScriptEngine->getQualifiedTriggerAreaByName(
        triggerName);
    if (trigger == 0 || team == 0)
        return false;

    const unsigned int type = (unsigned int)typeParm->m_int;
    Bool result = team->someInsideSomeOutside(trigger, type);
    if (!result)
        result = team->allInside(trigger, type);
    return result;
}
