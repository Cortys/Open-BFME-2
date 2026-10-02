// cl: /Ireference/shims/bfme2_ascii /O1 /EHs
// stlport
// ?rva0020881A@ScriptEngine@@QAEPAXVAsciiString@@@Z @0x0020881A 134B
// Unlock sibling of 0x002086C5 via resolveName plus Rva0002C4FD plus find
// Target evidence: callers 0x0020945A and 0x003C0578 unblocks 0x003C0532
// neighbours ScriptEngine_dtor 0x002086BD and stlport growth 0x00209952
// member at this+0x190AC is second team map m_map190AC per ScriptEngine_dtor layout
#include "ascii_string.h"
#include <utility>

class AsciiString;
struct TeamMapNode;

class Rva002046C0Owner
{
public:
	AsciiString resolveName(const AsciiString &name);
};

struct Rva0002C4FD : public _STL::pair<const AsciiString, AsciiString>
{
	Rva0002C4FD(const StringBase<char> &a, const StringBase<char> &b);
};

struct TeamMapNode
{
	char m_pad[0x18];
	char m_data[1];
};

class Rva0032C07COwner
{
public:
	TeamMapNode *find(Rva0002C4FD &key) throw();
};

class ScriptEngine : public Rva002046C0Owner
{
public:
	void *rva0020881A(AsciiString name);
private:
	char m_pad[0x190AC];
	Rva0032C07COwner m_owner;
};

void *ScriptEngine::rva0020881A(AsciiString name)
{
	AsciiString resolved = resolveName(name);
	Rva0002C4FD key(*(const StringBase<char> *)&resolved, *(const StringBase<char> *)&name);
	Rva0032C07COwner *owner = (Rva0032C07COwner *)((char *)this + 0x190AC);
	TeamMapNode *found = owner->find(key);
	if (found != *(TeamMapNode **)owner)
		return (void *)((char *)found + 0x18);
	return 0;
}
