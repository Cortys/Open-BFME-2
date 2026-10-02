// ?rva005F6DB0@Rva005F6A58@@UAEXH@Z
// partial score=0.9 date=2026-10-02
// cl: /O1 /MD /EHsc /Oy-
// ?rva005F6DB0@Rva005F6A58@@UAEXH@Z @ 0x005F6DB0 81B chain via rowed AptCall 0x0050E9FE.
// Slot 9 virtual of Rva005F6A58 (vtable 0x008797F4); index-to-string via table g_00C78D64.
// Evidence: EBP frame, rowed AptCall, table at VA 0x00C78D64, empty g_Rva0107301CEmptyString,
// manager TheRva00222A8BTarget, holder at +0x1c with level +4 team +8, cached +0x14.
// ?rva005F6DB0@Rva005F6A58@@UAEXH@Z present-unmatched
class Rva005F6941
{
public:
    virtual ~Rva005F6941();
};
struct Rva005F6DB0Holder
{
    char m_pad0[4];
    unsigned int m_level;
    char *m_teamData;
};
class Rva005F6A58 : public Rva005F6941
{
public:
    virtual void rva005F6DB0(int index);
private:
    char m_pad04[0x14 - 4];
    int m_cached;
    char m_pad18[0x1c - 0x18];
    Rva005F6DB0Holder *m_holder;
};
class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern const char g_Rva0107301CEmptyString[];
extern const char *g_00C78D64[];
int Rva0050E9FEAptCall(Rva00222A8BTarget *target, void *level, const char *prefix, const char *function, const char **a0ptr);
void Rva005F6A58::rva005F6DB0(int index)
{
    if (index == m_cached)
        return;
    register int orig = index;
    index = (int)g_00C78D64[orig];
    const char *team;
    if (m_holder->m_teamData)
        team = (const char *)(m_holder->m_teamData + 8);
    else
        team = g_Rva0107301CEmptyString;
    Rva0050E9FEAptCall(TheRva00222A8BTarget, (void *)m_holder->m_level, team, "SetInProgressIconSlotState", (const char **)&index);
    m_cached = orig;
}
