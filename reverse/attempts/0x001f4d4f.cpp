// ?rva001F4D4F@Rva001F4D4F@@QAEMXZ
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD /arch:SSE
// ?rva001F4D4F@Rva001F4D4F@@QAEMXZ @0x001F4D4F 39B.
// Float getter reads holder at +0x9c via sixth virtual slot plus 0x14 with 1.0f else.
// Same holder offset as sibling Rva001F4DC4; default 1.0f is float literal for g_Va00BBB8D8.
// Caller at 0x00562E88 proves thiscall float void. Honest Rva name.
struct Rva001F4D4FHelper {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual float f5();
};
class Rva001F4D4F {
public:
    char m_pad[0x9c];
    Rva001F4D4FHelper *m_ptr;
    float rva001F4D4F();
};
// ?rva001F4D4F@Rva001F4D4F@@QAEMXZ present-unmatched
float Rva001F4D4F::rva001F4D4F()
{
    Rva001F4D4FHelper *p = m_ptr;
    float v = 1.0f;
    if (p != 0)
        v = p->f5();
    return v;
}
