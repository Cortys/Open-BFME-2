// ?rva00208DB8@ScriptEngine@@QAEPAXVAsciiString@@@Z
// partial score=0.98 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /EHs
// stlport
// ?rva00208DB8@ScriptEngine@@QAEPAXVAsciiString@@@Z @0x00208DB8 225B
// Unlock callee of 4 free functions via resolveName plus Rva0002C4FD plus Make plus insert_unique
// Target evidence: callers 0x003C395C 0x003C39D2 etc unblocks 4; neighbours 0x0020881A same cl plus member at this+0x190F4
// member at this+0x190F4 is third team map per sibling second map at +0x190AC in ScriptEngineRva0020881A
#include "ascii_string.h"
#include <set>

class AsciiString;

class Rva002046C0Owner
{
public:
	AsciiString resolveName(const AsciiString &name);
};

struct Rva0002C4FD : public _STL::pair<const AsciiString, AsciiString>
{
	Rva0002C4FD(const StringBase<char> &a, const StringBase<char> &b);
};

struct Rva0020561C
{
	_STL::pair<AsciiString, AsciiString> m_pair;
	AsciiString m_str;
	Rva0020561C(const _STL::pair<AsciiString, AsciiString> &p, const StringBase<char> &s);
	~Rva0020561C();
};

Rva0020561C Rva0020568CMake(const _STL::pair<AsciiString, AsciiString> &p, const StringBase<char> &s);

struct Rva00204686
{
	_STL::pair<const AsciiString, AsciiString> m_pair;
	AsciiString m_entry;
	~Rva00204686();
};

struct BfmeStringRecord002049D6
{
	_STL::pair<AsciiString, AsciiString> m_pair;
	AsciiString m_third;
	BfmeStringRecord002049D6(const BfmeStringRecord002049D6 &o);
	~BfmeStringRecord002049D6();
};

bool operator<(const _STL::pair<AsciiString, AsciiString> &a, const _STL::pair<AsciiString, AsciiString> &b);
inline bool operator<(const BfmeStringRecord002049D6 &a, const BfmeStringRecord002049D6 &b) { return a.m_pair < b.m_pair; }

typedef _STL::_Rb_tree<BfmeStringRecord002049D6, BfmeStringRecord002049D6, _STL::_Identity<BfmeStringRecord002049D6>, _STL::less<BfmeStringRecord002049D6>, _STL::allocator<BfmeStringRecord002049D6> > BfmeStringRecordTree;

class ScriptEngine : public Rva002046C0Owner
{
public:
// ?rva00208DB8@ScriptEngine@@QAEPAXVAsciiString@@@Z present-unmatched
	void *rva00208DB8(AsciiString name);
private:
	char m_pad[0x190F4];
	BfmeStringRecordTree m_map190F4;
};

void *ScriptEngine::rva00208DB8(AsciiString name)
{
	AsciiString resolved = resolveName(name);
	Rva0002C4FD key(*(const StringBase<char> *)&resolved, *(const StringBase<char> *)&name);
	AsciiString extra(AsciiString::TheEmptyString);
	Rva0020561C maker = Rva0020568CMake(*(const _STL::pair<AsciiString, AsciiString> *)(const void *)&key, *(const StringBase<char> *)&extra);
	BfmeStringRecord002049D6 node(*(const BfmeStringRecord002049D6 *)(const void *)&maker);
	return (void *)((char *)m_map190F4.insert_unique(node).first._M_node + 0x18);
}
