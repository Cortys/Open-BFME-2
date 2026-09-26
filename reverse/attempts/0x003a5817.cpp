// ??1Rva003AEEB3@@UAE@XZ
// partial score=0.92 date=2026-09-26
// ??1Rva003AEEB3@@UAE@XZ
// partial score=0.92 date=2026-09-26
// cl: /O1 /MD
// ??1Rva003AEEB3@@UAE@XZ, retail 0x003A5817, 39 bytes.
// Derived dtor for Rva003AEEB3 (DefaultModuleBase family): two null-guarded
// vptr stores at +0x18/+0x14 (both 0x00C1C780) then tail-jmp to the rowed head
// base dtor at 0x003A57E7. novtable suppresses the derived +0 store so only
// the manual stores remain; plain bases give unconditional movs, ternary with
// volatile gives the retail neg/sbb/and shape. Current 38B probe keeps the
// value in eax for reuse across both stores and spills the second lea to esi
// (push/pop), where retail stores the imm directly twice with eax/edx only.
// Needs register/scheduling idiom to force imm-direct stores and avoid esi.
struct RvaSmartPtr12
{
    void *m_ptr;
    int m_pad04;
    int m_pad08;
};
class DefaultModuleHeadBase
{
public:
    virtual ~DefaultModuleHeadBase();
private:
    RvaSmartPtr12 m_smart;
    int m_int10;
};
class __declspec(novtable) Rva003AEEB3 : public DefaultModuleHeadBase
{
public:
    virtual ~Rva003AEEB3();
};
// ??1Rva003AEEB3@@UAE@XZ present-unmatched
Rva003AEEB3::~Rva003AEEB3()
{
    unsigned char *b18 = this ? (unsigned char *)this + 0x18 : 0;
    *(volatile unsigned int *)b18 = 0x00C1C780;
    unsigned char *b14 = this ? (unsigned char *)this + 0x14 : 0;
    *(volatile unsigned int *)b14 = 0x00C1C780;
}
