// cl: /O1 /MD
// ?Rva002B29BDFire@@YAXXZ, retail 0x002B29BD, 27 bytes.
// Fires HideEndGame UI callback through the global target: invoke with
// owner (void*)13, name "HideEndGame", rest 0. Same recipe as the landed
// UiCallbackFirers. Callers at 0x002B8922 0x002B99F3. Honest address name.
class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};
// Matched DIR32 references place this Apt callback target at VA 0x00DFE4CC.
// The retail bytes there are zero, so the pointer starts null.
Rva00222A8BTarget *TheRva00222A8BTarget = 0;
void __cdecl Rva002B29BDFire()
{
	TheRva00222A8BTarget->invoke((void *)13, "HideEndGame", 0, 0, 0, 0, 0, 0);
}
