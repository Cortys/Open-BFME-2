// ??1Rva0018BEC7@@UAE@XZ
// partial score=0.93 date=2026-10-02
// cl: /O1 /EHsc /MD
// ??0Rva0018BEC7@@QAE@XZ, retail 0x0018BEC7, 66 bytes.
// ??1Rva0018BEC7@@UAE@XZ, retail 0x0018BE87, 64 bytes.
// Ctor registers "WW3D", dtor erases "WW3D"; vtable at +0 plus member at +4,
// both reset to base vtable in dtor. Evidence: ctor stores 0x007D5BE4/0x007D5BD4
// then Register; dtor stores 0x007D5BE4 then Erase then both to 0x007C6F24;
// callers 0x0017414B/0x0018BF0C; inline virtuals give EH without calls.
void __cdecl Rva00153565Register(const char *name, void *obj);
void __cdecl Rva001532E1Erase(const char *name);

class Rva0018BEC7_Base {
public:
    virtual ~Rva0018BEC7_Base() {}
};

class Rva0018BEC7_Member : public Rva0018BEC7_Base {
public:
    ~Rva0018BEC7_Member() {}
};

class Rva0018BEC7 : public Rva0018BEC7_Base {
public:
    virtual ~Rva0018BEC7();
    Rva0018BEC7();
    Rva0018BEC7_Member m_member;
};

Rva0018BEC7::Rva0018BEC7()
{
    Rva00153565Register("WW3D", this);
}

Rva0018BEC7::~Rva0018BEC7()
{
    Rva001532E1Erase("WW3D");
}
