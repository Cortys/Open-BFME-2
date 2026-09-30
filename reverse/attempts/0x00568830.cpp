// ?Rva00568830Push@@YAXPAPAXHHPBXPAH@Z
// partial score=0.95 date=2026-09-30
// ?Rva00568830Push@@YAXPAPAXHHPBXPAH@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /G7
// ?Rva00568830Push@@YAXPAPAXHHPBXPAH@Z retail 0x00568830 77B: heap push sift-up via rowed stdcall Less with parent (hole-1)/2.
// Evidence: EBP frame with ebx base edi hole esi parent plus cdq sub sar mid plus Less element value with test al then shift plus final store value at hole; caller 0x00568B41 pushes 5 args.
bool __stdcall Rva00568721Less(const void *a, const void *b);
void __cdecl Rva00568830Push(void **base, int hole, int top, const void *value, int *tag)
{
	int parent = (hole - 1) / 2;
	while (hole > top)
	{
		const void *elem = base[parent];
		if (!Rva00568721Less(elem, value))
			break;
		base[hole] = base[parent];
		hole = parent;
		parent = (parent - 1) / 2;
	}
	base[hole] = (void *)value;
}
