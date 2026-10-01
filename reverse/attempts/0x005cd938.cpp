// ?rva005CD938@Rva005CD938@@QAEXXZ
// partial score=0.96 date=2026-10-01
// cl: /O1 /EHsc /MD
//
// ?rva005CD938@Rva005CD938@@QAEXXZ retail 0x005CD938 118B lazy ensure via delegate.
// Evidence: +4 PtrChase get 0x0042D6AE rowed +C bool; delegate to 0x005CD8A5 via Rva00579E47 0x00579E47 rowed; virtuals +0x14 +4 on get result; Release 0x0007DEEF rowed.
struct TargetRef00217D4C
{
	virtual void *destroy(unsigned int flags);
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);
struct DelegateDesc
{
	void *m_object;
	const void *m_method;
};
extern const void *const g_009CD8A5;
class Rva00579E47
{
public:
	Rva00579E47 &rva00579E47(const DelegateDesc *d) throw();
	~Rva00579E47() { if (m_ptr) ReleaseTreeHintRef00217D4C((TargetRef00217D4C *)m_ptr); }
	void *m_ptr;
};
class Rva0042D6AEPtrChaseField
{
public:
	int get() const;
};
struct Subscribable005CD938
{
	virtual void f0();
	virtual void f1(int v);
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5(Rva00579E47 *w);
};
class Rva005CD938
{
public:
	virtual ~Rva005CD938() {}
	void rva005CD938();
private:
	Rva0042D6AEPtrChaseField *m_4;
	void *m_8;
	bool m_C;
};
// ?rva005CD938@Rva005CD938@@QAEXXZ present-unmatched
void Rva005CD938::rva005CD938()
{
	if (m_C != 0)
		return;
	int v = m_4->get();
	Subscribable005CD938 *obj = (Subscribable005CD938 *)v;
	if (obj == 0)
		return;
	DelegateDesc desc;
	desc.m_method = g_009CD8A5;
	desc.m_object = this;
	{
		Rva00579E47 wrapper;
		wrapper.rva00579E47(&desc);
		obj->f5(&wrapper);
	}
	obj->f1(1);
	m_C = true;
}
