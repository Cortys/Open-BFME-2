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

class Rva00041004
{
public:
    bool lock(int time);

private:
    void *m_vtable; // +0
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
