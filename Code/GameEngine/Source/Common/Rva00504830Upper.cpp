// cl: /O1 /arch:SSE /DNDEBUG /MD /EHsc /Oi-
// ?Rva00504830UpperBound@@YAPAURva00504830Item@@PAU1@0PBMHH@Z @ 0x00504830 (64B):
// Upper-bound binary search over 16-byte records keyed by first float.
// len=(last-first); while len>0 { half=len>>1; mid=first+half;
// if mid->key<=*value { first=mid+1; len=len-half-1 } else len=half }
// return first. Evidence: sar 4/shl 4 stride 16; movss/comiss/jbe;
// caller at 0x0050490B pushes 5 args (first last value byte 0); unblocks 0x005048F9.
struct Rva00504830Item
{
	float key;
	char pad[12];
};

Rva00504830Item *__cdecl Rva00504830UpperBound(Rva00504830Item *first, Rva00504830Item *last, const float *value, int unused1, int unused2)
{
	int len = last - first;
	while (len > 0)
	{
		int half = len >> 1;
		Rva00504830Item *mid = first + half;
		if (mid->key > *value)
		{
			len = half;
		}
		else
		{
			first = mid + 1;
			len = len - half - 1;
		}
	}
	return first;
}
