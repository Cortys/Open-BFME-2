// cl: /O1 /MD
// ?rva005391FD@Rva005391FD@@QAEXXZ @0x005391FD 42B
// Honest address-derived loop: count via virtual slot 0x34 then for each
// index call virtual slot 0x3C to get Rva005C4B56 object then call its
// rowed rva005C4CC1. Chain lane after 0x005C4CC1. Prev 0x0053916B float
// getter and next 0x0053997D byte setter. No callers.
class Rva005C4B56
{
public:
	void rva005C4CC1();
};

class Rva005391FD
{
public:
	virtual ~Rva005391FD();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual int s13();
	virtual void s14();
	virtual Rva005C4B56 *s15(int i);
	void rva005391FD();
};

void Rva005391FD::rva005391FD()
{
	int count = s13();
	for (int i = 0; i < count; ++i)
	{
		Rva005C4B56 *p = s15(i);
		p->rva005C4CC1();
	}
}
