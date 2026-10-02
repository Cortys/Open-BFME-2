// Open-BFME5 conversions (trimmed to the placed 936B body; the other three
// are declared-only here).

void __stdcall bfmeElem936B(void *p);
void __stdcall bfmeVecDtor936B(void *p, unsigned int size, int count, void (__stdcall *dtor)(void *));

class BfmeThing936B
{
public:
	void bfmeGo936B(void);
};

// ?bfmeGo936B@BfmeThing936B@@QAEXXZ
void BfmeThing936B::bfmeGo936B(void)
{
	bfmeVecDtor936B(this, 4, 0x80, bfmeElem936B);
}

class BfmeThing936F
{
public:
	void bfmeGo936F(void);
};

void bfmeGo936C(void);

class BfmeThing936G
{
public:
	BfmeThing936G *bfmeGo936G(void);
	void bfmeInit936G(void);
};

// ?g_bfme936GlobG@@3PAXA: the global at this VA is ?_S_count@Init@ios_base@_STL@@0JA; this name is an alias for it.
extern void * g_bfme936GlobG;
#pragma comment(linker, "/alternatename:?g_bfme936GlobG@@3PAXA=?_S_count@Init@ios_base@_STL@@0JA")

// ?bfmeGo936G@BfmeThing936G@@QAEPAV1@XZ, retail 0x00016AA0 (21B).
BfmeThing936G *BfmeThing936G::bfmeGo936G(void)
{
	if (!g_bfme936GlobG)
		bfmeInit936G();
	return this;
}

// Retail's call sites in this unit's matched rows land on bodies rowed under
// other spellings at the same addresses (same ABI). Bind the spellings used here.
#pragma comment(linker, "/alternatename:?bfmeVecDtor936B@@YGXPAXIHP6GX0@Z@Z=??_M@YGXPAXIHP6EX0@Z@Z")
