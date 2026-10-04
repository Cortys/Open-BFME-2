// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
// ?bfmeGo939G@BfmeThing939G@@QAEXPAX@Z
// retail 0x0044BDC1, 23 bytes. Dedicated TU ported from the Open-BFME-1 donor
// game/GameEngine/Source/Common/BfmeConv939.cpp (reference/open-bfme-1 @ 6d943426).
// Compiled /Os the donor body is byte-identical to retail once relocations are
// masked (unique hit on unclaimed .text). Only the placed body is defined here;
// the donor's other definitions are omitted.

class BfmeSub939G
{
public:
	void bfmeCall939G();
	void *m_bfmeP;
};

class BfmeThing939G
{
public:
	void bfmeGo939G(void *a);
	char m_bfmePad[8];
	BfmeSub939G m_bfmeSub;
};

void BfmeThing939G::bfmeGo939G(void *a)
{
	BfmeSub939G *s = &m_bfmeSub;
	if (!a && s->m_bfmeP)
		s->bfmeCall939G();
}