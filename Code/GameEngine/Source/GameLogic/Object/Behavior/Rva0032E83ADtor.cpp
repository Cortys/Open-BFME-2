// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva0032E83A@@QAE@XZ — RVA 0x0032E83A, 8B.
// Non-virtual dtor destroying a vector<DynamicPortalLink> member at +4
// via tail-jmp to the rowed vector dtor 0x0032E7A3 (alias dup_0032E7A3).
// Evidence: retail add ecx 4 plus jmp; callee notes name true vector dtor
// at 0x004613EB; callers at 0x0032E92F 0x0032EAA1.
#include <vector>

struct DynamicPortalLink
{
	void *m_owned;
	int m_second;
	int m_third;
	~DynamicPortalLink();
};

class Rva0032E83A
{
public:
	~Rva0032E83A();
	char m_pad00[4];
	_STL::vector<DynamicPortalLink, _STL::allocator<DynamicPortalLink> > m_vec04;
};

Rva0032E83A::~Rva0032E83A()
{
}
