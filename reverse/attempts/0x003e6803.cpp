// ?evaluateTeamCreated@ScriptConditions@@IAEEPAVParameter@@@Z
// partial score=0.9 date=2026-09-26
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// BFME1 donor: evaluateTeamCreated; target reads Team state byte +0x5E.
typedef unsigned char Bool;
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
class Team
{
public:
    Bool isCreated() const { return *(const unsigned char *)((const char *)this + 0x5E); }
};
class ScriptEngine
{ public: Team *getTeamNamed(AsciiString, bool); };
class ScriptConditions
{ protected: Bool evaluateTeamCreated(Parameter *); };
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
Bool ScriptConditions::evaluateTeamCreated(Parameter *teamParm)
{
    Team *team = TheScriptEngine->getTeamNamed(teamParm->getString(), false);
    Bool result = 0;
    if (team)
        result = team->isCreated();
    return result;
}
