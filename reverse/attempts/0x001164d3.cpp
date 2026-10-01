// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z
// partial score=0.9 date=2026-10-01
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile *);
class Rva0036CA00Str {
    void *m_item;
public:
    __declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &other);
    ~Rva0036CA00Str();
};
Rva0036CA00Str::Rva0036CA00Str(const Rva0036CA00Str &other) : m_item(other.m_item) {
    if (m_item) InterlockedIncrement((long volatile *)((char *)m_item + 4));
}

class Base04 {
public:
    Base04() : m_04(0) {}
    volatile int m_04;
};

extern "C" char Rva001164D3_vftable;

class Rva001164D3 : public Base04 {
public:
    virtual void dummy();
    Rva0036CA00Str m_08;
    Rva001164D3(const Rva0036CA00Str &s);
};

Rva001164D3::Rva001164D3(const Rva0036CA00Str &s) : Base04(), m_08(s) {
}
