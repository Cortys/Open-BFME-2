// ?Rva0070B590Cleanup@@YAXXZ
// partial score=0.98 date=2026-09-29
// ?Rva0070B590Cleanup@@YAXXZ
// partial score=0.98 date=2026-09-29
// cl: /O2 /DNDEBUG /MD
// ?Rva0070B590Cleanup@@YAXXZ @0x0070B590 52B
// Evidence: global head at 0x00E18370; nodes with vptr+0 next+0xC; virtual slot 11 (0x2C)
// then slot 14 (0x38) with 1; callers at 0x006CFCC0 0x006E6F75 0x006E7044; neighbours
// Rva0070B4F0GetString and Rva0070DF60 (slot 11 class).
class AptListNode {
    int m_a;
    int m_b;
public:
    class AptListNode *m_next;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void slot11();
    virtual void f12();
    virtual void f13();
    virtual void slot14(int v);
};

extern AptListNode *g_00E18370;

// ?Rva0070B590Cleanup@@YAXXZ present-unmatched
void __cdecl Rva0070B590Cleanup()
{
    AptListNode *cur;
    AptListNode *next;
    AptListNode *head;
    cur = g_00E18370;
    if (!cur)
        return;
    do {
        next = cur->m_next;
        cur->slot11();
        head = g_00E18370;
        if (head)
            head->slot14(1);
        g_00E18370 = cur = next;
    } while (cur);
}
