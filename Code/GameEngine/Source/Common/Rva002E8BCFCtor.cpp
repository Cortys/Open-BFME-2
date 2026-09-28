// ??0Rva002E8BCF@@QAE@PBURva002E8BCFSrc@@_NH1@Z @0x002E8BCF 41B
// Converting ctor over an unidentified 0x10-byte value type: dword at +0x0
// from src+0x10 plus bool/int/bool at +0x4/+0x5/+0x8 plus byte from src+0x15
// at +0xC. Returns this (mov eax ecx) which selects the retail register
// allocation over the void variant. Callers are enclosing ctors that return
// this via mov eax esi: 0x002E9ACC lea ecx esi+0xC src ebx 0x002E9D09 lea
// ecx ebp-0x10 src esi+0x18 0x002EAB6F lea ecx esi+0x4 src ebp+0xC 0x002ECC0D
// lea ecx ebp-0x14 src ebx. Dest size 0x10 confirmed by next member at +0x1C
// in 0x002E9ACC and +0x14 in 0x002EAB6F. No vtable stores so non-virtual.
// Defaults match the frameless shape (prev Disp8PtrChaseDwordGetters.cpp).
struct Rva002E8BCFSrc
{
	char _00[0x10];
	int m10;
	char _14;
	bool m15;
};
class Rva002E8BCF
{
public:
	Rva002E8BCF(Rva002E8BCFSrc const *src, bool a, int b, bool c);
	int m0;
	bool m4;
	bool m5;
	int m8;
	bool mC;
};
Rva002E8BCF::Rva002E8BCF(Rva002E8BCFSrc const *src, bool a, int b, bool c)
{
	m0 = src->m10;
	m4 = a;
	m5 = c;
	m8 = b;
	mC = src->m15;
}
