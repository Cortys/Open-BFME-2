// ?rva000AE84A@Rva000AE84A@@QAEXHHPAEH@Z
// partial score=0.98 date=2026-10-01
// cl: /O1
// ?rva000AE84A@Rva000AE84A@@QAEXHHPAEH@Z @0x000AE84A 319B
// Evidence: thiscall ret10 4 args (x y out unused); callers 0x00115322;
// offsets +8 +0x20 +0x98 +0x9C +0x80B0 +0x120E0 +0x120E4; entry 16B shl4;
// out[4] zero then 0xFF patterns; BfmeGrokGrid neighbours /O1.
struct Entry16
{
    int f0;
    unsigned char c4;
    unsigned char c5;
    unsigned char c6;
    unsigned char c7;
    unsigned char flags;
    unsigned char c9;
    char padA[2];
    int fC;
};

class Rva000AE84A
{
public:
    void rva000AE84A(int x, int y, unsigned char *out, int unused);

private:
    int m_pad0;
    int m_pad1;
    int m_w;
    char m_pad0C[0x14];
    int m_20;
    char m_pad24[0x74];
    void *m_98;
    int *m_9C;
    char m_padA0[0x80B0 - 0xA0];
    Entry16 *m_80B0;
    char m_pad80B4[0x120E0 - 0x80B4];
    int m_120E0;
    int m_120E4;
};

// ?rva000AE84A@Rva000AE84A@@QAEXHHPAEH@Z present-unmatched
void Rva000AE84A::rva000AE84A(int x, int y, unsigned char *out, int unused)
{
    (void)unused;
    int idx = (m_120E4 + y) * m_w + m_120E0 + x;
    if (idx >= m_20)
        return;
    if (m_98 == 0)
        return;
    int slot = m_9C[idx];
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    if (slot == 0)
        return;
    int off = slot * 16;
    if (((Entry16 *)((char *)m_80B0 + off))->c4 != 0)
    {
        if ((((Entry16 *)((char *)m_80B0 + off))->flags & 1) != 0)
        {
            out[3] = 0xFF;
            out[0] = 0xFF;
        }
        else
        {
            out[2] = 0xFF;
            out[1] = 0xFF;
        }
    }
    if (((Entry16 *)((char *)m_80B0 + off))->c5 != 0)
    {
        if ((((Entry16 *)((char *)m_80B0 + off))->flags & 1) != 0)
        {
            out[1] = 0xFF;
            out[0] = 0xFF;
        }
        else
        {
            out[3] = 0xFF;
            out[2] = 0xFF;
        }
    }
    if (((Entry16 *)((char *)m_80B0 + off))->c6 != 0)
    {
        if ((((Entry16 *)((char *)m_80B0 + off))->flags & 1) != 0)
        {
            out[1] = 0xFF;
            if (*(const char *)((const char *)off + (unsigned int)m_80B0 + 9) != 0)
            {
                out[0] = 0xFF;
                out[2] = 0xFF;
            }
        }
        else
        {
            out[2] = 0xFF;
            if (*(const char *)((const char *)off + (unsigned int)m_80B0 + 9) != 0)
            {
                out[1] = 0xFF;
                out[3] = 0xFF;
            }
        }
    }
    if (((Entry16 *)((char *)m_80B0 + off))->c7 != 0)
    {
        if ((((Entry16 *)((char *)m_80B0 + off))->flags & 1) != 0)
        {
            out[0] = 0xFF;
            if (*(const char *)((const char *)off + (unsigned int)m_80B0 + 9) != 0)
            {
                out[1] = 0xFF;
                out[3] = 0xFF;
            }
        }
        else
        {
            out[3] = 0xFF;
            if (*(const char *)((const char *)off + (unsigned int)m_80B0 + 9) != 0)
            {
                out[0] = 0xFF;
                out[2] = 0xFF;
            }
        }
    }
    if (*(const int *)((const char *)off + (unsigned int)m_80B0 + 0xC) >= 0)
    {
        out[3] = 0;
        out[2] = 0;
        out[1] = 0;
        out[0] = 0;
    }
}
