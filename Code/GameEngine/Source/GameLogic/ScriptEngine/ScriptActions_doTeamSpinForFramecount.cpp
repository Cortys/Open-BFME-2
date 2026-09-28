// cl: /O1 /DNDEBUG /MD /EHsc
// Retail RVA 0x003C0FEA, 54 bytes.
// ?doTeamSpinForFramecount@ScriptActions@@IAEXABVAsciiString@@H@Z
// BFME1 donor reference/open-bfme-1/game/GameEngine/Source/GameLogic/ScriptEngine/ScriptActions.cpp
// doTeamSpinForFramecount: team lookup plus sequential-timer set, no AI calls.
// Evidence: getTeamNamed pin 0x003584E9 (by-value AsciiString temp pattern),
// rowed setSequentialTimer Team overload 0x00204002, TheScriptEngine 0x00DFE16C.
// Caller at 0x003CD447. Prev doTeamExitAll / next doTeamAttackNamed share flags.
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

class Team
{
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, Bool);
    void setSequentialTimer(Team *team, int frames);
};

class ScriptActions
{
protected:
    void doTeamSpinForFramecount(const AsciiString &, int);
};

void ScriptActions::doTeamSpinForFramecount(const AsciiString &teamName, int waitForFrames)
{
    Team *team = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed((AsciiString &)teamName, false);
    if (!team)
        return;
    (*(ScriptEngine **)0x00DFE16C)->setSequentialTimer(team, waitForFrames);
}
