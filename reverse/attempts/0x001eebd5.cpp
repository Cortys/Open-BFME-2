// ?rva001EEBD5@Mouse@@QAEXV?$StringBase@G@@PBU_MouseSixteen@@1@Z
// partial score=0.91 date=2026-09-29
// ?rva001EEBD5@Mouse@@QAEXV?$StringBase@G@@PBU_MouseSixteen@@1@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /MD /EHsc
// ?rva001EEBD5@Mouse@@QAEXV?$StringBase@G@@PBU_MouseSixteen@@1@Z, retail 0x001EEBD5, 118 bytes.
// Mouse wide-text plus two 16-byte payload setter. Evidence: Mouse neighbours
// (same /O1 area, +0x4Fxx offsets near rva001EEA6D); by-value wide-string temp
// via rowed private StringBase<G> copyctor plus rowed releaseBuffer EH
// cleanup (GadgetStaticText/MouseRva001EEC4B friend pattern); virtual slot 1
// on +0x4FA8; guarded 16-byte copies into +0x4FAC/+0x4FBC.
// ?rva001EEBD5@Mouse@@QAEXV?$StringBase@G@@PBU_MouseSixteen@@1@Z present-unmatched
class Mouse;
template <class T> class StringBase {
    StringBase(const StringBase &other);
    void releaseBuffer();
    T *m_data;
    friend class Mouse;
public:
    ~StringBase() { releaseBuffer(); }
};
struct _MouseSixteen { int v[4]; };
struct MouseFontThunk {
    virtual void slot0();
    virtual void setText(StringBase<unsigned short> text);
};
class Mouse {
    char m_pad[0x4FA8];
    MouseFontThunk *m_4FA8;
    _MouseSixteen m_4FAC;
    _MouseSixteen m_4FBC;
public:
    void rva001EEBD5(StringBase<unsigned short> text, const _MouseSixteen *a, const _MouseSixteen *b);
};
void Mouse::rva001EEBD5(StringBase<unsigned short> text, const _MouseSixteen *a, const _MouseSixteen *b)
{
    if (m_4FA8)
        m_4FA8->setText(text);
    if (a)
        m_4FAC = *a;
    if (b)
        m_4FBC = *b;
}
