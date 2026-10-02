// cl: /Ireference/shims/bfme2_ascii /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// ?rva0022161B@Rva0022161B@@QAEXXZ, retail 0x0022161B 26B.
// Holder at +4 of Rva0022167C owns Rva002215F4 pointer at +0; derived dtor
// 0x0022167C stores vtable 0x00BE6BA8 then add ecx,4 jmp here. Evidence: retail
// bytes plus rowed callee ??1Rva002215F4@@UAE@XZ at 0x002215F4 plus rowed
// operator delete 0x0002FD60 plus caller jmp at 0x00221685.
class Rva002215F4 {
public:
	virtual ~Rva002215F4();
};

void __cdecl operator delete(void *block);

class Rva0022161B {
public:
	void rva0022161B();
private:
	Rva002215F4 *m_ptr;
};

void Rva0022161B::rva0022161B()
{
	Rva002215F4 *p = m_ptr;
	m_ptr = 0;
	if (p) {
		p->Rva002215F4::~Rva002215F4();
		::operator delete(p);
	}
}
