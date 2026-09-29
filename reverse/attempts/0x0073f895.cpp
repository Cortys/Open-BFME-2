// ?rva0073F895@Rva0073F895@@QAEHXZ
// partial score=0.95 date=2026-09-29
// ?rva0073F895@Rva0073F895@@QAEHXZ
// partial score=0.95 date=2026-09-29
// cl: /O1 /MD /arch:SSE2
// ?rva0073F895@Rva0073F895@@QAEHXZ @0x0073F895 213B.
// Fade state machine blending base color by factor via RGBColor.
// Evidence: unlock lane packet; SSE ops; RGBColor rows; switch 0-3.
// ?rva0073F895@Rva0073F895@@QAEHXZ present-unmatched
struct RGBColor {
    float red;
    float green;
    float blue;
    int getAsInt() const;
    void setFromInt(int color);
};
class Rva0073F895 {
    char _pad[0x38];
    int m_base;
    char _pad3C[4];
    int m_state;
    float m_fade;
public:
    int rva0073F895();
};
int Rva0073F895::rva0073F895()
{
    switch (m_state) {
    case 0: {
        m_fade += 0.05f;
        if (m_fade < 1.0f)
            break;
        m_state = 1;
        break;
    }
    case 1:
        m_fade = 1.0f;
        break;
    case 2: {
        m_fade -= 0.05f;
        if (m_fade > 0.0f)
            break;
        m_fade = 0.0f;
        m_state = 3;
        break;
    }
    case 3:
        m_fade = 0.0f;
        break;
    default:
        break;
    }
    if (m_fade >= 1.0f)
        return m_base;
    if (m_fade <= 0.0f)
        return 0;
    RGBColor c;
    c.setFromInt(m_base);
    c.red *= m_fade;
    c.green *= m_fade;
    c.blue *= m_fade;
    return c.getAsInt() | 0xff000000;
}
