// cl: /O1 /MD
// ?rva00532165@Rva00532165@@QAEXGG@Z @ 0x00532165 108B.
// Union-by-rank: order by counts at +8, parent map via +4,
// remap via +0xC/+0x10, rank inc via +8 with 0xFE cap.
// Callees none. Same TU default flags as neighbours. Caller 0x0053244C.
class Rva00532165
{
public:
    void rva00532165(unsigned short a, unsigned short b);
private:
    int m_00;
    unsigned short *m_map;
    unsigned char *m_counts;
    unsigned short *m_aux;
    unsigned short *m_remap;
};

void Rva00532165::rva00532165(unsigned short a, unsigned short b)
{
    if (a == b)
        return;
    if (m_counts[a] > m_counts[b])
    {
        unsigned short t = a;
        a = b;
        b = t;
    }
    m_map[a] = b;
    unsigned short t2 = m_remap[b];
    m_aux[t2] = a;
    m_remap[b] = m_remap[a];
    {
        unsigned char c = m_counts[a];
        if (c != m_counts[b])
            return;
    }
    if (m_counts[b] >= 0xFE)
        return;
    m_counts[b]++;
}
