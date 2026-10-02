// cl: /O1 /MD
// ?rva005321D1@Rva005321D1@@QAEXGG@Z @ 0x005321D1 94B.
// Union-style with indirection: order two words, parent map via +4,
// remap via +0xC/+0x10 tables, rank bytes via +8 with 0xFE cap.
// Callees none. Same TU default flags as neighbours. Caller 0x00532470.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class Rva005321D1
{
public:
    void rva005321D1(unsigned short a, unsigned short b);
private:
    int m_00;
    unsigned short *m_map;
    unsigned char *m_counts;
    unsigned short *m_aux;
    unsigned short *m_remap;
};

void Rva005321D1::rva005321D1(unsigned short a, unsigned short b)
{
    if (a == b)
        return;
    if (a > b)
    {
        unsigned short t = a;
        a = b;
        b = t;
    }
    m_map[a] = b;
    unsigned short t2 = m_remap[b];
    m_aux[t2] = a;
    m_remap[b] = m_remap[a];
    unsigned char c = m_counts[a];
    if (c != m_counts[b])
        return;
    _ReadWriteBarrier();
    if (m_counts[b] >= 0xFE)
        return;
    m_counts[b]++;
}
