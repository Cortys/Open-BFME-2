// cl: /O1
// ?Rva003BD485Median@@YAPAPAURva003BD485Keyed@@PAPAU1@00@Z @0x003BD485 62B.
// Median-of-three pivot picker (retail 0x003BD485, 62 B): each arg is a
// pointer to a keyed element whose sort key sits at +0x20 through a second
// indirection; returns whichever arg carries the median key. Caller at
// 0x003CA2DF passes array slots (quicksort-style mid computation with sar
// halves just above the call). Class layout is honest-address only; the
// identity of the sorted type is unproven. Unlock lane.
struct Rva003BD485Keyed
{
	char m_pad[0x20];
	int m_key;
};

Rva003BD485Keyed **Rva003BD485Median(Rva003BD485Keyed **a, Rva003BD485Keyed **b, Rva003BD485Keyed **c)
{
	int ka = (*a)->m_key;
	int kb = (*b)->m_key;
	if (ka < kb)
	{
		int kc = (*c)->m_key;
		if (kb < kc)
			return b;
		if (ka >= kc)
			return a;
		return c;
	}
	int kc = (*c)->m_key;
	if (ka < kc)
		return a;
	if (kb < kc)
		return c;
	return b;
}
