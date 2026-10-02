// cl: /O2 /MD
// ?Rva006F2C50@Rva006F2C50@@UAEXXZ @0x006F2C50 30B.
// Recovered from the ?Rva0070DF60@Rva006DE2B0@@UAEXXZ recipe at 0x0070DF60.
// Same operand-masked shape: release the AptRef member through vtable slot 1,
// clear it, then tail-jump to the rowed clear on the same this. Only the member
// offset (+0x20 here, +0x1C in the template) and the tail target differ; the
// tail is a 5-byte thunk of the rowed Rva006DE150::rva006DE150 at 0x006DE150,
// so the existing name resolves it. Virtual slot 0x2C of the class vtable.
class AptRef
{
public:
	virtual void AddRef();
	virtual void Release();
};

class Rva006DE150
{
public:
	void rva006DE150();
};

class Rva006F2C50
{
public:
	char m_pad[0x1c];
	AptRef *m_ctor;
	virtual void rva006F2C50();
};

void Rva006F2C50::rva006F2C50()
{
	if (m_ctor)
		m_ctor->Release();
	m_ctor = 0;
	((Rva006DE150 *)this)->rva006DE150();
}
