// ?Rva005874BAInsert@@YAXPAURec12@@HHU1@PBX@Z
// partial score=0.93 date=2026-09-30
// ?Rva005874BAInsert@@YAXPAURec12@@HHU1@PBX@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /G7 /MD /arch:SSE
// ?Rva005874BAInsert@@YAXPAURec12@@HHU1@PBX@Z @0x005874BA 70B
// Sorted 12B rec insert via float key binary search and 12B moves.
// Evidence: stride 0xC comiss movss; caller 0x005876C8 5-arg cdecl; prev Pod60 next 60B copy; unblocks 0x0058765D.
struct Rec12
{
	float key;
	int b;
	int c;
};
// ?Rva005874BAInsert@@YAXPAURec12@@HHU1@PBX@Z present-unmatched
void __cdecl Rva005874BAInsert(Rec12 *base, int hi, int lo, Rec12 rec, const void *unused)
{
	(void)unused;
	int mid = hi - 1;
	while (1) {
		int half = mid / 2;
		if (hi <= lo)
			break;
		if (rec.key <= (base + half)->key)
			break;
		*(base + hi) = *(base + half);
		hi = half;
		mid = half - 1;
	}
	*(base + hi) = rec;
}
