// ?rva001F5300@Rva001F5300@@QAEXPAM@Z
// partial score=0.95 date=2026-09-30
// ?rva001F5300@Rva001F5300@@QAEXPAM@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /MD /arch:SSE
// ?rva001F5300@Rva001F5300@@QAEXPAM@Z @ 0x001F5300 76B: thiscall writes 2 floats
// to out ptr from extern float g_Va00BBB8D8 or from virtuals slot8/9 at +0x1C4
// returning int converted via cvtsi2ss; caller 0x001F71CF in 0x001F713E.
extern float g_Va00BBB8D8;

struct Inner
{
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
};

class Rva001F5300
{
public:
    void rva001F5300(float *out);
private:
    char m_pad[0x1C4];
    Inner *m_1C4;
};

// ?rva001F5300@Rva001F5300@@QAEXPAM@Z present-unmatched
void Rva001F5300::rva001F5300(float *out)
{
    float f0 = g_Va00BBB8D8;
    float f1 = f0;
    Inner **pp = &m_1C4;
    Inner *p = *pp;
    if (p)
    {
        f1 = (float)p->s8();
        f0 = (float)(*pp)->s9();
    }
    out[0] = f1;
    out[1] = f0;
}
