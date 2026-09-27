// ?rva0046274C@SlaughterHordeContain@@UAEXPAUArg740046274C@@H0@Z
// partial score=0.95 date=2026-09-27
// ?rva0046274C@SlaughterHordeContain@@UAEXPAUArg740046274C@@H0@Z
// partial score=0.95 date=2026-09-27
// cl: /O1 /DNDEBUG /MD
//
// ?rva0046274C@SlaughterHordeContain@@UAEXPAUArg740046274C@@H0@Z, retail 0x0046274C, 57 bytes.
// Virtual slot 81 (offset 0x144) of vtable 0x00848AA0 (class of
// ??0SlaughterHordeContain@@QAE@PAVThing@@PBVModuleData@@@Z in
// SlaughterHordeContainCtor.cpp). Takes (Arg74 *a, int b, Arg74 *c),
// stores max(b,1) at +0xCC plus a->m_74 at +0xC4 plus c->m_74 at +0xC8.
// Evidence: vtable slot plus +0xC4/+0xC8/+0xCC layout plus +0x74 field
// plus caller-free leaf. Honest address name: method identity unproven.
// Near miss: 57B/20insns exact size, 0 structural regions, only the
// one-temp register differs (retail eax vs ours edx for xor/inc/cmp/mov).

struct Arg740046274C { int m_pad[0x74/4]; int m_74; };

#define SLOT08(a,b,c,d,e,f,g,h) virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h();
#define SLOT16(a) SLOT08(a##0,a##1,a##2,a##3,a##4,a##5,a##6,a##7) SLOT08(a##8,a##9,a##A,a##B,a##C,a##D,a##E,a##F)

class SlaughterHordeContain
{
public:
SLOT16(p0) SLOT16(p1) SLOT16(p2) SLOT16(p3) SLOT16(p4)
virtual void s80();
virtual void rva0046274C(Arg740046274C *a, int b, Arg740046274C *c);
private:
char m_padC0[0xC0];
int m_C4;
int m_C8;
int m_CC;
};

void SlaughterHordeContain::rva0046274C(Arg740046274C *a, int b, Arg740046274C *c)
{
int one = 1;
int *p = &b;
if (b <= 1)
p = &one;
int v = *p;
m_C4 = a->m_74;
m_CC = v;
m_C8 = c->m_74;
}
