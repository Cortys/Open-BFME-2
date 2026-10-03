// ?rva002B59FF@Rva002B59FF@@QAE_NXZ
// partial score=0.99 date=2026-10-03
// ?rva002B59FF@Rva002B59FF@@QAE_NXZ @0x002B59FF 96B
// cl: /DNDEBUG /MD /EHsc /O1 /Ob2
// stlport
//
// Gap-page unlock draining 002B5xxx: a bool predicate with no stack args (ret,
// not ret 4).  Returns false unless the int at +0xF4 is 0 or 4 and the int
// vector at +0xB0 (start +0x14, finish +0x18) is empty; then it consults two
// singletons and two members.  Evidence: callers 0x002B5A6B (adjacent
// 0x002B5A5F, same-this) and 0x003FA8AA; every callee is rowed
// (0x0023C6A4, 0x002BE8D4, 0x002B5073, 0x0063C6A4, 0x006BE8D4).  Layout is a
// TU-local honest view; the original class identity is unproven, so the class
// is address-named.
//
// 95 of 96 bytes match.  Four findings fixed the body this pass, and they are
// the reusable ones for this shape:
//
//  1. The empty test is `vec.size() <= 0`, not `== 0`.  `size() == 0` folds to
//     the `test ecx,0xfffffffc` fast path that skips the element-size division;
//     only the `<= 0` comparison forces stlport to emit `sar ecx,2` and then
//     `jne`, which is what retail has.
//  2. All three predicate tests branch to the exit blocks the banked body had
//     backwards.  Retail's layout is `xor al,al / pop esi / ret` FIRST and
//     `mov al,1 / pop esi / ret` second, which only happens when every false
//     case is an early `return false` and the function's last statement is
//     `return true`.
//  3. The first singleton is called under a negation: retail's `test al,al` is
//     followed by `je` to the TRUE exit, so a FALSE result answers true.
//  4. The second singleton is NOT negated (its `jne` goes to the false exit) and
//     the mask call is not negated either (its `je` goes to the true exit).
//     Only the first is.
//
// Remaining gap: the single branch at 0x006B5A48, `jne 0x006B5A57` (false exit)
// where this emits `jne` to the true exit.  The `cmp byte [esi+0xe8],al` itself
// matches, so the byte test and its operand are right; only the block this
// branch targets is swapped.  Refuted: `!m_E8`, `m_E8` with an early
// `return false`, inverting the mask test, and splitting the byte test out.
#include <vector>

typedef bool Bool;

class Rva0023C6A4
{
public:
	bool rva0023C6A4();
};

class Rva002BE8D4
{
public:
	bool rva002BE8D4();
};

class Rva002B5073
{
public:
	bool rva002B5073(int mask);
};

#define TheRva00DFE78C (*(Rva0023C6A4 **)0x00DFE78C)
#define TheRva00DFEF18 (*(Rva002BE8D4 **)0x00DFEF18)

struct Rva002B59FFHolder
{
	char pad[0x14];
	_STL::vector<int> vec;	// +0x14
};

class Rva002B59FF
{
public:
	bool rva002B59FF();

private:
	char pad00_B0[0xB0];
	Rva002B59FFHolder *m_B0;
	char padB4_CC[0xCC - 0xB4];
	char vecCC[12];
	char padD8_E8[0xE8 - 0xD8];
	bool m_E8;
	char padE9_F4[0xF4 - 0xE9];
	int m_F4;
};

// ?rva002B59FF@Rva002B59FF@@QAE_NXZ present-unmatched
bool Rva002B59FF::rva002B59FF()
{
	if (m_F4 != 0 && m_F4 != 4)
		return false;
	if (m_B0->vec.size() > 0)
		return false;
	if (!TheRva00DFE78C->rva0023C6A4())
		return true;
	if (TheRva00DFEF18->rva002BE8D4())
		return false;
	if (m_E8 == 0) {
		if (((Rva002B5073 *)this)->rva002B5073(4))
			return false;
	}
	return true;
}