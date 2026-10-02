// Open-BFME5 conversions.

extern char g_bfmeVft969D1[];
extern char g_bfmeVft969D2[];
extern char g_bfmeVft969D3[];

class BfmeD969
{
public:
	void bfmeGo969D();
	void bfmeBase969D();

	char *volatile m_bfmeVft;
	char *volatile m_bfmeVft2;
	volatile int m_bfme08;
	volatile int m_bfme0c;
	volatile int m_bfme10;
	volatile int m_bfme14;
};

void BfmeD969::bfmeGo969D()
{
	m_bfmeVft2 = g_bfmeVft969D1;
	m_bfme08 = 0;
	m_bfme0c = 0;
	m_bfme10 = 0;
	m_bfme14 = 0;
	m_bfmeVft2 = g_bfmeVft969D2;
	m_bfmeVft = g_bfmeVft969D3;
	bfmeBase969D();
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:??1Gen007F4D00@@UAE@XZ=?bfmeGo969D@BfmeD969@@QAEXXZ")
