// cl: /O1 /DNDEBUG /MD /GX /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_STLP_USE_MALLOC /D_CRTIMP=
// stlport
// ??$_Destroy@PAURva004F69C3@@@_STL@@YAXPAURva004F69C3@@0@Z, retail 0x0040DCF1, 25 bytes.
// Range destroy over 8-byte Rva004F69C3 elements via rowed dtor at 0x004F69C3.
// Element layout int plus pointer matches rowed dtor TU. Callers push first+last
// with no tag (0x0040E105 0x004F884C 0x004F8A01) so it lives out of line as the
// 2-arg _Destroy, not the 3-arg __destroy_aux. Same 25B shape as _Destroy at
// 0x00331FF1 for Rva002DFC30 and destroy range at 0x002D02A8.
#include <vector>

struct Rva004F69C3
{
	int m_00;
	void *m_04;
	~Rva004F69C3();
};

namespace _STL
{

template <>
__declspec(noinline) void _Destroy<Rva004F69C3 *>(Rva004F69C3 *__first, Rva004F69C3 *__last)
{
	for (; __first != __last; ++__first)
		_Destroy(&*__first);
}

}
