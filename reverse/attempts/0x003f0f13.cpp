// ?rva003F0F13@Rva003F0F13@@QAEXPAURva003F0F13Elem@@@Z
// partial score=0.93 date=2026-09-29
// ?rva003F0F13@Rva003F0F13@@QAEXPAURva003F0F13Elem@@@Z
// partial score=0.93 date=2026-09-29
// cl: /Os /MD /arch:SSE
// stlport
// ?rva003F0F13@Rva003F0F13@@QAEXPAURva003F0F13Elem@@@Z, retail 0x003F0F13, 53 bytes.
#include <vector>
struct Rva003F0F13Elem {
    float a;
    float b;
};
class Rva003F0F13 {
public:
    void rva003F0F13(Rva003F0F13Elem *out);
private:
    char m_pad[0xF0];
    _STL::vector<Rva003F0F13Elem> m_vec;
};
// ?rva003F0F13@Rva003F0F13@@QAEXPAURva003F0F13Elem@@@Z present-unmatched
void Rva003F0F13::rva003F0F13(Rva003F0F13Elem *out)
{
    if (m_vec.size() != 0) {
        *out = m_vec[0];
    } else {
        out->a = 0.0f;
        out->b = 0.0f;
    }
}
