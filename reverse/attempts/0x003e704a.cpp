// ?evaluateTeamExitedAreaPartially@ScriptConditions@@IAE_NPAVParameter@@00@Z
// partial score=0.88 date=2026-09-27
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// BFME1 donor: ScriptConditions_evaluateTeamEnteredExitedArea.cpp.
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
class Team { public: bool didPartialExit(PolygonTrigger *, unsigned int); };
class ScriptEngine
{ public: Team *getTeamNamed(AsciiString, bool); PolygonTrigger *getQualifiedTriggerAreaByName(AsciiString); };
class ScriptConditions
{ protected: bool evaluateTeamExitedAreaPartially(Parameter *, Parameter *, Parameter *); };
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
bool ScriptConditions::evaluateTeamExitedAreaPartially(Parameter *teamParm, Parameter *triggerParm, Parameter *typeParm)
{
    Team *team = TheScriptEngine->getTeamNamed(teamParm->getString(), false);
    PolygonTrigger *trigger = TheScriptEngine->getQualifiedTriggerAreaByName(triggerParm->getString());
    if (!team || !trigger)
        return false;
    return team->didPartialExit(trigger, (unsigned int)typeParm->m_int);
}
