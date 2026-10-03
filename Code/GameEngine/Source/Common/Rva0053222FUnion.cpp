// cl: /O1 /MD
// ?rva0053222F@Rva0053222F@@QAEXGG@Z @0x0053222F 84B.
// Union-by-rank: early out when words equal rank table at +0x200 decides
// swap parent map at +0 then rank increment when ranks equal below 0xFE.
// Flags /O1 /MD like prev Rva005321D1Union. Caller 0x00532494.
class Rva0053222F
{
public:
    void rva0053222F(unsigned short a, unsigned short b);
private:
    unsigned short m_map[256];
    unsigned char m_counts[256];
};

void Rva0053222F::rva0053222F(unsigned short a, unsigned short b)
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
    unsigned char c = m_counts[b];
    if (m_counts[a] != c)
        return;
    if (c >= 0xFE)
        return;
    m_counts[b] = (unsigned char)(c + 1);
}
