// cl: /O1
//
// ?Rva002E08A2Insert@@YAXPAPAXPAX1@Z @0x002E08A2 37B.
// Sorted pointer-array insert: shifts slots backwards while the new element's
// key at +0xC exceeds the scanned element's key at +0xC, then stores it.
// Evidence: callers 0x002E0E7C (array sweep) and 0x002E1EB7 (vector insert
// with __copy_trivial_backward fast path); prev/next share /O1.
void Rva002E08A2Insert(void **pos, void *val, void *unused)
{
	void **src = pos - 1;
	while (((int *)val)[3] > ((int *)(*src))[3]) {
		*pos = *src;
		pos = src;
		--src;
	}
	*pos = val;
}

// ?Rva002E0E7CReinsert@@YAXPAPAX0PAX1@Z @0x002E0E7C 33B.
// Array re-sort sweep: re-inserts each slot from begin to end via
// Rva002E08A2Insert passing the extra arg through.
// Evidence: sole caller 0x002E180D; callee rowed 0x002E08A2.
void Rva002E0E7CReinsert(void **begin, void **end, void *unused, void *extra)
{
	for (void **p = begin; p != end; ++p)
		Rva002E08A2Insert(p, *p, extra);
}

// ?Rva002E180DReinsert@@YAXPAPAX0PAX@Z @0x002E180D 23B.
// Wrapper passing (begin end 0 extra) through to Rva002E0E7CReinsert.
// Evidence: sole caller 0x002E2313; callee rowed 0x002E0E7C.
void Rva002E180DReinsert(void **begin, void **end, void *extra)
{
	Rva002E0E7CReinsert(begin, end, 0, extra);
}

void **Rva002E0864Median(void **a, void **b, void **c)
{
	if (((int *)(*a))[3] > ((int *)(*b))[3])
	{
		if (((int *)(*b))[3] > ((int *)(*c))[3])
			return b;
		if (((int *)(*a))[3] <= ((int *)(*c))[3])
			return a;
		return c;
	}
	else
	{
		if (((int *)(*a))[3] > ((int *)(*c))[3])
			return a;
		if (((int *)(*b))[3] > ((int *)(*c))[3])
			return c;
		return b;
	}
}

// ?Rva002E08C7SiftUp@@YAXPAPAXHHPAX@Z @0x002E08C7 63B.
// Heap sift-up over void* elements keyed at +0xC (min-heap): bubbles pivot
// up from idx while the parent key exceeds it, stopping at top or a parent
// key at or below it. Sibling of the median/insert family above (same +0xC
// key, same /O1); caller at 0x002E0E9D is the adjust-heap that tail-calls
// this with 5 pushes like the 0x003BD4E8 precedent. Unlock lane, unblocks
// 0x002E0E9D.
void Rva002E08C7SiftUp(void **base, int idx, int top, void *pivot)
{
	int parent = (idx - 1) / 2;
	while (idx > top) {
		void *p = base[parent];
		if (((int *)p)[3] <= ((int *)pivot)[3])
			break;
		base[idx] = p;
		idx = parent;
		parent = (parent - 1) / 2;
	}
	base[idx] = pivot;
}
