// ??0Rva0035DCF9@@QAE@XZ
// partial score=0.9 date=2026-09-30
// ??0Rva0035DCF9@@QAE@XZ
// partial score=0.9 date=2026-09-30
// cl: /O1 /MD
// ??0Rva0035DCF9@@QAE@XZ @0x0035DE55 80B
// Ctor of Rva0035DCF9: base ??0Rva001DBAA4 at 0x001DBAA4, vtable 0x00C16574
// (RVA 0x00816574 same as dtor 0x0035DCF9 and vslots 0x0035DD08/0x0035DD9C
// in FamilyTailDtors1DBAC3.cpp). Sets m_10=0 m_14=3 then vtable then
// m_18..m_24=0 m_28=-1 m_2C..m_44=0, overwrites base m_C=0 m_4=m_14 m_9=1.
// Caller 0x0035DEE3 in 0x0035DEC1. Layout from FamilyTailDtors1DBAC3.cpp
// plus Rva001DBAA4Ctor.cpp. Uses novtable plus explicit store to get the
// init-before-vtable order like Rva00342FCDCtor.cpp.
class Rva001DBAA4
{
public:
    virtual ~Rva001DBAA4();
    Rva001DBAA4();
    int m_4;
    bool m_8;
    bool m_9;
    bool m_A;
    int m_C;
};

extern const void *const g_00C16574[];

class __declspec(novtable) Rva0035DCF9 : public Rva001DBAA4
{
public:
    virtual ~Rva0035DCF9();
    Rva0035DCF9();
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    void *m_44;
};

// ??0Rva0035DCF9@@QAE@XZ present-unmatched
Rva0035DCF9::Rva0035DCF9()
{
    m_10 = 0;
    m_14 = 3;
    *(const void **)this = g_00C16574;
    m_18 = 0;
    m_1C = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = -1;
    m_2C = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3C = 0;
    m_40 = 0;
    m_44 = 0;
    m_C = 0;
    m_4 = *(volatile int *)&m_14;
    m_9 = true;
}
