// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0029B17C@Rva0029B17C@@QAEXXZ @0x0029B17C 11B.
// Forwarder: loads member at +0x7F4 then tail-jumps to its vtable slot 9
// (0x24). Callers at 0x00213B3B 0x002B8A27 0x003F7FD2 pass singleton in ecx
// with no stack args and ignore return; same 11B shape as other disp8
// virtual forwards.
struct Helper0029B17C {
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5();
	virtual void f6();
	virtual void f7();
	virtual void f8();
	virtual void slot9();
};
class Rva0029B17C {
public:
	void rva0029B17C();
private:
	char m_pad[0x7F4];
	Helper0029B17C *m_7F4;
};
void Rva0029B17C::rva0029B17C()
{
	m_7F4->slot9();
}
