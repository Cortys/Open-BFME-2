// cl: /O1
// ?Rva003E41E3Get@@YG_NPAX@Z @0x003E41E3 24B ScriptEngine wrapper via rowed rva00357A36 0x00357A36 plus global at 0x00DFE16C.
// Evidence: chain lane callee rowed; caller 0x003EB405; string at base plus 0x10 plus true.
class AsciiString
{
public:
	char *m_text;
};
class ScriptEngine
{
public:
	bool rva00357A36(const AsciiString &s, bool remove);
};
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)

struct Rva003E41E3Base
{
	char m_pad[0x10];
	AsciiString m_name;
};

bool __stdcall Rva003E41E3Get(void *base)
{
	AsciiString *name = (AsciiString *)((char *)base + 0x10);
	return TheScriptEngine->rva00357A36(*name, true);
}
