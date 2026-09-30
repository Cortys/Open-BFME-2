// ?Rva002162CFFire@@YAPAXPAX0PBDPBI@Z
// partial score=0.94 date=2026-09-30
// ?Rva002162CFFire@@YAPAXPAX0PBDPBI@Z
// partial score=0.94 date=2026-09-30
// cl: /O1 /MD /EHsc /G7
// ?Rva002162CFFire@@YAXPAXPAXPBDPIB@@Z @0x002162CF 99B UI callback firer.
// Retail builds an AsciiString via rowed Rva0022288EGet from the ID at +0 of
// arg4, uses its data (+8) or a default, then fires rowed/pinned invoke with
// (target arg1, owner arg2, name arg3, 1, value, 0, 0, 0, 0, esi). Evidence:
// unlock lane; caller 0x002167DD passes DeleteBanner plus element; invoke
// signature shared with UiCallbackFirers TU; AsciiString pattern shared with
// Rva0022288EGet TU; prev/next flags /O1 /MD.
template <typename T> class StringBase
{
    friend class AsciiString;
    StringBase(const StringBase<T> &other);
    void releaseBuffer();
    T *m_data;
public:
    StringBase() : m_data(0) {}
    ~StringBase() { releaseBuffer(); }
};

class AsciiString : public StringBase<char>
{
public:
    AsciiString() {}
    AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    ~AsciiString() {}
    bool hasData() const { return m_data != 0; }
    const char *data() const { return m_data; }
};

AsciiString Rva0022288EGet(unsigned int val);

class Rva00222A8BTarget
{
public:
    void *invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern const char g_007BAC1C[];

// ?Rva002162CFFire@@YAPAXPAX0PBDPBI@Z present-unmatched
void *Rva002162CFFire(void *target, void *owner, const char *name, const unsigned int *id)
{
    AsciiString tmp = Rva0022288EGet(*id);
    const char *d = tmp.data();
    const char *value = d ? d + 8 : g_007BAC1C;
    void *r = ((Rva00222A8BTarget *)target)->invoke(owner, name, 1, value, 0, 0, 0, 0);
    return r;
}
