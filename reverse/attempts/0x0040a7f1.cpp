// ?rva0040A7F1@Rva0040A7F1@@QBEHH@Z
// partial score=0.9 date=2026-10-04
// cl: /Os
// Evidence: unlock lane; same unsigned bounds-checked index as sibling
// Rva0040A7D5 (begin-end count sar 2 returns 0 else element) but begin-end at
// +4-+8; callers 0x00409B73 0x0040BD91 unclaimed.
class Rva0040A7F1
{
public:
    int rva0040A7F1(int index) const;
private:
    int m_pad;
    const int *m_begin;
    const int *m_end;
};

int Rva0040A7F1::rva0040A7F1(int index) const
{
    unsigned int count = (unsigned int)(m_end - m_begin);
    if ((unsigned int)index >= count)
        return 0;
    return m_begin[index];
}
