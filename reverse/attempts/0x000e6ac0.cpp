// ??0Rva000E6AC0@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??0Rva000E6AC0@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /arch:SSE /Ireference/shims/bfmealloc
// stlport
// ??0Rva000E6AC0@@QAE@XZ retail 0x000E6AC0 211B chain lane ctor with EH.
// Calls rowed vector_base 0x00211E58 x4 plus landed Rva00171024 ctor 0x00171024
// x2 plus rowed Region3D ctor 0x0047A6A9 x12 via ??_H plus rowed __EH_prolog.
// Evidence: vtable 0x007CEAB4 at +0; DXT5/DXT1 FourCCs; float from 0x009FE710.

#include <map>

class LadderPref
{
    char m_pad[16];
};

typedef _STL::map<long, LadderPref> LadderPrefMap;

class Rva00171024
{
public:
    Rva00171024(int a, int b);

private:
    int m_00;
    int m_04;
    LadderPrefMap m_map;
    LadderPrefMap::iterator m_current;
    int m_18;
    bool m_1c;
    bool m_1d;
};

#include <vector>

struct BfmeE16 { float x, y, z, w; };

class Region3D
{
public:
    Region3D();
private:
    char m_pad[0x64];
};

struct Global9FE710
{
    char m_pad[0x38];
    int m_38;
};

extern Global9FE710 *g_Va009FE710;
extern float g_Va007BB8D8;

class Rva000E6AC0
{
public:
    Rva000E6AC0();
// ??1Rva000E6AC0@@UAE@XZ present-unmatched
    virtual ~Rva000E6AC0() {}

private:
    _STL::vector<BfmeE16> m_vec0;
    _STL::vector<BfmeE16> m_vec1;
    _STL::vector<BfmeE16> m_vec2;
    _STL::vector<BfmeE16> m_vec3;
    int m_34;
    int m_38;
    int m_3c;
    Rva00171024 m_r40;
    int m_60;
    int m_64;
    Rva00171024 m_r68;
    int m_88;
    int m_8c;
    Region3D m_region90[12];
    int m_540;
    char m_pad544[0x5BC - 0x544];
    float m_5bc;
};

// ??0Rva000E6AC0@@QAE@XZ present-unmatched
Rva000E6AC0::Rva000E6AC0()
    : m_vec0(), m_vec1(), m_vec2(), m_vec3()
    , m_34(0), m_38(0), m_3c(0)
    , m_r40(0x800, 0x35545844)
    , m_r68(0x400, 0x31545844)
{
    float f = (g_Va009FE710 != 0) ? (float)g_Va009FE710->m_38 : g_Va007BB8D8;
    m_540 = -1;
    m_5bc = f;
}
