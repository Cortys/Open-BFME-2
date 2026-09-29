// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva003BFC27Do@@YGXABVAsciiString@@@Z @0x003BFC27 152B
// Script team priority decrease via getTeamNamed pin 0x003584E9 with false,
// Team+0x30 TeamPrototype rowed rva0039D73A 0x0039D73A, AsciiString format
// row 0x00038150 Team priority decreased, rowed AppendDebugMessage 0x00205263
// with false, rowed releaseBuffer 0x00036410.
// Evidence: TheScriptEngine 0x009FE16C; caller 0x003CB99F; string at
// 0x0081FEF4 Team priority decreased; precedent ScriptEngineAppendDebugMessage
// StringBase layout with str plus format plus release.
typedef bool Bool;
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};
template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
protected:
	BfmeStringData<T> *m_data;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
};
class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	~AsciiString() {}
	void __cdecl format(const char *fmt, ...);
	const char *str() const { return m_data ? (const char *)m_data->text : ""; }
};
class TeamPrototype
{
public:
	void rva0039D73A();
private:
	char m_pad00[0x21C];
public:
	int m_priority21C;
private:
	char m_pad220[0x224 - 0x220];
	int m_delta224;
};
class Team
{
public:
	char m_pad00[0x30];
	TeamPrototype *m_proto30;
};
class ScriptEngine
{
public:
	Team *getTeamNamed(AsciiString, Bool);
	void AppendDebugMessage(const AsciiString &, Bool);
};
extern ScriptEngine *g_Va009FE16C;

void __stdcall Rva003BFC27Do(const AsciiString &teamName)
{
	Team *team = g_Va009FE16C->getTeamNamed((AsciiString &)teamName, false);
	if (team == 0)
		return;
	TeamPrototype *proto = team->m_proto30;
	if (proto == 0)
		return;
	proto->rva0039D73A();
	AsciiString msg;
	msg.format("Team '%s' priority decreased to %d for failure.", teamName.str(), proto->m_priority21C);
	g_Va009FE16C->AppendDebugMessage(msg, false);
}
