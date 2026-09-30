// ?rva004C1028@Rva004C1028@@QAEMH@Z
// partial score=0.9 date=2026-09-29
// ?rva004C1028@Rva004C1028@@QAEMH@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /MD /Oy- /arch:SSE
// ?rva004C1028@Rva004C1028@@QAEMH@Z, retail 0x004C1028, 50 bytes.
// Float getter: calls bool helper 0x004C0D4F on outer at this-0x10, on false
// returns 0.0f via SSE xorps, on true tail-jmps virtual slot 2 on inner at
// ([this+0xF0]+0x10) passing through int arg. Evidence: rowed bool callee,
// vptr+8 tail jmp, xmm0 zero plus fld return, neighbours BfmeConv700/575.
class Rva004C0D4F
{
public:
	bool rva004C0D4F();
};

class TailInner
{
public:
	virtual void f0();
	virtual void f1();
	virtual float f2(int x);
};

struct OuterPtr
{
	unsigned char m_pad[0x10];
	TailInner m_inner;
};

class Rva004C1028
{
public:
	float rva004C1028(int x);
private:
	unsigned char m_pad[0xF0];
	OuterPtr *m_pF0;
};

// ?rva004C1028@Rva004C1028@@QAEMH@Z present-unmatched
float Rva004C1028::rva004C1028(int x)
{
	Rva004C0D4F *outer = (Rva004C0D4F *)((char *)this - 0x10);
	if (outer->rva004C0D4F())
		return m_pF0->m_inner.f2(x);
	return 0.0f;
}
