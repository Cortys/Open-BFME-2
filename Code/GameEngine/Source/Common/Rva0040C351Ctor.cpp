// cl: /O1 /DNDEBUG /MD
// ??0Rva0040C351@@QAE@XZ @0x0040C351 (77B).
// Derived of rowed Rva0037DF2C ctor 0x0037DF2C (same this, no offset) with own
// vtable 0x00C3944C at +0x0 overwriting base vtable, member at +0xAC with base
// vtable 0x00BC6F20 plus int 0 plus derived vtable 0x00C3945C via inline base
// plus int init plus body derived store (preserves dead base store as mixed
// init versus body paths), ints 0 at +0xB4 +0xB8 +0xBC +0xC0 plus bytes 0 at
// +0xC4 +0xC5. Chain of 0x0037DF2C which this session landed. Callers at
// 0x003F22B6 0x0040EFBB 0x0040F09B 0x0040F149 0x0040F24D 0x0040F721.
class Rva0037DF2C
{
public:
	Rva0037DF2C();
private:
	char m_pad[0xac];
};
struct MemberAC
{
	MemberAC() : m_vtable((void *)0x00BC6F20), m_04(0) {}
	void *m_vtable;
	int m_04;
};
class Rva0040C351 : public Rva0037DF2C
{
public:
	Rva0040C351();
	void rva0040C5FA(class INI *ini);
	void rva0040C430(const class Rva004E0632 *a);
private:
	MemberAC m_ac;
	int m_b4;
	int m_b8;
	int m_bc;
	int m_c0;
	unsigned char m_c4;
	unsigned char m_c5;
};
struct FieldParse;
extern const FieldParse g_00C39474;
extern const FieldParse g_00C18D18;
class MultiIniFieldParse
{
public:
	MultiIniFieldParse();
	void add(const FieldParse *table, unsigned int x);
private:
	char m_pad[0x84];
};
class INI
{
public:
	void initFromINIMulti(void *what, const MultiIniFieldParse &parse);
};
class Rva004E0632
{
public:
	int rva004E0632() const;
};
struct Rva0040C430Ret
{
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void slotC(void *p);
};
Rva0040C351::Rva0040C351() : Rva0037DF2C()
{
	MemberAC *p = &m_ac;
	p->m_vtable = (void *)0x00C3945C;
	*(unsigned int *)this = 0x00C3944C;
	m_b4 = 0;
	m_b8 = 0;
	m_bc = 0;
	m_c0 = 0;
	m_c4 = 0;
	m_c5 = 0;
}

void Rva0040C351::rva0040C5FA(INI *ini)
{
	MultiIniFieldParse parse;
	parse.add(&g_00C39474, 0);
	parse.add(&g_00C18D18, 0);
	ini->initFromINIMulti(this, parse);
}

void Rva0040C351::rva0040C430(const Rva004E0632 *a)
{
	if (m_bc != 0)
		return;
	m_bc = *(const int *)((const char *)a + 0x18);
	int raw = a->rva004E0632();
	if (raw == 0)
		return;
	((Rva0040C430Ret *)raw)->slotC(this);
}
