// ?rva005D49F9@Rva005D49F9@@QAEXPAUApplyArg005D49F9@@@Z
// partial score=0.91 date=2026-09-30
// ?rva005D49F9@Rva005D49F9@@QAEXPAUApplyArg005D49F9@@@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /EHsc
// 0x005D49F9 109B unlock lane: vector-apply with RAII guard over m_idx at +0xC.
// this+0/+4 = begin/end (dword array), +8 = cap (untouched), +0xC = loop index.
// Guard {ptr,saved} inlines to save-zero-restore with EH prolog; loop is
// m_idx=i+1 with indirect thiscall via member-pointer functor {fn,ctx}.
// Ours 107B/43 insns vs retail 109B/43: this in esi vs edi (ptr in edi vs esi),
// push ecx*2 vs sub esp,0xc, test vs sar for empty check, lea vs mov+inc for i+1,
// jl vs jb for unsigned compare. Shape-lever rows 25/26 checked (def order, /Os).
struct ElemThunk005D49F9 { void Call(void *ctx); };
typedef void (ElemThunk005D49F9::*ElemFn005D49F9)(void *);
struct ApplyArg005D49F9 {
    ElemFn005D49F9 m_fn;
    void *m_ctx;
};
struct Guard005D49F9 {
    int *m_ptr;
    int m_saved;
    ~Guard005D49F9() { *m_ptr = m_saved; }
};
class Rva005D49F9 {
public:
    void *m_begin;
    void *m_end;
    void *m_cap;
    int m_idx;
    void rva005D49F9(ApplyArg005D49F9 *arg);
};
// ?rva005D49F9@Rva005D49F9@@QAEXPAUApplyArg005D49F9@@@Z present-unmatched
void Rva005D49F9::rva005D49F9(ApplyArg005D49F9 *arg)
{
    Guard005D49F9 g;
    g.m_ptr = &m_idx;
    g.m_saved = m_idx;
    m_idx = 0;
    int n = (int)((char *)m_end - (char *)m_begin) >> 2;
    if (n != 0) {
        int i = 0;
        do {
            m_idx = i + 1;
            (((ElemThunk005D49F9*)((void **)m_begin)[i])->*arg->m_fn)(arg->m_ctx);
            i = m_idx;
            n = (int)((char *)m_end - (char *)m_begin) >> 2;
        } while (i < n);
    }
}
