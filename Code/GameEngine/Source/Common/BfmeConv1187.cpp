// Open-BFME5 conversions.
// The compiler-generated vector constructor iterator (??_H) takes the
// optimization state of the first function that needs it. Retail links one
// copy, the /O1 body at 0x00001423; this unemitted anchor makes this unit's
// copy that same body, so it no longer loses to retail's at link time.
// It can also change how later array constructions here compile; checked to
// change nothing else in this unit, but if a function added later that builds
// an array will not match, try it without this block.
struct BfmeVciAnchorElem { BfmeVciAnchorElem(); };
#pragma optimize("gsy", on)
static void bfmeVciAnchor() { BfmeVciAnchorElem anchor[2]; (void)anchor; }
#pragma optimize("", on)

extern "C" char g_bfmeV1187[];

struct BfmePair1187
{
	BfmePair1187(void)
	{
		m_bfme00 = 0;
		m_bfme04 = 0;
	}
	int m_bfme00;
	int m_bfme04;
};

class BfmeBase1187
{
public:
	BfmeBase1187(void) { m_bfme00 = g_bfmeV1187; }
	char *volatile m_bfme00;
	volatile int m_bfme04;
};

class BfmeA1187 : public BfmeBase1187
{
public:
	BfmeA1187(void);
	BfmePair1187 m_bfme08[8];
};

BfmeA1187::BfmeA1187(void)
{
	m_bfme04 = 0;
}
