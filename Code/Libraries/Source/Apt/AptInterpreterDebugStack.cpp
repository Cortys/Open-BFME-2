// cl: /O2 /MD
// May2006 Xbox release APT0.19.03 PDB gives the template specialization.
// Target _AptDebugStack.h assertions establish the stack and sized-free callback.
// Target caller6FEB50 names AptActionInterpreter.cpp and mnStackFrameBase; at
// 6FEBC9 it passes this+0x34 to Shutdown6FE270. Destructor caller6FE9C0 likewise
// passes this+0x34 at6FE9DD to6FE160. These target offsets agree with the donor
// interpreter debugCallStack member, corroborating specialization ownership.
// Target establishes count0/capacity4/pointer8 and pointer-array size4 per slot.
// The nested info type is intentionally incomplete: its internal layout is unused.
// Full target spans6FE160+108 and6FE270+128 are checked against final returns.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *,const char *,int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
extern void (__cdecl *g_bfmeAptFreeSizeAtE17730)(void *,unsigned int);
void __debugbreak();
#pragma intrinsic(__debugbreak)
struct AptActionInterpreter { struct DebugCallStackInfo_t; };
template<class T> class AptDebugStack {
    int m_nElements;
    int m_nCapacity;
    T **m_aElements;
public:
    ~AptDebugStack();
    void Shutdown();
};
#define CHECK_AT(cond,text,line) if (!(cond)) { g_bfmeAptAssertAtE17734(text,"c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptDebugStack.h",line); if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak(); }
template<class T> AptDebugStack<T>::~AptDebugStack()
{
    CHECK_AT(m_nElements==0,"m_nElements == 0",60);
    if (m_aElements) {
        CHECK_AT(g_bfmeAptFreeSizeAtE17730,"gAptFuncs.pfnMemFreeSize",63);
        g_bfmeAptFreeSizeAtE17730(m_aElements,m_nCapacity*sizeof(T *));
    }
}
template<class T> void AptDebugStack<T>::Shutdown()
{
    CHECK_AT(m_nElements==0,"m_nElements == 0",83);
    if (m_aElements) {
        CHECK_AT(g_bfmeAptFreeSizeAtE17730,"gAptFuncs.pfnMemFreeSize",86);
        g_bfmeAptFreeSizeAtE17730(m_aElements,m_nCapacity*sizeof(T *));
    }
    m_nCapacity=0;
    m_nElements=0;
    m_aElements=0;
}
template class AptDebugStack<AptActionInterpreter::DebugCallStackInfo_t>;
