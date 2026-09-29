// ?Rva0032B598Construct@@YAXPAXABV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@@Z
// partial score=0.93 date=2026-09-28
// ?Rva0032B598Construct@@YAXPAXABV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// ?Rva0032B598Construct@@YAXPAXABV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@@Z at 0x0032B598 (45B).
// Null-guarded placement copy-construct of vector<BfmeE8> via rowed
// copy-ctor 0x4334D7. Evidence: 4 callers incl 0x32B5FE/0x32B5D3,
// unblocks 0x32B5EB/0x32B5C5.

#include <vector>
#include <new.h>

struct BfmeE8 { int a, b; };

void Rva0032B598Construct(void *dst, const _STL::vector<BfmeE8> &src);

// ?Rva0032B598Construct@@YAXPAXABV?$vector@UBfmeE8@@V?$allocator@UBfmeE8@@@_STL@@@_STL@@@Z present-unmatched
void Rva0032B598Construct(void *dst, const _STL::vector<BfmeE8> &src)
{
	if (dst != 0)
		new (dst) _STL::vector<BfmeE8>(src);
}
