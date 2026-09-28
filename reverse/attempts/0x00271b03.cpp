// ?rva00271B03@Rva00271B03@@QAEXXZ
// partial score=0.9 date=2026-09-28
// ?rva00271B03@Rva00271B03@@QAEXXZ
// partial score=0.90 date=2026-09-28
// cl: /O1 /MD
//
// ?rva00271B03@Rva00271B03@@QAEXXZ retail 0x00271B03 35 bytes.
// Max tracking via TheGameLogic frame: if m04 then v=m04[0x594]+frame if v>m388
// then m388=v. Unblocks 0x0027B18C. Prev/next in Common with /O1 /MD.
// Evidence: callers 0x0027B418 0x0027B44B plus TheGameLogic 0x00DFE78C plus
// frame +0x40 plus offsets +0x04 +0x594 +0x388.

struct Inner594
{
	unsigned char m_pre[0x594];
	unsigned int m_value;
};

struct GameLogic
{
	unsigned char m_pre[0x40];
	unsigned int m_frame;
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class Rva00271B03
{
public:
	void rva00271B03();

private:
	unsigned char m_pre04[4];
	Inner594 *m_04;
	unsigned char m_mid[0x388 - 0x08];
	int m_388;
};

// ?rva00271B03@Rva00271B03@@QAEXXZ present-unmatched
void Rva00271B03::rva00271B03()
{
	if (m_04 != 0)
	{
		unsigned int v1 = m_04->m_value;
		unsigned int v2 = TheGameLogic->m_frame;
		unsigned int v = v1 + v2;
		if (v > m_388)
			m_388 = v;
	}
}
