// cl: /O1 /DNDEBUG /MD /EHsc
// ??1Rva003FAFB9@@UAE@XZ @0x003FAFB9 82B chain from 0x003FAC3F
// Dtor: stores 0x00837A08, calls rowed rva003FAC3F, holder Release_Ref at +0x14,
// StringBase releaseBuffer at +4, restores 0x00BBB554. Evidence: EH prolog,
// states 2/1/0, Release_Ref row, StringBase row, base BBB554.
class Xfer;
class Snapshot {
public:
    virtual ~Snapshot();
    virtual void crc(Xfer *xfer);
    virtual void loadPostProcess();
    virtual void xfer(Xfer *xfer);
};
extern const void *const g_00BBB554[];
inline Snapshot::~Snapshot() { *(const void **)this = g_00BBB554; }
class Rva003FAC3F {
public:
    void rva003FAC3F();
};
class OpaqueRefCounted {
public:
    void Release_Ref();
};
struct RvaHolder14 {
    OpaqueRefCounted *m_ptr;
    ~RvaHolder14() { if (m_ptr != 0) m_ptr->Release_Ref(); }
};
template <typename T> class StringBase {
    void releaseBuffer();
public:
    ~StringBase() { releaseBuffer(); }
private:
    char m_pad[16];
};
class Rva003FAFB9 : public Snapshot {
public:
    virtual ~Rva003FAFB9();
private:
    StringBase<char> m_str04;
    RvaHolder14 m_14;
    unsigned char pad18[0x14];
    unsigned int m_2c;
};
Rva003FAFB9::~Rva003FAFB9()
{
    ((Rva003FAC3F *)this)->rva003FAC3F();
}
