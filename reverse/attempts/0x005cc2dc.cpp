// ?rva005CC2DC@Rva005CC2DC@@QAEXXZ
// partial score=0.97 date=2026-09-29
// ?rva005CC2DC@Rva005CC2DC@@QAEXXZ
// partial score=0.97 date=2026-09-29
// cl: /O1 /MD
// ?rva005CC2DC@Rva005CC2DC@@QAEXXZ retail 0x005CC2DC 47B lazy init cache via
// getter then append self as listener plus virtual slot2 notify. Evidence:
// chain calls append 0x005A0B4C plus getter 0x0042D6D6; caller at 0x00575062.
// ?rva005CC2DC@Rva005CC2DC@@QAEXXZ present-unmatched
struct Rva0042D6D6PtrChaseField { int get() const; };
struct Rva002BA8F1Listener { char opaque[4]; };
struct Rva005A0B4CList { void append(Rva002BA8F1Listener *p); };
struct Cache {
	virtual void s0();
	virtual void s1();
	virtual void s2(int arg);
};
class Rva005CC2DC : public Rva002BA8F1Listener
{
public:
	void rva005CC2DC();
private:
	Rva0042D6D6PtrChaseField *m_4;
	Cache *m_8;
	unsigned char m_C;
};
void Rva005CC2DC::rva005CC2DC()
{
	if (m_8 != 0)
		return;
	int v = m_4->get();
	m_8 = (Cache *)v;
	if (v == 0)
		return;
	((Rva005A0B4CList *)((char *)v + 4))->append(this);
	m_8->s2(m_C);
}
