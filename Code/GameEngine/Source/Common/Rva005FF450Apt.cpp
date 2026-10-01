// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ?rva005FF450@Rva005FF450@@QAEXHPBDABVUnicodeString@@@Z @ 0x005FF450 (109B).
// Apt Unit text setter; formats APT:_level%u.%s_Unit%s%d from m_level at +4 and team name at +8.
// Team pointer null uses g_Rva0107301CEmptyString; manager via TheRva00222A8BTarget.
// Evidence: format row 0x00038150; bfmeSetText pin 0x00225301; releaseBuffer 0x00036410;
// globals 0x009FE4CC 0x007BAC1C; callers 0x005FF593 0x005FFA3C; precedent AptPlayerNameSet 0x005FB770.
#include "ascii_string.h"

class UnicodeString;

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &key, const UnicodeString &value, bool b);
};

class Rva00222A8BTarget
{
	char m_pad;
};

extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];

struct Rva005FF450Team
{
	char m_pad[8];
	char m_name[1];
};

class Rva005FF450
{
public:
	void rva005FF450(int count, const char *kind, const UnicodeString &text);
private:
	char m_pad[4];
	unsigned int m_level;
	Rva005FF450Team *m_team;
};

void Rva005FF450::rva005FF450(int count, const char *kind, const UnicodeString &text)
{
	AsciiString key;
	const char *team = m_team ? m_team->m_name : g_Rva0107301CEmptyString;
	key.format("APT:_level%u.%s_Unit%s%d", m_level, team, kind, count);
	((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, text, true);
}
