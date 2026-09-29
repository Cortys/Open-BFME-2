// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??0Rva00550083@@QAE@XZ @0x00550083 21B.
// Default ctor of a 40-byte single-deque wrapper; the inlined deque init calls the rowed _Deque_base.
// Evidence: callee _Deque_base at 0x0054FC5A rowed in stlport_deque_pod20_initmap.cpp; two call sites at +0x1C/+0x44 in 0x0055011A prove a 0x28-sized member type; same BfmePod20 element view as the sibling TU.
#include <deque>

struct BfmePod20 { int a[5]; };

class Rva00550083
{
public:
	Rva00550083();
private:
	_STL::deque<BfmePod20, _STL::allocator<BfmePod20> > m_deque;
};

Rva00550083::Rva00550083()
{
}
