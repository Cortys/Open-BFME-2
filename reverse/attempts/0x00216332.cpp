// ?Rva00216332Call@@YAHPAX0PBDPBIPBQAX@Z
// partial score=0.97 date=2026-10-03
// cl: /O1 /MD /EHsc /G7
// class-gate: allow AsciiString shared str uses local empty vs retail global empty 0x00216332
// ?Rva00216332Call@@YAHPAX0PBDPBIPBQAX@Z @0x00216332 104B uint-keyed Apt invoke with AsciiString temp.
// Evidence: uint deref at 0x14 via rowed Rva0022288EGet 0x0022288E extra ptr double-deref at 0x18 rowed invoke 0x00222A8B caller 0x00216850.
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
    const char *data() const { return m_data; }
};
AsciiString Rva0022288EGet(unsigned int val);
class Rva00222A8BTarget
{
public:
    int invoke(void *level, const char *function, int argc, const char *a0, void *a1, void *a2, void *a3, void *a4);
};
extern const char g_Rva0107301CEmptyString[];
// ?Rva00216332Call@@YAHPAX0PBDPBIPBQAX@Z present-unmatched
int __cdecl Rva00216332Call(void *target, void *level, const char *func, const unsigned int *val, void *const *extra)
{
    AsciiString s = Rva0022288EGet(*val);
    const char *d = s.data();
    const char *p = d ? d + 8 : g_Rva0107301CEmptyString;
    const void *a1 = *extra;
    return ((Rva00222A8BTarget *)target)->invoke(level, func, 2, p, (void *)a1, 0, 0, 0);
}
