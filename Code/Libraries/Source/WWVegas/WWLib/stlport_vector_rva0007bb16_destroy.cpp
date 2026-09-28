// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??$_Destroy@PAURva0007BB16Record@@@_STL@@YAXPAURva0007BB16Record@@0@Z @0x0007C2D7 25B:
// ?_M_clear@?$vector@URva0007BB16Record@@V?$allocator@URva0007BB16Record@@@_STL@@@_STL@@IAEXXZ @0x0007C614 30B:
// STLport 4.5.3 range destroy over the 0x24-byte two-string record whose dtor
// is rowed at 0x0007BB16 (strings at +0x00/+0x08, tail past +0x0C unrecovered,
// same definition as Code/GameEngine/Source/Common/StringRecordDtors.cpp).
// Retail steps esi by 0x24 and calls the rowed dtor; callers at 0x0007C5D5,
// 0x0007C614, 0x0015229C and 0x001522CF prove the 0x24 stride and the two
// vector lifetimes. Landing this unblocks those four callers.
#include <vector>

class AsciiString
{
public:
	~AsciiString();

private:
	void *m_data;
};

struct Rva0007BB16Record
{
	~Rva0007BB16Record();
	AsciiString m_00;
	int m_04;
	AsciiString m_08;
	int m_tail0C[6];
};

namespace _STL
{

template <>
__declspec(noinline) void _Destroy<Rva0007BB16Record *>(Rva0007BB16Record *__first, Rva0007BB16Record *__last)
{
	for (; __first != __last; ++__first)
		_Destroy(&*__first);
}

}

template void _STL::vector<Rva0007BB16Record>::_M_clear();
