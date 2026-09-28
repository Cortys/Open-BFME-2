// cl: /O1 /G7 /MD
// ?rva00528309@Rva00528309@@QAEXXZ retail 0x00528309 64B
// Evidence: loop dec count at +0xD8; elem (count+3)*12 + this; clear +0 via 0xAD6F4 plus +4 via 0x2BED91; or +8 -1; caller 0x005283E6
struct Rva000AD6F4
{
	void clear();
	void *m_ptr;
};

struct Rva002BED91
{
	void clear();
	void *m_ptr;
};

struct Rva00528309Elem
{
	Rva000AD6F4 m_a;
	Rva002BED91 m_b;
	int m_c;
};

class Rva00528309
{
public:
	void rva00528309();
private:
	char m_pad[0x24];
	Rva00528309Elem m_elems[15];
	int m_count;
};

void Rva00528309::rva00528309()
{
	while (m_count > 0)
	{
		--m_count;
		Rva00528309Elem &e = m_elems[m_count];
		e.m_a.clear();
		e.m_b.clear();
		e.m_c = -1;
	}
}
