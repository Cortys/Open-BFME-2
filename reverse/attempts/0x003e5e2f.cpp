// ?evaluateTeamCountCompare@ScriptConditions@@IAE_NPAVParameter@@00@Z
// partial score=0.82 date=2026-09-26
// cl: /DNDEBUG /MD /EHsc
// Target adaptation of the BFME1 ScriptConditions::evaluateTeamCountCompare.
// Target boundary 0x003E5E2F (78 bytes): getTeamNamed, then Team's three-arg
// count helper, then a signed comparison of countParm against that result.

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
    int getInt() const { return m_int; }
    unsigned char m_beforeInt[8];
    int m_int;
    float m_real;
    AsciiString m_string;
};

class Team
{
public:
    int countKind(int kind, Bool includeContained, Bool includeDead);
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString name, Bool exact);
};

class ScriptConditions
{
protected:
    Bool evaluateTeamCountCompare(Parameter *, Parameter *, Parameter *);
};

extern ScriptEngine *TheScriptEngine;

Bool ScriptConditions::evaluateTeamCountCompare(
    Parameter *teamParm, Parameter *countParm, Parameter *kindParm)
{
    Team *team = TheScriptEngine->getTeamNamed(
        teamParm->getString(), false);
    if (team) {
        int kind = kindParm->getInt();
        if (countParm->getInt() < team->countKind(kind, false, true)) {
            return true;
        }
        return false;
    }
    return false;
}
