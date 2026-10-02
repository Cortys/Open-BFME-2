// ?Rva003E7D83Get@@YG_NPAX@Z
// partial score=0.88 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /O1 /QIfist
// ?Rva003E7D83Get@@YG_NPAX@Z retail 0x003E7D83 209 bytes.
// Evidence: chain lane calls rowed rva002086C5 0x002086C5 via g_Va009FE16C plus StringBase copy 0x365F0; caller 0x003EBDED; op switch 0..5 comparing lookup int vs ceil msec; float scale g_parseDurationMsecScale and g_00BBE358 with IAT ceil.
#include "ascii_string.h"

class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    int getInt() const { return m_int; }
    float getReal() const { return m_real; }
    unsigned char m_beforeInt[8]; int m_int; float m_real; AsciiString m_string;
    unsigned char m_afterString[8];
};

class ScriptEngine
{
public:
    void *rva002086C5(AsciiString name);
};
extern ScriptEngine *g_Va009FE16C;
extern float g_parseDurationMsecScale;
extern float g_00BBE358;
extern "C" __declspec(dllimport) double __cdecl ceil(double);

struct Rva003E7D83Args
{
    unsigned char m_pad[8];
    int m_count;
    Parameter *m_p0;
    Parameter *m_p1;
    Parameter *m_p2;
};

// ?Rva003E7D83Get@@YG_NPAX@Z present-unmatched
bool __stdcall Rva003E7D83Get(void *block)
{
    Rva003E7D83Args *args = (Rva003E7D83Args *)block;
    int left = 0;
    Parameter *p0 = args->m_count > 0 ? args->m_p0 : 0;
    void *res0 = g_Va009FE16C->rva002086C5(p0->getString());
    if (res0)
        left = *(int *)res0;
    Parameter *p2 = args->m_count > 2 ? args->m_p2 : 0;
    float scaled;
    scaled = (float)ceil(g_parseDurationMsecScale * p2->m_real * g_00BBE358);
    int right;
    right = (int)scaled;
    Parameter *p1 = args->m_count > 1 ? args->m_p1 : 0;
    int op = p1->getInt();
    switch (op)
    {
    case 0:
        return left < right;
    case 1:
        return left <= right;
    case 2:
        return left == right;
    case 3:
        return left >= right;
    case 4:
        return left > right;
    case 5:
        return left != right;
    default:
        return false;
    }
}
