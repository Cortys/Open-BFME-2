// cl: /O1 /DNDEBUG /MD
//
// AIGroup::groupAttackTeam (?groupAttackTeam@AIGroup@@QAEXPBVTeam@@HW4CommandSourceType@@@Z),
// retail 0x0036FF33, 65 bytes, plus
// AIGroup::groupHunt (?groupHunt@AIGroup@@QAEXW4CommandSourceType@@@Z),
// retail 0x0037008E, 50 bytes.
// ZH donor GeneralsMD/Code/GameEngine/Source/GameLogic/AI/AIGroup.cpp
// groupAttackTeam plus BFME2 layout Object+0x258 AIUpdate plus +0x20 command
// subobject plus MSVC list at AIGroup+0x00 (head at +0x04). Caller 0x003BED59 does
// getTeamNamed twice plus createGroup plus getTeamAsAIGroup plus this call
// with Team plus 0x7fffffff plus source 1 which is ZH doAttack TEAM_ATTACK_TEAM.
// groupHunt forwards aiHunt to each member; caller 0x003BF8F8 builds an AIGroup
// and calls with source 1; ZH groupHunt plus BFME1 ForwardedOrders groupHunt
// at 0x00156270 plus rowed aiHunt at 0x002AE657 prove the identity.

#include <list>

typedef int Int;

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT = 1,
	CMD_FROM_AI = 2
};

class Team;
class Object;

class AICommandInterface
{
public:
	void aiAttackTeam(const Team *team, Int maxShotsToFire, CommandSourceType cmdSource);
	void aiHunt(CommandSourceType cmdSource);
};

class AIUpdateInterface
{
public:
	char m_pad[0x20];
	AICommandInterface m_commands;
};

class Object
{
public:
	char m_pad[0x258];
	AIUpdateInterface *m_ai;
};

class AIGroup
{
public:
	void groupAttackTeam(const Team *team, Int maxShotsToFire, CommandSourceType cmdSource);
	void groupHunt(CommandSourceType cmdSource);

private:
	std::list<Object *> m_memberList;
};

void AIGroup::groupAttackTeam(const Team *team, Int maxShotsToFire, CommandSourceType cmdSource)
{
	if (!team) {
		return;
	}
	std::list<Object *>::iterator i;
	for (i = m_memberList.begin(); i != m_memberList.end(); ++i) {
		AIUpdateInterface *ai = (*i)->m_ai;
		if (ai) {
			ai->m_commands.aiAttackTeam(team, maxShotsToFire, cmdSource);
		}
	}
}

void AIGroup::groupHunt(CommandSourceType cmdSource)
{
	for (std::list<Object *>::iterator i = m_memberList.begin(); i != m_memberList.end(); ++i) {
		AIUpdateInterface *ai = (*i)->m_ai;
		if (ai) {
			ai->m_commands.aiHunt(cmdSource);
		}
	}
}
