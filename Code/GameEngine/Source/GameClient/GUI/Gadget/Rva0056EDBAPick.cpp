// cl: /O1 /DNDEBUG /MD
// ?Rva0056EDBAPick@@YAXPAH0@Z @0x0056EDBA 46B
// Random pair pick via rdtsc low bits into two parallel int[4] tables.
// Inline asm for rdtsc: MSVC 7.1 has no __rdtsc intrinsic, so __asm is the
// only way to emit 0F 31; the surrounding movs are plain C assignments.
// Unlocks 0x0056F32B 0x0056F2A5.
// Evidence: and [ebp-4]0 rdtsc mov [ebp-4]eax and-3 shl-2 two indexed loads.
extern int g_Va00DD2A5C[4];
extern int g_Va00DD2A6C[4];
void __cdecl Rva0056EDBAPick(int *out1, int *out2);
void __cdecl Rva0056EDBAPick(int *out1, int *out2)
{
	unsigned int t = 0;
	__asm {
		rdtsc
		mov t, eax
	}
	unsigned int i = t & 3;
	*out1 = g_Va00DD2A6C[i];
	*out2 = g_Va00DD2A5C[i];
}
