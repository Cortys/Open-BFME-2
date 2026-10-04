// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// STLport 4.5.3 vector<DynamicPortalLink>::_M_insert_overflow, false_type
// growth path (12-byte Patch-owned portal Link records). Emitted by explicit
// instantiation of the real vendor template; retail 0x0046152F is exactly this
// body, the _M_insert_overflow reachable from the DynamicPortalBehaviour list.
#include <vector>

class DynamicPortalLink
{
public:
	DynamicPortalLink();
	DynamicPortalLink(const DynamicPortalLink &other);
	DynamicPortalLink &operator=(const DynamicPortalLink &other);
	~DynamicPortalLink();
	void *m_owned;
	int m_second;
	int m_third;
};

template class _STL::vector<DynamicPortalLink, _STL::allocator<DynamicPortalLink> >;
