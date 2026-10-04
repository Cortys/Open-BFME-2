// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
//
// ?bfmeGoKA@@YAXXZ
// retail 0x00260805, 33 bytes. Dedicated TU ported from the Open-BFME-1
// donor game/GameEngine/Source/Common/BfmeConv902.cpp. Recompiled /Os the
// donor body is byte-identical to retail once relocations are masked (unique
// hit on unclaimed .text). Only the placed body is defined here; the donor's
// other definitions are omitted.
class BfmeItemKA
{
public:
	void bfmeDoKA();
};

extern BfmeItemKA **g_bfmeBegKA;
extern BfmeItemKA **g_bfmeEndKA;

void bfmeGoKA(void)
{
	BfmeItemKA **p = g_bfmeBegKA;
	BfmeItemKA **e = g_bfmeEndKA;
	while (p != e) {
		(*p)->bfmeDoKA();
		++p;
	}
}