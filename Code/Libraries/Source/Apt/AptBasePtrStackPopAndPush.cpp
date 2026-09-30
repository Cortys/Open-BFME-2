// cl: /O2 /MD
// ?PopAndPush@AptBasePtrStack@@QAEXHPAVBfmeAptValue006DCD20@@@Z @0x006FDFA0 157B
// Pop-and-push single value: asserts nItems >= 0 (_AptBasePtrStack.h:201),
// returns early when popping more than contained (:205 via shared Apt assert
// triple), else AddRefs the new value, Releases the top nItems in order,
// stores the value and nets the count. Evidence: unlock lane; callers
// 0x006FE910 0x007066AD; layout/flags/assert file shared with
// AptBasePtrStackPush.cpp; Bitwise PopAndPush decl names the method.
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
    void PopAndPush(int nItems, BfmeAptValue006DCD20 *pValue);

    int m_nElements;
    int m_nCapacity;
    BfmeAptValue006DCD20 **m_aElements;
};

void AptBasePtrStack::PopAndPush(int nItems, BfmeAptValue006DCD20 *pValue)
{
    if (nItems < 0) {
        g_bfmeAptAssertAtE17734("nItems >= 0", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptBasePtrStack.h", 201);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    if (m_nElements < nItems) {
        g_bfmeAptAssertAtE17734("false && \"[APT] Error, Popping more elements than the stack contains. Please contact the Apt Team for Support.\"", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptBasePtrStack.h", 205);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __asm int 3
        return;
    }
    pValue->AddRef();
    for (int i = 1; i <= nItems; ++i) {
        m_aElements[m_nElements - i]->Release();
    }
    m_aElements[m_nElements - nItems] = pValue;
    m_nElements = m_nElements + 1 - nItems;
}
