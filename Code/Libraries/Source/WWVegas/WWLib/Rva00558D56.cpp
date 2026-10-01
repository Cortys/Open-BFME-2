// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva00558D56@@QAE@XZ @0x00558D56 21B: Default ctor wraps DequeBase E16 with temp allocator plus 0 then returns this. Evidence: unlock lane calls rowed DequeBase 0x0055334A plus caller 0x00558F07 plus push0 lea-b shape.
#include <deque>
struct BfmeE16 { float x, y, z, w; };
class Rva00558D56
{
	_STL::_Deque_base<BfmeE16, _STL::allocator<BfmeE16> > m_base;
public:
	Rva00558D56();
};
Rva00558D56::Rva00558D56() : m_base(_STL::allocator<BfmeE16>(), 0)
{
}
