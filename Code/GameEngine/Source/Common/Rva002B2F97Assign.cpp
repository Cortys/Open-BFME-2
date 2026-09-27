// cl: /O1 /MD
// ??4Rva002B2F97@@QAEAAV0@ABV0@@Z, retail 0x002B2F97, 52 bytes.
// Ref-counted holder assignment: if (this != &other) { if (other.m_ptr)
// inc ref at +0xB0; if (m_ptr) Release(m_ptr+0xAC); m_ptr = other.m_ptr; }
// return *this. Release is rowed fastcall 0x0007DEEF. Same shape as rowed
// Rva005EEFD2 assign at 0x005EEFD2 with larger displacements. Callers at
// 0x002B3018 0x002B3024 0x002B306A 0x002B4446 0x002B45DC 0x002B45F9.

struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);

struct Rva002B2F97Target
{
	char m_pad[0xAC];
	TargetRef00217D4C m_ac;
};

class Rva002B2F97
{
public:
	Rva002B2F97 &operator=(const Rva002B2F97 &other);

private:
	Rva002B2F97Target *m_ptr;
};

Rva002B2F97 &Rva002B2F97::operator=(const Rva002B2F97 &other)
{
	if (this != &other) {
		if (other.m_ptr)
			++other.m_ptr->m_ac.references;
		if (m_ptr)
			ReleaseTreeHintRef00217D4C(&m_ptr->m_ac);
		m_ptr = other.m_ptr;
	}
	return *this;
}
