// ?Rva00521CBAAdvance@@YAXPAPAURva00521CBANode@@HPAX@Z
// partial score=0.93 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /MD
// ?Rva00521CBAAdvance@@YAXPAPAURva00521CBANode@@HPAX@Z retail 0x00521CBA 41B
// Evidence: unlock; caller 0x00521EC2 pushes 3 args; no callees; walks doubly-linked node forward via +0 for positive count and via +4 for negative count.
struct Rva00521CBANode
{
    struct Rva00521CBANode *m_next;
    struct Rva00521CBANode *m_prev;
};

// ?Rva00521CBAAdvance@@YAXPAPAURva00521CBANode@@HPAX@Z present-unmatched
void Rva00521CBAAdvance(struct Rva00521CBANode **holder, int count, void *unused)
{
    (void)unused;
    if (count > 0) {
        do {
            *holder = (*holder)->m_next;
        } while (--count != 0);
        return;
    }
    if (count == 0)
        return;
    count = -count;
    do {
        *holder = (*holder)->m_prev;
    } while (--count != 0);
}
