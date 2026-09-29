// cl: /O2 /MD
// ?rva006E3230@Rva006E3230@@QAEXPAURva006E3230Action@@@Z @0x006E3230 102B.
// ?rva006E3DB0@Rva006E3230@@QAEPAURva006E3230Action@@XZ @0x006E3DB0 17B.
// Validates an action pointer against the Apt action pool using _Apt.h asserts
// at lines 0x4e0 ("pCur >= &m_aActionPool[0]") and 0x4e1
// ("pCur < &m_aActionPool[ m_iActionPoolSize ]") via the shared Apt assert
// triple (E17734 + DDC01C + int3). Layout read from retail: base pointer at
// +0, current at +4, size at +0x10, stride 24 (lea size*3 then base+size*3*8).
// Callers at 0x006E3740 0x006E3810 0x006E4A90 0x006E4B80 0x006E4C70 0x006E4D50
// 0x006E6540 pass the same this, and AptAnimation.cpp Dequeue-full callers
// establish the queue owner. Chain 0x006E3DB0 validates and returns +4.
// Honest-address methods; no donor.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
struct Rva006E3230Action { char data[24]; };
class Rva006E3230 {
    Rva006E3230Action *m_aActionPool;
    Rva006E3230Action *m_pCurrent;
    char _pad2[8];
    int m_iActionPoolSize;
public:
    void rva006E3230(Rva006E3230Action *pCur);
    Rva006E3230Action *rva006E3DB0();
    Rva006E3230Action *rva006E3920(int arg);
};
void Rva006E3230::rva006E3230(Rva006E3230Action *pCur)
{
    if (!(pCur >= &m_aActionPool[0])) {
        g_bfmeAptAssertAtE17734("pCur >= &m_aActionPool[0]", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_Apt.h", 0x4e0);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (!(pCur < &m_aActionPool[m_iActionPoolSize])) {
        g_bfmeAptAssertAtE17734("pCur < &m_aActionPool[ m_iActionPoolSize ]", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_Apt.h", 0x4e1);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
}
Rva006E3230Action *Rva006E3230::rva006E3DB0()
{
    rva006E3230(m_pCurrent);
    return m_pCurrent;
}

// ?rva006E3920@Rva006E3230@@QAEPAURva006E3230Action@@H@Z @0x006E3920 114B.
// Wraps an argument by the action-pool cursor: iOffset = m_pCurrent -
// m_aActionPool (element stride 24), asserted into [0, m_iActionPoolSize) at
// AptAnimation.cpp:1911, then returns &pool[wrapped (arg + iOffset)] with a
// signed modulo folded into range. Evidence: unlock lane, caller 0x006E39A0;
// layout/stride/names shared with the two bodies above.
Rva006E3230Action *Rva006E3230::rva006E3920(int arg)
{
    int iOffset = m_pCurrent - m_aActionPool;
    if (iOffset < 0 || iOffset >= m_iActionPoolSize) {
        g_bfmeAptAssertAtE17734("(iOffset >= 0) && (iOffset < m_iActionPoolSize)", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptAnimation.cpp", 0x777);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    int idx = (arg + iOffset) % m_iActionPoolSize;
    if (idx >= 0)
        return &m_aActionPool[idx];
    return &m_aActionPool[idx + m_iActionPoolSize];
}
