// cl: /O1
// Retail RVA 0x0053FC81, 24 bytes.
// ?rva0053FC81@Rva0053FC81@@QAEPAV1@PAVRva0053F8E5DwordCounter@@@Z
// Ref-store setter at this+0x0 via rowed inc 0x0053F8E5: store new pointer
// then inc ref on non-null and return this. Callers 0x00540A88 0x005421AA.
// Prev disp8 inc / next div-avg getter. Honest address name.
class Rva0053F8E5DwordCounter
{
public:
	void inc();
};

class Rva0053FC81
{
public:
	Rva0053FC81 *rva0053FC81(Rva0053F8E5DwordCounter *p);

private:
	Rva0053F8E5DwordCounter *m_ptr;
};

Rva0053FC81 *Rva0053FC81::rva0053FC81(Rva0053F8E5DwordCounter *p)
{
	m_ptr = p;
	if (p)
		p->inc();
	return this;
}
