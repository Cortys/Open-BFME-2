extern "C" unsigned char bfmeVftUB[];

void bfmeFreeUB(void *what);

class BfmeThingUB
{
public:
	void bfmeResetUB();
	void *m_bfmeVft;
	unsigned char m_bfmeGap[8];
	void *m_bfmeWhat;
};

void BfmeThingUB::bfmeResetUB()
{
	m_bfmeVft = bfmeVftUB;
	bfmeFreeUB(m_bfmeWhat);
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:??1Rva0061ED80@@UAE@XZ=?bfmeResetUB@BfmeThingUB@@QAEXXZ")

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:??1Rva009EB810TailBase@@UAE@XZ=?bfmeResetUB@BfmeThingUB@@QAEXXZ")
