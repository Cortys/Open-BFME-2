// ?rva000FDF4C@Rva000FDF4C@@QAEXH@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /G7 /DNDEBUG /MD
// ?rva000FDF4C@Rva000FDF4C@@QAEXH@Z @0x000FDF4C 181B
// Evidence: thiscall ret4 1 int arg void return; callers 0x000FF7DD 0x000FFB0E 0x000FFCA3;
// offsets +0x10 +0x14 +0x30 +0x3C +0x68 +0x74 +0xB0 +0xB4 intrusive doubly-linked list;
// next Rva000FE001Move takes FeNode; flags from next /O1 /G7 /DNDEBUG /MD.
struct Node184
{
    char pad0[0x30];
    int m_30;
    char pad34[0x8];
    unsigned char m_3C;
    char pad3D[0x2B];
    int m_68;
    char pad6C[0x8];
    int m_74;
    char pad78[0x38];
    Node184 *m_B0;
    Node184 *m_B4;
};

class Rva000FDF4C
{
public:
    void rva000FDF4C(int key);

private:
    char m_pad0[0x10];
    Node184 *m_10;
    Node184 *m_14;
};

// ?rva000FDF4C@Rva000FDF4C@@QAEXH@Z present-unmatched
void Rva000FDF4C::rva000FDF4C(int key)
{
    Node184 *n = m_14;
    if (n != 0)
    {
        Node184 *next = n->m_B0;
        if (next != 0)
            next->m_B4 = n->m_B4;
        Node184 *prev = n->m_B4;
        if (prev != 0)
            prev->m_B0 = n->m_B0;
        else
            m_14 = n->m_B0;
        n->m_30 = key;
        Node184 *head = m_10;
        Node184 *pq = 0;
        Node184 *cur = head;
        for (; cur != 0;)
        {
            if (cur->m_30 == key)
                goto found;
            pq = cur;
            cur = cur->m_B0;
        }
        n->m_B0 = head;
        if (m_10 != 0)
            m_10->m_B4 = n;
        m_10 = n;
        goto done;
    found:
        n->m_B0 = cur;
        n->m_B4 = pq;
        cur->m_B4 = n;
        if (pq == 0)
            m_10 = n;
        else
            pq->m_B0 = n;
    done:
        n->m_3C = 1;
    }
    for (Node184 *c = m_10; c != 0; c = c->m_B0)
        c->m_74 = c->m_68;
}
