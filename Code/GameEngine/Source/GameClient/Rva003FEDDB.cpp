// cl: /DNDEBUG /MD /O1
//
// ?Rva003FEDDBShowButtonFlash@@YAXPAPAX@Z @0x003FEDDB 52B. Free __cdecl UI
// firer (same pattern as Rva003FECFECreateButtonFlash): selects the label from
// *(pp) (+8) or the empty string, and invokes ShowButtonFlash with (1, s,
// 0, 0, 0, 0) through the rowed target/owner. Evidence: caller 0x005C6690;
// literals link; invoke declared to the landed UiCallbackFirers shape.
class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern Rva00222A8BTarget *TheRva00222A8BTarget;
extern void *TheRva00222A8BOwner;

void __cdecl Rva003FEDDBShowButtonFlash(void **pp)
{
	void *p = *pp;
	const char *s;
	if (p)
		s = (const char *)p + 8;
	else
		s = "";
	TheRva00222A8BTarget->invoke(TheRva00222A8BOwner, "ShowButtonFlash", 1, s, 0, 0, 0, 0);
}
