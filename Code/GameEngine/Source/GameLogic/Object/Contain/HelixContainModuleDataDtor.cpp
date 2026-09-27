// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// Target ctor1E0C90 and vtableBDD91C link this cleanup to wrapper1E1152.
// The four-byte field at148 releases a string buffer; the donor vector layout
// does not apply. HelixContainModuleData remains a donor-based name inference.

template <typename T>
class StringBase
{
    void *m_data;
    void releaseBuffer();

protected:
    ~StringBase() { releaseBuffer(); }
};

class BfmeOwnedString4 : private StringBase<char>
{
public:
    ~BfmeOwnedString4() {}
};

class Rva001DFA48Owner
{
public:
    virtual ~Rva001DFA48Owner();

private:
    unsigned char unknownBaseTail[0x144];
};

// The target dtor has no derived-vptr store. novtable keeps this view's dtor
// body aligned with that fact; no constructor is emitted from this file.
class __declspec(novtable) HelixContainModuleData : public Rva001DFA48Owner
{
public:
    virtual ~HelixContainModuleData();

private:
    BfmeOwnedString4 unknownOwnedField148;
    unsigned char unknownByte14C;
};

typedef char BaseExtent[sizeof(Rva001DFA48Owner) == 0x148 ? 1 : -1];
typedef char OwnedFieldExtent[sizeof(BfmeOwnedString4) == 4 ? 1 : -1];

HelixContainModuleData::~HelixContainModuleData() {}
