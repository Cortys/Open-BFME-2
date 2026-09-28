// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva00500500@@QAE@ABV0@@Z @ 0x00500500 (29B).
// ??0Rva00500500@@QAE@AAPAXABVRva004E3184@@@Z @ 0x00500770 (29B).
// Copy and pointer-plus-Rva ctors of the 92-byte wrapper holding a pointer
// at +0 and the ModuleData Rva004E3184 at +4 via its rowed copy at
// 0x004E2F9F. Caller 0x00503355 builds a temp with the two-arg ctor then
// copies it with the copy ctor. Frameless: the pointer is trivial and the
// Rva is last so no EH unwind is needed.
#include <memory>
#include <vector>

template <typename T> class StringBase {
    friend class AsciiString;
public:
    StringBase() : m_data(0) {}
    StringBase(const StringBase &);
    ~StringBase();
protected:
    void *m_data;
};

class AsciiString : public StringBase<char> {
public:
    AsciiString() {}
    AsciiString(const AsciiString &other);
    ~AsciiString();
};

class Snapshot {
public:
    virtual ~Snapshot();
};

inline Snapshot::~Snapshot()
{
    *(const void **)this = reinterpret_cast<const void *>(0x00BBB554);
}

class Rva004E3184 : public Snapshot {
public:
    virtual ~Rva004E3184();
    Rva004E3184(const Rva004E3184 &o);
private:
    AsciiString m_04;
    AsciiString m_08;
    AsciiString m_0c;
    AsciiString m_10;
    AsciiString m_14;
    AsciiString m_18;
    AsciiString m_1c;
    unsigned int m_20;
    unsigned int m_24;
    AsciiString m_28;
    AsciiString m_2c;
    AsciiString m_30;
    AsciiString m_34;
    _STL::vector<AsciiString> m_vec38;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    AsciiString m_50;
    unsigned char m_54;
    unsigned char m_55;
};

class Rva00500500 {
public:
    Rva00500500(const Rva00500500 &o);
    Rva00500500(void *&p, const Rva004E3184 &r);
private:
    void *m_ptr;
    Rva004E3184 m_rva;
};

Rva00500500::Rva00500500(const Rva00500500 &o)
    : m_ptr(o.m_ptr), m_rva(o.m_rva)
{
}

Rva00500500::Rva00500500(void *&p, const Rva004E3184 &r)
    : m_ptr(p), m_rva(r)
{
}
