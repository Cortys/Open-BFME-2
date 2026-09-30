// ?rva004E594E@Rva004E594E@@QAEPAV1@ABV?$StringBase@G@@PBURva004E594ESource@@H@Z
// partial score=0.93 date=2026-09-30
// ?rva004E594E@Rva004E594E@@QAEPAV1@ABV?$StringBase@G@@PBURva004E594ESource@@H@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /MD /Oy-
// ?rva004E594E@Rva004E594E@@QAEPAV1@ABV?$StringBase@G@@PBURva004E594ESource@@H@Z present-unmatched
template <typename T> class StringBase
{
	friend class Rva004E594E;
	StringBase(const StringBase &other);
	void *m_data;
};
class DisplayString
{
public:
	virtual void v00();
	virtual void setText(StringBase<unsigned short> txt);
	virtual void v08();
	virtual void v0c();
	virtual void v10();
	virtual void v14();
	virtual void setSource(int val);
	virtual void v1c();
	virtual void v20();
	virtual void v24();
	virtual void tail(int a, int b);
};
class DisplayStringManager
{
public:
	virtual void v00();
	virtual void v04();
	virtual void v08();
	virtual void v0c();
	virtual void v10();
	virtual void v14();
	virtual void v18();
	virtual void v1c();
	virtual void v20();
	virtual void v24();
	virtual void v28();
	virtual void v2c();
	virtual void v30();
	virtual void v34();
	virtual DisplayString *newDisplayString();
};
extern DisplayStringManager *TheDisplayStringManager;
struct Rva004E594ESource
{
	int m_00;
	int m_04;
};
class Rva004E594E
{
public:
	Rva004E594E *rva004E594E(const StringBase<unsigned short> &a1, const Rva004E594ESource *a2, int a3);
private:
	const Rva004E594ESource *m_00;
	DisplayString *m_04;
	int m_08;
	int m_0c;
};
Rva004E594E *Rva004E594E::rva004E594E(const StringBase<unsigned short> &a1, const Rva004E594ESource *a2, int a3)
{
	m_04 = 0;
	m_08 = 0;
	m_00 = a2;
	m_0c = a3;
	m_04 = TheDisplayStringManager->newDisplayString();
	if (m_04 != 0) {
		m_04->setSource(a2->m_04);
		m_04->setText(a1);
		m_04->tail(0, 0);
	}
	return this;
}
