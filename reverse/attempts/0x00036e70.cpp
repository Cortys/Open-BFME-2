// ?releaseBuffer@?$StringBase@G@@AAEXXZ
// partial score=0.93 date=2026-09-27
// ?releaseBuffer@?$StringBase@G@@AAEXXZ
// partial score=0.93 date=2026-09-27
// cl: /O2 /EHs
// ?releaseBuffer@?$StringBase@G@@AAEXXZ present-unmatched
struct CRITICAL_SECTION
{
    unsigned char data[24];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section);
extern "C" void __cdecl free(void *block);

class Rva00041004
{
public:
    virtual ~Rva00041004();
    Rva00041004(int x);
    int m_unk04;
    CRITICAL_SECTION m_cs;
    unsigned char m_flag;
};

Rva00041004 *Rva00035DF0Get();

struct WideLockGuard
{
    Rva00041004 *m_lock;
    WideLockGuard(Rva00041004 *l) : m_lock(l)
    {
        if (!m_lock->m_flag)
            EnterCriticalSection(&m_lock->m_cs);
    }
    ~WideLockGuard()
    {
        if (!m_lock->m_flag)
            LeaveCriticalSection(&m_lock->m_cs);
    }
};

template <typename T>
class StringBase
{
private:
    struct Header
    {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };
    Header *m_data;
    void releaseBuffer();
};

template <>
void StringBase<unsigned short>::releaseBuffer()
{
    WideLockGuard guard(Rva00035DF0Get());
    if (m_data != 0) {
        if (--m_data->ref_count == 0)
            free(m_data);
        m_data = 0;
    }
}
