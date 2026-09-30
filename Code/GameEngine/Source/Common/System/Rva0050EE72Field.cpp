// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?Rva0050EE72Set@@YAXHABVAsciiString@@HABVUnicodeString@@@Z @0x0050EE72 106B
// APT field setter: key.format APT:_level%u.%s_field%d via rowed 0x00038150
// plus pinned bfmeSetText 0x00225301 plus releaseBuffer 0x00036410;
// team AsciiString empty via g_Rva0107301CEmptyString; manager 0x009FE4CC.
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};
#include "ascii_string.h"
class UnicodeString : public StringBase<unsigned short>
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
	~UnicodeString() {}
};
class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};
class Rva00222A8BTarget
{
};
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];

struct TeamNameRef
{
	const char *m_name08;
};

void __cdecl Rva0050EE72Set(int level, const AsciiString &team, int field, const UnicodeString &value)
{
	AsciiString key;
	const char *teamName;
	const BfmeStringData<char> *h = *(const BfmeStringData<char> *const *)&team;
	if (h)
		teamName = (const char *)&h->text[0];
	else
		teamName = g_Rva0107301CEmptyString;
	key.format("APT:_level%u.%s_field%d", level, teamName, field);
	((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, value, false);
}
