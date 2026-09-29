// cl: /O1 /MD
// ?bfmeDropVGO@@YAXPAX@Z 0x006D0440 32B: pool drop via teardown plus freeBlock.
// Evidence: leaf with LINK BONUS (2 files await bfmeDropVGO); 6 matched callers incl BfmeRefVGO dtor; pins teardown 0x006D0280 freeBlock 0x006DB270; pool 0x00A176E8 size 0x1C; donor bfmeDropA pattern.
class Rva006D0280
{
public:
	void teardown();
};

class Rva006DB270
{
public:
	void freeBlock(void *p, int size);
};

extern Rva006DB270 *g_00A176E8;

void __cdecl bfmeDropVGO(void *p)
{
	if (p != 0)
	{
		((Rva006D0280 *)p)->teardown();
		g_00A176E8->freeBlock(p, 0x1C);
	}
}
