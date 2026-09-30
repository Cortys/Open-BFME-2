// ?rva003B11D2@Rva003B11D2@@QAEPAVOverridable@@VAsciiString@@@Z
// partial score=0.9 date=2026-09-30
// ?rva003B11D2@Rva003B11D2@@QAEPAVOverridable@@VAsciiString@@@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /EHsc /MD
// ?rva003B11D2@Rva003B11D2@@QAEPAVOverridable@@VAsciiString@@@Z 0x003B11D2 114B evidence: array at +0xc/+0x10 of Overridable ptrs; final-override chase via rowed 0x00288609 plus StringBase compare row 0x000069D6 on +0x10 name; by-value key with releaseBuffer; callers 0x0029B70E 0x003B1614
template <typename T> class StringBase {
    friend class AsciiString;
    void releaseBuffer();
public:
    int compare(const StringBase<T> &other) const;
protected:
    void *m_data;
};
class AsciiString : public StringBase<char> {
public:
    ~AsciiString() { releaseBuffer(); }
};
class Overridable {
    void *m_vptr;
    char m_pad04[0xC];
public:
    const Overridable *friend_getFinalOverride() const;
    AsciiString m_name10;
};
class Rva003B11D2 {
    int m_pad00[3];
    Overridable **m_begin;
    Overridable **m_end;
public:
    Overridable *rva003B11D2(AsciiString key);
};
// ?rva003B11D2@Rva003B11D2@@QAEPAVOverridable@@VAsciiString@@@Z present-unmatched
Overridable *Rva003B11D2::rva003B11D2(AsciiString key)
{
    for (unsigned i = 0; i < (unsigned)(m_end - m_begin); ++i) {
        const Overridable *f = m_begin[i]->friend_getFinalOverride();
        if (f->m_name10.compare(key) == 0)
            return m_begin[i];
    }
    return 0;
}
