// ?Rva005E71DECopy@@YAPAPAXPAPAX00PAX@Z
// partial score=0.95 date=2026-09-28
// ?Rva005E71DECopy@@YAPAPAXPAPAX00PAX@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva005E71DECopy@@YAPAPAXPAPAX00PAX@Z, retail 0x005E71DE, 38 bytes.
// Copy looping Rva005E71C6Assign at 0x005E71C6. Evidence: callers at
// 0x005E7247 0x005E81CC 0x005E8217 pass 4 words; body ignores the 4th.

void Rva005E71C6Assign(void **dest, void **source);

// ?Rva005E71DECopy@@YAPAPAXPAPAX00PAX@Z present-unmatched
void **Rva005E71DECopy(void **first, void **last, void **dest, void *unused)
{
	void **f = first;
	void **d = dest;
	for (; f != last; ++d) {
		Rva005E71C6Assign(d, f);
		++f;
	}
	return d;
}
