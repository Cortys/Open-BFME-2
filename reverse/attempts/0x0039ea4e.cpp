// ?rva0039EA4E@Rva0039EA4E@@QAEPAURva0039EA4ENode@@ABURva0039D8FBKey@@@Z
// partial score=0.95 date=2026-09-29
// ?rva0039EA4E@Rva0039EA4E@@QAEPAURva0039EA4ENode@@ABURva0039D8FBKey@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
// ?rva0039EA4E@Rva0039EA4E@@QAEPAURva0039EA4ENode@@ABURva0039D8FBKey@@@Z, retail 0x0039EA4E 78B.
// RB-tree find for TeamFactory pair key: walks root at header+4, left +8,
// right +0xC, key at +0x10 via rowed Less 0x0039D8FB. Returns header on miss.
// Prev/next share /O1 /DNDEBUG /MD. Callers 0x39F5CC 0x39FDF7 0x39FE50.
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
    Rva0039EA4ENode *m_header00;
};

// ?rva0039EA4E@Rva0039EA4E@@QAEPAURva0039EA4ENode@@ABURva0039D8FBKey@@@Z present-unmatched
Rva0039EA4ENode *Rva0039EA4E::rva0039EA4E(const Rva0039D8FBKey &key)
{
    Rva0039EA4ENode *header = m_header00;
    Rva0039EA4ENode *x = header->m_parent04;
    Rva0039EA4ENode *y = header;
    while (x) {
        if (!(unsigned char)Rva0039D8FBLess(x->m_key10, key)) {
            y = x;
            x = x->m_left08;
        }
        else
            x = x->m_right0C;
    }
    if (y == header)
        return y;
    if ((unsigned char)Rva0039D8FBLess(key, y->m_key10))
        y = header;
    return y;
}
