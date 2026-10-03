// ?rva000B65FD@Rva000B65FD@@QAEHXZ
// partial score=0.95 date=2026-10-03
// rva000B65FD
// partial score=0.95 date=2026-10-03
// cl: /O1
// ?rva000B65FD@Rva000B65FD@@QAEHXZ, retail 0x000B65FD, 23B.
// Base at +8 plus nullable word at +4 of object reached via double
// dereference at +0xC. Callers 0x000B956A 0x000BDC8F. Honest address name.
//
// Retail (23B):
//   mov eax,[ecx+8]   ; base -> eax accumulator
//   mov ecx,[ecx+0xc] ; pp -> ecx
//   mov ecx,[ecx]     ; p  -> ecx
//   test ecx,ecx ; je +6
//   movzx ecx,W[ecx+4] ; jmp +2
//   xor ecx,ecx       ; the two-value phi lives in ecx
//   add eax,ecx ; ret
//
// New structural finding (space-bunny-alpha): the 23B ternary shape
//   int v = p ? p->m_word04 : 0; return m_base08 + v;
// emits retail's diamond (jmp/xor present, 23B) but always
//   mov eax,[ecx+0xc] first, sinking the +8 load AFTER the branch and routing
// the word through eax/edx. The `if (p) r += p->m_word04; return r;` form
// emits retail's EXACT load order and register choice
//   (mov eax,[ecx+8]; mov ecx,[ecx+0xc]; mov ecx,[ecx]; test; je;
//    movzx ecx,W[ecx+4]; add eax,ecx; ret)
// but is only 19B: cl forward-propagates the false edge's ecx=0 and drops the
// jmp/xor diamond. So the two shapes are mutually exclusive under this
// toolchain: order+registers need the `if` (no diamond), the diamond needs the
// ternary (wrong order). Confirmed over S1..S6, T1..T4, U1..U5 (all measured in
// one isolated TU each shape, /O1). No source spelling recovers both; this is a
// register-allocation/scheduler limit, not identity or layout. See
// reverse/re_attempts.log for the 23B best.
struct Rva000B65FDAux
{
	char m_pad00[4];
	unsigned short m_word04;
};

class Rva000B65FD
{
public:
	int rva000B65FD();
private:
	char m_pad00[8];
	int m_base08;
	Rva000B65FDAux **m_pp0C;
};

// ?rva000B65FD@Rva000B65FD@@QAEHXZ present-unmatched
int Rva000B65FD::rva000B65FD()
{
	int base = m_base08;
	Rva000B65FDAux *p = *m_pp0C;
	int v = p ? p->m_word04 : 0;
	return base + v;
}
