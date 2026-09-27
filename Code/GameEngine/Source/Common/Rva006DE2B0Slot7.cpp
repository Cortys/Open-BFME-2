// cl: /O2 /MD
// ?Rva006DE210@Rva006DE2B0@@UAEPAXHABVEAStringC@@@Z @0x006DE210 34B.
// Virtual slot 7 (offset 0x1C) of vtable 0x008EB150 (class of rowed dtor
// ??1Rva006DE2B0@@UAE@XZ in Rva006D63C0Derived.cpp). Returns the AptValue
// slot at +0x1C when the name equals "__constructor__" via rowed
// EAStringC compare ?rva006D3490@EAStringC@@QBE_NPBD@Z, else null.
// Base vtable 0x008EAED0 slot 7 is the empty xor-eax ret-8 stub at
// 0x0003FD80; this derived class overrides it. No donor; retail-shaped.
class EAStringC
{
public:
	bool rva006D3490(const char *text) const;
};

class Rva006DE2B0
{
public:
	char m_pad[0x18];
	void *m_ctor;
	virtual void *Rva006DE210(int unused, const EAStringC &name);
};

void *Rva006DE2B0::Rva006DE210(int, const EAStringC &name)
{
	if (name.rva006D3490("__constructor__"))
		return m_ctor;
	return 0;
}
