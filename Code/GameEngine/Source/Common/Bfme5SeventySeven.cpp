// ?bfmeClearAll@@YAXXZ, retail 0x006B5830 (53 bytes).
// BFME1 Bfme5SeventySeven.cpp donor, trimmed to bfmeClearAll; the file's
// other bodies live at other game.dat addresses and land separately.
// Retail-measured BFME2 repair: the four cleared tables bake to their
// BFME2 absolutes (the donor's externs carry the BFME1 addresses).

extern "C" void * __cdecl memset(void *destination, int value, unsigned int bytes);

#pragma intrinsic(memset)

// Address-derived dword buffers: bfmeClearAll's memset lengths establish the
// extents, and game.dat shows their initial bytes are all zero (.data/bss).
int g_Va00E1F8E0[0x230];
int g_Va00E21220[0x230];
int g_Va00E20FC0[0x80];
int g_Va00E20DA0[0x80];

// ?bfmeClearAll@@YAXXZ
void __cdecl bfmeClearAll(void)
{
	memset(g_Va00E1F8E0, 0, 0x230 * 4);
	memset(g_Va00E21220, 0, 0x230 * 4);
	memset(g_Va00E20FC0, 0, 0x80 * 4);
	memset(g_Va00E20DA0, 0, 0x80 * 4);
}
