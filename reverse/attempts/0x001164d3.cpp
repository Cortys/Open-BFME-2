// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z
// partial score=0.96 date=2026-10-03
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
class Rva0036CA00Str {
    void *m_item;
public:
    __declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &other);
    ~Rva0036CA00Str();
};
struct CountBase {
    volatile int m_count;
    __forceinline CountBase() : m_count(0) {}
};
class Rva001164D3 : public CountBase {
public:
    virtual void dummy();
    Rva001164D3(const Rva0036CA00Str &s);
private:
    Rva0036CA00Str m_str;
};
Rva001164D3::Rva001164D3(const Rva0036CA00Str &s) : m_str(s) {}
