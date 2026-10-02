// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ?rva005F7670@Rva005F7670@@QAEXABVUnicodeString@@@Z retail 0x005F7670 190B
// Evidence: format APT:_level%u.%s_UnitName via rowed 0x00038150; pinned bfmeSetText 0x00225301; rowed releaseBuffer 0x00036410; rowed compare 0x00006A7A and set 0x00037150; AptCall row 0x005FB5E6 with SetUnitNameState _show; globals 0x009FE4CC 0x007BAC1C; caller forwarder 0x005F772E; precedent Rva005FB770 cached compare plus Rva005FB6E2 once flag
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

struct Rva005F7670Team
{
	char m_pad[8];
	char m_name[1];
};

class Rva005F7670
{
public:
	void rva005F7670(const UnicodeString &text);
	void rva005F7161();
	void rva005F7412();
	void rva005F72C8();
private:
	char m_pad00[4];
	void *m_level04;
	Rva005F7670Team *m_team08;
	char m_pad0C[0x58 - 0x0C];
	UnicodeString m_cached58;
	char m_pad5C[0x64 - 0x5C];
	bool m_shown64;
	bool m_shown65;
	bool m_shown66;
};

int __cdecl Rva005FB5E6AptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, const char *a0);

void Rva005F7670::rva005F7670(const UnicodeString &text)
{
	if (text.compare(m_cached58) != 0) {
		AsciiString key;
		const char *team = m_team08 ? m_team08->m_name : g_Rva0107301CEmptyString;
		key.format("APT:_level%u.%s_UnitName", m_level04, team);
		((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, text, false);
		m_cached58.set(text);
	}
	if (!m_shown64) {
		const char *team = m_team08 ? m_team08->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level04, team, "SetUnitNameState", "_show");
		m_shown64 = true;
	}
}

class Rva005F772E
{
public:
	void rva005F772E(const UnicodeString &text);
	void rva005F7470();
private:
	char m_pad00[4];
	Rva005F7670 *m_member04;
};

void Rva005F772E::rva005F772E(const UnicodeString &text)
{
	m_member04->rva005F7670(text);
}

void Rva005F772E::rva005F7470()
{
	m_member04->rva005F7161();
}

void Rva005F7670::rva005F7161()
{
	if (m_shown64) {
		const char *team = m_team08 ? m_team08->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level04, team, "SetUnitNameState", "_hide");
		m_shown64 = false;
	}
}
void Rva005F7670::rva005F7412()
{
	if (m_shown66) {
		const char *team = m_team08 ? m_team08->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level04, team, "SetCommandPointsState", "_hide");
		m_shown66 = false;
	}
}
void Rva005F7670::rva005F72C8()
{
	if (m_shown65) {
		const char *team = m_team08 ? m_team08->m_name : g_Rva0107301CEmptyString;
		Rva005FB5E6AptCall(TheRva00222A8BTarget, m_level04, team, "SetBuildTimeState", "_hide");
		m_shown65 = false;
	}
}
