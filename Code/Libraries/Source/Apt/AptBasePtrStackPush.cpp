// cl: /O2 /MD
// Ghidra body at 0x006FE6E0: checked stack append, slot write, count increment,
// and first virtual call. Layout and checks are read from BFME2 retail.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class BfmeAptValue006DCD20
{
public:
    virtual void AddRef();
    virtual void Release();
    int isLookup() const;
    int isRegister() const;
};

class AptBasePtrStack
{
public:
    void Push(BfmeAptValue006DCD20 *pValue);
    void rva006E3AA0(int nItems);

    int m_nElements;
    int m_nCapacity;
    BfmeAptValue006DCD20 **m_aElements;
};

void AptBasePtrStack::Push(BfmeAptValue006DCD20 *pValue)
{
    if (!pValue) {
        g_bfmeAptAssertAtE17734("pValue", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptActionInterpreter.inl", 133);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (static_cast<unsigned char>(pValue->isLookup())) {
        g_bfmeAptAssertAtE17734("pValue->isLookup() == false", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptActionInterpreter.inl", 134);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (static_cast<unsigned char>(pValue->isRegister())) {
        g_bfmeAptAssertAtE17734("pValue->isRegister() == false", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptActionInterpreter.inl", 135);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (m_nElements >= m_nCapacity) {
        g_bfmeAptAssertAtE17734("m_nElements < m_nCapacity", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptBasePtrStack.h", 128);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    m_aElements[m_nElements] = pValue;
    ++m_nElements;
    pValue->AddRef();
}

// ?rva006E3AA0@AptBasePtrStack@@QAEXH@Z @0x006E3AA0 122B unlock lane.
// Checked stack pop: asserts nItems >= 0 (_AptBasePtrStack.h:167), returns
// early when more is popped than contained (_AptBasePtrStack.h:170 via the
// shared Apt assert triple), else Releases the top nItems entries in order
// and subtracts the count. Evidence: 12 callers; layout/flags/assert file
// shared with Push above; strings pinned by reverse/string_xrefs.tsv.
void AptBasePtrStack::rva006E3AA0(int nItems)
{
    if (nItems < 0) {
        g_bfmeAptAssertAtE17734("nItems >= 0", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptBasePtrStack.h", 167);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    if (m_nElements < nItems) {
        g_bfmeAptAssertAtE17734("false && \"[APT] Error, Popping more elements than the stack contains. Please contact the Apt Team for Support.\"", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptBasePtrStack.h", 170);
        // __asm barrier (not the intrinsic): keeps int3 ahead of the early
        // epilogue pops. Cf int3-barrier precedent in AptValueVectorReleaseBFME2.cpp.
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __asm int 3
        return;
    }
    for (int i = 1; i <= nItems; ++i) {
        m_aElements[m_nElements - i]->Release();
    }
    m_nElements -= nItems;
}
