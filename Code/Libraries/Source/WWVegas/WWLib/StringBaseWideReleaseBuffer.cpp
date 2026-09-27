// cl: /O2 /EHs
// ?releaseBuffer@?$StringBase@D@@AAEXXZ @0x00036410 133B
// ?releaseBuffer@?$StringBase@G@@AAEXXZ @0x00036E70 133B
// Narrow/wide StringBase releaseBuffer twins: scoped lock guard, refcount dec, free via rowed _free, null.
// Evidence: BFME2 exports ?releaseBuffer@?$StringBase@D@@AAEXXZ (narrow) and ?releaseBuffer@?$StringBase@G@@AAEXXZ (wide),
// pinned same bodies for AsciiString/UnicodeString teardown and public spellings; wide callers at 0x0000288A
// 0x000372EB 0x00037309 0x000373F2 0x00037402 plus set/ensureUnique; narrow callers at 0x0000216D 0x00002179
// 0x00002429 0x00002EC5 plus Version/ParticleSystemInfo dtors;
// ZH donor UnicodeString::releaseBuffer (GeneralsMD .../Common/System/UnicodeString.cpp) with ScopedCriticalSection
// plus --refcount==0 free plus null; BFME2 locks are Rva00041004 via rowed Rva00035C90Get (narrow singleton 0x35C90,
// object 0x9E0828) and Rva00035DF0Get (wide singleton 0x35DF0, object 0x9E0850), flag +0x20 bypass, cs +0x08,
// with IAT Enter/Leave 0xBBA200/0xBBA204; rowed _free 0x30830.
// Model/flags donor TU Code/Libraries/Source/WWVegas/WWLib/StringBaseWideStrLenSet.cpp // cl: /O2 /EHsc
// plus /EHs for the extern C free EH frame (with /EHsc the extern C free is nothrow and the manual frame vanishes;
// throw() on the dllimport Enter/Leave keeps their states out, leaving the single free state).
// Guard is 8B (ptr + state byte, sub esp,8 + mov byte [esp+0x0C],1 after acquire, evidenced by frame
// and by rowed guard dtor 0x000358B0 in StringBaseLockGuardDtor.cpp with m_lock +0 and bool m_locked +4).
typedef unsigned short wchar_t;

struct CRITICAL_SECTION
{
    unsigned char data[24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section) throw();

class WideLock;

class Rva00041004
{
public:
    virtual ~Rva00041004();
    Rva00041004(int x);

    int m_unk04;
    CRITICAL_SECTION m_cs;
    unsigned char m_flag;

    friend class WideLock;
};

Rva00041004 *Rva00035DF0Get();
Rva00041004 *Rva00035C90Get();

extern "C" void __cdecl free(void *block);

template <typename T>
class StringBase
{
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

class WideLock
{
    Rva00041004 *m_lock;
    unsigned char m_state;

public:
    // ??0WideLock@@QAE@PAVRva00041004@@@Z present-unmatched
    __forceinline WideLock(Rva00041004 *lock) : m_lock(lock)
    {
        if (!m_lock->m_flag)
            EnterCriticalSection(&m_lock->m_cs);
        m_state = 1;
    }

    // ??1WideLock@@QAE@XZ present-unmatched
    __forceinline ~WideLock()
    {
        if (!m_lock->m_flag)
            LeaveCriticalSection(&m_lock->m_cs);
    }
};

template <>
void StringBase<wchar_t>::releaseBuffer()
{
    WideLock lock(Rva00035DF0Get());
    if (m_data)
    {
        if (--m_data->ref_count == 0)
            free(m_data);
        m_data = 0;
    }
}

template <>
void StringBase<char>::releaseBuffer()
{
    WideLock lock(Rva00035C90Get());
    if (m_data)
    {
        if (--m_data->ref_count == 0)
            free(m_data);
        m_data = 0;
    }
}
