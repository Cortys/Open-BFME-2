// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??1BfmeStringTailRecord144@@UAE@XZ: 128B EH destructor of the 144-byte
// tail record at 0x2D9A43, reloc-named by the single-element Destroy call
// site in stlport_asciistring_record_bodies.cpp (that TU keeps its flat
// placeholder, so the vector Destroy path there still calls the dtor
// directly; the scalar-deleting-dtor at vtable slot0 0x2DA070 proves this
// destructor itself is virtual, hence the UAE spelling and the real vtable
// here). Layout cross-proven by the installing constructors at
// 0x2D97D6/0x2D982A/0x2D9893: AsciiString members at +0x04/+0x1C/+0x20/+0x84
// (each destroyed through the 0x36410 fold), two refcounted-pointer members
// released through the pinned PoolMember::Rva0050ED3 at 0x50ED3 (same
// spelling as Rva004E18A2Dtor.cpp), and ints elsewhere. The +0x10 member's
// release runs against pointee+0x88, hence the holder; the holder's own
// layout past the release slot is unproven. Destruction runs
// +0x84/+0x20/+0x1C/+0x10/+0x08/+0x04, plain reverse declaration order under
// an empty dtor body. Zero new pins.
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
    ~AsciiString();
    AsciiString &operator=(const AsciiString &);
};
class PoolMember
{
public:
    void Rva0050ED3();
};
typedef long Long;
extern "C" __declspec(dllimport) Long __stdcall InterlockedIncrement(Long volatile *addend);
struct BfmePoolHolder88
{
    unsigned char m_pad[0x88];
    PoolMember m_ref;
};
class BfmePoolRef08
{
    PoolMember *m_target;
public:
    __forceinline ~BfmePoolRef08() { if (m_target != 0) m_target->Rva0050ED3(); }
};
class BfmePoolRef10
{
    BfmePoolHolder88 *m_target;
public:
    __forceinline ~BfmePoolRef10() { if (m_target != 0) m_target->m_ref.Rva0050ED3(); }
    BfmePoolRef10(BfmePoolHolder88 *p);
    BfmePoolRef10(const BfmePoolRef10 &other);
    BfmePoolRef10 &operator=(const BfmePoolRef10 &other);
    void rva000519BD();
    void rva00053D26(BfmePoolHolder88 *p);
};
struct BfmeStringTailRecord144
{
    virtual ~BfmeStringTailRecord144();
    AsciiString m_string04;
    BfmePoolRef08 m_pool08;
    int m_int0C;
    BfmePoolRef10 m_pool10;
    int m_int14;
    int m_int18;
    AsciiString m_string1C;
    AsciiString m_string20;
    int m_data[24];
    AsciiString m_string84;
    int m_tail[2];
};
// ??1BfmeStringTailRecord144@@UAE@XZ
BfmeStringTailRecord144::~BfmeStringTailRecord144()
{
}
// ??0BfmePoolRef10@@QAE@PAUBfmePoolHolder88@@@Z 0x00051931 31B raw ctor via InterlockedIncrement on holder+0x8c; 2 callers at 0x528A9/0x56A78F; same shape as AudioEventInfoRef ctor at 0x51914 with +0x8c offset
BfmePoolRef10::BfmePoolRef10(BfmePoolHolder88 *p) : m_target(p)
{
    if (m_target)
        InterlockedIncrement((Long *)((char *)m_target + 0x8c));
}
// ??0BfmePoolRef10@@QAE@ABV0@@Z 0x00051950 33B copy ctor via InterlockedIncrement on holder+0x8c; 9 callers incl 0x519F1/0x51C7E; double-deref of source ref
BfmePoolRef10::BfmePoolRef10(const BfmePoolRef10 &other) : m_target(other.m_target)
{
    if (m_target)
        InterlockedIncrement((Long *)((char *)m_target + 0x8c));
}
// ??4BfmePoolRef10@@QAEAAV0@ABV0@@Z 0x00051971 58B operator= self-check then AddRef source and Release old via pinned 0x50ED3; 13 callers incl 0x5990A/0x2D98C2; same shape as OpaqueRefElement4::operator= at 0x239099
BfmePoolRef10 &BfmePoolRef10::operator=(const BfmePoolRef10 &other)
{
    if (this != &other) {
        if (other.m_target)
            InterlockedIncrement((Long *)((char *)other.m_target + 0x8c));
        if (m_target)
            m_target->m_ref.Rva0050ED3();
        m_target = other.m_target;
    }
    return *this;
}
// ?rva000519BD@BfmePoolRef10@@QAEXXZ 0x000519BD 25B release via pinned 0x50ED3 then and-zero; 7 callers incl 0x53D32/0x599FD/0x2D97C7; address-derived clear on BfmePoolRef10 (dtor already rowed at 0x519AB)
void BfmePoolRef10::rva000519BD()
{
    if (m_target) {
        m_target->m_ref.Rva0050ED3();
        m_target = 0;
    }
}
// ?rva00053D26@BfmePoolRef10@@QAEXPAUBfmePoolHolder88@@@Z 0x00053D26 41B assign from raw holder via clear at 0x519BD then InterlockedIncrement on holder+0x8c; 10 callers incl 0x59943/0x5B2E9; same family as ctors above
void BfmePoolRef10::rva00053D26(BfmePoolHolder88 *p)
{
    if (p != m_target) {
        rva000519BD();
        m_target = p;
        if (p)
            InterlockedIncrement((Long *)((char *)p + 0x8c));
    }
}
