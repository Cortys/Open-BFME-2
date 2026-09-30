// Grow a UPC value stack slot.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv1339.cpp); trimmed to the single T1
// body the sweep places.

struct BfmeValueUPC
{
	int m_bfmeType;
	char m_bfmePad[4];
	void *m_bfmeValue;
};

struct BfmeStateUPC
{
	BfmeValueUPC *m_bfmeTop;
	char m_bfmePad[4];
	BfmeValueUPC *m_bfmeLimit;
};

extern "C" void *luaH_new(BfmeStateUPC *L, int a, int b);
extern "C" void luaD_checkstack(BfmeStateUPC *L, int n);

void bfmeGoUPC(BfmeStateUPC *L, int n)
{
	L->m_bfmeTop->m_bfmeValue = luaH_new(L, 0, n);
	L->m_bfmeTop->m_bfmeType = 4;
	if (L->m_bfmeTop == L->m_bfmeLimit)
		luaD_checkstack(L, 1);
	L->m_bfmeTop = (BfmeValueUPC *)((char *)L->m_bfmeTop + 0x10);
}
