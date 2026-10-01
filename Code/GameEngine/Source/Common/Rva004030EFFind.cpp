// cl: /O1 /MD /Oi-
// ?Rva004030EFFind@@YGHPBD@Z @0x004030EF 58B
// Index lookup in the pointer table g_00DC1B68: return the index of the
// first entry that strcmp-matches the argument, else 0. Evidence: the
// ret-4 single-arg shape with no ecx use (free __stdcall function); the
// E8 call at 0x00403108 targets the ji_006291c6 thunk whose TU body is
// { strcmp(); }; caller at 0x00404679. Plain extern strcmp (no dllimport)
// so the call routes through the thunk; /Oi- keeps it a call instead of
// inlined repz cmpsb.
extern "C" int __cdecl strcmp(const char *a, const char *b);

extern const char *g_00DC1B68[];

int __stdcall Rva004030EFFind(const char *s)
{
	int i;
	for (i = 0; g_00DC1B68[i] != 0; ++i)
		if (strcmp(g_00DC1B68[i], s) == 0)
			return i;
	return 0;
}
