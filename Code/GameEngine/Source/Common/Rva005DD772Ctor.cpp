// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /arch:SSE
// ??0Rva005DD772@@QAE@XZ @0x005DD772 81B.
// Default ctor of an 8-byte UnicodeString+float display record: base UnicodeString
// from narrow "-" at 0x83DD78 via AsciiString temp then float 0.0f at +4 via xmm.
// Callees all rowed: StringBase<char> 0x37BA0 plus UnicodeString(AsciiString)
// 0x6CB6D0 plus releaseBuffer 0x36410. Callers 0x5DD8E0/0x5DD9F9/0x5DDED5 all pass
// the same this as base init then format percent/time via set/format/concat.
// Non-virtual no vptr; returns this. Honest Rva ctor name; owner proven only as
// the shared base of those callers.
typedef unsigned short Wide;
class AsciiString;
class UnicodeString;
template<class T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    struct Header { int refs; unsigned short length,capacity; T data[1]; };
    Header *data;
    StringBase(const T*);
    StringBase(const StringBase&);
    void releaseBuffer();
public:
    StringBase():data(0){}
    ~StringBase(){ releaseBuffer(); }
};
class AsciiString:public StringBase<char> {
public:
    AsciiString(const char *s):StringBase<char>(s){}
};
class UnicodeString:public StringBase<Wide> {
public:
    UnicodeString(const AsciiString&);
};
class Rva005DD772 : public UnicodeString {
public:
    float m04;
    Rva005DD772();
};
Rva005DD772::Rva005DD772() : UnicodeString(AsciiString("-")), m04(0.0f) {}
