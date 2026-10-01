// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z
// partial score=0.95 date=2026-10-01
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// ??0Rva001164D3@@QAE@ABVRva0036CA00Str@@@Z retail 0x001164D3 34B: vptr +0,
// zeroed dword +4, Rva0036CA00Str copy-constructed at +8 (rowed copy ctor
// 0x000A8C7C). Retail order: push arg, lea ecx,[esi+8], mov [esi+4],0, vptr
// store, call. This model (the +4/+8 pair as a holder BASE with a forceinline
// ctor) is the only form found that emits the lea before the +4 store, but as
// a base it puts the vptr store after the call (3 diff bytes). The member form
// of the same holder keeps lea-then-store but leaves the vptr store first
// (volatile store blocks its sinking; a plain int becomes and [esi+4],0; a
// float goes x87). The base-int plus member-Str model has the right vptr
// position but the lea after the store (9 diff bytes).
class Rva0036CA00Str {
    void *m_item;
public:
    __declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &other);
    ~Rva0036CA00Str();
};
extern "C" char Rva001164D3_vftable;
struct Holder {
    volatile int m_count;
    Rva0036CA00Str m_str;
    __forceinline Holder(const Rva0036CA00Str &s) : m_count(0), m_str(s) {}
};
class Rva001164D3 : public Holder {
public:
    virtual void dummy();
    Rva001164D3(const Rva0036CA00Str &s);
};
Rva001164D3::Rva001164D3(const Rva0036CA00Str &s) : Holder(s) {
}
