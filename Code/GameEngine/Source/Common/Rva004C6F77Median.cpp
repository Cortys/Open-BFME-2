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

struct Rva004C6FD0Val
{
	int m0;
	int m4;
};

// ?Rva004C6FD0Insert@@YAXPAXURva004C6FD0Val@@P6A_N00@Z@Z @0x004C6FD0 57B:
// linear insert of 8-byte value via __cdecl bool predicate (call [ebp+0x14]).
// Shifts [pos-8..] while pred(&value, elem) then stores value. Evidence:
// caller 0x004C70D4 pushes 4 and caller-cleans; predicate takes 2 pointers.
void Rva004C6FD0Insert(void *pos, Rva004C6FD0Val value, Rva004C6F77Pred pred)
{
	char *edi = (char *)pos;
	char *esi = edi - 8;
	while (pred(&value, esi)) {
		((Rva004C6FD0Val *)edi)->m0 = ((Rva004C6FD0Val *)esi)->m0;
		((Rva004C6FD0Val *)edi)->m4 = ((Rva004C6FD0Val *)esi)->m4;
		edi = esi;
		esi -= 8;
	}
	((Rva004C6FD0Val *)edi)->m0 = value.m0;
	((Rva004C6FD0Val *)edi)->m4 = value.m4;
}
