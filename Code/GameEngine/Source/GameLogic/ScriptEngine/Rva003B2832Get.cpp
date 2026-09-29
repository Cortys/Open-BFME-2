// cl: /O1 /DNDEBUG /MD
// ?rva003B2832@Rva003B2832@@QAEHXZ 0x003B2832 17B
// Evidence: pushes member at +4 into rowed ScriptEngine::getActionTemplate
// 0x00203926 through the engine pointer at 0x00DFE16C, returns the template's
// first dword; twin of rva003B275A; callers 0x0020C83F/0x0020C5C7.
typedef int Int;
typedef unsigned char Byte;

class ActionTemplate
{
public:
	Byte m_pad[128];
};

class ScriptEngine
{
public:
	const ActionTemplate *getActionTemplate(Int actionType);
};

class Rva003B2832
{
	char m_pad[4];
	int m_id;

public:
	int rva003B2832();
};

int Rva003B2832::rva003B2832()
{
	return *(const int *)(*(ScriptEngine **)0x00DFE16C)->getActionTemplate(m_id)->m_pad;
}
