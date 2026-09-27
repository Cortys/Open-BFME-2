// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva00111D65@LookupTablePostEffect@@UAEXXZ, retail 0x00111D65, 53 bytes.
// Virtual slot 3 (offset 0xC) of vtable 0x007CFAC8 (class of
// ??0LookupTablePostEffect@@QAE@XZ in LookupTablePostEffectCtor.cpp).
// Guarded resource release: takes the DX8 device mutex, releases the
// ref-counted handle at +0x08 through the rowed helper 0x005F2577, then
// releases the mutex. Callees all rowed (Lock 0x0011F520, release
// 0x005F2577, Assert 0x00120F50). No callers. Honest address name: class
// plus slot are proven, method identity is not.

void BFME_DX8_Thread_Lock();
bool BFME_DX8_Thread_Assert();

class BFMEDX8DeviceLock
{
public:
	BFMEDX8DeviceLock() { BFME_DX8_Thread_Lock(); }
	~BFMEDX8DeviceLock() { BFME_DX8_Thread_Assert(); }
};

class Rva005F2577Holder
{
public:
	void rva005F2577();
private:
	void *m_ptr;
};

class LookupTablePostEffect
{
public:
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void rva00111D65();
	virtual void s4();
private:
	int m_04;
	Rva005F2577Holder m_08;
};

void LookupTablePostEffect::rva00111D65()
{
	BFMEDX8DeviceLock lock;
	m_08.rva005F2577();
}
