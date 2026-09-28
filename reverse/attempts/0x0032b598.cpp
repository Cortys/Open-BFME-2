// ?Rva0032B598Construct@@YAXPAV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@ABV12@@Z
// partial score=0.97 date=2026-09-28
// ?Rva0032B598Construct@@YAXPAV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@ABV12@@Z
// partial score=0.97 date=2026-09-28
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?Rva0032B598Construct@@YAXPAV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@ABV12@@Z @ 0x0032B598 (45B).
// Guarded placement copy of vector<BfmeE8>: null-checked destination,
// out-of-line rowed copy ctor 0x004334D7, EH state 0 for the partial vector.
// Callers walk 0xC-stride vector arrays (0x0032B5C5/0x0032B5EB/0x0032E842/0x0032EA3F).
#include <vector>
#include <new>

struct BfmeE8 { int a, b; };

namespace _STL
{

template <>
vector<BfmeE8, allocator<BfmeE8> >::vector(const vector<BfmeE8, allocator<BfmeE8> > &);

}

// ?Rva0032B598Construct@@YAXPAV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@ABV12@@Z present-unmatched
void __cdecl Rva0032B598Construct(_STL::vector<BfmeE8> *dst, const _STL::vector<BfmeE8> &src)
{
	if (dst)
		new (dst) _STL::vector<BfmeE8>(src);
}
