// ?rva00583C88@Rva005843DA@@QAEXH@Z
// partial score=0.97 date=2026-09-29
// ?rva00583C88@Rva005843DA@@QAEXH@Z
// partial score=0.97 date=2026-09-29
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?rva00583C88@Rva005843DA@@QAEXH@Z @0x00583C88 44B
// Rva005843DA slot10 vector-flag setter: bounds-checked 28B element dword at +0 set to 2 via idiv count.
// Evidence: vtable 0x0086FC80 slot 0x28 idiv 0x1C imul 0x1C vslot same flags.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class Rva005843DA
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10(int idx);
	void rva00583C88(int idx);
private:
	char m_pad[4];
	void *m_begin;
	void *m_end;
};

void Rva005843DA::rva00583C88(int idx)
{
	if (idx < 0)
		return;
	int count = ((char *)m_end - (char *)m_begin) / 28;
	if ((unsigned)idx >= (unsigned)count)
		return;
	_ReadWriteBarrier();
	*(int *)((char *)m_begin + idx * 28) = 2;
}
