// cl: /DNDEBUG /MD /O2
// Open-BFME-1 donor at cd32c8ef06dfb0d995b2f47e93e41622e4447092:
// Rva009C7380BinkSse.cpp, BFME 1 RVA 0x009C7380.
// BFME2 target RVA 0x001D7C80 is selected by the address map and independently
// agrees with the donor's distance dispatch and matched Bink SSE callees.
// The target's weight table address is 0x00DB84E0 (retail VA).

extern void __cdecl rva009C7060BinkSse(const void *, void *, int, int, int, int, const void *);
extern void __cdecl rva009C70D0BinkSse(const void *, void *, int, int, int, int, const void *);
extern void __cdecl rva009C7140BinkSse(const void *, void *, int, const void *, const void *);

struct Rva009C7380WeightPair
{
	unsigned int coefficient[8];
};

extern const Rva009C7380WeightPair rva009C7380WeightPairs[];

static const Rva009C7380WeightPair *rva009C7380Weights(int index)
{
	return &rva009C7380WeightPairs[index];
}

void __cdecl rva009C7380BinkSse(const unsigned char *rowA, const unsigned char *rowB,
	void *destination, int stride, int horizontalIndex, int verticalIndex)
{
	int distance = rowB - rowA;
	if (distance < 0)
	{
		const unsigned char *oldRowA = rowA;
		rowA = rowB;
		distance = oldRowA - rowB;
	}
	if (distance == 1)
	{
		rva009C7060BinkSse(rowA, destination,
			stride, 1, 8, 8, rva009C7380Weights(horizontalIndex));
		return;
	}
	if (distance == stride)
	{
		rva009C70D0BinkSse(rowA, destination,
			stride, stride, 8, 8, rva009C7380Weights(verticalIndex));
		return;
	}
	if (distance == stride - 1)
	{
		rva009C7140BinkSse(rowA - 1, destination,
			stride, rva009C7380Weights(horizontalIndex),
			rva009C7380Weights(verticalIndex));
		return;
	}
	if (distance == stride + 1)
		rva009C7140BinkSse(rowA, destination,
			stride, rva009C7380Weights(horizontalIndex),
			rva009C7380Weights(verticalIndex));
}
