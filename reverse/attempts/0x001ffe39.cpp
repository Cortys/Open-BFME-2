// ??0Rva001FFE39@@QAE@XZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva001FFE39@@QAE@XZ @0x001FFE39 62B: ctor with base providing +0x04/08/0C/10 defaults and derived vtable plus BfmeE16 vector at +0x1C via rowed 0x00211E58. Evidence: vtable store callers 0x001FFF9F 0x001FFFF6 0x0020004E in 0x001FFF3A.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

struct Rva001FFE39Base
{
	Rva001FFE39Base() { m_0C = -1; m_10 = -1; m_04 = 0; m_08 = 0; }
	int m_04;
	unsigned char m_08;
	int m_0C;
	int m_10;
};

class Rva001FFE39 : public Rva001FFE39Base
{
public:
	Rva001FFE39();
	virtual void Unknown();
	int m_14;
	int m_18;
	_STL::vector<BfmeE16> m_1C;
	int m_28;
	int m_2C;
	unsigned char m_30;
};

// ??0Rva001FFE39@@QAE@XZ present-unmatched
Rva001FFE39::Rva001FFE39() : m_14(0), m_18(0), m_28(0), m_2C(0), m_30(1)
{
}
