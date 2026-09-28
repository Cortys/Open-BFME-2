// cl: /O1 /DNDEBUG /MD
//
// ?rva0036FA56@AIGroup@@QAEXPBVWaypoint@@W4CommandSourceType@@@Z, retail 0x0036FA56, 54 bytes.
// AIGroup forward of aiFollowWaypointPathExact to each member via the rowed
// AICommandInterface method at 0x0036ECE7. Evidence: same list-at-+0x00 plus
// Object+0x258 plus +0x20 subobject loop as the rowed groupAttackTeam at
// 0x0036FF33 in AIGroupAttackTeam.cpp; caller at 0x003BF712; prev/next are
// aiGuardPosition and groupAttackTeam with compatible flags.

#include <list>

class Waypoint;

typedef int Int;

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT = 1,
	CMD_FROM_AI = 2
};

class AICommandInterface
{
public:
	void aiFollowWaypointPathExact(const Waypoint *waypoint, CommandSourceType cmdSource);
};

class AIUpdateInterface
{
public:
	void rva0026DE3B(int arg);
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
	void rva0036FA56(const Waypoint *waypoint, CommandSourceType cmdSource);
private:
	std::list<Object *> m_memberList;
};

void AIGroup::rva0036FA56(const Waypoint *waypoint, CommandSourceType cmdSource)
{
	for (std::list<Object *>::iterator i = m_memberList.begin(); i != m_memberList.end(); ++i)
	{
		AIUpdateInterface *ai = (*i)->m_ai;
		if (ai != 0)
			ai->m_commands.aiFollowWaypointPathExact(waypoint, cmdSource);
	}
}
