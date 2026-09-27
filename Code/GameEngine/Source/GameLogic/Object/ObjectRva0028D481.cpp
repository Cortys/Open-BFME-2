// cl: /O1 /MD
//
// ?rva0028D481@Object@@QBEHXZ @0x0028D481 (16B).
// Leaf Object reader: returns bit 7 of the dword at template+0x108
// ((template->field108 >> 7) & 1). Layout from retail: this+0x4 is the
// template pointer (same slot Object_isAbleToAttack.cpp documents),
// field at +0x108 is an unsigned dword so retail emits logical shr.
// Callers at 0x00261250 + 0x002612D5 + 0x005399F1. No donor name claimed,
// so the name keeps the address token with the proven Object owner.
//
// ?rva0028D282@Object@@QAEXPAX@Z @0x0028D282 (32B).
// Guarded forward to the helper at this+0x4C4: forwards the single void*
// arg to Gen_008F7B50::bfmeForward when the helper is present and the
// template byte at +0x10E lacks 0x20. Retail shape is mov eax,ecx plus
// helper null test plus template flag test plus tail jmp. Caller at
// 0x003958D5. Same honest Object naming as its file sibling.

struct Rva0028D481Template
{
	unsigned char m_pad[0x108];
	unsigned int m_field108;
	unsigned char m_pad10C[2];
	unsigned char m_byte10E;
};

class Gen_008F7B50
{
public:
	void bfmeForward(void *a0);
};

class Object
{
public:
	int rva0028D481() const;
	void rva0028D282(void *a0);

private:
	char m_pad00[4];
	Rva0028D481Template *m_template;
	char m_pad08[0x4C4 - 8];
	Gen_008F7B50 *m_helper;
};

int Object::rva0028D481() const
{
	return (m_template->m_field108 >> 7) & 1;
}

void Object::rva0028D282(void *a0)
{
	Gen_008F7B50 *helper = m_helper;
	if (helper != 0 && ((m_template->m_byte10E & 0x20) == 0))
		helper->bfmeForward(a0);
}
