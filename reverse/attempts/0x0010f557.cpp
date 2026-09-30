// ?rva0010F557@Rva0010F557@@QAEXXZ
// partial score=0.97 date=2026-09-30
// ?rva0010F557@Rva0010F557@@QAEXXZ
// partial score=0.97 date=2026-09-28
// ?rva0010F557@Rva0010F557@@QAEXXZ
// partial score=0.97 date=2026-09-28
// cl: /O1 /MD
// ?rva0010F557@Rva0010F557@@QAEXXZ @0x0010F557 81B.
// Guarded AIL_set_stream_loop_count: same guard derivation as 0x0010F33C,
// lock via rowed 0x0010F24F, set loop count from +0x0C on the +0x08 inner
// stream when non-null, unlock via rowed 0x0010F26E. Evidence: rowed lock
// pair, IAT AIL_set_stream_loop_count at 0x00BBAB28, Rva00041004 layout
// from rowed ctor 0x000411C1. Honest address name.
struct CRITICAL_SECTION
{
    unsigned char data[24];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall AIL_set_stream_loop_count(void *stream, int count);

class Rva00041004
{
public:
    virtual ~Rva00041004();
    int m_unk04; // +4
    CRITICAL_SECTION m_cs; // +8
    unsigned char m_flag; // +0x20
};

class Rva0010F24F
{
public:
    void rva0010F24F();
};

class Rva0010F26E
{
public:
    void rva0010F26E();
};

struct Rva0010F557Mid
{
    char pad[0x38];
    Rva00041004 lock; // +0x38
};

struct Rva0010F557Inner
{
    char pad0[8]; // +0..+7
    void *m_stream; // +8
    Rva0010F557Mid *m_outer; // +0x0C
};

class Rva0010F557
{
public:
    void rva0010F557();
private:
    char m_pad0[8]; // +0..+7
    Rva0010F557Inner *m_inner; // +8
    int m_loopCount; // +0x0C
};

struct Rva0010F557Guard
{
    Rva00041004 *m_target; // +0
    unsigned char m_locked; // +4
};

void Rva0010F557::rva0010F557()
{
    Rva00041004 *p;
    Rva0010F557Inner *inner = m_inner;
    if (inner != 0) {
        Rva0010F557Mid *o = inner->m_outer;
        if (o == 0)
            p = 0;
        else
            p = (Rva00041004 *)((char *)o + 0x38);
    } else
        p = 0;
    Rva0010F557Guard g;
    g.m_target = p;
    g.m_locked = 0;
    ((Rva0010F24F *)&g)->rva0010F24F();
    void *s = m_inner->m_stream;
    if (s != 0)
        AIL_set_stream_loop_count(s, m_loopCount);
    if (g.m_locked != 0)
        ((Rva0010F26E *)&g)->rva0010F26E();
}
