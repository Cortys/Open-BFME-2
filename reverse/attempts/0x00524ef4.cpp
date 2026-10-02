// ?Rva00524EF4AptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2@Z
// partial score=0.95 date=2026-10-02
// cl: /O1 /MD
// ?Rva00524EF4AptCall@@YAHPAVRva00222A8BTarget@@PAXPBD2@Z @0x00524EF4 30B
// Free AptCall wrapper: forwards Target as this plus 3 stack args plus six zeros to thiscall 0x00222C12 which forwards to rowed stdcall 0x00222B19.
// Evidence: callers 0x00528389 0x0057A805 pass Target plus 3 args plus FadeOut/FadeIn, mov ecx proves thiscall inner.
class Rva00222A8BTarget
{
public:
	int rva00222C12(void *level, const char *prefix, const char *function, int argc, const char *a0, void *a1, void *a2, void *a3, void *a4);
};
int __cdecl Rva00524EF4AptCall(Rva00222A8BTarget *t, void *a1, const char *a2, const char *a3)
{
	return t->rva00222C12(a1, a2, a3, 0, 0, 0, 0, 0, 0);
}
