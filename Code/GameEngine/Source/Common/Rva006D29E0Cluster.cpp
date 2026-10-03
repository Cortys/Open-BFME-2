// cl: /O2 /DNDEBUG /MD
// ?allocBlock@Rva006D2A60@@QAEPAXH@Z @ 0x006D29E0 (127B). Retail's class is the
// AptValueGCAllocator (assert literals name AptValueGCAllocator.cpp/.h); the
// address-derived class name matches the already-published pin at this RVA.
//
// Allocates through the pool's own base allocator (0x006DB160, rowed as
// Rva006DB160::allocBlock), marks the new value's mbIsAllocated bit false and
// then true, asserting the bit after each step. The mode byte at VA
// 0x00E177E0 selects which word of the value the setter at 0x006D28D0
// toggles; the asserts read +4, so the bitfield sits at +4.
//
// The base call keeps ecx == this (Rva006DB160 is the offset-0 base), which is
// why retail emits no `mov ecx` before it. The setter 0x006D28D0 is declared
// here and pinned address-derived.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

extern unsigned char g_bfmeAptGCAllocModeAtE177E0;
// g_bfmeAptGCAllocModeAtE177E0: the mode byte read at VA 0xe177e0 (zero-filled .bss).

class Rva006DB160
{
public:
	void *allocBlock(int blockSize);

	int m_pad0;
	struct ValueBitfield
	{
		unsigned int mbIsAllocated : 1;
		unsigned int mRest : 31;
	} mValueBitfield;
};

class Rva006D2A60 : public Rva006DB160
{
public:
	void *allocBlock(int nBytes);
	void rva006D28D0(int mode, bool value);
};

void *Rva006D2A60::allocBlock(int nBytes)
{
	Rva006D2A60 *p = (Rva006D2A60 *)Rva006DB160::allocBlock(nBytes);
	p->rva006D28D0(g_bfmeAptGCAllocModeAtE177E0, false);
	if (!(p->mValueBitfield.mbIsAllocated == false)) {
		g_bfmeAptAssertAtE17734("pValue->mValueBitfield.mbIsAllocated == false",
			"C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptValueGCAllocator.cpp", 0x6F);
		if (g_bfmeAptBreakOnAssertAtDDC01C) { __asm int 3 }
	}
	p->rva006D28D0(g_bfmeAptGCAllocModeAtE177E0, true);
	if (!(p->mValueBitfield.mbIsAllocated == true)) {
		g_bfmeAptAssertAtE17734("pValue->mValueBitfield.mbIsAllocated == true",
			"C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptValueGCAllocator.cpp", 0x73);
		if (g_bfmeAptBreakOnAssertAtDDC01C) { __asm int 3 }
	}
	return p;
}
