// cl: /O2 /MD
//
// ?rva006E0D40@Rva006E0D40@@QAEXXZ, retail 0x006E0D40, 22 bytes.
// Reference-count release: decrement the 16-bit field at +0x5C and, when it
// reaches zero, call the __cdecl teardown at 0x006CE1C0 with 0. Evidence: the
// caller at 0x006FAC33 (on the pointer at +0x24 of an Apt value) and the
// caller at 0x00709E2D both load the pointer into ecx and call this after a
// vtable-slot-1 release; the 0xffff dword test is the bitfield zero test.
// The owning class name is not recovered, so it stays address-derived.

void rva006CE1C0(int arg);

class Rva006E0D40
{
public:
	void rva006E0D40();

private:
	char m_pad[0x5C];
	unsigned int m_5C : 16;
};

void Rva006E0D40::rva006E0D40()
{
	if (--m_5C == 0)
		rva006CE1C0(0);
}
