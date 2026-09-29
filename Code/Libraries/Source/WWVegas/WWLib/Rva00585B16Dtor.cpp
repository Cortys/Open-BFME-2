// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ??1Rva00585B16@@QAE@XZ @0x00585B16 8B tail-jmp to rowed deque dtor;
// callers at 0x00585D24 0x00586B9B and Unwind funclets; unlock.
#include <deque>
struct BfmeE12 { float x, y, z; };
class Rva00585B16
{
public:
	~Rva00585B16();
private:
	char m_pad[0x28];
	_STL::deque<BfmeE12, _STL::allocator<BfmeE12 > > m_deque;
};
Rva00585B16::~Rva00585B16()
{
}
