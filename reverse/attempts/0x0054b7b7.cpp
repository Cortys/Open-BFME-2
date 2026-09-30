// ??0Rva0054B7B7@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??0Rva0054B7B7@@QAE@XZ
// partial score=0.95 date=2026-09-30
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva0054B7B7@@QAE@XZ @0x0054B7B7 (69B):
// Default ctor with vtable 0x0086A698 plus four zeroed dwords at +4..+0x10
// and deque<BfmePod8> at +0x14 via rowed Deque_base Pod8 ctor 0x0054A1B7.
// Callers include 0x005494DE and seven big bodies.
// Evidence: chain lane, callee just landed, all callees rowed.
#include <deque>
struct BfmePod8 { int a[2]; };
struct Rva0054B7B7EmptyBase
{
	Rva0054B7B7EmptyBase() {}
	~Rva0054B7B7EmptyBase();
};
// ?keep@Rva0054B7B7@@UAEXXZ present-unmatched
class Rva0054B7B7 : public Rva0054B7B7EmptyBase
{
public:
	Rva0054B7B7();
	virtual void keep();
private:
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	_STL::deque<BfmePod8, _STL::allocator<BfmePod8> > m_14;
};
Rva0054B7B7::Rva0054B7B7()
	: m_04(0)
	, m_08(0)
	, m_0c(0)
	, m_10(0)
	, m_14()
{
}
void Rva0054B7B7::keep() {}
