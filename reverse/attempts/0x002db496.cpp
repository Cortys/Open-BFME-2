// ?rva002DB496@Rva002DB496@@QAEPAXVAsciiString@@@Z
// partial score=0.95 date=2026-09-29
// ?rva002DB496@Rva002DB496@@QAEPAXVAsciiString@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /EHs
// ?rva002DB496@Rva002DB496@@QAEPAXVAsciiString@@@Z @0x002DB496 68B evidence: StringBase compare 0x000069D6 releaseBuffer 0x00036410 rowed; 4 callers
// Best probe 72B vs 68B 1 region: extra and [ebp-4],0 EH-state init at +0xB; 0 memory 0 register. Tried /EHsc vs /EHs (same) and throw() (kills EH to 45B). Needs EH-table shape without initial state store.

template <typename T>
class StringBase
{
    friend class AsciiString;
    friend class UnicodeString;
public:
    int compare(const StringBase<T> &other) const;
private:
    void releaseBuffer();
    struct Header
    {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };
    Header *m_data;
};

class AsciiString : public StringBase<char>
{
public:
    AsciiString() {}
    AsciiString(const AsciiString &other);
    __forceinline ~AsciiString() { releaseBuffer(); }
};

struct ListNode
{
    char m_pad00[4];
    AsciiString m_str04;
    char m_pad08[8];
    ListNode *m_next10;
};

class Rva002DB496
{
public:
    void *rva002DB496(AsciiString key);
private:
    char m_pad00[0xC];
    ListNode *m_head0C;
};

void *Rva002DB496::rva002DB496(AsciiString key)
{
    for (ListNode *n = m_head0C; n != 0; n = n->m_next10) {
        if (n->m_str04.compare(key) == 0)
            return n;
    }
    return 0;
}
