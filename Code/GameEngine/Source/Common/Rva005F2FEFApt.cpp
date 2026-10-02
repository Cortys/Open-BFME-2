// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva005F2FEF@Rva005F2FEF@@QAEXABVUnicodeString@@@Z retail 0x005F2FEF 191B
// Evidence: SetMemberNameState _show plus APT:_level%u.%s_MemberName via rowed format 0x00038150 and pinned bfmeSetText 0x00225301; rowed compare 0x00006A7A set 0x00037150 release 0x00036410 AptCall 0x005FB5E6; globals 0x009FE4CC 0x007BAC1C; caller forwarder 0x005F3272; precedent Rva005F7670 UnitName show plus cached
#include "ascii_string.h"
#include "unicode_string.h"

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &key, const UnicodeString &value, bool b);
};

class Rva00222A8BTarget
{
};

extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];

struct Rva005F2FEFTeam
{
	char m_pad[8];
	char m_name[1];
};

class Rva005F2FEF
{
public:
	void rva005F2FEF(const UnicodeString &text);
	void rva005F2897();
	void rva005F2953();
private:
	char m_pad00[8];
	void *m_level08;
	Rva005F2FEFTeam *m_team0C;
	char m_pad10[0x48 - 0x10];
	UnicodeString m_cached48;
	char m_pad4C[0x58 - 0x4C];
	unsigned char m_flags58;
};

int __cdecl Rva005FB5E6AptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, const char *a0);

void Rva005F2FEF::rva005F2FEF(const UnicodeString &text)
{
	if (!(m_flags58 & 1)) {
		const char *team = m_team0C ? m_team0C->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level08, team, "SetMemberNameState", "_show");
		m_flags58 |= 1;
	}
	if (text.compare(m_cached48) != 0) {
		AsciiString key;
		const char *team = m_team0C ? m_team0C->m_name : g_Rva0107301CEmptyString;
		key.format("APT:_level%u.%s_MemberName", m_level08, team);
		((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, text, false);
		m_cached48.set(text);
	}
}

void Rva005F2FEF::rva005F2897()
{
	if (m_flags58 & 1) {
		const char *team = m_team0C ? m_team0C->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level08, team, "SetMemberNameState", "_hide");
		m_flags58 &= ~1;
	}
	if (!m_cached48.isEmpty()) {
		AsciiString key;
		const char *team = m_team0C ? m_team0C->m_name : g_Rva0107301CEmptyString;
		key.format("APT:_level%u.%s_MemberName", m_level08, team);
		((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, UnicodeString::TheEmptyString, false);
		m_cached48.set(UnicodeString::TheEmptyString);
	}
}

void Rva005F2FEF::rva005F2953()
{
	if (m_flags58 & 2) {
		const char *team = m_team0C ? m_team0C->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level08, team, "SetMemberRankState", "_hide");
		m_flags58 &= ~2;
	}
}

class Rva005F2A32
{
public:
	void rva005F2A32();
	void rva005F2A3A();
private:
	char m_pad00[4];
	Rva005F2FEF *m_member04;
};

void Rva005F2A32::rva005F2A32()
{
	m_member04->rva005F2897();
}

void Rva005F2A32::rva005F2A3A()
{
	m_member04->rva005F2953();
}
