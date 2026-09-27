// ?rva00264688@Rva00264688@@QAEEXZ
// partial score=0.93 date=2026-09-27
// ?rva00264688@Rva00264688@@QAEEXZ
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD
// ?rva00264688@Rva00264688@@QAEEXZ, retail 0x00264688 (97B).
// Unlock-lane predicate reached from 40+ call sites. Reads ecx before
// writing it so it is a __thiscall method with no stack arguments (ret,
// not ret N) returning unsigned char in al (xor al/al plus mov al/1 plus
// setne). Current best is 102B vs 97B with loop peeling plus entry jmp and
// final je vs jne scheduling left.
// Evidence: vtable call at +0x1b8 returning byte, member reads at +8/+4,
// +0x108 bit 4, +0x274/+0x258 chain with +4/+0x115 bit 0x20, plus +0x3b7
// byte and +0x1fc int for the final true/false folding.
struct C108
{
    char pad[0x108];
    unsigned char b108;
};
struct F115
{
    char pad[0x115];
    unsigned char b115;
};
class Rva00264688;
struct D274
{
    char pad0[4];
    F115 *p4;
    char pad[0x258 - 8];
    Rva00264688 *p258;
};
struct B8
{
    char pad0[4];
    C108 *p4;
    char pad[0x274 - 8];
    D274 *p274;
};
class Rva00264688
{
public:
#define V(n) virtual void s##n() = 0;
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
#undef V
    virtual bool s110() = 0;
    unsigned char rva00264688();
private:
    char pad4[4];
    B8 *p8;
    char pad12[0x1FC - 0xC];
    int i1fc;
    char pad200[0x3B7 - 0x200];
    unsigned char b3b7;
};

// ?rva00264688@Rva00264688@@QAEEXZ present-unmatched
unsigned char Rva00264688::rva00264688()
{
    Rva00264688 *cur = this;
    for (;;)
    {
        B8 *b = cur->p8;
        if (b->p4->b108 & 4)
            return 0;
        D274 *d = b->p274;
        if (!d)
            break;
        Rva00264688 *next = d->p258;
        if (!next)
            break;
        if (d->p4->b115 & 0x20)
            break;
        cur = next;
    }
    if (cur->b3b7)
        return 1;
    if (cur->s110())
        return 0;
    return (unsigned char)(cur->i1fc != 0);
}
