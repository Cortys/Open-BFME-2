// cl: /O1 /MD
// ?rva00133380@Rva00131BE5@@QAEXXZ @0x00133380 42B.
// Slot 7 (offset 0x1C) of vtable 0x007D25D8 for ??1Rva00131BE5@@UAE@XZ.
// Clears m_14 (+0x14) like the rowed dtor in Rva00131BE5Dtor.cpp but with a
// prior pin-only tail call 0x0013331A and a null store. Evidence: same vtable
// and m_14 offset as the dtor; rowed operator delete 0x0002FD60; virtual slot1
// v04(0) on M14; caller 0x001333AA (28B) and unblocked 0x001333AA; prev/next
// share // cl: /O1 /MD.
class Rva00131BE5M14
{
public:
	virtual void v00();
	virtual void *v04(int);
};

class Rva0013331A
{
public:
	void rva0013331A();
};

void operator delete(void *p);

class Rva00131BE5
{
public:
	void rva00133380();

private:
	char m_pad[0x14];
	Rva00131BE5M14 *m_14;
};

void Rva00131BE5::rva00133380()
{
	((Rva0013331A *)m_14)->rva0013331A();
	void *p;
	if (m_14)
		p = m_14->v04(0);
	else
		p = 0;
	::operator delete(p);
	m_14 = 0;
}
