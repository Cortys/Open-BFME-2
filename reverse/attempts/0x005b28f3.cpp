// ?Rva005B28F3PushHeap@@YAXPAUBfmeE16@@HHU1@@Z
// partial score=0.97 date=2026-09-30
// ?Rva005B28F3PushHeap@@YAXPAUBfmeE16@@HHU1@@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
struct BfmeE16 { float x, y, z, w; };
typedef bool __stdcall LessFn(const void *a, const void *b);
extern LessFn Rva005B26CELess;
void __cdecl Rva005B28F3PushHeap(BfmeE16 *first, int hole, int top, BfmeE16 value)
{
	int parent = (hole - 1) / 2;
	while (hole > top && Rva005B26CELess(first + parent, &value)) {
		first[hole] = first[parent];
		hole = parent;
		parent = (hole - 1) / 2;
	}
	first[hole] = value;
}
