// ?rva005490AE@Rva005490D2@@QBEHXZ
// partial score=0.93 date=2026-09-28
// ?rva005490AE@Rva005490D2@@QBEHXZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /arch:SSE
// Max sibling of sum 0x005490D2: same Owner (count+inline array) via double
// indirection, dword at +0x564 with cmovg (needs /arch:SSE). s2 shape gives
// 36B exact regs (n in edx, v in esi, cmovg esi, push late) with only the
// `add ecx,4` for p hoisted early (before test at +0x04) where retail keeps
// it late (after jle at +0x08). Tried p-inside (late add) but then n goes to
// esi with early push; p-outside gives correct regs but early add. Needs a
// source that keeps p-init late (inside if) while keeping n in edx.
struct Leaf005490D2 {
	char pad[0x564];
	int field564;
	int field568;
};
struct Mid005490D2 {
	int unk0;
	Leaf005490D2 *leaf;
};
struct Rva005490D2 {
	int count;
	Mid005490D2 *array[1];
	int rva005490AE() const;
};
int Rva005490D2::rva005490AE() const
{
	int best = 0;
	int n = count;
	Mid005490D2 **p = (Mid005490D2 **)array;
	if (n > 0) {
		do {
			int v = (*p)->leaf->field564;
			if (v > best)
				best = v;
			++p;
		} while (--n);
	}
	return best;
}
