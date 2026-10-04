// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
// Three errands handed straight on: one to a holder that may not be there, one
// to a part of the record itself, and one that asks first which of two to run.

class BfmeSubBJ
{
public:
	virtual void bfmeDoBJ(void);
};

struct BfmeKindBJ
{
	unsigned char m_bfmeHead[0x10];		// 0x00
	unsigned char m_bfmeStop;		// 0x10
};

class BfmeThingBJ
{
public:
	void bfmeGoBJ(void);

private:
	int m_bfmeFirst;			// 0x00
	BfmeKindBJ *m_bfmeKind;			// 0x04
	unsigned char m_bfmeGap[8];		// 0x08
	BfmeSubBJ m_bfmeSub;			// 0x10
};

void BfmeThingBJ::bfmeGoBJ(void)
{
	if (m_bfmeKind->m_bfmeStop != 0)
		return;

	m_bfmeSub.bfmeDoBJ();
}


