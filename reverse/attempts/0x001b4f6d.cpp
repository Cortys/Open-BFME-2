// ?rva001B4F6D@Rva001B4F6D@@QAEXXZ
// partial score=0.93 date=2026-10-04
// cl: /O1 /MD
//
// ?rva001B4F6D@Rva001B4F6D@@QAEXXZ @0x001B4F6D 30B. Reverse loop over an
// 8-byte-entry array ([this+0]=begin, [this+4]=end): walks from end-8 down
// to begin, calling virtual slot 9 (call [eax+0x24]) on each entry's +0
// object, stepping -8 bytes.
// Evidence: ret with no N proves __thiscall with no stack args; ecx read
// before write proves thiscall; stride 8 matches Rva001B4F8B entry shape;
// neighbours share // cl: /O1 /MD.

struct Rva001B4F6DTarget
{
	virtual void vf0();
	virtual void vf1();
	virtual void vf2();
	virtual void vf3();
	virtual void vf4();
	virtual void vf5();
	virtual void vf6();
	virtual void vf7();
	virtual void vf8();
	virtual void vf9();
};

struct Rva001B4F6DEntry
{
	void *m_obj; // +0 dereferenced for the virtual call
	int m_pad; // +4 keeps the 8-byte stride retail steps
};

class Rva001B4F6D
{
public:
	void rva001B4F6D();

private:
	Rva001B4F6DEntry *m_begin; // +0
	Rva001B4F6DEntry *m_end; // +4
};

// ?rva001B4F6D@Rva001B4F6D@@QAEXXZ present-unmatched
void Rva001B4F6D::rva001B4F6D()
{
	Rva001B4F6DEntry *p = m_end;
	if (p == m_begin)
		return;
	Rva001B4F6DEntry *q;
	for (;;) {
		q = p - 1;
		((Rva001B4F6DTarget *)q->m_obj)->vf9();
		p = q;
		if (p == m_begin)
			break;
	}
}
