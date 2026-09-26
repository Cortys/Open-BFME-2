// ?evaluateTeamEnteredAreaPartially@ScriptConditions@@IAE_NPAVParameter@@00@Z
// partial score=0.88 date=2026-09-27
// ?evaluateTeamEnteredAreaPartially@ScriptConditions@@IAE_NPAVParameter@@00@Z
// partial score=0.86 date=2026-09-26
// ?evaluateTeamEnteredAreaPartially@ScriptConditions@@IAE_NPAVParameter@@00@Z
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// BFME1 donor: ScriptConditionsTriggerAreas.cpp.
template <class T> class StringBase
{ friend class AsciiString; private: StringBase(const StringBase &); ~StringBase(); };
class AsciiString
{
public:
    AsciiString(const AsciiString &that) { ((StringBase<char> *)this)->StringBase<char>::StringBase(*(const StringBase<char> *)&that); }
    ~AsciiString();
private: char *m_text;
};
class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    unsigned char m_beforeInt[8]; int m_int; float m_real; AsciiString m_string;
    unsigned char m_afterString[8];
};
class PolygonTrigger;
class Team { public: bool didPartialEnter(PolygonTrigger *, unsigned int); };
class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool);
    PolygonTrigger *getQualifiedTriggerAreaByName(AsciiString);
};
class ScriptConditions
{ protected: bool evaluateTeamEnteredAreaPartially(Parameter *, Parameter *, Parameter *); };
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
bool ScriptConditions::evaluateTeamEnteredAreaPartially(Parameter *teamParm, Parameter *triggerParm, Parameter *typeParm)
{
    Team *team = TheScriptEngine->getTeamNamed(teamParm->getString(), false);
    PolygonTrigger *trigger = TheScriptEngine->getQualifiedTriggerAreaByName(triggerParm->getString());
    if (trigger == 0) return false;
    if (team) return team->didPartialEnter(trigger, (unsigned int)typeParm->m_int);
    return false;
}
