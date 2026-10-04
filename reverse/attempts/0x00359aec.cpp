// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.98 date=2026-10-04
// cl: /O1 /EHsc
// v10: v0's register plan (index in eax, `i` live so the zero-store is
// `xor reg,reg` / `mov [esi],reg`) but retail's STATEMENT ORDER in the body:
// retail bumps the shared counter FIRST and loads the element with the
// pre-bump index afterwards, because ecx still holds the entry index when the
// load at +66 runs. So the source order is bump-then-load-at-old-index.
struct ElemThunk00359AEC { void Call(void *ctx); };
typedef void (ElemThunk00359AEC::*ElemFn00359AEC)(void *);
struct ApplyArg00359AEC {
	ElemFn00359AEC m_fn;
	void *m_ctx;
};
struct GuardR00359AEC {
	int *m_ptr;
	GuardR00359AEC(int *p) : m_ptr(p) {}
	virtual ~GuardR00359AEC() {}
};
class Rva00359AEC {
public:
	void *m_begin;
	void *m_end;
	void *m_cap;
	int m_idx;
	void rva00359AEC(ApplyArg00359AEC *arg);
};
void Rva00359AEC::rva00359AEC(ApplyArg00359AEC *arg)
{
	int *pidx = &m_idx;
	int saved = *pidx;
	{
		GuardR00359AEC g(pidx);
		*pidx = 0;
		unsigned i = 0;
		while (i < (unsigned)(((int)((char *)m_end - (char *)m_begin)) >> 2)) {
			*pidx = *pidx + 1;
			ElemThunk00359AEC *e = ((ElemThunk00359AEC **)m_begin)[i];
			(e->*arg->m_fn)(arg->m_ctx);
			i = *pidx;
		}
	}
	*pidx = saved;
}