// ??0Rva00506B1B@@QAE@XZ @0x00506B1B 13B: base/member ctor storing vtable
// 0x00C63F9C at [this] then byte 0 at +4. Called by 8 bodies (e.g. 0x004E9B46
// passes ecx=this as base, 0x00597693 passes ecx=esi+0xC as member); next row
// 0x00506B28 setter stores the same vtable immediate. Honest address-derived
// name; manual vtable (no virtuals) for exact store order like Rva000D1930.

extern int Gen00C63F9C;

class Rva00506B1B
{
public:
	Rva00506B1B();
	int *m_vtable;
	unsigned char m_04;
};

Rva00506B1B::Rva00506B1B()
{
	m_vtable = &Gen00C63F9C;
	m_04 = 0;
}
