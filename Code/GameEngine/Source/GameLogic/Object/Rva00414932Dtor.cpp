// cl: /O1 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva00414932@@UAE@XZ @ 0x00414932 75B: novtable dtor restoring Snapshot vtable 0x007BB554,
// calls vector<BfmeAssignRecord44> dtor at +0x1C, Rva00360D26Member dtor at +0x14,
// StringBase releaseBuffer at +0x04. Precedent Rva0040DB52Dtor plus
// stlport_asciistring_record_bodies layout; callers include ??_G at 0x00414AEE.
#include <vector>

template<class T> class StringBase {
    void *m_data;
    void releaseBuffer();
public:
    StringBase();
    StringBase(const StringBase &);
    StringBase &operator=(const StringBase &);
protected:
    __forceinline ~StringBase() { releaseBuffer(); }
};
class AsciiString : private StringBase<char> {
public:
    __forceinline AsciiString() {}
    __forceinline AsciiString(const AsciiString &o) : StringBase<char>(o) {}
    __forceinline ~AsciiString() {}
    AsciiString &operator=(const AsciiString &);
};

struct BfmeAssignRecord44 { AsciiString s; int a[10]; };

class Rva00360D26Member
{
public:
    ~Rva00360D26Member();
private:
    unsigned m_unknown;
};

class Xfer;
class Snapshot
{
public:
    virtual ~Snapshot();
    virtual void crc(Xfer *xfer);
    virtual void loadPostProcess();
    virtual void xfer(Xfer *xfer);
};
extern const void *const g_00BBB554[];
inline Snapshot::~Snapshot()
{
    *(const void **)this = g_00BBB554;
}

class __declspec(novtable) Rva00414932 : public Snapshot
{
public:
    virtual ~Rva00414932();
private:
    AsciiString m_str04;
    char m_pad08[0x14 - 0x08];
    Rva00360D26Member m_member14;
    char m_pad18[0x1C - 0x18];
    _STL::vector<BfmeAssignRecord44, _STL::allocator<BfmeAssignRecord44> > m_vec1C;
};

Rva00414932::~Rva00414932()
{
}
