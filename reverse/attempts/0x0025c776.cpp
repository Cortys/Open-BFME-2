// ?rva0025C776@BfmeStrVM0@@QAEXHMMMMHH@Z
// partial score=0.94 date=2026-09-29
// ?rva0025C776@BfmeStrVM0@@QAEXHMMMMHH@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /Ob0 /G7 /arch:SSE
// ?rva0025C6E2@BfmeStrVM0@@QAEXHHMMMM@Z @0x0025C6E2 74B evidence: same TU class BfmeStrVM0 as neighbours rva0025C46E rva0025D10F in BfmeConv1435.cpp; array at +0x68 element 24B bounds 3; 6 stack args ret 0x18; unblocks 0x00356724 0x00356889
// ?rva0025C72C@BfmeStrVM0@@QAEXHHMMMM@Z @0x0025C72C 74B twin with const 2 at +0x14 via same array bounds and G7 imul; unblocks 0x0023958B 0x0035C566
// ?rva0025C776@BfmeStrVM0@@QAEXHMMMMHH@Z @0x0025C776 131B evidence: same class offsets +0x110/+0x138 block with divss 1.0/a20; 7 stack args ret 0x1c; float 1.0 VA 0x00BBB8D8

extern float g_Va00BBB8D8;

struct Rva0025C6E2Elem
{
	int m_00;
	float m_04;
	float m_08;
	float m_0c;
	float m_10;
	int m_14;
};

class BfmeStrVM0
{
public:
	virtual ~BfmeStrVM0();
	void rva0025C6E2(int v0, int idx, float f0, float f1, float f2, float f3);
	void rva0025C72C(int v0, int idx, float f0, float f1, float f2, float f3);
	void rva0025C776(int a8, float fc, float f10, float f14, float f18, int a1c, int a20);
private:
	char m_pad04[0x64];
	Rva0025C6E2Elem m_arr[3];
	char m_padB0[0x60];
	int m_110;
	char m_pad114[4];
	int m_118;
	float m_11c;
	float m_120;
	int m_124;
	float m_128;
	float m_12c;
	float m_130;
	float m_134;
	int m_138;
};

void BfmeStrVM0::rva0025C6E2(int v0, int idx, float f0, float f1, float f2, float f3)
{
	if (idx >= 3)
		return;
	Rva0025C6E2Elem &e = m_arr[idx];
	e.m_04 = f0;
	e.m_08 = f1;
	e.m_0c = f2;
	e.m_00 = v0;
	e.m_10 = f3;
	e.m_14 = 1;
}

void BfmeStrVM0::rva0025C72C(int v0, int idx, float f0, float f1, float f2, float f3)
{
	if (idx >= 3)
		return;
	Rva0025C6E2Elem &e = m_arr[idx];
	e.m_04 = f0;
	e.m_08 = f1;
	e.m_0c = f2;
	e.m_00 = v0;
	e.m_10 = f3;
	e.m_14 = 2;
}

// ?rva0025C776@BfmeStrVM0@@QAEXHMMMMHH@Z present-unmatched
void BfmeStrVM0::rva0025C776(int a8, float fc, float f10, float f14, float f18, int a1c, int a20)
{
	m_128 = fc;
	m_12c = f10;
	m_124 = a8;
	int t_a1c = a1c;
	m_130 = f14;
	m_134 = f18;
	m_138 = 1;
	float one = g_Va00BBB8D8;
	m_110 = t_a1c;
	float fdiv = one / (float)a20;
	m_118 = a20;
	m_11c = fdiv;
	m_120 = one;
}
