// cl: /O1 /MD
//
// ??1Rva0020453CHolderBase@@QAE@XZ @0x00204C16 11B: non-virtual dtor storing
// vtable 0x00BE39F4 then tail-jumping to release 0x0020453C (pin).
// Evidence: deleting-dtor caller 0x00204D6B (push esi call ??1 test [esp+8],1
// call operator delete ret 4) calls this body; pin for release describes the
// inline dtor storing vtable 0xBE39F4 right before the release call; class
// layout follows ScriptEngine_dtor.cpp HolderBase.

class __declspec(novtable) Rva0020453CHolderBase
{
public:
    ~Rva0020453CHolderBase();
    virtual void holderSlot0();
    void release();
private:
    void *m_handle;
    bool m_active;
};

extern const void *const g_00BE39F4[];

Rva0020453CHolderBase::~Rva0020453CHolderBase()
{
    *(const void **)this = g_00BE39F4;
    release();
}
