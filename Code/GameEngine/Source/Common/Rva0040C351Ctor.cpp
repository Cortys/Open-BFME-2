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
private:
	MemberAC m_ac;
	int m_b4;
	int m_b8;
	int m_bc;
	int m_c0;
	unsigned char m_c4;
	unsigned char m_c5;
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
