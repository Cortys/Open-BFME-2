// ?rva0030C9E6@Rva0030C9E6@@QAEXPAUApplyArg0030C9E6@@@Z
// partial score=0.91 date=2026-09-30
// ?rva0030C9E6@Rva0030C9E6@@QAEXPAUApplyArg0030C9E6@@@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /EHsc
// 0x0030C9E6 109B unlock: same guard-loop vector-apply wall as 0x005D49F9
// (same scope table g_00BFB1CC, same 109B shape). this+0/+4 begin/end,
// +8 cap untouched, +0xC loop index with RAII guard save-zero-restore;
// loop m_idx=i+1 with indirect thiscall via member-pointer functor.
// Ours 107B/43 vs retail 109B/43: this in esi vs edi, push*2 vs sub esp,
// test vs sar, lea vs mov+inc, jl vs jb. Def-order swap tried, no change.
// t=8 model=muse-03
struct ElemThunk0030C9E6 { void Call(void *ctx); };
typedef void (ElemThunk0030C9E6::*ElemFn0030C9E6)(void *);
struct ApplyArg0030C9E6 {
    ElemFn0030C9E6 m_fn;
    void *m_ctx;
};
struct Guard0030C9E6 {
    int *m_ptr;
    int m_saved;
    ~Guard0030C9E6() { *m_ptr = m_saved; }
};
class Rva0030C9E6 {
public:
    void *m_begin;
    void *m_end;
    void *m_cap;
    int m_idx;
    void rva0030C9E6(ApplyArg0030C9E6 *arg);
};
// ?rva0030C9E6@Rva0030C9E6@@QAEXPAUApplyArg0030C9E6@@@Z present-unmatched
void Rva0030C9E6::rva0030C9E6(ApplyArg0030C9E6 *arg)
{
    Guard0030C9E6 g;
    g.m_ptr = &m_idx;
    g.m_saved = m_idx;
    m_idx = 0;
    int n = (int)((char *)m_end - (char *)m_begin) >> 2;
    if (n != 0) {
        int i = 0;
        do {
            m_idx = i + 1;
            (((ElemThunk0030C9E6*)((void **)m_begin)[i])->*arg->m_fn)(arg->m_ctx);
            i = m_idx;
            n = (int)((char *)m_end - (char *)m_begin) >> 2;
        } while (i < n);
    }
}
