// ??0Rva004E5A24@@QAE@XZ
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD /arch:SSE
// ??0Rva004E5A24@@QAE@XZ @0x004E5A24 84B: ctor via baseConstruct.
// Calls row baseConstruct 0x001B4E63 then zeroes +0xC then constructs
// _Vector_base BfmeE16 at +0x10 with dummy allocator then zeroes +0x1C/+0x20
// then three floats from g_00DD00A8/g_00DD00AC/g_00C623C8. Vtable 0x008623CC.
// Caller is 0x002A64C2.
#include <new>
extern float g_00DD00A8;
extern float g_00DD00AC;
extern float g_00C623C8;

struct BfmeE16
{
    float x;
    float y;
    float z;
    float w;
};

namespace _STL
{
template <class T> class allocator
{
};
template <class T, class A> class _Vector_base
{
public:
    _Vector_base(const A &a) throw();
};
}

class BFME2NativeNetwork
{
public:
    BFME2NativeNetwork *baseConstruct();
};

class Rva004E5A24
{
public:
    Rva004E5A24();
private:
    char m_pad0[0xC];
    int m_0C;
    char m_vecPad[12];
    int m_1C;
    int m_20;
    char m_pad24[4];
    float m_28;
    float m_2C;
    float m_30;
};

// ??0Rva004E5A24@@QAE@XZ present-unmatched
Rva004E5A24::Rva004E5A24()
{
    ((BFME2NativeNetwork *)this)->baseConstruct();
    m_0C = 0;
    *(void **)this = (void *)0x008623CC;
    const _STL::allocator<BfmeE16> alloc = _STL::allocator<BfmeE16>();
    new (m_vecPad) _STL::_Vector_base<BfmeE16, _STL::allocator<BfmeE16> >(alloc);
    m_1C = 0;
    m_20 = 0;
    m_28 = g_00DD00A8;
    m_2C = g_00DD00AC;
    m_30 = g_00C623C8;
}
