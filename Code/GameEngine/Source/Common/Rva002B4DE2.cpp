// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /arch:SSE
// stlport
// ?rva002B4DE2@Rva002B4DE2@@QAEHXZ @0x002B4DE2 139B.
// Unlock lane; list of BfmeStringRecord002B4DC1 at +0xF0 counted by word1
// (2 -> ebx, 1 -> count1, total) then float ratios vs threshold at 0x007C6688.
// Callees rowed 0x002B4DC1 and 0x00036E70; unblocks 0x00512948.
// TU-local honest-address class; record layout from StringRecordInlineCopyBFME2.cpp.
template <typename T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    StringBase(const StringBase &) throw();
    __forceinline ~StringBase() { releaseBuffer(); }
    void releaseBuffer() throw();
public:
    void set(const StringBase &);
private:
    void *m_data;
};
class UnicodeString : private StringBase<unsigned short> {
public:
    __forceinline UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    __forceinline ~UnicodeString() {}
};

struct BfmeStringRecord002B4DC1 {
    UnicodeString text;
    unsigned int word0;
    unsigned int word1;
    BfmeStringRecord002B4DC1(const BfmeStringRecord002B4DC1 &o) throw();
};

struct Rva002B4DE2Node {
    Rva002B4DE2Node *m_next;
    Rva002B4DE2Node *m_prev;
    BfmeStringRecord002B4DC1 m_value;
};

class Rva002B4DE2 {
    char m_pad[0xF0];
    Rva002B4DE2Node *m_list;
public:
    int rva002B4DE2();
};

int Rva002B4DE2::rva002B4DE2()
{
    int count1 = 0;
    int total = 0;
    int count2 = 0;
    for (Rva002B4DE2Node *n = m_list->m_next; n != m_list; n = n->m_next) {
        BfmeStringRecord002B4DC1 tmp = n->m_value;
        if (tmp.word1 == 2)
            ++count2;
        else if (tmp.word1 == 1)
            ++count1;
        ++total;
    }
    if ((float)count2 / (float)total >= 0.75f)
        return 2;
    if ((float)(count2 + count1) / (float)total >= 0.75f)
        return 1;
    return 0;
}
