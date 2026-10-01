// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /arch:SSE2 /O1
// ?evaluateTeamIsContained@ScriptConditions@@IAE_NPAVParameter@@_N@Z
// @0x003E70AC 126B. BFME1 donor ScriptConditionsTeamMembers.cpp
// evaluateTeamIsContained: member walk through the pinned
// iterate_TeamMemberList 0x00263864 and DLINK advance 0x00263526, contained =
// Object +0x274 non-null. The donor's AI-exit refinement is kept: it only runs
// when isContained is false, so `isContained && ...` folds away entirely (no
// load survives in BFME2), but it is what makes MSVC materialise the bool
// (setne/test) as retail does. The m_ai slot below is therefore never read
// and its BFME2 offset is not asserted.
#include "ascii_string.h"
class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    unsigned char m_beforeInt[8]; int m_int; float m_real; AsciiString m_string;
    unsigned char m_afterString[8];
};
class AIUpdateInterface
{
public:
    int getCurrentStateID() const;
};
// AI_EXIT is enum item 37 in the pristine Zero Hour AIStateMachine.h.
enum { BFME_AI_EXIT = 37 };
class Object
{
public:
    void *getContainedBy() const { return m_containedBy; }
    AIUpdateInterface *getAIUpdateInterface() const { return m_ai; }
private:
    unsigned char m_pad[0x274];
    void *m_containedBy; // +0x274
    AIUpdateInterface *m_ai; // offset not asserted (never read, see above)
};
template<class OBJCLASS>
class DLINK_ITERATOR
{
private:
    OBJCLASS *m_cur;
    unsigned char m_targetAbiState[20];
public:
    void advance();
    bool done() const { return m_cur == 0; }
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
    Team *getTeamNamed(AsciiString, bool);
};
extern ScriptEngine *TheScriptEngine;
class ScriptConditions
{
protected:
    bool evaluateTeamIsContained(Parameter *, bool);
};
bool ScriptConditions::evaluateTeamIsContained(Parameter *teamParm, bool allContained)
{
    Team *team = TheScriptEngine->getTeamNamed(teamParm->getString(), false);
    if (!team)
        return false;
    bool anyConsidered = false;
    for (DLINK_ITERATOR<Object> iter = team->iterate_TeamMemberList(); !iter.done(); iter.advance())
    {
        Object *obj = iter.cur();
        if (!obj)
            continue;
        bool isContained = obj->getContainedBy() != 0;
        if (!isContained)
        {
            AIUpdateInterface *ai = obj->getAIUpdateInterface();
            if (ai)
                isContained = isContained && ai->getCurrentStateID() == BFME_AI_EXIT;
        }
        if (isContained)
        {
            if (!allContained)
                return true;
        }
        else
        {
            if (allContained)
                return false;
        }
        anyConsidered = true;
    }
    if (anyConsidered)
        return allContained;
    return false;
}
