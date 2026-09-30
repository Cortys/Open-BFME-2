// ??0Rva006FE380@@QAE@PAVAptValue@@@Z
// partial score=0.93 date=2026-09-30
// ??0Rva006FE380@@QAE@PAVAptValue@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O2 /DNDEBUG /MD /EHsc
// ??0Rva006FE380@@QAE@PAVAptValue@@@Z @0x006FE380 120B ctor of Rva006FE460 family.
// Retail calls base BfmeAptValue(0x2a) plus AptNativeHash(8) at +8, stores base
// vtable 0x008EA228 then final 0x008EDE4C, inits m_bits at +0x1C via byte+and
// 0xFFFFFCFF, AddRefs arg via slot0 and stores to +0x20. Evidence: unlock lane;
// same vtable/base/member pattern as Rva006D6360Ctor TU; dtor 0x006FE460 sibling.
class BfmeAptValue006DCD20
{
    virtual void vtableSlot0();
    unsigned int m_flags;
    void setTypeAt006DBBC0(int type);
public:
    BfmeAptValue006DCD20(int type);
    virtual ~BfmeAptValue006DCD20();
};
class AptValue
{
public:
    virtual void AddRef();
    virtual void Release();
};
class AptNativeHash
{
    struct Entry { void *key; AptValue *value; };
    int mnTotalSize;
    Entry *mpData;
    AptValue *mp__proto__;
    AptValue *mpPrototype;
    unsigned int nEventHandlers;
public:
    AptNativeHash(int size);
    ~AptNativeHash();
};
class Rva006D6360 : public BfmeAptValue006DCD20
{
    AptNativeHash m_hash;
public:
    Rva006D6360(int type, int size) : BfmeAptValue006DCD20(type), m_hash(size) {}
    virtual ~Rva006D6360();
};
class Rva006FE380 : public Rva006D6360
{
    volatile unsigned int m_bits;
    AptValue *m_20;
public:
    Rva006FE380(AptValue *p);
    virtual ~Rva006FE380();
};

// ??0Rva006FE380@@QAE@PAVAptValue@@@Z present-unmatched
Rva006FE380::Rva006FE380(AptValue *p) : Rva006D6360(0x2a, 8)
{
    *(unsigned char *)&m_bits = 0;
    m_bits &= 0xFFFFFCFF;
    p->AddRef();
    m_20 = p;
}
