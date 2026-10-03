// ??0Rva005AD9FF@@QAE@IPAX@Z
// partial score=0.97 date=2026-10-04
// ??0Rva005AD9FF@@QAE@IPAX@Z
// partial score=0.97 date=2026-10-03
// ??0Rva005AD9FF@@QAE@IPAX@Z
// partial score=0.97 date=2026-10-03
// cl: /O1 /EHsc /MD /arch:SSE2 /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva005AD9FF@@QAE@IPAX@Z @0x005AD9FF 65B
// Ctor of a 0x2c-byte object with vector<BfmeE16> at +0 via rowed _Vector_base
// 0x00211E58 (empty allocator temp at [ebp+0xb]), dword at +0xc from first arg,
// zero at +0x10, ptr at +0x14 from second arg, four floats at +0x18..0x24 zeroed,
// zero at +0x28. Callers 0x0050738F and 0x005074B9 news 0x2c and pass
// (count/arg, caller+8). BfmeE16 is the 16B size stand-in from
// stlport_vector_e16_o1.
// Improvement this pass: assigning m_0c BEFORE m_10 = 0 makes the compiler
// schedule the arg-a load (mov eax,[ebp+8]) first and the `and [esi+10],0`
// second, matching retail's opening. Prior bank had them swapped (55 vs 54
// equal bytes). Sole remaining gap: retail materialises the xmm0 zero with
// `xorps` BETWEEN `and [esi+0x10],0` and `mov [esi+0xc],eax`; cl emits the
// xorps after the store. Refuted here: /O1 /Ob2 /Os /Ot /O2 (58B), moving any
// float zero earlier (38-52 equal), init-list for m_0c/m_10/m_18 (47-54),
// shared float local (54), reordering the trailing movss group (38). The
// xorps is the xmm0 def and cl places it just before its first movss use; the
// target places it before an unrelated integer store.
#include <vector>

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

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
	: m_vec(_STL::allocator<BfmeE16>())
{
	unsigned int ta = a;
	_ReadWriteBarrier();
	m_0c = ta;
	m_10 = 0;
	_ReadWriteBarrier();
	m_14 = b;
	m_18 = 0.0f;
	m_1c = 0.0f;
	m_20 = 0.0f;
	_ReadWriteBarrier();
	m_28 = 0;
	_ReadWriteBarrier();
	m_24 = 0.0f;
}