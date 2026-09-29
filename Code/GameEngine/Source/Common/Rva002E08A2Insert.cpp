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
