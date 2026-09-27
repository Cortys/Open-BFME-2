// cl: /O2 /MD
// ?rva006E3230@Rva006E3230@@QAEXPAURva006E3230Action@@@Z @0x006E3230 102B.
// Validates an action pointer against the Apt action pool using _Apt.h asserts
// at lines 0x4e0 ("pCur >= &m_aActionPool[0]") and 0x4e1
// ("pCur < &m_aActionPool[ m_iActionPoolSize ]") via the shared Apt assert
// triple (E17734 + DDC01C + int3). Layout read from retail: base pointer at
// +0, size at +0x10, stride 24 (lea size*3 then base+size*3*8). Callers at
// 0x006E3740 0x006E3810 0x006E4A90 0x006E4B80 0x006E4C70 0x006E4D50
// 0x006E6540 pass the same this, and AptAnimation.cpp Dequeue-full callers
// establish the queue owner. Honest-address method; no donor.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
struct Rva006E3230Action { char data[24]; };
class Rva006E3230 {
    Rva006E3230Action *m_aActionPool;
    char _pad[12];
    int m_iActionPoolSize;
public:
    void rva006E3230(Rva006E3230Action *pCur);
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
