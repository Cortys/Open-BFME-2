// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z
// partial score=0.97 date=2026-10-04
// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z
// partial score=0.97 date=2026-10-04
// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?rva00474431@Rva00474431@@QAEHABURva00474431Pair@@H@Z, retail 0x00474431, 82 bytes.
// Build record from pair plus int via rowed Rva004691A5 ctor, push into
// vector at +0x188, return size-1.
//
// Retail store order decoded from the frame (u is at ebp-0x1c):
//   447 mov [ebp-0x10],ecx   m_0C = p.m_00
//   44d mov [ebp-0xc],ecx    m_10 = p.m_04
//   455 mov [ebp-0x14],eax   m_08 = p.m_04
//   45b mov [ebp-0x1c],eax   m_00 = v
//   461 mov [ebp-0x18],ecx   m_04 = p.m_00
// so m_00 (v) is stored FOURTH, between m_08 and m_04 -- not first as the
// banked body had it. Retail also reads the pair fields TWICE (442/445 then
// 450/452), which only survives when the loads are not common-subexpression
// eliminated; binding the parameter to a `const volatile` reference is what
// pins that reload (6 differing instruction rows vs the banked 26, with the
// prologue, ctor call, both first stores and the entire push_back / idiv tail
// byte-exact).
//
// Residual wall, 6 rows: in the second half retail loads [eax] into ecx and
// [eax+4] into eax (m_00 read first, stored last), while this build emits
// [eax+4] into ecx and [eax] into eax and shifts the last two stores with it.
// Semantics are identical -- this is the /O1 allocator choosing the first-read
// register first. Refuted this pass: hoisted const locals (CSE collapses to
// one load each, 26 rows), staged locals in m_00-then-m_04 order (a0 spills
// to a frame slot, 30+ rows), volatile record writes (reverts to the single-read
// rotation), volatile-hoisted b0 (spills), non-volatile reference (CSE, 26
// rows), m_04 read from p instead of q (6 rows, identical). /O2, /Ob2 and
// /O2 /Ob2 all drop to 32 rows, so /O1 is required and no flag steers the
// swap.
#include <vector>

class Rva004691A5
{
public:
	Rva004691A5();
private:
	int m_00;
	char m_pad04[0x10];
	float m_14;
	int m_18;
};

class Rva00064640Record
{
public:
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
	float m_10;
	float m_14;
	unsigned int m_18;
};

struct Rva00474431Pair
{
	int m_00;
	int m_04;
};

class Rva00474431
{
public:
	int rva00474431(const Rva00474431Pair &p, int v);
	char m_pad[0x188];
	_STL::vector<Rva00064640Record> m_vec;
};

int Rva00474431::rva00474431(const Rva00474431Pair &p, int v)
{
	Rva004691A5 u;
	Rva00064640Record &r = *(Rva00064640Record *)&u;
	const volatile Rva00474431Pair &q = p;
	r.m_0C = q.m_00;
	*(int *)&r.m_10 = q.m_04;
	r.m_08 = q.m_04;
	r.m_00 = v;
	r.m_04 = q.m_00;
	m_vec.push_back(r);
	return m_vec.size() - 1;
}
