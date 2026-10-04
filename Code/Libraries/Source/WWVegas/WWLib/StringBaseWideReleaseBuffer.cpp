// cl: /O2 /EHs
#include "../../../../GameEngine/Include/Common/Rva00041004Lock.h"
// ?releaseBuffer@?$StringBase@D@@AAEXXZ @0x00036410 133B
// ?releaseBuffer@?$StringBase@G@@AAEXXZ @0x00036E70 133B
// ?ensureUniqueBufferOfSize@?$StringBase@D@@AAEXH_NPBV?$CharSource@D@@1@Z @0x000364A0 330B
// ?ensureUniqueBufferOfSize@?$StringBase@G@@AAEXH_NPBV?$CharSource@G@@1@Z @0x00036F00 336B
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
// The shared headers declare these members with the access/virtual spelling
// retail's vftables reference; the ledger row keeps the spelling this TU
// compiled to. Same function, same address: bind the header spelling here.
#pragma comment(linker, "/alternatename:?releaseBuffer@?$StringBase@D@@IAEXXZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")
typedef unsigned short wchar_t;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section) throw();

class WideLock;

Rva00041004 *Rva00035DF0Get();
Rva00041004 *Rva00035C90Get();

extern "C" void __cdecl free(void *block);

#include <string.h>

namespace _STL {
template <class _Tp> class allocator;
template <> class allocator<char> {
public:
    static char *allocate(unsigned int n, const void *hint);
};
}

template <typename T>
class CharSource {
public:
    virtual int getLength() const = 0;
    virtual void _gap() const = 0;
    virtual int getChars(T *dest) const = 0;
};

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
    void ensureUniqueBufferOfSize(int numCharsNeeded, bool preserveData, const CharSource<T> *strToCopy,
        const CharSource<T> *strToCat);
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
    // Retail EH handler75CCE8 -> one-state map -> action75CCE0 selects
    // the full35B guard cleanup358B0: test +4 and clear it after optional leave.
    // Same8B callable view; original guard/template identity is unknown.
    __forceinline ~WideLock()
    {
        if (m_state) {
            if (!m_lock->m_flag)
                LeaveCriticalSection(&m_lock->m_cs);
            m_state = 0;
        }
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

// One template definition, two explicit instantiations: retail's narrow and
// wide bodies (exports 1625/1626) each sit straight after their releaseBuffer
// and compile from this same source. In place when the buffer is unshared and
// big enough; otherwise grow by half when concatenating, cap the 8-byte header
// plus characters at 0x7FFF (throw int, ThrowInfo 0x00CFE2C8), round to four,
// allocate through the rowed byte allocator 0x000307F0 with the 'str' tag,
// copy, append, terminate and release the old buffer. CharSource slot +8 fills
// a buffer and returns the count. Control flow follows Open-BFME-1's matched
// StringBase<T>::ensureUniqueBufferOfSize (game/Libraries/Source/string/StringBase.cpp),
// whose BFME 1 form takes (ptr, len) pairs where BFME 2 takes CharSource
// pointers. Naming the appended destination and count before the += keeps the
// header pointer out of a callee-saved register across the virtual call.
template <typename T>
void StringBase<T>::ensureUniqueBufferOfSize(int numCharsNeeded, bool preserveData,
    const CharSource<T> *strToCopy, const CharSource<T> *strToCat)
{
    if (m_data)
    {
        if (m_data->capacity > numCharsNeeded)
        {
            if (m_data->ref_count == 1)
            {
                if (strToCopy)
                    m_data->length = (unsigned short)strToCopy->getChars(m_data->data);
                if (strToCat)
                {
                    T *dest = m_data->data + m_data->length;
                    unsigned short n = (unsigned short)strToCat->getChars(dest);
                    m_data->length += n;
                }
                m_data->data[m_data->length] = 0;
                return;
            }
        }
        else if (strToCat)
        {
            unsigned grown = m_data->capacity + m_data->capacity / 2;
            if ((int)grown - 1 > numCharsNeeded)
                numCharsNeeded = (int)grown - 1;
        }
    }

    int minBytes = sizeof(int) + 2 * sizeof(unsigned short) + (numCharsNeeded + 1) * sizeof(T);
    if (minBytes > 0x7fff)
        throw 1;
    int actualBytes = (minBytes + 3) / 4 * 4;

    Header *newData = (Header *)_STL::allocator<char>::allocate(actualBytes, (const void *)'str');
    newData->ref_count = 1;
    newData->capacity = (unsigned short)((actualBytes - 8) / sizeof(T));
    if (m_data && preserveData)
    {
        memcpy(newData->data, m_data->data, m_data->length * sizeof(T));
        newData->length = m_data->length;
    }
    else
    {
        newData->length = 0;
    }
    if (strToCopy)
        newData->length = (unsigned short)strToCopy->getChars(newData->data);
    if (strToCat)
    {
        T *dest = newData->data + newData->length;
        unsigned short n = (unsigned short)strToCat->getChars(dest);
        newData->length += n;
    }
    newData->data[newData->length] = 0;

    releaseBuffer();
    m_data = newData;
}

template void StringBase<char>::ensureUniqueBufferOfSize(int, bool, const CharSource<char> *,
    const CharSource<char> *);
template void StringBase<wchar_t>::ensureUniqueBufferOfSize(int, bool, const CharSource<wchar_t> *,
    const CharSource<wchar_t> *);

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?releaseBuffer@UnicodeString@@IAEXXZ=?releaseBuffer@?$StringBase@G@@AAEXXZ")
#pragma comment(linker, "/alternatename:??1AsciiStringMember@@QAE@XZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")
#pragma comment(linker, "/alternatename:??1BfmeWideString000543F5@@QAE@XZ=?releaseBuffer@?$StringBase@G@@AAEXXZ")
#pragma comment(linker, "/alternatename:?releaseBuffer@?$StringBase@G@@QAEXXZ=?releaseBuffer@?$StringBase@G@@AAEXXZ")

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?destroy@CustomAsciiStringShim@@QAEXXZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")
#pragma comment(linker, "/alternatename:?release@Rva0048C200String@@QAEXXZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")
#pragma comment(linker, "/alternatename:?bfmeClearYK@BfmeStringYK@@QAEXXZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")
#pragma comment(linker, "/alternatename:?bfmeFail1033@BfmeSub1033@@QAEXXZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")
