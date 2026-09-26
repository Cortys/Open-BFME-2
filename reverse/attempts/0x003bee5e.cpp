// ?updateTeamSetAttitude@ScriptActions@@IAEXABVAsciiString@@H@Z
// partial score=0.88 date=2026-09-26
// cl: /O1 /Oy- /DNDEBUG /MD /EHsc
//
// ScriptActions::updateTeamSetAttitude, retail 0x003BEE5E, 80 bytes.
// Target evidence: initActionTemplates index 0x2E (46) is TEAM_SET_ATTITUDE;
// executeAction case 0x2E calls VA 0x007BEE5E. Target body copies the team
// name, resolves it through getTeamNamed at 0x3584E9, asks TheAI at 0xDFF0F8
// for a group via 0x2FEC4B, then calls 0x3A0F62 with the team/group and
// 0x36DD16 with the attitude argument. Callee pins record these relationships.
// Donor facts: BFME1 ScriptActions.cpp maps TEAM_SET_ATTITUDE to
// updateTeamSetAttitude and performs the same create-group, team-fill, set-
// attitude sequence. Data layouts and the helper names beyond those pin uses
// remain donor-derived; the target body independently establishes call order.

class AsciiString
{
public:
    AsciiString(const AsciiString &);
private:
    int m_string;
};
class Team;
class AIGroup;

enum AttitudeType { ATTITUDE_UNSPECIFIED = 0 };

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, bool = false);
};

class AIGroup
{
public:
    void setAttitude(AttitudeType);
};

class AI
{
public:
    AIGroup *createGroup();
};

class Team
{
public:
    void getTeamAsAIGroup(AIGroup *);
};

class ScriptActions
{
protected:
    void updateTeamSetAttitude(const AsciiString &, int);
};

void ScriptActions::updateTeamSetAttitude(const AsciiString &teamName, int attitude)
{
    Team *theSrcTeam = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed(teamName);
    if (!theSrcTeam) {
        return;
    }
    AIGroup *pAIGroup = (*(AI **)0x00DFF0F8)->createGroup();
    if (!pAIGroup) {
        return;
    }
    theSrcTeam->getTeamAsAIGroup(pAIGroup);
    pAIGroup->setAttitude((AttitudeType)attitude);
}
