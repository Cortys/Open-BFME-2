// ?rva006FBC10@Rva006FBC90Owner@@UAEXXZ
// partial score=0.92 date=2026-09-30
// ?rva006FBC10@Rva006FBC90Owner@@UAEXXZ
// partial score=0.92 date=2026-09-30
// cl: /O1 /MD
// ?rva006FBC10@Rva006FBC90Owner@@UAEXXZ @0x006FBC10 25B
// VSlot 11 of 0x008ED880 (class Rva006FBC90Owner): if +0x1C calls virtual 0x4
// then tail-jmps rowed Rva006DE150::rva006DE150 0x006DE150. Evidence: no EH,
// donor dtor TU, rowed clear target, flags /O1 /MD like neighbour.
class Inner1C
{
public:
	virtual void s00();
	virtual void v01();
};

class Rva006DE150
{
public:
	void rva006DE150();
};

class Rva006FBC90Owner
{
public:
	virtual void rva006FBC10();
private:
	char m_pad[0x18];
	Inner1C *m_1C;
};

// ?rva006FBC10@Rva006FBC90Owner@@UAEXXZ present-unmatched
void Rva006FBC90Owner::rva006FBC10()
{
	if (m_1C != 0)
		m_1C->v01();
	((Rva006DE150 *)this)->rva006DE150();
}
