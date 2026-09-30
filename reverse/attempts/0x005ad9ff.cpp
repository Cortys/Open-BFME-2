// ??0Rva005AD9FF@@QAE@IPAX@Z
// partial score=0.93 date=2026-09-30
// ??0Rva005AD9FF@@QAE@IPAX@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /EHsc /MD /arch:SSE2 /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva005AD9FF@@QAE@IPAX@Z @0x005AD9FF 65B
// Ctor of a 0x2c-byte object with vector<BfmeE16> at +0 via rowed _Vector_base
// 0x00211E58 (empty allocator temp at [ebp+0xb]), dword at +0xc from first arg,
// zero at +0x10, ptr at +0x14 from second arg, four floats at +0x18..0x24 zeroed,
// zero at +0x28. Callers 0x0050738F and 0x005074B9 news 0x2c and pass
// (count/arg, caller+8). BfmeE16 is the 16B size stand-in from
// stlport_vector_e16_o1. Near miss: same 65B/22insns, only store scheduling
// differs (both `and [m],0` hoisted early; retail splits them around xorps and
// the last movss). Tried /arch:SSE, /Os, /G7, body-order split: identical.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class Rva005AD9FF
{
public:
	Rva005AD9FF(unsigned int a, void *b);
private:
	_STL::vector<BfmeE16> m_vec; // +0
	unsigned int m_0c; // +0xc
	unsigned int m_10; // +0x10
	void *m_14; // +0x14
	float m_18; // +0x18
	float m_1c; // +0x1c
	float m_20; // +0x20
	float m_24; // +0x24
	unsigned int m_28; // +0x28
};

// ??0Rva005AD9FF@@QAE@IPAX@Z present-unmatched
Rva005AD9FF::Rva005AD9FF(unsigned int a, void *b)
	: m_vec(_STL::allocator<BfmeE16>()), m_0c(a), m_10(0), m_14(b),
	  m_18(0.0f), m_1c(0.0f), m_20(0.0f), m_24(0.0f), m_28(0)
{
}
