// ?rva00209811@ScriptEngine@@QAEXABVAsciiString@@E@Z
// partial score=0.97 date=2026-10-03
// ?rva00209811@ScriptEngine@@QAEXABVAsciiString@@E@Z
// partial score=0.97 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?rva00209811@ScriptEngine@@QAEXABVAsciiString@@E@Z @0x00209811 132B
// ScriptEngine map insert-or-update at +0x190D0 via rowed _M_find: hit
// stores flag at node+0x14, miss builds Rva003004C1 via just-landed Make
// 0x002056C1 then pair copy and rowed hint insert_unique. 1-byte payload
// layout per stlport_rb_tree_hint_00302081. Caller 0x003C35EE.
// ?rva00209811@ScriptEngine@@QAEXABVAsciiString@@E@Z present-unmatched
#include "ascii_string.h"
#include <map>

struct TreeHintPayload00207343
{
	unsigned char value;
	~TreeHintPayload00207343();
};

typedef _STL::pair<const AsciiString, TreeHintPayload00207343> TreeHintPair00207343;
typedef _STL::map<AsciiString, TreeHintPayload00207343> Map190D0;

struct Rva003004C1
{
	AsciiString m_key;
	unsigned char m_flag;
};

Rva003004C1 Rva002056C1Make(const AsciiString &key, const unsigned char &flag);

class ScriptEngine
{
public:
	void rva00209811(const AsciiString &key, unsigned char flag);
private:
	char m_pad[0x190D0];
	Map190D0 m_map; // +0x190D0
};

void ScriptEngine::rva00209811(const AsciiString &key, unsigned char flag)
{
	Map190D0::iterator f = m_map.find(key);
	if (f != m_map.end()) {
		f->second.value = flag;
		return;
	}
	Rva003004C1 tmp = Rva002056C1Make(key, flag);
	_STL::pair<const AsciiString, char> p((const _STL::pair<const AsciiString, char> &)tmp);
	m_map.insert(*(const TreeHintPair00207343 *)&p);
}
