extern "C" void *bfmeVftYX[];
extern "C" void __stdcall bfmeFreeAYX(void *p);
extern "C" void __stdcall bfmeFreeBYX(void *p);

void __cdecl operator delete[](void *block);

class BfmeOwnerYX
{
public:
	void bfmeCleanupYX();

	void bfmeShutdownYX();

	void **m_bfmeVfptrYX;
	unsigned char m_bfmePadYX[8];
	unsigned char *m_bfmeArrayYX;
	unsigned char m_bfmeMidYX[8];
	void *m_bfmeBYX;
	void *m_bfmeAYX;
};

void BfmeOwnerYX::bfmeCleanupYX()
{
	m_bfmeVfptrYX = bfmeVftYX;

	bfmeShutdownYX();

	if (m_bfmeAYX != 0)
		bfmeFreeAYX(m_bfmeAYX);

	if (m_bfmeBYX != 0)
		bfmeFreeBYX(m_bfmeBYX);

	if (m_bfmeArrayYX != 0)
		delete [] m_bfmeArrayYX;
}

// Retail's call sites in this unit's matched rows land on bodies rowed under
// other spellings at the same addresses (same ABI). Bind the spellings used here.
#pragma comment(linker, "/alternatename:_bfmeFreeAYX@4=?ji_0065477e@@YAXXZ")
#pragma comment(linker, "/alternatename:_bfmeFreeBYX@4=?ji_0065478a@@YAXXZ")

// Retail's data references in this unit's matched rows land on globals defined
// under other spellings at the same addresses (addend-corrected DIR32). Bind them.
#pragma comment(linker, "/alternatename:_bfmeVftYX=??_7BfmeThingTXA@@6B@")
