// ??0Rva005CCC07@@QAE@XZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /MD /EHsc /arch:SSE /G7
// ??0Rva005CCC07@@QAE@XZ, retail 0x005CCBD0, 55 bytes.
// Base ctor stores vtable 0x00874F04 then zeros and sets members to +0x23; derived ctor 0x005CCC50 overwrites vtable.
// Evidence: vtable store plus member pattern; dtor 0x005CCC07; caller 0x005CCC50 stores +0x24 and vtable 0x00874F24.
class Rva005CCC07 {
public:
    virtual ~Rva005CCC07();
    Rva005CCC07();
private:
    void *m_04;
    void *m_08;
    int m_0C;
    int m_10;
    float m_14;
    float m_18;
    float m_1C;
    unsigned char m_20;
    unsigned char m_21;
    unsigned char m_22;
    unsigned char m_23;
};
// ??0Rva005CCC07@@QAE@XZ present-unmatched
Rva005CCC07::Rva005CCC07()
{
    m_04 = 0;
    m_08 = 0;
    m_10 = -1;
    m_0C = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1C = 0.0f;
    m_20 = 0;
    m_21 = 0;
    m_22 = 1;
    m_23 = 0;
}
