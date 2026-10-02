// ?Rva0007B734Find@@YAPAURva0007B734Item@@PAU1@0P6A_NPBU1@1@Z@Z
// partial score=0.93 date=2026-10-02
// cl: /G7 /O2 /DNDEBUG /MD /EHsc /Oy- /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
//
// ?Rva0007B734Find@@YAPAURva0007B734Item@@PAU1@0P6A_NPBU1@1@Z@Z @ 0x0007B734 (47B):
// __cdecl min-element over 8-byte records: if first==last return first,
// else best=first and for each subsequent record if pred(current,best)
// update best via cmovne, step 8 to last, return best. Caller 0x0007C73A
// 631B unclaimed. Evidence: 47B leaf with add esi 8 stride, push edi/push esi
// indirect call at ebp+0x10, test al/al plus cmovne edi/esi.
// ?Rva0007B734Find@@YAPAURva0007B734Item@@PAU1@0P6A_NPBU1@1@Z@Z present-unmatched
struct Rva0007B734Item {
	char m_pad[8];
};

typedef bool (__cdecl *Rva0007B734Pred)(const Rva0007B734Item *, const Rva0007B734Item *);

Rva0007B734Item *__cdecl Rva0007B734Find(Rva0007B734Item *first, Rva0007B734Item *last, Rva0007B734Pred pred)
{
	if (first == last)
		return first;
	Rva0007B734Item *best = first;
	++first;
	while (first != last) {
		best = pred(first, best) ? first : best;
		++first;
	}
	return best;
}
