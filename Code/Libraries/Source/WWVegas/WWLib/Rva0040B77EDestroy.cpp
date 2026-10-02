// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??$_Destroy@PAVRva0040B77E@@@_STL@@YAXPAVRva0040B77E@@0@Z @ 0x0040BEA1 (25B). Range destroy for 0x28-byte Rva0040B77E via rowed dtor 0x0040B77E.
// Evidence: chain lane calls rowed dtor 0x0040B77E stride 0x28; callers 0x0040BED4 0x0040BF01; same 25B shape as rowed 0x0048CE25.
#include <vector>

class Rva0040B77E
{
public:
	~Rva0040B77E();
	char m_pad[0x28];
};

template void _STL::_Destroy<Rva0040B77E *>(Rva0040B77E *, Rva0040B77E *);
