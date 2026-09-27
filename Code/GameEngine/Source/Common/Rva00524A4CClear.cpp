// cl: /O1 /MD
// ?clear@Rva00524A4C@@QAEXXZ @0x00524A4C (25B): clears the +0x0C interface
// pointer through its slot-7 virtual then clears the low two flag bits at
// +0x24. Called by the dtor at 0x00524BB4 and by 0x00524D01 plus a jmp from
// 0x00524A84; vtable 0x00867DFC family. No donor name claimed so the name
// keeps the address token with an honest Rva owner.
class Rva00524A4CInterface
{
public:
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5();
	virtual void f6();
	virtual void slot7();
};

class Rva00524A4C
{
public:
	void clear();

private:
	char m_pad00[0x0C];
	Rva00524A4CInterface *m_ptr;
	char m_pad10[0x14];
	unsigned char m_flags;
};

void Rva00524A4C::clear()
{
	if (m_ptr) {
		m_ptr->slot7();
	}
	m_ptr = 0;
	m_flags &= 0xFC;
}
