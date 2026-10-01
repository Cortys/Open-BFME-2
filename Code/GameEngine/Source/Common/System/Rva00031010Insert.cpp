// ?rva00031010@Rva00031010@@QAEXPAURva00031010Node@@_N@Z @0x00031010 66B evidence EA GeneralAllocator large-bin insert beside GetLargeBinIndex plus caller 0x000333ED plus head at +0x440 plus bin at +0x30
struct Rva00031010Node
{
    unsigned char m_pad[8];
    Rva00031010Node *m_link8;
    Rva00031010Node *m_linkC;
};
class Rva00031010
{
public:
    void rva00031010(Rva00031010Node *node, bool flag);
private:
    unsigned char m_pad0[0x30];
    Rva00031010Node m_bin;
    unsigned char m_pad1[0x440 - 0x30 - sizeof(Rva00031010Node)];
    Rva00031010Node *m_head;
};
void Rva00031010::rva00031010(Rva00031010Node *node, bool flag)
{
    Rva00031010Node *old = m_head;
    m_head = node;
    node->m_linkC = node;
    node = *(Rva00031010Node * volatile *)&m_head;
    Rva00031010Node *bin;
    {
        Rva00031010Node *next = *(Rva00031010Node * volatile *)&node->m_linkC;
        bin = (Rva00031010Node *)((char *)this + 0x30);
        node->m_link8 = next;
        if (old == bin)
            return;
    }
    if (!flag)
        return;
    Rva00031010Node *after = bin->m_linkC;
    old->m_link8 = bin;
    old->m_linkC = after;
    bin->m_linkC = old;
    after->m_link8 = old;
}
