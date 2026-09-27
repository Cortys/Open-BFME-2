// cl: /O1 /DNDEBUG /MD /EHsc
// ??0Rva003AE1A7@@QAE@ABV0@@Z, retail 0x003AE1A7, 38 bytes.
// Derived V3-inline copy: calls rowed base ??0Rva003AE1CD@@QAE@ABV0@@Z at
// 0x003AE1CD then installs its own three vftables (+0 0x00C1CA40,
// +8 0x00C1CA3C, +0x0C 0x00C1CA2C). Caller is 0x003AE19C. Vtable dwords are
// DIR32 sites the gate takes from the target.

class Rva003AE1CD
{
public:
	Rva003AE1CD(const Rva003AE1CD &other);
};

extern "C" char Rva003AE1A7_v0;
extern "C" char Rva003AE1A7_v8;
extern "C" char Rva003AE1A7_v0C;

class Rva003AE1A7
{
public:
	__declspec(noinline) Rva003AE1A7(const Rva003AE1A7 &other);

private:
	void *m_v0;
	char m_pad04[4];
	void *m_v8;
	void *m_v0C;
};

Rva003AE1A7::Rva003AE1A7(const Rva003AE1A7 &that)
{
	const void *src = &that;
	((Rva003AE1CD *)this)->Rva003AE1CD::Rva003AE1CD(*(const Rva003AE1CD *)src);
	*(void **)this = &Rva003AE1A7_v0;
	*(void **)((char *)this + 8) = &Rva003AE1A7_v8;
	*(void **)((char *)this + 0x0C) = &Rva003AE1A7_v0C;
}
