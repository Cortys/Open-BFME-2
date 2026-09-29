// ?rva002A9DB8@Rva002A9DB8@@QAEPAXH@Z
// partial score=0.96 date=2026-09-29
// ?rva002A9DB8@Rva002A9DB8@@QAEPAXH@Z
// partial score=0.96 date=2026-09-29
// cl: /O1 /MD
//
// ?rva002A9DB8@Rva002A9DB8@@QAEPAXH@Z retail 0x002A9DB8 23B
// Void chase with virtual tail call: if the pointer at +0x2DC is null
// fall off the end (ret 4 with address residue) else tail-jump to its
// vtable slot 15 returning the slot value. Takes one ignored int arg
// (ret 4). Evidence: caller 0x003BCB6B pushes computed int plus
// sibling 0x002A9BBD slot 12 precedent.
class Rva002A9DB8Target
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void *v15();
};

struct Rva002A9DB8Holder
{
	Rva002A9DB8Target *m_target;
};

class Rva002A9DB8
{
public:
	void *rva002A9DB8(int unused);
private:
	unsigned char m_pad[0x2DC];
	Rva002A9DB8Holder m_holder;
};

void *Rva002A9DB8::rva002A9DB8(int unused)
{
	(void)unused;
	if (m_holder.m_target != 0)
		return m_holder.m_target->v15();
}
