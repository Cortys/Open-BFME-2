extern void *g_bfmeVftTXA[];

void __stdcall bfmeReleaseATXA(void *place);
void __stdcall bfmeReleaseBTXA(void *place);
void bfmeFreeArrayTXA(void *place);
void bfmeFreeTXA(void *place);

class BfmeThingTXA
{
public:
	void *bfmeDelTXA(unsigned char flags);
	void bfmeDtorTXA(void);
	void *m_bfmeVft;
	char m_bfmePad[8];
	void *m_bfmeBuf;
	char m_bfmePad2[8];
	void *m_bfmeB;
	void *m_bfmeA;
};

// ?bfmeDelTXA@BfmeThingTXA@@QAEPAXE@Z
void *BfmeThingTXA::bfmeDelTXA(unsigned char flags)
{
	m_bfmeVft = g_bfmeVftTXA;
	bfmeDtorTXA();
	if (m_bfmeA)
		bfmeReleaseATXA(m_bfmeA);
	if (m_bfmeB)
		bfmeReleaseBTXA(m_bfmeB);
	if (m_bfmeBuf)
		bfmeFreeArrayTXA(m_bfmeBuf);
	if (flags & 1)
		bfmeFreeTXA(this);
	return this;
}

// Retail's call sites in this unit's matched rows land on bodies rowed under
// other spellings at the same addresses (same ABI). Bind the spellings used here.
#pragma comment(linker, "/alternatename:?bfmeReleaseATXA@@YGXPAX@Z=?ji_0065477e@@YAXXZ")
#pragma comment(linker, "/alternatename:?bfmeReleaseBTXA@@YGXPAX@Z=?ji_0065478a@@YAXXZ")

// Retail's data references in this unit's matched rows land on globals defined
// under other spellings at the same addresses (addend-corrected DIR32). Bind them.
#pragma comment(linker, "/alternatename:?g_bfmeVftTXA@@3PAPAXA=??_7BfmeThingTXA@@6B@")
