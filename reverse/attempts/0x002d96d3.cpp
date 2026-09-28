// ?rva002D96D3@BfmeStringTailRecord144@@QAEXABUOpaqueRefElement4@@@Z
// partial score=0.97 date=2026-09-28
// ?rva002D96D3@BfmeStringTailRecord144@@QAEXABUOpaqueRefElement4@@@Z
// partial score=0.97 date=2026-09-28
// cl: /O1 /MD /arch:SSE
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
template<typename T> class StringBase {
    void *m_data;
    void releaseBuffer();
    friend struct BfmeStringTailRecord144;
public:
    StringBase();
    StringBase(const StringBase &);
    StringBase &operator=(const StringBase &);
protected:
    __forceinline ~StringBase() { releaseBuffer(); }
};
class AsciiString : public StringBase<char> {
public:
    AsciiString() {}
    AsciiString(const AsciiString &o) : StringBase<char>(o) {}
    ~AsciiString();
    AsciiString &operator=(const AsciiString &);
    static const AsciiString TheEmptyString;
};
class OpaqueRefCounted { public: void Release_Ref(); };
struct OpaqueRefElement4 {
    OpaqueRefCounted *referent;
    OpaqueRefElement4 &operator=(const OpaqueRefElement4 &other);
};
class Rva000A8C9B {
public:
    void clear();
};
class PoolMember { public: void Rva0050ED3(); };
struct BfmePoolHolder88 { unsigned char m_pad[0x88]; PoolMember m_ref; };
class BfmePoolRef10 {
    BfmePoolHolder88 *m_target;
public:
    void rva000519BD();
};
struct BfmeStringTailRecord144 {
    virtual ~BfmeStringTailRecord144();
    AsciiString m_string04;
    Rva000A8C9B m_holder08;
    int m_int0C;
    BfmePoolRef10 m_pool10;
    int m_int14;
    int m_int18;
    AsciiString m_string1C;
    AsciiString m_string20;
    float m_f24;
    float m_f28;
    float m_f2C;
    int m_int30;
    int m_int34;
    int m_int38;
    float m_f3C;
    float m_f40;
    float m_f44;
    unsigned char m_b48;
    unsigned char m_b49;
    unsigned char m_b4A;
    unsigned char m_b4B;
    unsigned char m_b4C;
    unsigned char m_b4D;
    unsigned char m_b4E;
    unsigned char m_b4F;
    unsigned char m_b50;
    unsigned char m_b51;
    unsigned char m_b52;
    unsigned char m_b53;
    float m_f54;
    float m_f58;
    float m_f5C;
    float m_f60;
    float m_f64;
    int m_int68;
    int m_int6C;
    int m_int70;
    int m_int74;
    int m_int78;
    int m_int7C;
    int m_int80;
    AsciiString m_string84;
    int m_tail88;
    int m_tail8C;
    void rva002D96D3(const OpaqueRefElement4 &arg);
};
void BfmeStringTailRecord144::rva002D96D3(const OpaqueRefElement4 &arg)
{
    m_f24 = -1.0f;
    m_f28 = -1.0f;
    m_f2C = 1.0f;
    m_f3C = 0.0f;
    m_f40 = 0.0f;
    m_f44 = 0.0f;
    _ReadWriteBarrier();
    m_b48 = 0;
    m_int38 = 6;
    m_int30 = 0;
    m_b49 = 0;
    m_string04 = AsciiString::TheEmptyString;
    Rva000A8C9B &holder = m_holder08;
    holder.clear();
    m_int68 = -1;
    m_int6C = -1;
    m_f54 = 1.0f;
    m_f58 = 1.0f;
    m_f5C = 1.0f;
    m_f60 = 1.0f;
    m_int0C = 0;
    m_int18 = 0;
    m_f64 = 0.0f;
    m_b4A = 0;
    m_b4B = 0;
    m_b4C = 0;
    m_b4D = 1;
    m_b4E = 0;
    m_b4F = 0;
    m_b50 = 0;
    m_b51 = 0;
    m_b52 = 0;
    m_b53 = 0;
    m_int74 = 0;
    static_cast<StringBase<char>&>(m_string1C).releaseBuffer();
    static_cast<StringBase<char>&>(m_string20).releaseBuffer();
    m_int78 = 1;
    static_cast<StringBase<char>&>(m_string84).releaseBuffer();
    m_int7C = -12345;
    reinterpret_cast<OpaqueRefElement4&>(holder) = arg;
    m_int70 = -1;
    m_int80 = 1;
    m_pool10.rva000519BD();
    m_int14 = 0;
}
