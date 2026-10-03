// ?rva0039EA4E@Rva0039EA4E@@QAEPAURva0039EA4ENode@@ABURva0039D8FBKey@@@Z
// partial score=0.98 date=2026-10-03
// cl: /O1 /DNDEBUG /MD
struct Rva0039D8FBKey
{
    int m_first;
    int m_second;
};

int __cdecl Rva0039D8FBLess(const Rva0039D8FBKey &a, const Rva0039D8FBKey &b);

struct Rva0039EA4ENode
{
    int m_color00;
    Rva0039EA4ENode *m_parent04;
    Rva0039EA4ENode *m_left08;
    Rva0039EA4ENode *m_right0C;
    Rva0039D8FBKey m_key10;
};

class Rva0039EA4E
{
public:
    Rva0039EA4ENode *rva0039EA4E(const Rva0039D8FBKey &key);

private:
    __forceinline Rva0039EA4ENode *lower_bound(Rva0039EA4ENode *x, Rva0039EA4ENode *y, const Rva0039D8FBKey &key);
    Rva0039EA4ENode *m_header00;
};

__forceinline Rva0039EA4ENode *Rva0039EA4E::lower_bound(Rva0039EA4ENode *x, Rva0039EA4ENode *y, const Rva0039D8FBKey &key)
{
    while (x != 0) {
        if (!(unsigned char)Rva0039D8FBLess(x->m_key10, key)) {
            y = x;
            x = x->m_left08;
        } else
            x = x->m_right0C;
    }
    return y;
}

// ?rva0039EA4E@Rva0039EA4E@@QAEPAURva0039EA4ENode@@ABURva0039D8FBKey@@@Z present-unmatched
Rva0039EA4ENode *Rva0039EA4E::rva0039EA4E(const Rva0039D8FBKey &key)
{
    Rva0039EA4ENode *header = m_header00;
    Rva0039EA4ENode *j = lower_bound(header->m_parent04, header, key);
    if (j == header || (unsigned char)Rva0039D8FBLess(key, j->m_key10))
        j = header;
    return j;
}
