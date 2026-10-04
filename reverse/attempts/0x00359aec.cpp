// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.97 date=2026-10-04
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z
// partial score=0.97 date=2026-10-04
// cl: /O1 /EHsc
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z @0x00359AEC 109B:
// guard-loop vector-apply over the pointer vector at +0/+4 with the +0xC index
// saved/zeroed/restored through an EH scope-table frame; per-iteration call
// through a member-pointer functor held in the ApplyArg bundle.
// prev Rva003598D3Ctor next ListInsert; caller 0x00359BFD in 0x00359BE8;
// same 109B guard-loop family as 0x0030C9E6 and 0x005D49F9.
//
// RECOVERED SHAPE (this spelling, 107B/37 insns vs retail 109B/43). The
// earlier 0.95 bank stood at 104B and read its remaining 5 bytes as "purely
// register allocation". That reading was wrong about the cause: the blocker was
// that the guard cached the SAVED VALUE, which forced MSVC 7.1 to assign ebx to
// it and spill ebx in the prolog. Dropping the cached value -- the guard holds
// only the pointer and an empty body, the save/zero/restore is three explicit
// statements around a plain scope -- frees ebx, and ebx then goes to `arg`,
// which is what produces retail's in-loop
//
//   push ebx ; mov ebx,[ebp+8] ; ... push [ebx+4] ; call [ebx] ; pop ebx
//
// that no earlier spelling could reach. /O1 /EHsc, virtual dtor for the scope
// table (an inlinable dtor emits no scope table at all).
//
// THREE COMPILER FACTS MEASURED IN A SCRATCH TU (build/scratch359*.cpp), worth
// keeping because they are not guessable from the language:
//
//  1. At /O1 this compiler emits `*p = 0` as `and dword ptr [p],0` -- a
//     read-modify-write, not a store. NO spelling of a literal zero produces
//     `mov [p],reg`: not `*p = 0`, not `int z = 0; *p = z;`, not `*p = *p * 0`.
//     The store only becomes `xor reg,reg ; mov [p],reg` when the zero is the
//     VALUE OF A VARIABLE the loop then uses, so CSE keeps it in a register.
//     Retail's `xor ecx,ecx` / `mov [esi],ecx` therefore proves `*pidx = 0` is
//     written from a variable, not a literal.
//
//  2. That same variable zero is what pins the loop INDEX to ecx. Writing the
//     pre-header store as `*pidx = i` with `unsigned i = 0` yields retail's
//     register mapping end to end: `xor ecx,ecx` for the zero, and ecx as the
//     index through `mov [eax+ecx*4]`, `mov ecx,eax`, `cmp ecx,edx`, `jb`.
//
//  3. `*pidx = i + 1` does NOT give retail's `mov eax,ecx / inc eax`; that pair
//     comes from `*pidx = i` with the increment folded to the bottom of the
//     body, which is also what makes retail's back edge target `inc eax` and
//     skip the `mov eax,ecx` pre-header line.
//
// REMAINING WALL (107B vs 109B). Exactly one instruction plus two register
// renames remain, and all three are the same root cause -- [ebp-0x10]:
//
//   retail  mov [ebp-0x10],esi        <- the guard's POINTER
//           mov [ebp-0x14],eax        <- the saved value
//   this    mov [ebp-0x10],eax        <- saved value here
//           mov [ebp-0x14],esi        <- pointer here
//
// The scope table sits at [ebp-0x18] and the SEH cookie at [ebp-0xc], so with
// `sub esp,0xc` retail has room for exactly three local slots, and this body
// spends two of them on the guard's pointer and the saved value, one slot each.
// Giving the guard a second member -- any second member, an int pad included --
// grows the frame to `sub esp,0x10` and is therefore ruled out (measured, both
// an int pad and a second pointer). The scope-table value itself is uninitialised
// stack garbage in retail (0xbfb1cc here) and is not compared; only the slot
// assignment is.
//
// Remaining candidate levers, none tried: make the saved value live in the guard
// and the pointer in a plain local so the two swap slots, or keep both in one
// slot by restoring through esi instead of a cached pointer.
//
// IDENTITY IS NOT PROVEN. Class, member offsets and the ApplyArg functor shape
// are carried from the banked 0.94 attempt and this body's own prolog
// (esi = this+0xC, edi = this, [edi]/[edi+4] as the vector bounds). The
// member-pointer call through [arg] and [arg+4] matches retail's
// `push [ebx+4] ; call [ebx]`, so the ApplyArg bundle is two dwords at +0/+4
// and the callee takes one pushed argument.
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
// ?rva00359AEC@Rva00359AEC@@QAEXPAUApplyArg00359AEC@@@Z present-unmatched
void Rva00359AEC::rva00359AEC(ApplyArg00359AEC *arg)
{
	int *pidx = &m_idx;
	int saved = *pidx;
	{
		GuardR00359AEC g(pidx);
		*pidx = 0;
		unsigned i = 0;
		while (i < (unsigned)(((int)((char *)m_end - (char *)m_begin)) >> 2)) {
			ElemThunk00359AEC *e = ((ElemThunk00359AEC **)m_begin)[i];
			*pidx = i + 1;
			(e->*arg->m_fn)(arg->m_ctx);
			i = *pidx;
		}
	}
	*pidx = saved;
}