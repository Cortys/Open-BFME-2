// ?rva006D01D0@Rva006D01D0@@QAEXPAX@Z
// partial score=0.98 date=2026-09-30
// ?rva006D01D0@Rva006D01D0@@QAEXPAX@Z
// partial score=0.98 date=2026-09-30
// cl: /DNDEBUG /MD
// ?rva006D01D0@Rva006D01D0@@QAEXPAX@Z @ 0x006D01D0 100B
// Honest address name: __thiscall chain remove by key beside Rva008951B0Find.
// Target evidence: retail walks head at +0 with key at +0 and link at +4,
// frees matching 8B node via rowed freeBlock 0x006DB270 through
// g_pChainBlockAllocator 0x00E176E8, ret 4. Prev/next share /DNDEBUG /MD.
class Rva006DB270
{
public:
    void freeBlock(void *block, int blockSize);
};
extern Rva006DB270 *g_pChainBlockAllocator;
struct Rva006D01D0Node
{
    void *m_key;
    Rva006D01D0Node *m_next;
};
class Rva006D01D0
{
public:
    void rva006D01D0(void *key);
private:
    Rva006D01D0Node *m_head;
};
// ?rva006D01D0@Rva006D01D0@@QAEXPAX@Z present-unmatched
void Rva006D01D0::rva006D01D0(void *key)
{
    Rva006D01D0Node *prev = m_head;
    if (prev->m_key == key)
    {
        if (m_head == 0)
            return;
        Rva006D01D0Node *next = prev->m_next;
        g_pChainBlockAllocator->freeBlock(prev, 8);
        m_head = next;
        return;
    }
    if (m_head == 0)
        return;
    Rva006D01D0Node *cur;
    do
    {
        cur = prev->m_next;
        if (cur != 0 && cur->m_key == key)
            break;
        prev = cur;
    } while (prev != 0);
    if (prev == 0)
        return;
    Rva006D01D0Node *found = prev->m_next;
    if (found != 0)
        prev->m_next = found->m_next;
    g_pChainBlockAllocator->freeBlock(found, 8);
}
