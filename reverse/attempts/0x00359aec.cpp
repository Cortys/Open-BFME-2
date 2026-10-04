// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.94 date=2026-10-04
// cl: /O1 /EHsc
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z @0x00359AEC 109B:
// guard-loop vector-apply over the pointer vector at +0/+4 with the +0xC index
// saved/zeroed/restored through an EH scope-table frame; per-iteration call
// through a member-pointer functor held in the ApplyArg bundle.
// prev Rva003598D3Ctor next ListInsert; caller 0x00359BFD in 0x00359BE8;
// same 109B guard-loop family as 0x0030C9E6 and 0x005D49F9.
//
// This spelling reproduces retail's prolog exactly (__SEH_prolog, then
// sub esp,0xc / push esi / push edi / mov edi,ecx / lea esi,[edi+0xC]) which
// needs three contiguous frame slots, so the guard carries the pad member.
// Caching &m_idx in a local is what moves `this` into edi and &m_idx into esi
// as retail has it; a signed count keeps retail's `sar eax,2 ; je` instead of
// the `test eax,0xfffffffc ; jbe` an unsigned bound produces.
struct ElemThunk00359AEC { void Call(void *ctx); };
typedef void (ElemThunk00359AEC::*ElemFn00359AEC)(void *);
struct ApplyArg00359AEC {
	ElemFn00359AEC m_fn;
	void *m_ctx;
};
struct Guard00359AEC {
	int *m_ptr;
	int m_saved;
	int m_pad;
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
	int *pidx = &m_idx;
	Guard00359AEC g;
	g.m_ptr = pidx;
	g.m_saved = *pidx;
	*pidx = 0;
	int n = ((char *)m_end - (char *)m_begin) >> 2;
	if (n != 0) {
		int i = 0;
		do {
			*pidx = i + 1;
			(((ElemThunk00359AEC *)((void **)m_begin)[i])->*arg->m_fn)(arg->m_ctx);
			i = *pidx;
			n = ((char *)m_end - (char *)m_begin) >> 2;
		} while (i < n);
	}
}