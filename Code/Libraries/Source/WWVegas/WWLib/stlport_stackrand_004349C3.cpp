// cl: /O1 /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// ?Rva004349C3Get@@YAXPAI0@Z @0x004349C3 44B: sibling of 0x00434969 same stack-seeded two-out shape; tables at 0x00DC8A7C/0x00DC8A6C; unblocks 0x00434D7A caller 0x00434D8A.
extern unsigned g_00DC8A7C[];
extern unsigned g_00DC8A6C[];
void __cdecl Rva004349C3Get(unsigned *a, unsigned *b)
{
	// inline asm is a proven codegen blocker here: plain C++ x=(unsigned)&x emits
	// lea eax,[ebp-4]; mov [ebp-4],eax (volatile) or lea eax,[ebp+8] (plain),
	// never retail's mov [ebp-4],esp. __asm mov x,esp emits it byte-exact (see 0x00434969).
	unsigned x = 0;
	__asm mov x, esp
	unsigned idx = (x & 3);
	*a = g_00DC8A7C[idx];
	*b = g_00DC8A6C[idx];
}
