extern int g_bfmeSeedJC;
// g_bfmeSeedJC: VA 0xddbfc0 (retail .data initial value 13).
int g_bfmeSeedJC = 13;
extern int g_bfmeCarryJC;
// g_bfmeCarryJC: VA 0xddbfc4 (retail .data initial value 117).
int g_bfmeCarryJC = 117;

// ?bfmeRandom@@YAHH@Z
int bfmeRandom(int range)
{
	int seed = g_bfmeSeedJC;
	int carry = g_bfmeCarryJC;

	int mix = seed * 0x3E322 + carry * 0x8149A;
	int next = mix % 0xF408B;

	g_bfmeCarryJC = seed;
	g_bfmeSeedJC = next;
	return next % range;
}
