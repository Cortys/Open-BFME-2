// ?Rva0059B036Copy@@YAXPAX0H@Z
// partial score=0.95 date=2026-09-29
// ?Rva0059B036Copy@@YAXPAX0H@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /GX-
//
// ?Rva0059B036Copy@@YAXPAX0H@Z retail 0x0059B036 42B.
// 24-byte struct build: copy 20B from src to stack tmp then store tail
// then copy 24B to dst via rep movsd 5 and 6, EBP frame, plain ret.
// Evidence: retail push ebp frame rep movsd 5 and 6; callers 0x00513ED1 0x0059B5A3 0x005E3753.
struct Rva0059B036Five
{
	int v[5];
};

struct Rva0059B036Six
{
	Rva0059B036Five head;
	int tail;
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

// ?Rva0059B036Copy@@YAXPAX0H@Z present-unmatched
void __cdecl Rva0059B036Copy(void *dst, void *src, int tail)
{
	Rva0059B036Six tmp;
	tmp.head = *(Rva0059B036Five *)src;
	tmp.tail = tail;
	_ReadWriteBarrier();
	*(Rva0059B036Six *)dst = tmp;
}
