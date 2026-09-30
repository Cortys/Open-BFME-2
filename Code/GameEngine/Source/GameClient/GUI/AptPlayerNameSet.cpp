// cl: /O1 /DNDEBUG /MD /EHsc
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
template <typename T> class StringBase
{
    friend class AsciiString;
    friend class UnicodeString;
public:
    StringBase() : m_data(0) {}
    int compare(const StringBase<T> &other) const;
    void set(const StringBase<T> &other);
private:
    StringBase(const T *text);
    StringBase(const StringBase<T> &other);
    ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
    BfmeStringData<T> *m_data;
};
class AsciiString : private StringBase<char>
{
public:
    AsciiString() {}
    AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    ~AsciiString() {}
    void format(const char *fmt, ...);
};
class UnicodeString : public StringBase<unsigned short>
{
public:
    UnicodeString() {}
    UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    ~UnicodeString() {}
    void format(const unsigned short *fmt, ...);
};
class BfmeAptWindowManager
{
public:
    void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};
extern BfmeAptWindowManager *g_bfmeAptWindowManager;
extern const char g_007BAC1C[];
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
private:
    char m_pad[4];
    unsigned int m_level;
    TeamNameHolder *m_team;
    char m_pad0C[0x28 - 0x0C];
    UnicodeString m_cachedName;
    char m_pad2C[0x38 - 0x2C];
    int m_cachedCount;
};
void Rva005FB770::rva005FB770(const UnicodeString &playerName)
{
    AsciiString key;
    const char *teamName;
    if (m_team)
        teamName = (const char *)((char *)m_team + 8);
    else
        teamName = g_007BAC1C;
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
        teamName = g_007BAC1C;
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
