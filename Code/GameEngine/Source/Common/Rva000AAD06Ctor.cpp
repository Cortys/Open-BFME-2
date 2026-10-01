// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva000AAD06@@QAE@XZ @0x000AAD06 32B frameless ctor over vector at +0x08
// Evidence: push ecx push esi mov esi ecx and [esi+4] 0 lea eax esp+7 push allocator call rowed Vector_base BfmeE16 0x00211E58; vtable 0x00BC9454 at +0 gate DIR32; caller 0x000AAD5C derived ctor calls this then stores 0x00BC9468; BfmeE16 16B stand-in from stlport_vector_e16_o1; owner unproven honest Rva name
#include <vector>
struct BfmeE16 { float x, y, z, w; };
class Rva000AAD06
{
public:
	Rva000AAD06();
protected:
	virtual void _0();
private:
	int m_04;
	_STL::vector<BfmeE16> m_vec08;
};

Rva000AAD06::Rva000AAD06()
	: m_04(0), m_vec08(_STL::allocator<BfmeE16>())
{
}
