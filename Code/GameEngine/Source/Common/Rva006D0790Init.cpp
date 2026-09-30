// ?rva006D0790@Rva006D0790@@QAEPAV1@PAURva006D0280@@PAX@Z @0x006D0790 70B evidence list init plus Rva006D0280 acquire-release via chain allocator
class Rva006DB270
{
public:
    void freeBlock(void *block, int blockSize);
};
extern Rva006DB270 *g_pChainBlockAllocator;
struct Rva006D0280
{
    void teardown();
    int m_useCount;
};
class Rva006D0790
{
public:
    Rva006D0790 *rva006D0790(Rva006D0280 *p, void *q);
private:
    int m_unk00;
    Rva006D0280 *m_sub;
    void *m_unk08;
    bool m_flag0C;
};
Rva006D0790 *Rva006D0790::rva006D0790(Rva006D0280 *p, void *q)
{
    m_unk00 = 0;
    m_sub = p;
    if (p != 0)
        ++p->m_useCount;
    m_unk08 = q;
    m_flag0C = false;
    if (p == 0)
        return this;
    if (--p->m_useCount != 0)
        return this;
    p->teardown();
    g_pChainBlockAllocator->freeBlock(p, 0x1C);
    return this;
}
