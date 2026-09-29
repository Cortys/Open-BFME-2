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

// ?Rva003BD4E8SiftUp@@YAXPAPAURva003BD485Keyed@@HHPAU1@@Z @0x003BD4E8 63B.
// Heap sift-up over the same keyed array: bubbles pivot up from idx while
// the parent key is below the pivot key, stopping at top or a parent key at
// or above it. Sibling of the median picker above (same +0x20 key, same
// quicksort/heap family); caller at 0x003BE5A1. Unlock lane, makes
// 0x003BE553 ready.
void Rva003BD4E8SiftUp(Rva003BD485Keyed **base, int idx, int top, Rva003BD485Keyed *pivot)
{
	int parent = (idx - 1) / 2;
	while (idx > top)
	{
		Rva003BD485Keyed *p = base[parent];
		if (p->m_key >= pivot->m_key)
			break;
		base[idx] = p;
		idx = parent;
		parent = (parent - 1) / 2;
	}
	base[idx] = pivot;
}

// ?Rva003BE553AdjustHeap@@YAXPAPAURva003BD485Keyed@@HHPAU1@H@Z @0x003BE553 90B.
// Heap adjust over the same keyed array: sifts the hole down picking the
// larger child, drops the last slot in when the child runs even with len,
// then tail-calls the 5-push sift-up at 0x003BD4E8. Chain lane on 0x003BD4E8;
// callers 0x003C3AC7/0x003C3AF0 push 5 args (cdecl, ret with caller cleanup).
void Rva003BD4E8SiftUp(Rva003BD485Keyed **base, int idx, int top, Rva003BD485Keyed *pivot, int extra);

void Rva003BE553AdjustHeap(Rva003BD485Keyed **base, int hole, int len, Rva003BD485Keyed *value, int extra)
{
	int top = hole;
	int child = hole * 2 + 2;
	while (child < len)
	{
		if (base[child]->m_key < base[child - 1]->m_key)
			--child;
		base[hole] = base[child];
		hole = child;
		child = child * 2 + 2;
	}
	if (child == len)
	{
		base[hole] = base[child - 1];
		hole = child - 1;
	}
	Rva003BD4E8SiftUp(base, hole, top, value, extra);
}
