// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.995 date=2026-10-04
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// cl: /O1 /EHsc
// v13: the saved-value read moves INTO the guard's constructor and the
// guard's members are declared (saved, ptr) with the ptr initialized first in
// the init list and saved assigned in the ctor body. That is what makes MSVC
// /O1 emit the EH scope table first (matching retail byte-for-byte) and assign
// [ebp-0x10] to the pointer and [ebp-0x14] to the saved counter. Guard region
// now matches retail instruction for instruction.
// Remaining: retail mov eax,ecx reloads the induction variable at the loop head
// where /O1 folds the first iteration back to xor eax,eax.
struct ElemThunk00359AEC { void Call(void *ctx); };
typedef void (ElemThunk00359AEC::*ElemFn00359AEC)(void *);
struct ApplyArg00359AEC {
	ElemFn00359AEC m_fn;
	void *m_ctx;
};
struct GuardR00359AEC {
	int m_saved;
	int *m_ptr;
	GuardR00359AEC(int *p) : m_ptr(p), m_saved(0) { m_saved = *p; }
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
	unsigned i = 0;
	int saved;
	{
		GuardR00359AEC g(pidx);
		saved = g.m_saved;
		*pidx = 0;
		while (i < (unsigned)(((int)((char *)m_end - (char *)m_begin)) >> 2)) {
			*pidx = *pidx + 1;
			ElemThunk00359AEC *e = ((ElemThunk00359AEC **)m_begin)[i];
			(e->*arg->m_fn)(arg->m_ctx);
			i = *pidx;
		}
	}
	*pidx = saved;
}