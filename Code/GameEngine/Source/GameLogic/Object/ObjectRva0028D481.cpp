// cl: /O1 /MD
//
// ?rva0028D481@Object@@QBEHXZ @0x0028D481 (16B).
// Leaf Object reader: returns bit 7 of the dword at template+0x108
// ((template->field108 >> 7) & 1). Layout from retail: this+0x4 is the
// template pointer (same slot Object_isAbleToAttack.cpp documents),
// field at +0x108 is an unsigned dword so retail emits logical shr.
// Callers at 0x00261250 + 0x002612D5 + 0x005399F1. No donor name claimed,
// so the name keeps the address token with the proven Object owner.

struct Rva0028D481Template
{
	unsigned char m_pad[0x108];
	unsigned int m_field108;
};

class Object
{
public:
	int rva0028D481() const;

private:
	char m_pad00[4];
	Rva0028D481Template *m_template;
};

int Object::rva0028D481() const
{
	return (m_template->m_field108 >> 7) & 1;
}
