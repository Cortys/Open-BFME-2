// Open-BFME5 conversion of the codec's second bounding-value table setup.

extern "C" void * __cdecl memset(void *, int, unsigned int);
#pragma intrinsic(memset)

struct Rva009ACBA0Context
{
	unsigned char m_pad0[0x3C];
	int *m_boundingBase;
};

int *Rva009ACBA0SetupBounding(Rva009ACBA0Context *ctx, int flimit)
{
	int *base = ctx->m_boundingBase;
	int *bounding = base + 256;
	int i;

	memset(base, 0, 512 * sizeof(int));

	for (i = 0; i < flimit; i++) {
		bounding[-flimit - i] = i - flimit;
		bounding[-i] = -i;
		bounding[i] = i;
		bounding[flimit + i] = flimit - i;
	}

	return bounding;
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?Rva009ACBA0SetupBounding@@YAPAHPAURva009ACC40State@@H@Z=?Rva009ACBA0SetupBounding@@YAPAHPAURva009ACBA0Context@@H@Z")
