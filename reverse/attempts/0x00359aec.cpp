// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.95 date=2026-10-04
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.95 date=2026-10-04
// cl: /O1 /EHsc
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z @0x00359AEC 109B:
// guard-loop vector-apply over the pointer vector at +0/+4 with the +0xC index
// saved/zeroed/restored through an EH scope-table frame; per-iteration call
// through a member-pointer functor held in the ApplyArg bundle.
// prev Rva003598D3Ctor next ListInsert; caller 0x00359BFD in 0x00359BE8;
// same 109B guard-loop family as 0x0030C9E6 and 0x005D49F9.
//
// RECOVERED SHAPE (this spelling). Two changes over the 0.94 bank carry the
// body to retail's structure:
//
//  1. The guard is a VIRTUAL-destructor type. Retail's
//     `mov [ebp-0x18], <scope>` after __SEH_prolog is the EH scope table, and
//     MSVC 7.1 only emits one for a local object whose destructor it has to
//     register as a cleanup funclet. A trivially-inlinable destructor
//     (`*m_ptr = m_saved`) is fully inlined at normal exit and NO scope table
//     appears -- that is the wall the earlier spellings hit. Making the
//     destructor virtual forces registration while still letting the fast path
//     inline the restore, which is exactly retail's shape.
//
//  2. The guard fields are declared (m_saved, m_ptr) and set through a
//     constructor `GuardR00359AEC(saved, ptr)`. Declaring m_ptr first makes
//     MSVC spill ebx for the saved value in the prolog and load ebx again as
//     the argument; retail instead reloads the argument from [ebp+8] INSIDE the
//     loop and keeps the saved value in eax. The reversed declaration is what
//     moved the saved-value store to [ebp-0x14] and the scope slot to
//     [ebp-0x10], the slots retail uses.
//
//  3. The element count is `(int)((char*)m_end - (char*)m_begin) >> 2`, i.e. an
//     explicit signed cast around the byte difference before the shift. That
//     keeps MSVC emitting a real `sar` for the count instead of its
//     `test reg,0xfffffffc` alignment idiom, which is what produces retail's
//     `sar eax,2 / je` entry test and its `sar edx,2 / cmp / jb` back edge. The
//     loop counter is `unsigned`, which is what makes the back edge `jb`
//     (unsigned) rather than `jl` (signed).
//
// IDENTITY IS NOT PROVEN. Class, member offsets and the ApplyArg functor shape
// are carried from the banked 0.94 attempt and this body's own prolog
// (esi = this+0xC, edi = this, [edi]/[edi+4] as the vector bounds). The
// member-pointer call through [arg] and [arg+4] matches retail's
// `push [ebx+4] ; call [ebx]`, so the ApplyArg bundle is two dwords at +0/+4
// and the callee takes one pushed argument.
//
// REMAINING WALL (104B vs retail 109B, all register allocation). The body now
// reproduces retail's __SEH_prolog cookie form, `sub esp,0xc / push / push`,
// the scope-table store at [ebp-0x18], the [ebp-0x10]/[ebp-0x14] state slots,
// the `sar` entry test and the unsigned `jb` back edge. What is left is one
// register-allocation difference that cascades:
//
//   retail keeps the saved index in eax and reloads the argument into ebx
//   INSIDE the loop (`push ebx ; mov ebx,[ebp+8]` after the entry je), so ebx
//   is never live across the prolog. This spelling keeps the saved index in
//   ebx and passes the argument in edx (`mov edx,[ebp+8]`), which costs the
//   extra `push ebx` in the prolog and the missing `pop ebx`.
//
// It follows that retail's `xor ecx,ecx` (zero) and `mov [ebp-4],ecx` (store
// that zero to a slot that is neither the scope table nor the saved value)
// imply ecx is the loop-index register for the whole function, with the count
// in eax/edx. This spelling zeroes eax instead and keeps the index there.
//
// Tried and rejected, all 104B or shorter with the register assignment
// unchanged: caching fn/ctx in locals before the guard (118B, worse); a
// running element pointer; ++i with [i-1] indexing (93B, drops the entry
// test); separate k/bytes locals for the [ebp-4] slot; unsigned n; do/while
// against while; reversed guard field order alone. Caching &m_idx in a local
// is load-bearing -- it is what puts this in edi and &m_idx in esi.
//
// So the next lever is not the guard or the loop bounds, both of which are
// settled. It is getting MSVC 7.1 to allocate ebx inside the loop rather than
// in the prolog, which most likely needs the argument to be used only after
// the entry test -- i.e. a do/while whose body reads arg through a value the
// allocator treats as short-lived.
struct ElemThunk00359AEC { void Call(void *ctx); };
typedef void (ElemThunk00359AEC::*ElemFn00359AEC)(void *);
struct ApplyArg00359AEC {
	ElemFn00359AEC m_fn;
	void *m_ctx;
};
struct GuardR00359AEC {
	int m_saved;
	int *m_ptr;
	GuardR00359AEC(int v, int *p) : m_saved(v), m_ptr(p) {}
	virtual ~GuardR00359AEC() { *m_ptr = m_saved; }
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
	int saved = *pidx;
	*pidx = 0;
	GuardR00359AEC g(saved, pidx);
	unsigned i = 0;
	int n = ((int)((char *)m_end - (char *)m_begin)) >> 2;
	while (i < (unsigned)n) {
		*pidx = i + 1;
		ElemThunk00359AEC *e = ((ElemThunk00359AEC **)m_begin)[i];
		(e->*arg->m_fn)(arg->m_ctx);
		i = *pidx;
		n = ((int)((char *)m_end - (char *)m_begin)) >> 2;
	}
}