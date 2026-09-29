// cl: /O2 /MD
// ?rva006E0DE0@Rva006E0DE0@@QAEHPAVAptValue@@@Z, retail 0x006E0DE0, 142 bytes.
// Word-counted Apt pointer-array remove with mnElements/mnMaxElements guards.
// Evidence: unlock lane unblocking 2 callers; Release virtual slot 4 via
// AptValuePtrStack neighbour; same /O2 shape as Apt neighbours.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class AptValue {
public:
    virtual void AddRef();
    virtual void Release();
};
class Rva006E0DE0 {
    unsigned short m_nElements;
    unsigned short m_nMaxElements;
    AptValue **m_ppElements;
public:
    int rva006E0DE0(AptValue *p);
};
int Rva006E0DE0::rva006E0DE0(AptValue *p)
{
    if (m_nElements == 0)
        return 0;
    if (m_nElements >= m_nMaxElements) {
        g_bfmeAptAssertAtE17734("mnElements < mnMaxElements", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptSet.h", 0x43);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    unsigned short nMax = m_nMaxElements;
    int i = 0;
    for (; i < m_nMaxElements; ++i) {
        if (m_ppElements[i] == p)
            break;
    }
    if (i < nMax) {
        --m_nElements;
        m_ppElements[i]->Release();
        m_ppElements[i] = 0;
        return 1;
    }
    return 0;
}
