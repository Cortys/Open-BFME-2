// ?rva006D28D0@Rva006D28D0@@QAEXH_N@Z
// partial score=0.99 date=2026-09-29
// ?rva006D28D0@Rva006D28D0@@QAEXH_N@Z
// partial score=0.99 date=2026-09-29
// cl: /O2 /DNDEBUG /MD
// ?rva006D28D0@Rva006D28D0@@QAEXH_N@Z 0x006D28D0 92B evidence: Apt GC flag setter via offset 0 or 4 with branchless bit0 set; assert false at AptValueGCAllocator.h 0x107 via g_bfmeAptAssertAtE17734 plus break global; callers 0x006D29F9 0x006D2A2F 0x006D2AEC unblocks 0x006D29E0
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class Rva006D28D0 {
    int m_a;
    int m_b;
public:
    void rva006D28D0(int which, bool val);
};
// ?rva006D28D0@Rva006D28D0@@QAEXH_N@Z present-unmatched
void Rva006D28D0::rva006D28D0(int which, bool val)
{
    if (which == 4) {
        m_b ^= (val ^ m_b) & 1;
        return;
    }
    if (which == 0) {
        m_a ^= (m_a ^ val) & 1;
        return;
    }
    g_bfmeAptAssertAtE17734("false", "..\\..\\include\\apt\\AptValueGCAllocator.h", 0x107);
    if (g_bfmeAptBreakOnAssertAtDDC01C)
        __debugbreak();
}
