// ?Rva004582F3Find@@YAXPAUOwner004582F3@@@Z
// partial score=0.95 date=2026-09-29
// ?Rva004582F3Find@@YAXPAUOwner004582F3@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1
struct Slot14Obj004582F3
{
	virtual ~Slot14Obj004582F3() {}
	virtual void *d1(); virtual void *d2(); virtual void *d3(); virtual void *d4();
	virtual void *d5(); virtual void *d6(); virtual void *d7(); virtual void *d8();
	virtual void *d9(); virtual void *d10(); virtual void *d11(); virtual void *d12();
	virtual void *d13();
	virtual int slot14();
};
struct Elem004582F3
{
	char m_pad[0xC];
	Slot14Obj004582F3 m_objC;
};
struct Owner004582F3
{
	char m_pad[0x244];
	Elem004582F3 **m_244;
};
// ?Rva004582F3Find@@YAXPAUOwner004582F3@@@Z present-unmatched
void Rva004582F3Find(Owner004582F3 *owner)
{
	if (owner == 0)
		return;
	Elem004582F3 **arr = owner->m_244;
	while (*arr != 0) {
		if ((*arr)->m_objC.slot14() != 0)
			return;
		++arr;
	}
}
