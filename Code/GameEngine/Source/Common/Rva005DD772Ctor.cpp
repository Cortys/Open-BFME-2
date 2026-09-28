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
    UnicodeString(){}
    UnicodeString(const UnicodeString& o):StringBase<Wide>(o){}
    ~UnicodeString(){}
    void __cdecl format(const UnicodeString* fmt, ...);
};
class Rva005DD772 : public UnicodeString {
public:
    float m04;
    Rva005DD772();
    Rva005DD772(const UnicodeString &str, float v);
};
Rva005DD772::Rva005DD772() : UnicodeString(AsciiString("-")), m04(0.0f) {}
// ??0Rva005DD772@@QAE@ABVUnicodeString@@M@Z @0x005DD86D 29B unlock lane:
// (UnicodeString,float) copy ctor: StringBase Wide copy 0x00037050 for the
// base at +0 then float to +4 via xmm; frameless ret 8 returning this.
// Same 8B layout and callees as the default ctor above; callers in the big
// parsers 0x005BEA70/0x005C1BDE.
Rva005DD772::Rva005DD772(const UnicodeString &str, float v) : UnicodeString(str), m04(v) {}
class GameTextInterface {
public:
    virtual ~GameTextInterface(){}
    virtual void slot00()=0; virtual void slot01()=0; virtual void slot02()=0; virtual void slot03()=0;
    virtual void slot04()=0; virtual void slot05()=0; virtual void slot06()=0; virtual void slot07()=0;
    virtual void slot08()=0; virtual void slot09()=0; virtual void slot10()=0; virtual void slot11()=0;
    virtual void slot12()=0; virtual void slot13()=0; virtual void slot14()=0; virtual void slot15()=0;
    virtual const UnicodeString& slot44(const char* label, bool* exists=0)=0;
};
extern GameTextInterface* TheGameText;
// ??0Rva005DD9F9@@QAE@M@Z @0x005DD9F9 94B chain of base 0x5DD772.
// Float ctor overwrites base m04 then rounds v+0.5f via 0x7C26F0 to int for
// TheGameText slot44 GUI:WinPercent fetch returning const UnicodeString&
// then UnicodeString format 0x6CB660. Same 8B layout no vptr returns this.
class Rva005DD9F9 : public Rva005DD772 {
public:
    Rva005DD9F9(float v);
};
Rva005DD9F9::Rva005DD9F9(float v) : Rva005DD772() {
    m04 = v;
    int i = (int)(v + 0.5f);
    ((UnicodeString*)this)->format(&TheGameText->slot44("GUI:WinPercent"), i);
}
