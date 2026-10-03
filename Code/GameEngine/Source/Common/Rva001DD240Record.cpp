// cl: /O1 /G7 /arch:SSE /MD
// ?rva001DD240@Rva001DD240@@QAEXPAI@Z @0x001DD240 54B unlock lane max-of-two-uints to float with constant store.
// Evidence: callers at 0x001DD533 and 0x001DD7CB context; data refs g_00BBB9AC g_00BC26EC; honest address name.
extern const float g_00BBB9AC;
class Rva001DD240 {
public:
    float m_0;
    float m_4;
    void rva001DD240(unsigned int *p);
};
void Rva001DD240::rva001DD240(unsigned int *p)
{
    m_4 = g_00BBB9AC;
    unsigned int *sel = p;
    if (*sel < sel[2])
        sel = &sel[2];
    unsigned int v = *sel;
    m_0 = (float)v;
}
