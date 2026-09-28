// ??0BfmeB1137@@QAE@XZ
// partial score=0.93 date=2026-09-27
// ??0BfmeB1137@@QAE@XZ
// partial score=0.93 date=2026-09-27
// cl: /O2 /DNDEBUG /MD /EHsc /arch:SSE
class RefCountClass
{
public:
    RefCountClass() : m_numRefs(1) {}
    virtual ~RefCountClass();
    int m_numRefs;
};
class MaterialPassStage
{
public:
    MaterialPassStage();
    ~MaterialPassStage();
private:
    void *m_ptr;
};
class MaterialPassClass : public RefCountClass
{
public:
    MaterialPassClass();
private:
    MaterialPassStage m_stages[8];
    int m_28;
    int m_2c;
    bool m_30;
    int m_34;
};
class BfmeB1137 : public MaterialPassClass
{
public:
    BfmeB1137();
private:
    float m_38; float m_3C; float m_40;
    int m_44; int m_48;
    float m_4C; float m_50;
    unsigned char m_54;
    void *m_58; void *m_5C; void *m_60; void *m_64;
    unsigned char m_68; unsigned char m_69; unsigned char m_6A;
    char m_gap[0xE0 - 0x6B];
    float m_E0; int m_E4;
};
BfmeB1137::BfmeB1137() : m_38(0.0f), m_3C(0.0f), m_40(0.0f), m_44(0), m_48(0), m_4C(0.0f), m_50(0.0f), m_54(1), m_E0(0.0f)
{
    m_58 = 0; m_5C = 0; m_60 = 0; m_64 = 0;
    m_68 = 0; m_69 = 0; m_6A = 0;
    m_E4 = 0;
}
