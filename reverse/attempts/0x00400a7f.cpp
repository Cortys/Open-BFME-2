// ??1Rva00400A7F@@UAE@XZ
// partial score=0.95 date=2026-09-27
// ??1Rva00400A7F@@UAE@XZ
// partial score=0.95 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
// stlport
// ??1Rva00400A7F@@UAE@XZ @0x00400A7F 121B: Snapshot dtor stores vtable 0x008193C8 then restores 0x00BBB554; owns TreeHintOpaque0043671B 0x00229840 at +0xC8 via delete plus null, Version 0x00002152 at +0x90, narrow releaseBuffer 0x00036410 at +0x40, wide releaseBuffer 0x00036E70 at +0x04; layout from callers and EH states 3-0.
#include <map>
template <typename T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    StringBase(const StringBase &);
    void releaseBuffer();
    __forceinline ~StringBase() { releaseBuffer(); }
    void *m_data;
};
class AsciiString : private StringBase<char> {
public:
    __forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    __forceinline ~AsciiString() {}
};
class UnicodeString : private StringBase<unsigned short> {
public:
    __forceinline UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    __forceinline ~UnicodeString() {}
};
class Xfer;
class Snapshot {
public:
    __forceinline virtual ~Snapshot() {}
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
};
struct BfmeSubobject0022CE19 {
    virtual ~BfmeSubobject0022CE19();
    unsigned char m_opaque[0xDE4];
    BfmeSubobject0022CE19(const BfmeSubobject0022CE19 &);
};
struct TreeHintOpaque0043671B {
    UnicodeString m_text;
    BfmeSubobject0022CE19 m_subobject;
    unsigned int m_wordDEC, m_wordDF0;
    TreeHintOpaque0043671B();
    TreeHintOpaque0043671B(const TreeHintOpaque0043671B &);
    ~TreeHintOpaque0043671B();
};
struct Version {
    unsigned char m_opaque[0x30];
    ~Version();
};
struct Rva00400A7F : public Snapshot {
    UnicodeString m_text04;
    unsigned char m_pad08[0x38];
    AsciiString m_text40;
    unsigned char m_pad44[0x4C];
    Version m_version90;
    unsigned char m_padC0[8];
    TreeHintOpaque0043671B *m_ptrC8;
    virtual ~Rva00400A7F();
};
Rva00400A7F::~Rva00400A7F() {
    delete m_ptrC8;
    m_ptrC8 = 0;
}
