// ?Rva003E7CBAGet@@YG_NPAX@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /arch:SSE2 /O1
// ?Rva003E7CBAGet@@YG_NPAX@Z retail 0x003E7CBA 201 bytes.
// Evidence: chain lane calls rowed rva002086C5 0x002086C5 twice via g_Va009FE16C plus StringBase copy 0x365F0; neighbours same cl; caller 0x003EBDE2; op switch 0..5 to setl/setle/sete/setge/setg/setne comparing two deref ints.
#include "ascii_string.h"

class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    int getInt() const { return m_int; }
    unsigned char m_beforeInt[8]; int m_int; float m_real; AsciiString m_string;
    unsigned char m_afterString[8];
};

class ScriptEngine
{
public:
    void *rva002086C5(AsciiString name);
};
extern ScriptEngine *g_Va009FE16C;

struct Rva003E7CBAArgs
{
    unsigned char m_pad[8];
    int m_count;
    Parameter *m_p0;
    Parameter *m_p1;
    Parameter *m_p2;
};

// ?Rva003E7CBAGet@@YG_NPAX@Z present-unmatched
bool __stdcall Rva003E7CBAGet(void *block)
{
    Rva003E7CBAArgs *args = (Rva003E7CBAArgs *)block;
    int left = 0;
    int right = 0;
    Parameter *p0;
    if (args->m_count > 0)
        p0 = args->m_p0;
    else
        p0 = 0;
    void *res0 = g_Va009FE16C->rva002086C5(p0->getString());
    if (res0)
        left = *(int *)res0;
    Parameter *p2 = args->m_count > 2 ? args->m_p2 : 0;
    void *res1 = g_Va009FE16C->rva002086C5(p2->getString());
    if (res1)
        right = *(int *)res1;
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
