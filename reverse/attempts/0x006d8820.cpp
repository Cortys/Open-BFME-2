// ?Rva006D8820Cleanup@@YAXXZ
// partial score=0.98 date=2026-10-01
// ?Rva006D8820Cleanup@@YAXXZ
// partial score=0.98 date=2026-10-01
// cl: /O2 /MD
// ?Rva006D8820Cleanup@@YAXXZ @0x006D8820 (52 bytes).
// Free cleanup reading global at 0x00E18024, saving next at +8, calling
// vtable slot 0x2c on the head, re-reading the global for a deleting-dtor
// slot 0x38 call with 1, then storing the saved next. Callers 0x006CFAB0
// 0x006E6E20 0x006E6F80; callees are virtual slots, no rowed names.
class Rva006D8820Node
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(int n);
    int m_unk04;
    Rva006D8820Node *m_next;
};
extern Rva006D8820Node *g_00E18024;
// ?Rva006D8820Cleanup@@YAXXZ present-unmatched
void __cdecl Rva006D8820Cleanup()
{
    Rva006D8820Node *cur = g_00E18024;
    if (!cur)
        return;
    Rva006D8820Node *next;
    do {
        next = cur->m_next;
        cur->v11();
        Rva006D8820Node *q = g_00E18024;
        if (q)
            q->v14(1);
        cur = next;
        g_00E18024 = cur;
    } while (cur);
}
