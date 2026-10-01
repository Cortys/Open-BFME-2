extern int g_bfmeSeedJC;
extern int g_bfmeCarryJC;

int d_008790b0(int reset)
{
	int carry;
	int seed;
	if (reset) {
		seed = 13;
		carry = 117;
	} else {
		carry = g_bfmeCarryJC;
		seed = g_bfmeSeedJC;
	}
	int next = (seed * 0x3E322 + carry * 0x8149A) % 0xF408B;
	g_bfmeCarryJC = seed;
	g_bfmeSeedJC = next;
	return next;
}
