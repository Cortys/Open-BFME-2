// cl: /O1 /arch:SSE /DNDEBUG /MD
// ?rva0049D526@Rva0049D526@@QAEXPAX@Z retail 0x0049D526 89B
// List push-front of new entry plus WeaponTemplateSetHead copy check for
// flag bits at +0xD1/+0x114. Head at +0x2C tail at +0x28 count at +0x34.
// Evidence: copy ctor row 0x00045455 with 0x4C temp; link through +0x48/+0x4C;
// callers at 0x0049D987 0x0049DC12. A _ReadWriteBarrier between the shift and
// the test keeps retail mov shr test al 1 shape (else folds to test byte 2).
class WeaponTemplateSetHead
{
	char _m[0x4C];

public:
	WeaponTemplateSetHead(const WeaponTemplateSetHead &that);
};

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Rva0049D526Src
{
	char _pad[0x10C];
	WeaponTemplateSetHead m_head;
};

struct Rva0049D526Node
{
	char _pad[0x48];
	void *m_48;
	void *m_4C;
};

class Rva0049D526
{
public:
	void rva0049D526(void *entry);

private:
	char _p00[0x08];
	void *m_08;
	char _p0C[0x1C];
	void *m_28;
	void *m_2C;
	char _p30[0x04];
	int m_34;
	char _p38[0x99];
	unsigned char m_D1;
	char _pD2[0x42];
	unsigned char m_114;
};

void Rva0049D526::rva0049D526(void *entry)
{
	if (m_28 == 0)
		m_28 = entry;
	if (m_2C != 0)
	{
		((Rva0049D526Node *)m_2C)->m_48 = entry;
		((Rva0049D526Node *)entry)->m_4C = m_2C;
	}
	++m_34;
	m_2C = entry;
	Rva0049D526Src *src = *(Rva0049D526Src **)((char *)this + 0x08);
	WeaponTemplateSetHead tmp(src->m_head);
	unsigned v = *(unsigned *)((char *)&tmp + 8);
	v >>= 9;
	_ReadWriteBarrier();
	if ((v & 1) == 0)
	{
		m_D1 |= 2;
		m_114 = 1;
	}
}
