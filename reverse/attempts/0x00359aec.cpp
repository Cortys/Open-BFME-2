// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.985 date=2026-10-04
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// cl: /O1 /EHsc
// v11 (seat5): the banked v10 moved the loop index into a local declared
// BEFORE the guard scope, which puts `unsigned i = 0` ahead of the guard's
// slot spills. That reproduces retail's `xor ecx,ecx` at 359b02 in its real
// position -- the only remaining prolog-order delta v10 had. 9 concrete byte
// diffs left (reloc sites masked, as tools/build.py masks them), down from 12:
// the whole loop body and the epilogue's pop/leave/ret stay byte-identical.
//
// Retail vs this, all that is left:
//   guard region: retail emits the scope table first, then [ebp-0x10]=esi
//     (the pointer) and [ebp-0x14]=eax (the saved counter); this emits
//     [ebp-0x10]=eax, then the scope table, then [ebp-0x14]=esi. Same two
//     slots, swapped occupants and reordered against the scope table.
//   loop head:    retail mov eax,ecx (reload the induction variable) where
//     this emits xor eax,eax (MSVC folds the first iteration to zero).
// A second guard member was measured to grow the frame to `sub esp,0x10`
// and lose `push ebx`/`pop ebx`, so the slot swap is not reachable by adding
// state to the guard.
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
	unsigned i = 0;
	int saved = *pidx;
	{
		GuardR00359AEC g(pidx);
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