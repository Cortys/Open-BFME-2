// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva003C4449Do@@YGXABVAsciiString@@0@Z @0x003C4449 83B.
// Script free function finding Team named then Player by name key and
// calling rowed armor remove 0x003A28ED. Evidence: chain lane via 0x003A28ED
// just landed; prev 0x003C43A3 and next 0x003C4570 share /O1 /EHsc and
// two-AsciiString void stdcall shape plus ScriptEngine global 0xDFE16C;
// caller at 0x003CC9DE; ret 8 two args.
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
class Player
{
public:
	char m_pad[0x54];
	NameKeyType m_key;
};
class Rva003A28ED
{
public:
	bool rva003A28ED(NameKeyType key);
};
extern ScriptEngine *g_009FE16C;
extern NameKeyGenerator *g_009F36A4;
extern PlayerList *g_009FEEE8;
void __stdcall Rva003C4449Do(const AsciiString &teamName, const AsciiString &playerName)
{
	Team *team = g_009FE16C->getTeamNamed(teamName, false);
	NameKeyType key = g_009F36A4->nameToKey(playerName);
	Player *player = g_009FEEE8->findPlayerWithNameKey(key);
	if (team == 0)
		return;
	if (player == 0)
		return;
	((Rva003A28ED *)team)->rva003A28ED(player->m_key);
}
