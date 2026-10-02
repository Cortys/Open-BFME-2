// ?rva005FB872@Rva005FB770@@QAEXH@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva005FB770@Rva005FB770@@QAEXABVUnicodeString@@@Z @ 0x005FB770 103B
// Honest address name: __thiscall Apt PlayerName key setter beside AptMapPreview.
// Target evidence: 103B retail, EH_prolog, format string
// "APT:_level%u.%s_PlayerName" at VA 0x879F60, rowed AsciiString::format
// 0x38150, pinned bfmeSetText 0x225301, rowed releaseBuffer 0x36410,
// manager at VA 0xDFE4CC, default %s at VA 0xBBAC1C, 2 callers.
template <typename T> struct BfmeStringData
{
    int refCount;
    unsigned short length;
    unsigned short capacity;
    T text[1];
};
#include "ascii_string.h"
#include "unicode_string.h"
class BfmeAptWindowManager
{
public:
    void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};
extern BfmeAptWindowManager *g_bfmeAptWindowManager;
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
int __cdecl Rva0052519DFire(void *a1, void *a2, const char *a3, const char *a4, int *a5);
struct TeamNameHolder
{
    char m_pad[8];
    const char *m_name;
};
class Rva005FB770
{
public:
    void rva005FB770(const UnicodeString &playerName);
    void rva005FBBC0(const UnicodeString &playerName);
    void rva005FB7D7(const UnicodeString &value);
    void rva005FB903(int count);
    void rva005FB872(int color);
private:
    char m_pad[4];
    unsigned int m_level;
    TeamNameHolder *m_team;
    char m_pad0C[0x28 - 0x0C];
    UnicodeString m_cachedName;
    int m_cachedColor;
    char m_pad30[0x38 - 0x30];
    int m_cachedCount;
};
void Rva005FB770::rva005FB770(const UnicodeString &playerName)
{
    AsciiString key;
    const char *teamName;
    if (m_team)
        teamName = (const char *)((char *)m_team + 8);
    else
        teamName = "";
    key.format("APT:_level%u.%s_PlayerName", m_level, teamName);
    g_bfmeAptWindowManager->bfmeSetText(key, playerName, true);
}
void Rva005FB770::rva005FBBC0(const UnicodeString &playerName)
{
    if (playerName.compare(m_cachedName) != 0)
    {
        rva005FB770(playerName);
        m_cachedName.set(playerName);
    }
}
void Rva005FB770::rva005FB7D7(const UnicodeString &value)
{
    AsciiString key;
    const char *teamName;
    if (m_team)
        teamName = (const char *)((char *)m_team + 8);
    else
        teamName = "";
    key.format("APT:_level%u.%s_UnitCount", m_level, teamName);
    g_bfmeAptWindowManager->bfmeSetText(key, value, true);
}
void Rva005FB770::rva005FB903(int count)
{
    if (count == m_cachedCount)
        return;
    UnicodeString tmp;
    if (count >= 0)
        tmp.format(L"%d", count);
    rva005FB7D7(tmp);
    m_cachedCount = count;
}
// ?rva005FB872@Rva005FB770@@QAEXH@Z @ 0x005FB872 66B unlock via rowed Fire 0x0052519D.
// Apt SetPlayerColor setter with int cache at +0x2c; team at +8 else empty; level at +4.
// Evidence: "SetPlayerColor" at VA 0x878610, empty at VA 0xBBAC1C, manager VA 0xDFE4CC,
// wrapper jmp at 0x005FBB4D, same class as neighbours 0x005FB7D7 0x005FB903.
// ?rva005FB872@Rva005FB770@@QAEXH@Z present-unmatched
void Rva005FB770::rva005FB872(const int color)
{
    if (color == m_cachedColor)
        return;
    const char *team;
    if (m_team)
        team = (const char *)((char *)m_team + 8);
    else
        team = g_Rva0107301CEmptyString;
    Rva0052519DFire(TheRva00222A8BTarget, (void *)m_level, team, "SetPlayerColor", (int *)&color);
    m_cachedColor = color;
}
class Rva005FBB68
{
public:
    void rva005FBB68(int count);
private:
    char m_pad[4];
    Rva005FB770 *m_member;
};
void Rva005FBB68::rva005FBB68(int count)
{
    return m_member->rva005FB903(count);
}
