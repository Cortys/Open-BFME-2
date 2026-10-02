// ?rva005DE926@Rva005DE5B5@@QAEXXZ
// partial score=0.88 date=2026-10-02
struct Rva005DE5B5;
struct BfmeStringRecord005DDD40;
struct BfmeStringRecordVectorView
{
    BfmeStringRecord005DDD40 *begin;
    BfmeStringRecord005DDD40 *end;
    BfmeStringRecord005DDD40 *capacity;
};

// Rva005DE5B5 receiver: vector<BfmeStringRecord005DDD40> at +4; byte at +0x14.
void Rva005DE5B5::rva005DE926()
{
    register BfmeStringRecordVectorView *records =
        (BfmeStringRecordVectorView *)&m_04;
    unsigned int count = records->end - records->begin;
    m_04.erase(records->begin, records->end);
    m_04.resize(count);
    m_14 = 0;
}
