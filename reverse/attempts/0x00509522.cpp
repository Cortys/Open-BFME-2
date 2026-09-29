// ??0Made002CC774@@QAE@XZ
// partial score=0.9 date=2026-09-29
// ??0Made002CC774@@QAE@XZ
// partial score=0.90 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
// ??0Made002CC774@@QAE@XZ, retail 0x00509522 38B.
// Base Rva00507823 plus vtable 0x00864520 plus three ints at
// +0x130/+0x128/+0x12c zeroed. Caller parseDamageFieldNugget.
// Made002CCBCA precedent.
class Rva00507823
{
public:
    virtual ~Rva00507823();
    Rva00507823();
private:
    char m_pad04[0x128 - 4];
};
class Made002CC774 : public Rva00507823
{
public:
    Made002CC774();
    ~Made002CC774();
private:
    int m_128;
    int m_12c;
    int m_130;
};
// ??0Made002CC774@@QAE@XZ present-unmatched
Made002CC774::Made002CC774()
{
    m_130 = 0;
    m_128 = 0;
    m_12c = 0;
}
