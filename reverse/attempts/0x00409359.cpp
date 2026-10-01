// ??4CreateAHeroData@@QAEAAV0@ABV0@@Z
// partial score=0.97 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??4CreateAHeroData@@QAEAAV0@ABV0@@Z @0x00409359 254B
// Evidence: unlock lane; CreateAHeroData 0x140 layout from matched copy ctor
// 0x00409D4D and dtor 0x00409285 with vtable C38D88; callees all rowed
// (setters 407A6A 407004 406EFD 406F12 406F27 406F3C, vector/tree assigns,
// BfmeHeroElement assign 406E22); callers 40A384 2DBAB9 5B5C02 5B2725 21A428 3FF50C 5B1E71.
#include <memory>
#include <vector>
#include <map>

#include "ascii_string.h"
#include "unicode_string.h"
class Xfer;
class Snapshot {
public:
    __forceinline virtual ~Snapshot() {}
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
};
struct TreeHintPayload001F8ACB { unsigned int value; };
bool operator<(const AsciiString &, const AsciiString &);
typedef _STL::map<int,int> IntegerMap;
typedef _STL::map<AsciiString,TreeHintPayload001F8ACB> StringPayloadMap;
typedef _STL::map<int,_STL::vector<unsigned int> > IntegerVectorMap;
struct BfmeHeroElement005C39DE {
    AsciiString text;
    unsigned int word4, word8;
    BfmeHeroElement005C39DE();
    BfmeHeroElement005C39DE &operator=(const BfmeHeroElement005C39DE &);
};
class Rva00407A6A { public: bool rva00407A6A(const UnicodeString &arg); };
class Rva00406EFD { public: bool rva00406EFD(int v); bool rva00407004(int v); };
class Rva00406F12 { public: bool rva00406F12(int v); };
class Rva00406F27 { public: bool rva00406F27(int v); };
class Rva00406F3C { public: bool rva00406F3C(int v); };
class CreateAHeroData : public Snapshot {
    unsigned int word04;
    UnicodeString text08;
    unsigned int word0C, word10;
    IntegerMap map14, map20;
    unsigned int word2C, word30, word34, word38;
    _STL::vector<AsciiString> strings3C;
    unsigned char flag48;
    AsciiString text4C;
    StringPayloadMap map50;
    _STL::vector<bool> bits5C;
    unsigned char flag70, flag71;
    IntegerVectorMap map74;
    BfmeHeroElement005C39DE elements80[15];
    unsigned int word134, word138, word13C;
public:
    CreateAHeroData &operator=(const CreateAHeroData &o);
    virtual ~CreateAHeroData();
};
CreateAHeroData &CreateAHeroData::operator=(const CreateAHeroData &o)
{
    if (this != &o) {
        word04 = o.word04;
        ((Rva00407A6A *)this)->rva00407A6A(o.text08);
        ((Rva00406EFD *)this)->rva00407004(o.word0C);
        ((Rva00406EFD *)this)->rva00406EFD(o.word10);
        map14 = o.map14;
        map20 = o.map20;
        ((Rva00406F12 *)this)->rva00406F12(o.word2C);
        ((Rva00406F27 *)this)->rva00406F27(o.word30);
        ((Rva00406F3C *)this)->rva00406F3C(o.word34);
        word38 |= 0xE4;
        strings3C = o.strings3C;
        flag48 = o.flag48;
        text4C = o.text4C;
        map50 = o.map50;
        bits5C = o.bits5C;
        flag70 = 0;
        flag71 = o.flag71;
        map74 = o.map74;
        word134 = o.word134;
        word138 = o.word138;
        word13C = o.word13C;
        for (int i = 0; i < 15; ++i)
            elements80[i] = o.elements80[i];
    }
    return *this;
}
