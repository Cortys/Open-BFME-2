// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva003C43A3Do@@YGXABVAsciiString@@0@Z @0x003C43A3 80B.
// Script free function finding Player by name key and Team named then
// calling rowed armor remove. Evidence: chain lane via 0x002AD19E,
// prev doTeamAttackNamed and next Rva003C4570Do share /O1 /EHsc and
// two-AsciiString void stdcall shape plus ScriptEngine global 0xDFE16C.
typedef int Int;
typedef bool Bool;
class Object;
class Team;
class Player;
template<class T>
class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase &);
public:
	int compare(const T *) const;
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
class ScriptEngine
{
public:
	Team *getTeamNamed(AsciiString, bool);
};
enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	NAMEKEY_MAX = 1 << 23
};
class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const AsciiString &s);
};
class PlayerList
{
public:
	Player *findPlayerWithNameKey(NameKeyType key);
};
class Rva002AD19E
{
public:
	bool rva002AD19E(void *arg);
};
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
#define TheNameKeyGen (*(NameKeyGenerator **)0x00DF36A4)
#define ThePlayerList (*(PlayerList **)0x00DFEEE8)
void __stdcall Rva003C43A3Do(const AsciiString &playerName, const AsciiString &teamName)
{
	NameKeyType key = TheNameKeyGen->nameToKey(playerName);
	Player *player = ThePlayerList->findPlayerWithNameKey(key);
	Team *team = TheScriptEngine->getTeamNamed(teamName, false);
	if (player == 0)
		return;
	if (team == 0)
		return;
	((Rva002AD19E *)player)->rva002AD19E(team);
}
