// cl: /O1
// ?rva003F7E83@Rva003F7E83@@QAEXXZ @0x003F7E83 13B.
// Null-checked tail forward to virtual slot 3 of the +0x1C member.
// Evidence: retail mov ecx,[ecx+0x1C]; test ecx,ecx; je ret; mov eax,[ecx];
// jmp [eax+0xC]. Caller at 0x003F807D is a tail jmp (chain). Slot 3 is the
// fourth virtual; inner layout is honest size-free.
struct Rva003F7E83Inner
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
};
class Rva003F7E83
{
	char m_pad[0x1C];
	Rva003F7E83Inner *m_ptr1C;
public:
	void rva003F7E83();
};

void Rva003F7E83::rva003F7E83()
{
	Rva003F7E83Inner *p = m_ptr1C;
	if (p == 0)
		return;
	p->v3();
}
