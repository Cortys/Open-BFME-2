// cl: /O1 /DNDEBUG /MD
//
// ?Rva004C6F77Median@@YAPAXPAX00P6A_N00@Z@Z @0x004C6F77 89B: median of three
// via __cdecl bool predicate (call esi, test al). Returns one of the three
// pointers. Evidence: callers at 0x00174705 and 0x004C7595 push 4 and
// caller-clean; predicate takes 2 pointers and returns bool in al; shape is
// the STL __median pivot helper used by the 0x004C755B binary search.
typedef bool (__cdecl *Rva004C6F77Pred)(void *a, void *b);

void *Rva004C6F77Median(void *a, void *b, void *c, Rva004C6F77Pred pred)
{
	if (pred(a, b)) {
		if (pred(b, c))
			return b;
		if (pred(a, c))
			return c;
		return a;
	} else {
		if (pred(a, c))
			return a;
		if (pred(b, c))
			return c;
		return b;
	}
}
