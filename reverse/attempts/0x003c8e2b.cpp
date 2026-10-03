// ?Rva003C8E2BExit@@YGXABVAsciiString@@@Z
// partial score=0.95 date=2026-10-03
// ?Rva003C8E2BExit@@YGXABVAsciiString@@@Z
// partial score=0.95 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?Rva003C8E2BExit@@YGXABVAsciiString@@@Z retail 0x003C8E2B 94B
// Evidence: between Rva003C89D1Guard and Rva003C90B1Exit; caller 0x003CC1A3; rowed getTeamNamed 0x003584E9 plus iterate 0x00263864 plus advance 0x00263526 plus aiExit 0x0036F39B
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

class Object;
template<class OBJ> class DLINK_ITERATOR
{
public:
	void advance();
	bool done() const { return m_cur == 0; }
	OBJ *cur() const { return m_cur; }
private:
	OBJ *m_cur;
	char m_pad[20];
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
};

enum CommandSourceType { CMD_FROM_SCRIPT = 1 };

class ScriptEngine
{
public:
	Team *getTeamNamed(AsciiString name, bool exact);
};

class AICommandInterface
{
public:
	void aiExit(Object *obj, CommandSourceType src);
};

class AIUpdateInterface
{
public:
	char m_pad[0x20];
	AICommandInterface m_command;
};

class Object
{
public:
	AIUpdateInterface *getAI() const { return *(AIUpdateInterface **)((const char *)this + 0x258); }
};

#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)

// ?Rva003C8E2BExit@@YGXABVAsciiString@@@Z present-unmatched
void __stdcall Rva003C8E2BExit(const AsciiString &teamName)
{
	Team *team = TheScriptEngine->getTeamNamed(teamName, false);
	if (!team)
		return;
	for (DLINK_ITERATOR<Object> iter = team->iterate_TeamMemberList(); !iter.done(); iter.advance()) {
		Object *obj = iter.cur();
		AIUpdateInterface *ai = obj->getAI();
		if (!ai)
			continue;
		ai->m_command.aiExit(0, CMD_FROM_SCRIPT);
	}
}
