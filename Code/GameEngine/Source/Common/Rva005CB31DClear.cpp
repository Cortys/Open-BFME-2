// cl: /O1 /MD
// ??1Rva005CB31D@@QAE@XZ retail 0x005CB31D 26B
// Holder dtor releasing Rva005E0B0F ptr at +0. Retail nulls first via
// and [ecx] 0 then calls rowed ??1Rva005E0B0F@@UAE@XZ and rowed ??3 delete.
// Evidence: outer dtor 0x005CB4E6 destroys three members at +0x10 +0x14 +0x18
// via this address with EH states 1 0 -1 which only member dtors produce.
class Rva005E0B0F
{
public:
	virtual ~Rva005E0B0F();
};

void __cdecl operator delete(void *);

class Rva005CB31D
{
public:
	~Rva005CB31D();

private:
	Rva005E0B0F *m_ptr;
};

Rva005CB31D::~Rva005CB31D()
{
	Rva005E0B0F *p = m_ptr;
	m_ptr = 0;
	if (p != 0) {
		p->Rva005E0B0F::~Rva005E0B0F();
		operator delete(p);
	}
}
