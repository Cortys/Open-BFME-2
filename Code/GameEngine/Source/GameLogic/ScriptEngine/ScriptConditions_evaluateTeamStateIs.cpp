// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /arch:SSE2 /O1
// ?evaluateTeamStateIs@ScriptConditions@@IAE_NPAVParameter@@0@Z @0x003E859E 66B.
// ZH donor evaluateTeamStateIs; BFME2 asks a Team method (0x003A3717, a
// lookup in the +0x48 container, address-named and pinned from this sole
// call site) instead of comparing getState() with a copied name.
#include "ascii_string.h"
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
    bool rva003A3717(const AsciiString &stateName);
};
class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool);
};
extern ScriptEngine *TheScriptEngine;
class ScriptConditions
{
protected:
    bool evaluateTeamStateIs(Parameter *, Parameter *);
};
bool ScriptConditions::evaluateTeamStateIs(Parameter *teamParm, Parameter *stateParm)
{
    Team *team = TheScriptEngine->getTeamNamed(teamParm->getString(), false);
    if (!team)
        return false;
    return team->rva003A3717(stateParm->getString()) ? true : false;
}
