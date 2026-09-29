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
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(__debugbreak, _ReadWriteBarrier)
class AptCIH {
    virtual void vtableSlot0();
    unsigned char _pad[0x44];
    AptCIH *m_parent;
    void *m_4C;
    unsigned char _pad3[8];
    int m_code;
public:
    int rva006E0B80(int nLvl) const;
    bool rva006E2460(const AptCIH *other) const;
    void *rva006E0FB0() const;
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

// ?rva006E2460@AptCIH@@QBE_NPBV1@@Z, retail 0x006E2460, 104 bytes.
// Ancestor-code comparison, true when other sorts strictly below this at the
// first differing level. Evidence: chain lane, calls rowed
// rva006E0B80 twice per level with the same index; self/depth-zero guards;
// caller at 0x006FB21E; same /O2 shape and AptCIH layout as above.
bool AptCIH::rva006E2460(const AptCIH *other) const
{
    int depth = 0;
    for (const AptCIH *p = m_parent; p; p = p->m_parent)
        ++depth;
    if (this == other || depth == 0)
        return false;
    for (int i = 0; i <= depth; ++i) {
        int a = rva006E0B80(i);
        int b = other->rva006E0B80(i);
        if (b < a)
            return true;
        if (b > a)
            break;
    }
    return false;
}

// ?rva006E0FB0@AptCIH@@QBEPAXXZ, retail 0x006E0FB0, 103 bytes.
// Static-text field accessor at +0x4C guarded by type 0x10 and defined checks,
// "this" assert at line 0xC9 and "isStaticTextInst()" at 0x87 via AptCIH.h.
// Evidence: rowed getters 0x6DBB30 and 0x6DC010; unlock lane; caller at
// 0x006E18FD; same /O2 AptCIH layout as neighbours. Barrier keeps the +0x4C
// load late (retail test-je-int3-mov, no hoist); emits no bytes.
class Rva006DBB30SarDwordField
{
public:
    int get() const;
};

class BfmeAptValue006DCD20
{
public:
    bool isUndefined() const;
};

void *AptCIH::rva006E0FB0() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0xC9);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    if (((const Rva006DBB30SarDwordField *)this)->get() != 0x10 || ((const BfmeAptValue006DCD20 *)this)->isUndefined()) {
        g_bfmeAptAssertAtE17734("isStaticTextInst()", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0x87);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    _ReadWriteBarrier();
    return m_4C;
}
