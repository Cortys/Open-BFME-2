// ?Rva006DC7C0Shutdown@@YAXH@Z
// partial score=0.99 date=2026-10-01
// ?Rva006DC7C0Shutdown@@YAXH@Z
// partial score=0.99 date=2026-10-01
// cl: /O2 /MD
// ?Rva006DC7C0Shutdown@@YAXH@Z @0x006DC7C0 501B evidence chain via 0x006DB270 freeBlock plus DestroyGCPointers row plus caller 0x006CFAB0 forwarding int plus virtual release pairs at +0x2c and +0x4
class AptNativeHash {
public:
    void DestroyGCPointers();
};
class Rva0070A840 {
public:
    ~Rva0070A840();
};
class Rva006DB270 {
public:
    void freeBlock(void *pNowFree, int nSize);
};
extern Rva006DB270 *g_pChainBlockAllocator;
struct AptShutdownRef {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
};
extern AptNativeHash *g_00E180E4;
extern AptShutdownRef *g_00E18360;
extern AptShutdownRef *g_00E18650;
extern AptShutdownRef *g_00E18070;
extern AptShutdownRef *g_00E180B8;
extern AptShutdownRef *g_00E18068;
extern AptShutdownRef *g_00E180BC;
extern AptShutdownRef *g_00E180AC;
extern void *g_00E180C0;
extern AptShutdownRef *g_00E180A8;
extern AptShutdownRef *g_00E18080;
extern AptShutdownRef *g_00E18084;
extern AptShutdownRef *g_00E180B4;
extern AptShutdownRef *g_00E18074;
extern AptShutdownRef *g_00E1806C;
extern AptShutdownRef *g_00E180E8;
extern int g_00E18064;
// ?Rva006DC7C0Shutdown@@YAXH@Z present-unmatched
void __cdecl Rva006DC7C0Shutdown(int)
{
    if (g_00E180E4 != 0) {
        g_00E180E4->DestroyGCPointers();
        if (g_00E180E4 != 0) {
            Rva0070A840 *tmp = (Rva0070A840 *)g_00E180E4;
            tmp->~Rva0070A840();
            g_pChainBlockAllocator->freeBlock(tmp, 0x14);
        }
        g_00E180E4 = 0;
    }
    g_00E18360->v2C();
    g_00E18360->v04();
    g_00E18360 = 0;
    g_00E18650->v2C();
    g_00E18650->v04();
    g_00E18650 = 0;
    g_00E18070->v2C();
    g_00E18070->v04();
    g_00E18070 = 0;
    g_00E180B8->v2C();
    g_00E180B8->v04();
    g_00E180B8 = 0;
    g_00E18068->v2C();
    g_00E18068->v04();
    g_00E18068 = 0;
    g_00E180BC->v2C();
    g_00E180BC->v04();
    g_00E180BC = 0;
    g_00E180AC->v2C();
    g_00E180AC->v04();
    g_00E180AC = 0;
    g_pChainBlockAllocator->freeBlock(g_00E180C0, 0x3c0);
    g_00E180A8->v2C();
    g_00E180A8->v04();
    g_00E180A8 = 0;
    g_00E18080->v2C();
    g_00E18080->v04();
    g_00E18080 = 0;
    g_00E18084->v2C();
    g_00E18084->v04();
    g_00E18084 = 0;
    g_00E180B4->v2C();
    g_00E180B4->v04();
    g_00E180B4 = 0;
    g_00E18074->v2C();
    g_00E18074->v04();
    g_00E18074 = 0;
    g_00E1806C->v2C();
    g_00E1806C->v04();
    g_00E1806C = 0;
    g_00E180E8->v2C();
    g_00E180E8->v04();
    g_00E180E8 = 0;
    ((AptShutdownRef *)*(void **)&g_00E18064)->v2C();
    ((AptShutdownRef *)*(void **)&g_00E18064)->v04();
    g_00E18064 = 0;
}
