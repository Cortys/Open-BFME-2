// cl: /O1 /MD
// ?lock@Rva00041004@@QAE_NH@Z @0x00041004 32B
// Conditional critical-section enter: returns false unless time == -1,
// returns true without locking when the +0x20 bypass flag is set, else
// enters the +0x08 section and returns true. Evidence: single caller at
// 0x000411E7, IAT EnterCriticalSection at 0x00BBA200, layout with vtable
// at +0 and bypass byte at +0x20 read off retail offsets. Honest
// address-derived name: identity unproven from 32 bytes.

struct CRITICAL_SECTION
{
    unsigned char data[24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(CRITICAL_SECTION *section);

class Rva00041004
{
public:
    virtual ~Rva00041004();
    bool lock(int time);
    Rva00041004(int x);

private:
    int m_unk04; // +4
    CRITICAL_SECTION m_cs; // +8
    unsigned char m_flag; // +0x20
};

bool Rva00041004::lock(int time)
{
    if (time != -1)
        return false;
    if (m_flag != 0)
        return true;
    EnterCriticalSection(&m_cs);
    return true;
}

// ??0Rva00041004@@QAE@H@Z @0x000411C1 49B
// Initializer: zeroes +0x04, inits the +0x08 section, clears the +0x20
// bypass flag, then takes the lock when the arg is 0. Evidence: callers
// at 0x00035CC8 0x00035E28 0x000A8935 0x0010F037 0x001491E7 0x006CB838
// 0x007ACDB3, vtable 0x007C16DC, IAT InitializeCriticalSection.
Rva00041004::Rva00041004(int x) : m_unk04(0), m_flag(0)
{
    InitializeCriticalSection(&m_cs);
    if (x == 0)
        lock(-1);
}
