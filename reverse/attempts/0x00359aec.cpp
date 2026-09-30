// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.91 date=2026-09-30
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /EHsc
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z @0x00359AEC 109B: guard-loop vector-apply over pointer vector at +0/+4 with +0xC index save-zero-restore; per-iter member-pointer functor via bundle; caller 0x00359BFD in 0x00359BE8; prev Rva003598D3Ctor next ListInsert; same 109B family as 0x0030C9E6 stash.
struct ElemThunk00359AEC { void Call(void *ctx); };
typedef void (ElemThunk00359AEC::*ElemFn00359AEC)(void *);
struct ApplyArg00359AEC {
	ElemFn00359AEC m_fn;
	void *m_ctx;
};
struct Guard00359AEC {
	int *m_ptr;
	int m_saved;
	~Guard00359AEC() { *m_ptr = m_saved; }
};
class Rva00359AEC {
public:
	void *m_begin;
	void *m_end;
	void *m_cap;
	int m_idx;
	void rva00359AEC(ApplyArg00359AEC *arg);
};
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z present-unmatched
void Rva00359AEC::rva00359AEC(ApplyArg00359AEC *arg)
{
	Guard00359AEC g;
	g.m_ptr = &m_idx;
	g.m_saved = m_idx;
	m_idx = 0;
	int n = (int)((char *)m_end - (char *)m_begin) >> 2;
	if (n != 0) {
		int i = 0;
		do {
			m_idx = i + 1;
			(((ElemThunk00359AEC *)((void **)m_begin)[i])->*arg->m_fn)(arg->m_ctx);
			i = m_idx;
			n = (int)((char *)m_end - (char *)m_begin) >> 2;
		} while (i < n);
	}
}
