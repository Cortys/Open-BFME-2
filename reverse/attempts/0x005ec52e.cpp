// ?rva005EC52E@Rva005EC52E@@QAE_NABV1@@Z
// partial score=0.9 date=2026-09-28
// ?rva005EC52E@Rva005EC52E@@QAE_NABV1@@Z
// partial score=0.90 date=2026-09-28
// cl: /O1 /MD
// probe5 - swapped order + unsigned - 102B same size 38 insns same count
// Retail 0x005EC52E is an 8-byte element operator< used by sort/heap helpers
// (callers 0x005EC5BD linear-insert 0x005EC5F5 push-heap 0x005EC872 median
// and 0x0051D0B3 partition). Compares bit26 of [m_b+0x110] then int at
// [m_a+0x9c] signed-greater then AsciiString at [m_a+4] via rowed 0x5598C.
// This TU keeps thisMask as int for two test-setne conversions and uses
// unsigned flags for shr to match retail shr. Remaining diff is register
// allocation only: ebx-for-edi esi-offset-C-for-8 edx-for-eax dword-cmp
// for byte-cmp plus xor-ebx-before vs xor-eax-on-return.

template <typename T> class StringBase
{
public:
    int compare(const StringBase<T> &that) const;
private:
    void *m_data;
};

class AsciiString : public StringBase<char>
{
};

bool operator<(const AsciiString &left, const AsciiString &right);

struct ObjA
{
    int _0;
    AsciiString m_str;
    unsigned char _pad[0x9c - 8];
    int m_key;
};

struct ObjB
{
    unsigned char _pad[0x110];
    unsigned int m_flags;
};

class Rva005EC52E
{
public:
    ObjA *m_a;
    ObjB *m_b;
    bool rva005EC52E(const Rva005EC52E &other);
};

// ?rva005EC52E@Rva005EC52E@@QAE_NABV1@@Z present-unmatched
bool Rva005EC52E::rva005EC52E(const Rva005EC52E &other)
{
    bool otherBit = ((other.m_b->m_flags >> 26) & 1) != 0;
    int thisMask = m_b->m_flags & 0x4000000;
    if ((thisMask != 0) != otherBit)
        return thisMask;
    int thisKey = m_a->m_key;
    int otherKey = other.m_a->m_key;
    if (thisKey != otherKey)
        return thisKey > otherKey;
    return m_a->m_str < other.m_a->m_str;
}
