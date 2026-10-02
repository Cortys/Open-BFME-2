// cl: /O1 /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// ?Rva004349EFGet@@YAXPAI0@Z @0x004349EF 46B: rdtsc-seeded two-out table fetch sibling of 0x00434995; tables at 0x00DC8A9C/0x00DC8A8C; unblocks 0x00434E07 caller 0x00434E17.
extern unsigned g_00DC8A9C[];
// g_00DC8A8C: matched references place it at VA 0xdc8a8c; retail contents, sized to the
// 0x10-byte gap before the next known global there.
unsigned g_00DC8A8C[4] = {
	2723132174, 3752270798, 637426574, 397760014,
};
void __cdecl Rva004349EFGet(unsigned *a, unsigned *b)
{
	unsigned x = 0;
	__asm rdtsc
	__asm mov x, eax
	unsigned idx = (x & 3);
	*a = g_00DC8A9C[idx];
	*b = g_00DC8A8C[idx];
}
