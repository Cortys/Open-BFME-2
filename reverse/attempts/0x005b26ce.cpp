// ?Rva005B26CECompare@@YGEPAPAX0@Z
// partial score=0.91 date=2026-09-28
// ?Rva005B26CECompare@@YGEPAPAX0@Z
// partial score=0.91 date=2026-09-28
// cl: /O1 /G7 /DNDEBUG /MD
unsigned char __stdcall Rva005B26CECompare(void **a, void **b)
{
	for (int i = 0; i < 4; ++i) {
		void *x = a[i];
		void *y = b[i];
		if (x != 0) {
			if (y == 0)
				return 1;
		} else {
			if (y != 0)
				return 0;
		}
	}
	return 1;
}
