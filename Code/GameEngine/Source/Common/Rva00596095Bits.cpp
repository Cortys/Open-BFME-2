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
// ?Rva005960FFGet@@YGHPAX@Z @0x005960FF 76B
// Bit-test predicate returning Int: loads inner at arg+4, checks 0x10E&0x40==0,
// 0x108 low byte &0x84==0, 0x11F&0x80==0, then 0x108&8!=0 or 0x113&4!=0 gives 1,
// else needs 0x109&0x40!=0 and rva004884B7(arg)==false for 1, else 0.
// Evidence: mov edx[esp+4] mov eax[edx+4] test chain plus call 0x4884B7; callers
// at 0x00596156 and 0x00596302 pass holder; __stdcall ret 4 with xor+inc.
class Object;
bool __cdecl rva004884B7(Object *obj);
Int __stdcall Rva005960FFGet(void *arg)
{
	void *inner = *(void **)((char *)arg + 4);
	if ((((unsigned char *)inner)[0x10E] & 0x40) == 0)
	{
		unsigned int flags = *(unsigned int *)((char *)inner + 0x108);
		if (((flags & 0x84) == 0) &&
			((((unsigned char *)inner)[0x11F] & 0x80) == 0) &&
			(((flags & 8) != 0) ||
				((((unsigned char *)inner)[0x113] & 4) != 0) ||
				(((flags & 0x4000) != 0) && !rva004884B7((Object *)arg))))
		{
			return 1;
		}
	}
	return 0;
}
