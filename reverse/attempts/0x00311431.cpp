// ?rva00311431@Rva00311431@@QAEPAV1@PBURva00311431Arg@@@Z
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /arch:SSE /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
// ?rva00311431@Rva00311431@@QAEPAV1@PBURva00311431Arg@@@Z @ 0x00311431 98B.
// Copies arg string at +8 via rowed set, 12B at +0xC to +0xA4, int at +4 to +0xB4,
// zeroes 41 floats +0..+0xA0 as 1+10+30 via 10-iter loop, returns this.
// Callees rowed set 0x000366F0. Callers 0x00312F1E 0x00312FAA 0x00312FD0.
#include "ascii_string.h"
struct Rva00311431Vec
{
    float x;
    float y;
    float z;
};
struct Rva00311431Arg
{
    char m_pad0[4];
    int m_04;
    AsciiString m_08;
    Rva00311431Vec m_0C;
};
class Rva00311431
{
public:
    Rva00311431 *rva00311431(const Rva00311431Arg *a);
    float m_00;
    float m_04[10];
    Rva00311431Vec m_2C[10];
    Rva00311431Vec m_A4;
    AsciiString m_B0;
    int m_B4;
};

// ?rva00311431@Rva00311431@@QAEPAV1@PBURva00311431Arg@@@Z present-unmatched
Rva00311431 *Rva00311431::rva00311431(const Rva00311431Arg *a)
{
    ((StringBase<char> &)m_B0).set((const StringBase<char> &)a->m_08);
    m_A4 = a->m_0C;
    m_B4 = a->m_04;
    m_00 = 0.0f;
    for (int i = 0; i < 10; ++i)
    {
        m_04[i] = 0.0f;
        float *pz = &m_2C[i].z;
        pz[-2] = 0.0f;
        pz[-1] = 0.0f;
        pz[0] = 0.0f;
    }
    return this;
}
