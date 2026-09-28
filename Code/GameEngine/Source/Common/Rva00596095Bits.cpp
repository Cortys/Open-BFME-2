// cl: /O1 /DNDEBUG /MD
// ?Rva00596095Get@@YGHPAX@Z, retail 0x00596095, 44 bytes.
// Bit-test predicate returning Int: loads inner pointer at arg+4, requires
// byte at inner+0x10E &0x40 ==0, byte at inner+0x108 &0x80 ==0, byte at
// inner+0x11F &0x80 !=0, in that order for the byte-exact test chain.
// Returns 1 via xor+inc else 0 (__stdcall gives ret 4 with single ret via jmp).
// Callers (2 at 0x005960C5 etc.) pass a holder; unblocks 2 with 1 ready.
// Prev is deleting dtor, next is derived ctor; /O1 gives xor+inc and and/or idioms.
typedef int Int;
Int __stdcall Rva00596095Get(void *arg)
{
	void *inner = *(void **)((char *)arg + 4);
	if ((((unsigned char *)inner)[0x10E] & 0x40) == 0 &&
		(((unsigned char *)inner)[0x108] & 0x80) == 0 &&
		(((unsigned char *)inner)[0x11F] & 0x80) != 0)
	{
		return 1;
	}
	return 0;
}
