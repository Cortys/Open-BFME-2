// ?rva004182F8@Rva004182F8@@QAEPAUOutIter004182F8@@PAU2@PBVRva004181F5@@@Z
// partial score=0.97 date=2026-09-30
// ?rva004182F8@Rva004182F8@@QAEPAUOutIter004182F8@@PAU2@PBVRva004181F5@@@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /Ob2 /EHsc /MD
// 0x004182F8 124B chain: hash insert via bucketIndex rowed + StringBase compare
// rowed + Alloc. align_diff exact 124B/0 structural (only relocs); gate blocked
// because Alloc row 0x004182D3 is free YGPAX but caller passes this (mov ecx,esi)
// so Alloc must be thiscall method (retype centrally, body 37B ignores this so
// retype still matches). Caller uses thiscall allocNode plus OutIter* return
// (mov eax,ecx) for exact. t=25 model=muse-03
template <typename T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    StringBase(const StringBase &);
    __forceinline ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
public:
    int compare(const StringBase &other) const;
private:
    void *m_data;
};
class AsciiString : private StringBase<char> {
public:
    __forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    __forceinline ~AsciiString() {}
    AsciiString &operator=(const AsciiString &other);
};
class Rva004181F5 {
public:
    Rva004181F5(const Rva004181F5 &other);
private:
    char m_pad[0x1c];
};
class Rva000427195 {
public:
    int bucketIndex(const AsciiString *key);
};
struct Wrapper004182D3 {
    Wrapper004182D3 *m_next;
    Rva004181F5 m_value;
};
struct OutIter004182F8 {
    void *m_node;
    void *m_table;
    unsigned char m_inserted;
};
class Rva004182F8 {
public:
    void *allocNode(const Rva004181F5 *src);
    OutIter004182F8 *rva004182F8(OutIter004182F8 *out, const Rva004181F5 *key);
private:
    Rva000427195 m_base;
    Wrapper004182D3 **m_buckets;
    char m_pad08[8];
    int m_size;
};
// ?rva004182F8@Rva004182F8@@QAEPAUOutIter004182F8@@PAU2@PBVRva004181F5@@@Z present-unmatched
OutIter004182F8 *Rva004182F8::rva004182F8(OutIter004182F8 *out, const Rva004181F5 *key)
{
    int idx = m_base.bucketIndex((const AsciiString *)key);
    Wrapper004182D3 *head = m_buckets[idx];
    Wrapper004182D3 *cur = head;
    if (cur != 0) {
        do {
            const StringBase<char> &curKey = (const StringBase<char> &)cur->m_value;
            if (curKey.compare((const StringBase<char> &)*key) == 0) {
                out->m_node = cur;
                out->m_table = this;
                out->m_inserted = 0;
                return out;
            }
            cur = cur->m_next;
        } while (cur != 0);
    }
    Wrapper004182D3 *fresh = (Wrapper004182D3 *)allocNode(key);
    fresh->m_next = head;
    m_buckets[idx] = fresh;
    ++m_size;
    out->m_node = fresh;
    out->m_table = this;
    out->m_inserted = 1;
    return out;
}
