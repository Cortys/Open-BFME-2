// ?Rva006038EFBswap@@YAKK@Z
// partial score=0.94 date=2026-09-28
// ?Rva006038EFBswap@@YAKK@Z
// partial score=0.94 date=2026-09-28
// cl: /O1 /Oi- /MD
// ?Rva006038EFBswap@@YAKK@Z @0x006038EF 35B: free byteswap ulong via shifts.
// No donor; callers at 0x00603914 plus 0x00604732 need byte-swapped ulong.
// /Oi- disables bswap intrinsic to keep retail manual shift shape.
unsigned long Rva006038EFBswap(unsigned long v)
{
	unsigned long a = (v & 0xff00ul) + (v << 16);
	unsigned long b = ((unsigned char *)&v)[2];
	b <<= 8;
	a <<= 8;
	return a + b + (v >> 24);
}
