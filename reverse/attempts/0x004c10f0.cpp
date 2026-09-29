// ?rva004C10F0@Rva004C10F0@@QAEMXZ
// partial score=0.93 date=2026-09-29
// ?rva004C10F0@Rva004C10F0@@QAEMXZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD /arch:SSE2
// ?rva004C10F0@Rva004C10F0@@QAEMXZ 0x004C10F0 49B: Ask-gated float via slot 0x78.
// Evidence: chain from 0x004C0D4F row; prev BfmeConv700; same shape as 0x004C0DF3.
class Rva004C0D4F
{
public:
	bool rva004C0D4F();
};

class RvaInner004C10F0
{
public:
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5();
	virtual void f6();
	virtual void f7();
	virtual void f8();
	virtual void f9();
	virtual void f10();
	virtual void f11();
	virtual void f12();
	virtual void f13();
	virtual void f14();
	virtual void f15();
	virtual void f16();
	virtual void f17();
	virtual void f18();
	virtual void f19();
	virtual void f20();
	virtual void f21();
	virtual void f22();
	virtual void f23();
	virtual void f24();
	virtual void f25();
	virtual void f26();
	virtual void f27();
	virtual void f28();
	virtual void f29();
	virtual float GetFloat();
};

struct RvaSub004C10F0
{
	char m_pad[0x10];
	RvaInner004C10F0 m_inner;
};

class Rva004C10F0
{
public:
	float rva004C10F0();
	char m_pad[0xF0];
	RvaSub004C10F0 *m_sub;
};

// ?rva004C10F0@Rva004C10F0@@QAEMXZ present-unmatched
float Rva004C10F0::rva004C10F0()
{
	if (((Rva004C0D4F *)((char *)this - 0x10))->rva004C0D4F())
		return m_sub->m_inner.GetFloat();
	volatile float zero = 0.0f;
	return zero;
}
