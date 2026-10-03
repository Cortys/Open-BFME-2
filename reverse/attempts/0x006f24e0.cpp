// ??0Rva006F24E0@@QAE@PAVBfmeAptValue006DCD20@@@Z
// partial score=0.93 date=2026-10-03
// cl: /O2 /DNDEBUG /MD /EHsc
// ??0Rva006F24E0@@QAE@PAVBfmeAptValue006DCD20@@@Z @0x006F24E0 229B. Apt-derived ctor (type 0x1A, hash 8) with pMovie retain.
// Evidence: stores base vtable 0x008EA228 via inlined Rva006D6360 then own vtable 0x008ECE50; calls rowed
// ??0BfmeAptValue006DCD20@@QAE@H@Z (0x006DCCC0) and ??0AptNativeHash@@QAE@H@Z (0x0070A740); clears bits at +0x1C
// with 0xFFFFFCFF; asserts "pMovie != NULL" at AptObject/AptScriptColour.cpp:0x30 then isCIH/rva006DCF60/
// isSpriteInstBase/rva006E02B0 retain into +0x20 with vtable slot-0 call; chain from just-landed 0x006CFCD0.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class BfmeAptValue006DCD20
{
    unsigned int m_flags;
    void setTypeAt006DBBC0(int type);
public:
    virtual void vtableSlot0();
    BfmeAptValue006DCD20(int type);
    virtual ~BfmeAptValue006DCD20();
    int isCIH(bool) const;
    BfmeAptValue006DCD20 *rva006DCF60(bool);
    int rva006E02B0() const;
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
    Rva006D6360(int type, int size) : BfmeAptValue006DCD20(type), m_hash(size)
    {
    }
    virtual ~Rva006D6360();
};
class Rva006CFCD0
{
    virtual void vtableSlot0();
    unsigned int m_flags;
public:
    bool isSpriteInstBase() const;
};
class Rva006F24E0 : public Rva006D6360
{
    unsigned int m_bits;
    BfmeAptValue006DCD20 *m_held;
public:
    Rva006F24E0(BfmeAptValue006DCD20 *pMovie);
};
Rva006F24E0::Rva006F24E0(BfmeAptValue006DCD20 *pMovie) : Rva006D6360(0x1A, 8)
{
    *(unsigned char *)&m_bits = 0;
    m_bits &= 0xFFFFFCFF;
    if (!pMovie) {
        g_bfmeAptAssertAtE17734("pMovie != NULL", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptObject\\AptScriptColour.cpp", 0x30);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (static_cast<unsigned char>(pMovie->isCIH(false))) {
        pMovie = pMovie->rva006DCF60(false);
        if (reinterpret_cast<Rva006CFCD0 *>(pMovie)->isSpriteInstBase() || static_cast<unsigned char>(pMovie->rva006E02B0())) {
            m_held = pMovie;
            pMovie->vtableSlot0();
        }
    } else {
        m_held = 0;
    }
}
