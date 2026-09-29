// cl: /O1 /DNDEBUG /MD
// ?Rva003F10D0Pick@@YAXPAH0@Z @0x003F10D0 44B
// Stack-pick pair via ebp low bits into two parallel int[4] tables.
// Inline asm for mov t,ebp: plain C cannot read the frame pointer, so __asm
// is the only way; surrounding movs are plain C assignments.
// Sibling of Rva0056ED34Pick 44B (mov t,esp variant) per
// Rva0056EDBAPick.cpp precedent; unlocks 0x003F17D6 141B sibling of
// Rva0056EF65 141B obfuscated init.
// Evidence: and [ebp-4]0 mov [ebp-4]ebp and-3 shl-2 two indexed loads
// at 0xDC15EC/0xDC15DC.
extern int g_Va00DC15EC[4];
extern int g_Va00DC15DC[4];
void __cdecl Rva003F10D0Pick(int *out1, int *out2);
void __cdecl Rva003F10D0Pick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		mov t, ebp
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DC15EC[i];
	*out2 = g_Va00DC15DC[i];
}
