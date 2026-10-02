// ?rva005F618E@Rva005F618E@@QAEXE@Z
// partial score=0.9 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /Oy-
// ?rva005F618E@Rva005F618E@@QAEXE@Z @ 0x005F618E 86B chain via rowed AptCall 0x0050E9FE.
// Byte flag setter with _selected/_up literals, cache byte at +0x36, team +8 level +4.
// Evidence: EBP frame, rowed AptCall, literals at VA 0x872C80 0x8031D8 0x879648,
// empty g_Rva0107301CEmptyString, manager TheRva00222A8BTarget, caller jmp 0x005F6301.
// ?rva005F618E@Rva005F618E@@QAEXE@Z present-unmatched
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
int Rva0050E9FEAptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, const char **a0ptr);
struct Rva005F618ETeam
{
    char m_pad[8];
    const char *m_name;
};
class Rva005F618E
{
public:
    void rva005F618E(unsigned char v);
private:
    char m_pad0[4];
    unsigned int m_level;
    Rva005F618ETeam *m_team;
    char m_pad0C[0x36 - 0x0C];
    unsigned char m_cached;
};
void Rva005F618E::rva005F618E(unsigned char v)
{
    if (v == m_cached)
        return;
    unsigned char orig = v;
    *(const char **)(void *)&v = orig ? "_selected" : "_up";
    const char *team;
    if (m_team)
        team = (const char *)((char *)m_team + 8);
    else
        team = g_Rva0107301CEmptyString;
    Rva0050E9FEAptCall(TheRva00222A8BTarget, (void *)m_level, team, "SetLeaderIconState", (const char **)(void *)&v);
    m_cached = orig;
}
