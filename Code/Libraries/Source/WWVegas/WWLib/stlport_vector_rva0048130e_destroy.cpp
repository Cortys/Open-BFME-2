// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??$_Destroy@PAURva0048130E@@@_STL@@YAXPAURva0048130E@@0@Z, retail 0x00481595, 25 bytes.
// Range destroy for ProductionQueueHordeContainModuleData's +0xD4 vector
// element (8-byte filter-plus-string Rva0048130E whose dtor is rowed at
// 0x0048130E): strides 8 calling that dtor. Same 25B loop shape as rowed
// BfmeVectorRecord000BDF17 _Destroy at 0x000C37CD. Emitted via explicit
// _Destroy instantiation over an opaque 8-byte view declaring the rowed
// dtor; the vector dtor at 0x004815AE calls here.
#include <vector>

struct Rva0048130E
{
	~Rva0048130E();

	unsigned char m_data[8];
};

template void _STL::_Destroy<Rva0048130E *>(Rva0048130E *, Rva0048130E *);
