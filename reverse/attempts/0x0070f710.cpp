// _bfmeReload1221
// partial score=0.9 date=2026-10-01
// _bfmeReload1221 @0x0070F710 275B
// Mersenne-twister reload over g_bfmeStateFA: reseeds via bfmeSeed(0x1105)
// when the shared index reads below -1 (first use after bfmeNext1221's
// pre-decrement), twists 227 + 396 + 1 words with MATRIX_A 0x9908b0df,
// publishes g_bfmeNext1221 at &state[1], then tempers state[0] and returns it.
// Evidence: LINK BONUS caller ?bfmeNext1221@@YAIXZ in BfmeConv1221.cpp names
// exactly _bfmeReload1221; callee ?bfmeSeed@@YAXH@Z rowed in
// Bfme5SeventyFour.cpp; twist constants and 0xe3/0x18c trip counts.

extern int g_bfmeLeft1221;
extern int g_bfmeStateFA[];
extern unsigned int *g_bfmeNext1221;

void __cdecl bfmeSeed(int seed);

extern "C" unsigned int bfmeReload1221(void)
{
	unsigned int *dest = (unsigned int *)g_bfmeStateFA;
	unsigned int *src = (unsigned int *)&g_bfmeStateFA[2];
	unsigned int prev;
	unsigned int curr;
	int left;
	unsigned int other;
	unsigned int y;
	unsigned int mag;

	if (g_bfmeLeft1221 < -1)
		bfmeSeed(0x1105);

	prev = (unsigned int)g_bfmeStateFA[0];
	curr = (unsigned int)g_bfmeStateFA[1];
	g_bfmeLeft1221 = 0x26f;
	g_bfmeNext1221 = (unsigned int *)&g_bfmeStateFA[1];

	left = 0xe3;
	do {
		other = *(src + 395);
		y = (curr ^ prev) & 0x7ffffffe ^ prev;
		mag = (curr & 1) ? 0x9908b0df : 0;
		*dest = ((y >> 1) ^ mag) ^ other;
		prev = curr;
		curr = *src;
		++dest;
		++src;
	} while (--left != 0);

	unsigned int *low = (unsigned int *)g_bfmeStateFA;
	left = 0x18c;
	do {
		y = (curr ^ prev) & 0x7ffffffe ^ prev;
		mag = (curr & 1) ? 0x9908b0df : 0;
		*dest = ((y >> 1) ^ mag) ^ *low;
		prev = curr;
		curr = *src;
		++dest;
		++low;
		++src;
	} while (--left != 0);

	curr = (unsigned int)g_bfmeStateFA[0];
	y = (curr ^ prev) & 0x7ffffffe ^ prev;
	mag = (curr & 1) ? 0x9908b0df : 0;
	*dest = ((y >> 1) ^ mag) ^ *low;

	y = curr;
	y ^= y >> 11;
	y ^= (y << 7) & 0x9d2c5680;
	y ^= (y << 15) & 0xefc60000;
	y ^= y >> 18;
	return y;
}
