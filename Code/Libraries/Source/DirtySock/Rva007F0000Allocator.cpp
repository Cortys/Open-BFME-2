// DirtySock FESL allocator wrapper at retail RVA 0x007F0000.
// The allocation slot returns its pointer in EAX.
class BfmeS1019
{
public:
	virtual void bfmeVS01019();
	virtual void bfmeVS11019();
	virtual void *bfmeDoB1019(int a, int b);
	virtual void bfmeDoC1019(int a, int b);
};

extern BfmeS1019 *g_bfmeS1019;
void bfmeInit1019(char *n);

void *Rva007F0000Alloc(int a)
{
	if (g_bfmeS1019 == 0)
		bfmeInit1019((char *)"no FESL allocator defined\n");

	return g_bfmeS1019->bfmeDoB1019(a, 0);
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:_Rva007F0000Alloc=?Rva007F0000Alloc@@YAPAXH@Z")

// Retail's call sites in this unit's matched rows land on bodies rowed under
// other spellings at the same addresses (same ABI). Bind the spellings used here.
#pragma comment(linker, "/alternatename:?bfmeInit1019@@YAXPAD@Z=?ji_00629b14@@YAXXZ")
