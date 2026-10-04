// ?init@Rva006E3CF0@@QAEPAV1@XZ
// partial score=0.96 date=2026-10-04
// ?init@Rva006E3CF0@@QAEPAV1@XZ
// cl: /O1 /MD
//
// Apt-neighbourhood block-init at 0x006E3CF0 (86 bytes), page of
// Rva006E3C80.cpp.
//
// Zero-initializes the simple members (+0x00..+0x0C), sets the mode dword at
// +0x18 to 6, then allocates a 0x18-byte block from the chain-block allocator at
// VA 0x00E176E8 through the rowed Rva006DB160::allocBlock (0x006DB160).  A null
// block raises the shared Apt assert triple (0x00E17734 call target,
// 0x00DDC01C break flag, __debugbreak), exactly the shape Rva006E3C80.cpp uses.
// The global addresses are absolute DIR32 operands the gate masks; the class and
// its identity are address-named.
//
// Flags: /O1 is load-bearing.  Under /O2 the two exits (the block!=0 jump and
// the break-flag test) each get their own copy of `mov eax,esi`, so the
// epilogue duplicates and the body grows to 91 bytes.  /O1 keeps one shared
// epilogue, which is retail's shape.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class Rva006DB160
{
public:
	void *allocBlock(int size);
};

// 0x00E176E8, the chain-block allocator singleton.
Rva006DB160 *g_pChainBlockAllocator;

class Rva006E3CF0
{
public:
	Rva006E3CF0 *init();

private:
	int m00;
	int m04;
	int m08;
	int m0C;
	int m10;	// not touched
	int m14;
	int m18;
	void *m1C;
};

Rva006E3CF0 *Rva006E3CF0::init()
{
	m00 = 0;
	m04 = 0;
	m08 = 0;
	m0C = 0;
	m14 = 0;
	m18 = 6;
	m1C = 0;

	void *block = g_pChainBlockAllocator->allocBlock(0x18);
	m1C = block;

	if (block == 0) {
		g_bfmeAptAssertAtE17734("block != NULL", "AptCIH.h", 0x46);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	return this;
}