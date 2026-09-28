// ?Rva0053442ADiv@@YAXPAH0@Z
// partial score=0.86 date=2026-09-28
// ?Rva0053442ADiv@@YAXPAH0@Z
// partial score=0.86 date=2026-09-28
// cl: /O1 /MD
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
// ?Rva0053442ADiv@@YAXPAH0@Z present-unmatched
void __cdecl Rva0053442ADiv(int *dst, int *src)
{
	int t0 = src[0] / 16;
	_ReadWriteBarrier();
	int t1 = src[1] / 16;
	dst[0] = t0;
	dst[1] = t1;
}
