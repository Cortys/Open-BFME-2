// ?set@?$StringBase@G@@QAEXABV1@@Z
// partial score=0.91 date=2026-09-30
// ?set@$StringBase@G@@QAEXABV1@@Z
// partial score=0.91 date=2026-09-30
// cl: /O2 /EHsc
// ?set@?$StringBase@G@@QAEXPBGH@Z @0x000371E0 321B
// ?concat@?$StringBase@G@@QAEXPBGH@Z @0x00037410 134B
// Wide StringBase (ptr,len) setter: alias check then length branch, wrapper
// CharSource on the stack for the copy, fast in-place when unique with spare
// capacity else allocate via the rowed byte allocator with the 0x737472 tag.
// Wide (ptr,len) concat: empty length returns, null buffer forwards to the
// 2-arg set, else wraps (str,len) and grows via ensureUniqueBufferOfSize.
// Evidence: pinned names, set callers at 0x00005679 0x0000568A 0x000066A2
// 0x00037818 0x00037E25 0x00037ED8, concat callers at 0x000056AE 0x000056BF
// 0x000066D2 0x00006A4C, wrapper vtable 0x00BBE798 slots getLength
// 0x00144010 copy-mid 0x00035E70 getChars 0x00035EA0, releaseBuffer 0x00036E70,
// ensure 0x00036F00, allocator 0x000307F0. Model/flags donor TU
// Code/Libraries/Source/WWVegas/WWLib/StringBaseWideCharSourceSet.cpp // cl: /O2
// plus /EHsc for the handler 0x0075CD08 scope unwind of the stack source.
#include <string.h>
typedef unsigned short wchar_t;

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
class StringBase {
private:
    struct Header {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };
    Header *m_data;
    void releaseBuffer();
    void ensureUniqueBufferOfSize(int newLen, bool keepData, const CharSource<T> *src1, const CharSource<T> *src2);
public:
    void set(const T *str, int len);
    void set(const StringBase &str);
    void concat(const T *str, int len);
};

class WideStrLenSource : public CharSource<wchar_t> {
    const wchar_t *m_str;
    int m_len;
public:
    WideStrLenSource(const wchar_t *s, int l) : m_str(s), m_len(l) {}
    ~WideStrLenSource() {}
    virtual int getLength() const { return m_len; }
    virtual void _gap() const {}
    virtual int getChars(wchar_t *dest) const {
        memcpy(dest, m_str, m_len * 2);
        return m_len;
    }
};

// ?getLength@WideStrLenSource@@UBEHXZ present-unmatched
// ?_gap@WideStrLenSource@@UBEXXZ present-unmatched
// ??0WideStrLenSource@@QAE@PBGH@Z present-unmatched
// ??1WideStrLenSource@@QAE@XZ present-unmatched
template <>
void StringBase<wchar_t>::set(const wchar_t *str, int len)
{
    if (m_data != 0 && str == &m_data->data[0])
        return;
    if (len != 0) {
        WideStrLenSource src(str, len);
        const CharSource<wchar_t> &ref = src;
        if (m_data != 0 && m_data->capacity > len && m_data->ref_count == 1) {
            int got = ref.getChars(&m_data->data[0]);
            m_data->length = (unsigned short)got;
            m_data->data[m_data->length] = 0;
            return;
        }
        int bytes = len * 2 + 10;
        if (bytes > 0x7fff)
            throw 1;
        bytes = ((bytes + 3) / 4) * 4;
        Header *fresh = (Header *)_STL::allocator<char>::allocate(bytes, (const void *)0x737472);
        fresh->ref_count = 1;
        fresh->capacity = (unsigned short)((unsigned int)(bytes - 8) / 2u);
        fresh->length = 0;
        int got = ref.getChars(&fresh->data[0]);
        fresh->length = (unsigned short)got;
        fresh->data[fresh->length] = 0;
        releaseBuffer();
        m_data = fresh;
        return;
    }
    releaseBuffer();
}

template <>
void StringBase<wchar_t>::concat(const wchar_t *str, int len)
{
    if (len == 0)
        return;
    if (m_data != 0) {
        WideStrLenSource src(str, len);
        ensureUniqueBufferOfSize(m_data->length + len, true, 0, &src);
        return;
    }
    set(str, len);
}

class Rva00041004
{
public:
    virtual ~Rva00041004();
    Rva00041004(int x);
    int m_unk04;
    unsigned char m_cs[24];
    unsigned char m_flag;
};

Rva00041004 *Rva00035DF0Get();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

struct LockGuard {
    LockGuard(Rva00041004 *l) : m_lock(l) { if (!l->m_flag) EnterCriticalSection(&l->m_cs); }
    ~LockGuard() { if (!m_lock->m_flag) LeaveCriticalSection(&m_lock->m_cs); }
    Rva00041004 *m_lock;
};

// ?set@?$StringBase@G@@QAEXABV1@@Z @ 0x00037150 (132B). Thread-safe copy via lock with self-check.
template <>
void StringBase<wchar_t>::set(const StringBase<wchar_t> &str)
{
    Rva00041004 *lock = Rva00035DF0Get();
    LockGuard guard(lock);
    const StringBase<wchar_t> *src = &str;
    if (src != this) {
        releaseBuffer();
        Header *data = src->m_data;
        m_data = data;
        if (data) {
            ++data->ref_count;
        }
    }
}
