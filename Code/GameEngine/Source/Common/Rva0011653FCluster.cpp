// cl: /DNDEBUG /MD /EHsc /O1 /G7
//
// ??_GRva001164F5@@UAEPAXI@Z, retail 0x0011653F, 28 bytes.
//
// Scalar deleting destructor of the class whose virtual destructor sits at
// 0x001164F5 (74B, same neighbourhood; Ghidra start FUN_005164f5). The class
// is the one whose constructor at 0x001164D3 stores vtable 0x00BCFB38 and
// zeroes the +4 flag that the rowed method ?rva001164AA@Rva001164AA@@QAEXXZ
// (0x001164AA) tests; the destructor restores base vtable 0x00BC5128.
// Target shape is the /O1 28B flag-test form:
//   push esi / mov esi,ecx / call <dtor> / test byte [esp+8],1 / je /
//   push esi / call ??3 0x0002FD60 / pop ecx / mov eax,esi / pop esi / ret 4.
// The class name is address-derived from the destructor it calls; its true
// identity is not proven. The ephemeral local destructor below only forces
// the ??_G emission, and the ledger pin at 0x001164F5 resolves the call.

class Rva001164F5
{
public:
	__declspec(noinline) virtual ~Rva001164F5();
};

// ??1Rva001164F5@@UAE@XZ present-unmatched
Rva001164F5::~Rva001164F5() {}

void Rva001164F5_ScalarDeletingDtor(Rva001164F5 *p)
{
	delete p;
}
