// cl: /O1 /G7 /DNDEBUG /MD /arch:SSE
// ?rva000B3C61@Rva000B3C61@@QAEXH@Z @0x000B3C61 110B
// Evidence: neighbours 0x000B3A68 (same +0x110 class) and 0x000B3E96;
// array at +0x110 stride 0x1c (elem 28B: ptr/floats/int/bytes);
// release via dec [ecx+4] plus slot-0 virtual then clear; three floats
// zeroed via xorps-movss with middle folded to (index+10)*28.
class RefCounted
{
public:
	virtual void rva000B3C61_virt0();
	int m_ref;
};

struct Rva000B3C61Elem
{
	RefCounted *m_ptr;
	float m_f04;
	float m_f08;
	float m_f0C;
	int m_10;
	int m_14;
	unsigned char m_18;
	unsigned char m_19;
	char m_pad1A[2];
};

class Rva000B3C61
{
public:
	void rva000B3C61(int index);
private:
	char m_pad[0x110];
	Rva000B3C61Elem m_items[32];
};

void Rva000B3C61::rva000B3C61(int index)
{
	if (m_items[index].m_ptr)
	{
		RefCounted *p = m_items[index].m_ptr;
		if (--p->m_ref == 0)
			p->rva000B3C61_virt0();
		m_items[index].m_ptr = 0;
	}
	m_items[index].m_10 = 0;
	*(float *)((char *)this + (index + 10) * 28) = 0.0f;
	m_items[index].m_19 = 0;
	m_items[index].m_f0C = 0.0f;
	m_items[index].m_f04 = 0.0f;
	m_items[index].m_18 = 0;
	m_items[index].m_14 = 1;
}
