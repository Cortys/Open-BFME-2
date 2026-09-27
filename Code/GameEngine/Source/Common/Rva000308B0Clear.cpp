// cl: /GX-
// ?Rva000308B0Clear@@YAXXZ @ 0x000308B0 17B
// Guarded flag clear: if the init flag at 0x00DE0821 is set, writes 0 to the
// byte at 0x00DE0818, else returns. Evidence: caller at 0x00225401, sibling
// set at 0x00030890 writes 1, getter at 0x000308D0 reads 0x00DE0818.
// Honest address-derived name. No STL.
extern unsigned char g_Va00DE0821;
extern unsigned char g_Va00DE0818;

void Rva000308B0Clear(void)
{
	if (g_Va00DE0821 != 0)
		g_Va00DE0818 = 0;
}
