// cl: /O2 /MD
// ?rva006D8A50@BfmeAptValue006DCD20@@QAEPAV1@H@Z @0x006D8A50 (121 bytes).
// Array element access asserting nIndex < mnLength at _Apt.h:0x110 then
// nIndex < mnCapacity at _Apt.h:0x111 via the shared Apt assert pointer at
// 0x00A17734 and break flag at 0x009DC01C, returning m_data[nIndex].
// Layout (m_data at +0x20, mnCapacity at +0x24, mnLength at +0x28) and the
// array-value role are read from retail and callers: 0x006D94A0 loops over
// +0x28 calling this per index, 0x006D9B50 accesses +0x20/+0x28 after the
// rowed isArray checked cast, 0x006D9660 consumes the returned AptValue*.
// __asm int 3 is a proven blocker: the __debugbreak() intrinsic misplaces
// the second int3 between the pops (see AptValueCheckedCastsBFME2.cpp).
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
class BfmeAptValue006DCD20
{
    virtual void slot0();
    unsigned int m_flags;
    char m_pad[0x18];
    BfmeAptValue006DCD20 **m_data;
    int mnCapacity;
    int mnLength;
public:
    BfmeAptValue006DCD20 *rva006D8A50(int nIndex);
};
BfmeAptValue006DCD20 *BfmeAptValue006DCD20::rva006D8A50(int nIndex)
{
    if (!(nIndex < mnLength)) {
        g_bfmeAptAssertAtE17734("nIndex < mnLength", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_Apt.h", 0x110);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __asm int 3
    }
    if (!(nIndex < mnCapacity)) {
        g_bfmeAptAssertAtE17734("nIndex < mnCapacity", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_Apt.h", 0x111);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __asm int 3
    }
    return m_data[nIndex];
}
