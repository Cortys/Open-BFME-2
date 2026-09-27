// cl: /GX-
// ?Rva00030890Set@@YAXXZ @ 0x00030890 17B
// Guarded flag set: if the init flag at 0x00DE0821 is set, writes 1 to the
// byte at 0x00DE0818, else returns. Evidence: caller at 0x0022540E, sibling
// clear at 0x000308B0 writes 0, getter at 0x000308D0 reads 0x00DE0818.
// Honest address-derived name. No STL.
extern unsigned char g_Va00DE0821;
extern unsigned char g_Va00DE0818;

void Rva00030890Set(void)
{
	if (g_Va00DE0821 != 0)
		g_Va00DE0818 = 1;
}
