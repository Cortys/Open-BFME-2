// ??0Rva0035DA01@@QAE@XZ
// partial score=0.9 date=2026-09-30
// ??0Rva0035DA01@@QAE@XZ
// partial score=0.90 date=2026-09-30
// cl: /O1 /MD
// ??0Rva0035DA01@@QAE@XZ @0x0035DB3F 71B
// Ctor for Rva0035DA01 (sibling of rowed dtor 0x35DA01 and deleting dtor
// 0x35DB86 in FamilyTailDtors1DBAC3.cpp). Evidence: vtable 0x00816554 at
// [this] via gate; rowed base ctor 0x1DBAA4 first; member inits +0x10..+0x3c
// with -1 at +0x20 via OR under /O1; base overwrites +0xC=0 +0x4=6 +0x9=1.
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

class Rva0035DA01 : public Rva001DBAA4
{
public:
    Rva0035DA01();
private:
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};

// ??0Rva0035DA01@@QAE@XZ present-unmatched
Rva0035DA01::Rva0035DA01() : m_10(0), m_14(0), m_18(0), m_1c(0), m_20(-1), m_24(0), m_28(0), m_2c(0), m_30(0), m_34(0), m_38(0), m_3c(0)
{
    m_C = 0;
    m_4 = 6;
    m_9 = true;
}
