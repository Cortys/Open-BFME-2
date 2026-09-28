// ?Rva006D8630Drain@@YAXXZ
// partial score=0.98 date=2026-09-28
// ?Rva006D8630Drain@@YAXXZ
// partial score=0.98 date=2026-09-28
// cl: /O2 /MD
struct AptNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual ~AptNode();
    int _pad;
    AptNode *m_next;
};
extern AptNode *g_aptHead006D8630; // 0x00A18020
// ?Rva006D8630Drain@@YAXXZ present-unmatched
void __cdecl Rva006D8630Drain()
{
    AptNode *cur = g_aptHead006D8630;
    if (!cur)
        return;
    AptNode *next;
    do {
        next = cur->m_next;
        cur->v11();
        AptNode *head = g_aptHead006D8630;
        if (head)
            delete head;
        cur = next;
        g_aptHead006D8630 = cur;
    } while (cur);
}
