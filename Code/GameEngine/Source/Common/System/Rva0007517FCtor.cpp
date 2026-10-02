// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /arch:SSE
// ??0Rva0007517F@@QAE@XZ, retail 0x0007517F, 112 bytes.
// Ctor calls rowed base 0x0030B0E3, installs its own vtable, inits +0x1C/+0x20/+0x24/+0x28,
// builds 20x RubbleFXVec at +0x2C through ehvec iterator 0x00629512, registers
// singleton g_00DE1ED0, zeroes 5 dwords at +0x11C. Evidence: chain packet (calls
// 0x0030B0E3 just landed); array 0x2C..0x11C is 0xF0 = 20*0xC matching RubbleFXVec
// size 0xC from RubbleRiseUpdateModuleDataCtor; ctor 0x656646 is ??0RubbleFXVec
// per LINK BONUS on 0x00256646; dtor slot 0x47FAB3 is the folded free-if-non-null
// shared with BasicStringCharDtor_dup; caller 0x00046A50.

class EmptyBase
{
public:
	~EmptyBase();
};

class Rva0030B0E3
{
public:
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void v3(int a, int b);
	virtual void s4();
	virtual void s5();
	virtual int v6();
	virtual void s7();
	virtual void v8(int a);
	virtual void v9(int a);
	Rva0030B0E3();

private:
	int m_pad04;
	int m_pad08;
	int m_c;
	int m_d;
};

class RubbleFXVec
{
public:
	RubbleFXVec();
	~RubbleFXVec();

private:
	unsigned char m_data[0x0C];
};

extern void *g_00DE1ED0;
extern float g_Va00BBB8D8;

class Rva0007517F : public Rva0030B0E3, public EmptyBase
{
public:
	Rva0007517F();
	virtual void _D10();
	virtual void _D11();
	virtual void _D12();
	virtual void _D13();
	virtual void _D14();
	virtual void _D15();
	virtual void _D16();
	virtual void _D17();
	virtual void _S18(float const *m, float f, int a, int b, int c);
	virtual void rva00075016(float const *p, float f, int a, int b, int c);

private:
	int m_14;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	int m_28;
	RubbleFXVec m_arr[20];
	int m_tail[5];
};

Rva0007517F::Rva0007517F()
	: m_1c(0)
	, m_20(9)
	, m_24(13)
	, m_28(0)
{
	g_00DE1ED0 = this;
	for (int i = 0; i < 5; ++i)
		m_tail[i] = 0;
}

void Rva0007517F::rva00075016(float const *p, float f, int a, int b, int c)
{
	float m[12];
	m[0] = g_Va00BBB8D8;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = p[0];
	m[4] = 0.0f;
	m[5] = g_Va00BBB8D8;
	m[6] = 0.0f;
	m[7] = p[1];
	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = g_Va00BBB8D8;
	m[11] = p[2];
	_S18(m, f, a, b, c);
}
