// ?rva002086C5@ScriptEngine@@QAEPAXVAsciiString@@@Z
// partial score=0.97 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /EHs
// stlport
// ?rva002086C5@ScriptEngine@@QAEPAXVAsciiString@@@Z @0x002086C5 134B
// Unlock of 5 free functions (2 ready): findTeam-like lookup via resolveName plus Rva0002C4FD plus find.
// Target evidence: caller 0x003E7CE8 sets ecx to ScriptEngine* (g_Va009FE16C), ret 4 with pointer return,
// neighbours ScriptEngine_dtor 0x002086BD and stlport growth 0x00209952. Recipe: EH with AsciiString temps.
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
	TeamMapNode *find(Rva0002C4FD &key);
};

class ScriptEngine : public Rva002046C0Owner
{
public:
	void *rva002086C5(AsciiString name);
private:
	char m_pad[0x190A0];
	Rva0032C07COwner m_owner;
};

// ?rva002086C5@ScriptEngine@@QAEPAXVAsciiString@@@Z present-unmatched
void *ScriptEngine::rva002086C5(AsciiString name)
{
	AsciiString resolved = resolveName(name);
	Rva0002C4FD key(*(const StringBase<char> *)&resolved, *(const StringBase<char> *)&name);
	Rva0032C07COwner *owner = (Rva0032C07COwner *)((char *)this + 0x190A0);
	TeamMapNode *found = owner->find(key);
	void *ret;
	if (found != *(TeamMapNode **)owner)
		ret = (void *)((char *)found + 0x18);
	else
		ret = 0;
	return ret;
}
