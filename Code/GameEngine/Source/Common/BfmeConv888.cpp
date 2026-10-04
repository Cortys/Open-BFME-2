// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
//
// ?bfmeGoEYF@BfmeThingEYF@@QAE_NPAX0@Z
// retail 0x0030DE61, 37 bytes. Dedicated TU ported from the Open-BFME-1
// donor game/GameEngine/Source/Common/BfmeConv888.cpp. Recompiled /Os the
// donor body is byte-identical to retail once relocations are masked (unique
// hit on unclaimed .text). Only the placed body is defined here; the donor's
// other definitions are omitted.
struct BfmeNodeEYF
{
	unsigned char m_bfmeHead[4];
	BfmeNodeEYF *m_bfmeNext;
};

// retail 0x0030DC85: the donor's allocator. Unclaimed (no ledger row, no
// pin) and a ghidra function start (FUN_0070dc85, 476 bytes), so the donor's
// name is pinned here rather than an address-derived one. The address is read
// off retail's REL32 at 0x0030DE6D: next-instruction 0x0030DE71 plus the
// displacement 0xFFFFFE14. Carried from the donor source; the body at the
// address remains unrecovered.
extern BfmeNodeEYF *__cdecl bfmeMakeEYF(void *a, void *b);

struct BfmeThingEYF
{
	bool bfmeGoEYF(void *a, void *b);
	unsigned char m_bfmeHead[0xc];
	BfmeNodeEYF *m_bfmeHead2;
};

bool BfmeThingEYF::bfmeGoEYF(void *a, void *b)
{
	BfmeNodeEYF *n = bfmeMakeEYF(a, b);
	if (n)
	{
		m_bfmeHead2->m_bfmeNext = n;
		m_bfmeHead2 = n;
	}
	return true;
}