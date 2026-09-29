// ?rva005DB9E4@Rva005DB9E4@@QAEXXZ
// partial score=0.93 date=2026-09-29
// ?rva005DB9E4@Rva005DB9E4@@QAEXXZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /G7 /DNDEBUG /MD
// ?rva005DB9E4@Rva005DB9E4@@QAEXXZ, retail 0x005DB9E4, 89 bytes.
// Nested 8x8 zeroing of three dword arrays plus word array, outer dword array, tail stores.
// Evidence: no callees; lea edx/eax/esi at +0x718/+0x118/+0x838; push-8 pop-ebx counters; neighbours Rva005DB98EGet/Rva005DBBA5Get same flags; unblocks 0x005DBA3D/0x005DC43B.
struct Rva005DB9E4 {
    char m_pad[0x8bc];
    void rva005DB9E4();
};
// ?rva005DB9E4@Rva005DB9E4@@QAEXXZ present-unmatched
void Rva005DB9E4::rva005DB9E4()
{
    int *p718 = (int *)((char *)this + 0x718);
    int *p118 = (int *)((char *)this + 0x118);
    unsigned short *p838 = (unsigned short *)((char *)this + 0x838);
    volatile int outer = 8;
    do {
        int inner = 8;
        do {
            p118[-64] = 0;
            *p118 = 0;
            p118[392] = 0;
            *p838 = 0;
            ++p118;
            ++p838;
        } while (--inner != 0);
        *p718++ = 0;
    } while (--outer);
    *(int *)((char *)this + 0x8b8) = 0;
    *(unsigned short *)((char *)this + 0x14) = 8;
}
