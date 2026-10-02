// cl: /O1 /G7 /arch:SSE
// ?rva005688D2@Rva005688D2@@QAEXPAMH@Z @0x005688D2 78B: two-float out at [esp+4] gated by mode at [esp+8]; base float at [ecx+0x3C]+0x10 scaled by g_00BC6C50; callers 0x005689C3 0x00569B03; same +0x2C/+0x3C layout as Rva00568920/Rva005686C1
extern float g_00BC6C50;

struct Rva005688D2Base
{
    char m_pad[0x10];
    float m_scale;
};

class Rva005688D2
{
public:
    void rva005688D2(float *out, int mode);
private:
    char m_pad[0x3C];
    Rva005688D2Base *m_base;
};

void Rva005688D2::rva005688D2(float *out, int mode)
{
    float first;
    float second;
    if (mode == 0 || mode == 2)
        first = 0.0f;
    else
        first = m_base->m_scale * g_00BC6C50;
    if (mode == 0 || mode == 1)
        second = 0.0f;
    else
        second = m_base->m_scale * g_00BC6C50;
    out[0] = first;
    out[1] = second;
}
