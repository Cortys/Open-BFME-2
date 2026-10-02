// cl: /O1 /MD /GX-
// ?rva005173CB@Rva005173CB@@QAEPAU1@ABURva0051732A@@@Z @0x005173CB 45B
// Allocating setter: new 12B Rva00517345 via rowed ctor at 0x00517345
// forwarding the holder arg, store into +0, AddRef the new object at +4,
// return this. Rowed operator new at 0x0002FDA0. Caller 0x0051755C.
struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};

struct Rva0051732A
{
	TargetRef00217D4C *m_ptr;
};

struct Rva00517345
{
	void *m_vtbl;
	int m_04;
	TargetRef00217D4C *m_08;
	Rva00517345(const Rva0051732A &other);
};

void *__cdecl operator new(unsigned int size) throw();

struct Rva005173CB
{
	Rva00517345 *m_ptr;
	Rva005173CB *rva005173CB(const Rva0051732A &arg);
};

Rva005173CB *Rva005173CB::rva005173CB(const Rva0051732A &arg)
{
	Rva00517345 *p = new Rva00517345(arg);
	m_ptr = p;
	if (p)
		++p->m_04;
	return this;
}

// ?rva0044BEE6@Rva0044BEE6@@QAEPAU1@ABURva0051732A@@@Z, retail 0x0044BEE6, 45 bytes:
// the same setter over the rowed Rva0044BDA2 holder constructor (a twin of
// Rva00517345's that installs its own vtable), the only difference from
// rva005173CB's bytes.
struct Rva0044BDA2
{
	void *m_vtbl;
	int m_04;
	TargetRef00217D4C *m_08;
	Rva0044BDA2(const Rva0051732A &other);
};
struct Rva0044BEE6
{
	Rva0044BDA2 *m_ptr;
	Rva0044BEE6 *rva0044BEE6(const Rva0051732A &arg);
};
Rva0044BEE6 *Rva0044BEE6::rva0044BEE6(const Rva0051732A &arg)
{
	Rva0044BDA2 *p = new Rva0044BDA2(arg);
	m_ptr = p;
	if (p)
		++p->m_04;
	return this;
}
