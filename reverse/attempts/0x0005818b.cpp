// ?rva0005818B@Rva00699180Owner@@QAEXPBUHolderPtr@@H@Z
// partial score=0.95 date=2026-09-30
// ?rva0005818B@Rva00699180Owner@@QAEXPBUHolderPtr@@H@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /arch:SSE2 /Oi
// stlport
// ?rva0005818B@Rva00699180Owner@@QAEXPBUHolderPtr@@H@Z @0x0005818B 96B: thiscall.
// Iterates array at arg+0xB8 of {int id float val} skipping -1, push_backs
// {val secondArg} to this+0x4C[id] vectors then calls row 0x00052098 on id.
// Owner proven as Rva00699180Owner via shared this to row rva00052098.
// Chain from 0x00052098. Callers are 0x000581FA x2.
#include <vector>

struct BfmeE8
{
    float m_val;
    int m_b;
};

struct Elem8
{
    int m_id;
    float m_val;
};

struct HolderB8
{
    char m_pad[0xB8];
    Elem8 *m_begin;
    Elem8 *m_end;
};

struct HolderPtr
{
    HolderB8 *m_ptr;
};

class Rva00699180Owner
{
public:
    void rva00052098(int b);
    void rva0005818B(const HolderPtr *p, int b);
private:
    char m_pad0[4];
    float m_base[12];
    float m_product[6];
    _STL::vector<BfmeE8> m_vec[6];
    float m_atten;
    float m_vol;
    float m_scale;
    char m_padA0[0xC8 - 0xA0];
    float m_slot[12][4];
};

// ?rva0005818B@Rva00699180Owner@@QAEXPBUHolderPtr@@H@Z present-unmatched
void Rva00699180Owner::rva0005818B(const HolderPtr *p, int b)
{
    char *base = (char *)p->m_ptr + 0xB8;
    Elem8 *first = *(Elem8 **)base;
    Elem8 *last = *(Elem8 **)(base + 4);
    for (Elem8 *it = first; it != last; ++it)
    {
        int id = it->m_id;
        if (id == -1)
            continue;
        BfmeE8 e;
        e.m_val = it->m_val;
        e.m_b = b;
        m_vec[id].push_back(e);
        rva00052098(id);
    }
}
