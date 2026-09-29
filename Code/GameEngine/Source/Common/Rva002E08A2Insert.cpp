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
