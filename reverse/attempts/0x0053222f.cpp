// ?rva0053222F@Rva0053222F@@QAEXGG@Z
// partial score=0.92 date=2026-10-02
void rva_192000_swap_unsigned_short(unsigned short *left, unsigned short *right)
{
    unsigned short temporary = *left;
    *left = *right;
    *right = temporary;
}

// ?rva_53229d_copy_unsigned_short@@YAXPAG0@Z @ 0x0053229D 27B
// Null-guarded 4-byte copy as two word moves. Unblocks 0x005322B8,
// 0x005322DE, 0x005334A4 (callers push two pointers, callee plain ret).
void rva_53229d_copy_unsigned_short(unsigned short *dst, unsigned short *src)
{
    if (dst) {
        dst[0] = src[0];
        dst[1] = src[1];
    }
}

// ?rva0053222F@Rva0053222F@@QAEXGG@Z @0x0053222F 84B.
// Union-by-rank style: early out when words equal, rank table at +0x200
// decides swap of the two words, parent map at +0 then rank increment
// when ranks equal and below 0xFE. Callees none. Prev/next free word
// helpers in this TU give default flags and word idiom. Caller 0x00532494.
class Rva0053222F
{
public:
    void rva0053222F(unsigned short a, unsigned short b);
private:
    unsigned short m_map[256];
    unsigned char m_counts[256];
};

// ?rva0053222F@Rva0053222F@@QAEXGG@Z present-unmatched
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
    unsigned char *pr = &m_counts[b];
    unsigned char c = *pr;
    if (m_counts[a] != c)
        return;
    if (c >= 0xFE)
        return;
    *pr = (unsigned char)(c + 1);
}
