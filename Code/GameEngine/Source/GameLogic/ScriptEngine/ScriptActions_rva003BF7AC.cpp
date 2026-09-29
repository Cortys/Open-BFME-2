// cl: /O1 /DNDEBUG /MD
// ?Rva003BF7ACDo@@YGXABVAsciiString@@PAVParameter@@@Z @0x003BF7AC 103B
// Script team group order via getUnitNamed row 0x003588E7 (Parameter overload)
// plus getTeamNamed pin 0x003584E9 with false, createGroup pin 0x002FEC4B,
// getTeamAsAIGroup pin 0x003A0F62, then rowed rva00370410 with unit plus 0 and 1.
// Evidence: TheScriptEngine 0x009FE16C, TheAI 0x009FF0F8; caller 0x003CB5E4;
// precedent Rva003C2A29Script.cpp 118B same team/group sequence with two teams.
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
	~AsciiString() {}
private:
	char *m_text;
};
typedef bool Bool;

enum CommandSourceType
{
	CMD_FROM_PLAYER = 0,
	CMD_FROM_SCRIPT = 1
};

class Parameter;
class Object;
class Team;
class AIGroup;

class ScriptEngine
{
public:
	Object *getUnitNamed(Parameter *param);
	Team *getTeamNamed(AsciiString, Bool);
};

class AI
{
public:
	AIGroup *createGroup();
};

class Team
{
public:
	void getTeamAsAIGroup(AIGroup *group);
};

class AIGroup
{
public:
	void rva00370410(Object *obj, int x, CommandSourceType src);
};

extern ScriptEngine *g_Va009FE16C;
extern AI *g_Va009FF0F8;

void __stdcall Rva003BF7ACDo(const AsciiString &teamName, Parameter *param)
{
	Object *unit = g_Va009FE16C->getUnitNamed(param);
	Team *team = g_Va009FE16C->getTeamNamed((AsciiString &)teamName, false);
	if (team == 0 || unit == 0)
		return;
	AIGroup *group = g_Va009FF0F8->createGroup();
	if (group == 0)
		return;
	team->getTeamAsAIGroup(group);
	group->rva00370410(unit, 0, CMD_FROM_SCRIPT);
}
