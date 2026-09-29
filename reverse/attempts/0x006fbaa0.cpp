// ??0Rva006FBC90Owner@@QAE@PAVAptValue@@@Z
// partial score=0.92 date=2026-09-29
// ??0Rva006FBC90Owner@@QAE@PAVAptValue@@@Z
// partial score=0.92 date=2026-09-29
// cl: /O2 /DNDEBUG /MD /EHsc
// ??0Rva006FBC90Owner@@QAE@PAVAptValue@@@Z @0x006FBAA0 109B
// Evidence: EH ctor calling base Rva006D6360(0x14,4) (BfmeAptValue type + AptNativeHash
// size) then storing derived vtable 0x00CED880; m_ctor at +0x1C assigned from arg
// with AddRef if non-null (slot 0 call); ret 4; caller at 0x006FBF3A.
class AptValue {
public:
    virtual void AddRef();
    virtual void Release();
};

class BfmeAptValue006DCD20 {
    virtual void vtableSlot0();
    unsigned int m_flags;
public:
    BfmeAptValue006DCD20(int type);
    virtual ~BfmeAptValue006DCD20();
};

class AptNativeHash {
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

class Rva006D6360 : public BfmeAptValue006DCD20 {
    AptNativeHash m_hash;
public:
    Rva006D6360(int type, int size);
};

class Rva006FBC90Owner : public BfmeAptValue006DCD20 {
    AptNativeHash m_hash;
    AptValue *m_ctor;
public:
    Rva006FBC90Owner(AptValue *p);
};

// ??0Rva006FBC90Owner@@QAE@PAVAptValue@@@Z present-unmatched
Rva006FBC90Owner::Rva006FBC90Owner(AptValue *p) : BfmeAptValue006DCD20(0x14), m_hash(4)
{
    m_ctor = p;
    if (p)
        p->AddRef();
}
