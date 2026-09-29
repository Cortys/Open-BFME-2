// cl: /O2 /MD
// ?rva006E0B80@AptCIH@@QBEHH@Z, retail 0x006E0B80, 103 bytes.
// Level-indexed ancestor field accessor, "nLvl >= 0" assert at line 0x85C via
// file string at 0x008EB4A8. Evidence: rowed-assert helper shape shared with
// AptCIHEventHandlers neighbours; +0x48 parent chain depth count with -1 on
// over-level; +0x58 low-17-bit sign-extended result; callers at
// 0x006E2493/0x006E249F compare results signed; same /O2 shape as neighbours.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class AptCIH {
    virtual void vtableSlot0();
    unsigned char _pad[0x44];
    AptCIH *m_parent;
    unsigned char _pad2[0x0C];
    int m_code;
public:
    int rva006E0B80(int nLvl) const;
};
int AptCIH::rva006E0B80(int nLvl) const
{
    if (nLvl < 0) {
        g_bfmeAptAssertAtE17734("nLvl >= 0", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptCIH.cpp", 0x85C);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    int depth = 0;
    for (const AptCIH *p = m_parent; p; p = p->m_parent)
        ++depth;
    if (nLvl > depth)
        return -1;
    const AptCIH *node = this;
    if (depth != nLvl) {
        int steps = depth - nLvl;
        do {
            node = node->m_parent;
        } while (--steps != 0);
    }
    return (node->m_code << 15) >> 15;
}
