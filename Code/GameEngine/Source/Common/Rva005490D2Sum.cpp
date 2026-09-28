// cl: /O1 /DNDEBUG /MD
// ?rva005490D2@Rva005490D2@@QBEHXZ, RVA 0x005490D2, 31B
// Summing loop over array at +4 with count at +0 via double indirection.
// Evidence: single caller at 0x005493CC; xor-first and dec/jne point to /O1;
// dword at +0x568 summed; neighbours are Disp getters and clamped setter.
struct Leaf005490D2 {
	char pad[0x568];
	int field568;
};
struct Mid005490D2 {
	int unk0;
	Leaf005490D2 *leaf;
};
struct Rva005490D2 {
	int count;
	Mid005490D2 *array[1];
	int rva005490D2() const;
};
int Rva005490D2::rva005490D2() const
{
	int total = 0;
	int n = count;
	if (n > 0) {
		Mid005490D2 **p = (Mid005490D2 **)array;
		do {
			total += (*p)->leaf->field568;
			++p;
		} while (--n);
	}
	return total;
}
