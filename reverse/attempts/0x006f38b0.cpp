// ??0Rva006F38B0@@QAE@PAVAptCIH@@@Z
// partial score=0.9 date=2026-10-03
// cl: /O2 /DNDEBUG /MD /EHsc
//
// ??0Rva006F38B0@@QAE@PAVAptCIH@@@Z, retail 0x006F38B0, 170 bytes.
// Address-derived derived-value ctor: builds the Rva006D6360 base with type
// 0x15 and hash size 8, clears the +0x1C bits through the byte store plus
// 0xFFFFFCFF mask used by the rowed sibling Rva006FC1D0, zeroes +0x24, then
// asserts the argument's isSpriteInstBase() predicate (0x6CFCD0 pinned) at
// AptCIH.h:0x7D and copies the +0x4C -> +0x0C -> +0x04 chain into +0x20.
// Callees 0x6DCCC0, 0x70A740 and 0x6CFCD0 are rowed or pinned; the own vtable
// 0x008ECF18 is stored after the inlined base vtable 0x008EA228.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

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

class BfmeAptValue006DCD20
{
    virtual void vtableSlot0();
    unsigned int m_flags;
    void setTypeAt006DBBC0(int type);
public:
    BfmeAptValue006DCD20(int type);
    virtual ~BfmeAptValue006DCD20();
};

class Rva006D6360 : public BfmeAptValue006DCD20
{
    AptNativeHash m_hash;
public:
    Rva006D6360(int type, int size) : BfmeAptValue006DCD20(type), m_hash(size)
    {
    }
    virtual ~Rva006D6360();
};

struct Rva006F38B0Inner2
{
    char m_pad[4];
    void *m_04;
};

struct Rva006F38B0Inner
{
    char m_pad[0xC];
    Rva006F38B0Inner2 *m_0C;
};

class AptCIH
{
public:
    bool rva006CFCD0() const;
    char m_pad4C[0x4C];
    Rva006F38B0Inner *m_4C;
};

class Rva006F38B0 : public Rva006D6360
{
    unsigned int m_1C;
    void *m_20;
    int m_24;
    int m_28;
public:
    Rva006F38B0(AptCIH *arg);
    virtual ~Rva006F38B0();
};

Rva006F38B0::Rva006F38B0(AptCIH *arg) : Rva006D6360(0x15, 8)
{
    m_24 = 0;
    *(unsigned char *)&m_1C = 0;
    m_1C &= 0xFFFFFCFF;
    if (!arg->rva006CFCD0()) {
        g_bfmeAptAssertAtE17734("isSpriteInstBase()",
            "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0x7D);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    m_20 = arg->m_4C->m_0C->m_04;
    m_28 = 0;
}
