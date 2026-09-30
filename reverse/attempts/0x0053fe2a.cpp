// ?rva0053FE2A@Rva0053FE2A@@QAEXPAUS12@@PAUS16@@MH@Z
// partial score=0.9 date=2026-09-30
// ?rva0053FE2A@Rva0053FE2A@@QAEXPAUS12@@PAUS16@@MH@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /arch:SSE
// ?rva0053FE2A@Rva0053FE2A@@QAEXPAUS12@@PAUS16@@MH@Z @0x0053FE2A 58B
// Four-arg setter: dword arg4 to +0, three dwords from arg1 to +4/+8/+0xC,
// 16 bytes from arg2 to +0x10 via movsd x4, float arg3 to +0x20 via movss.
// Evidence: ret 0x10 four stack args; movss xmm0 early plus movsd x4;
// caller at 0x0053FF10.
struct S12
{
	int a;
	int b;
	int c;
};
struct S16
{
	int a;
	int b;
	int c;
	int d;
};
class Rva0053FE2A
{
public:
	void rva0053FE2A(S12 *a1, S16 *a2, float f, int d);
	int m_00;
	int m_04;
	int m_08;
	int m_0c;
	S16 m_10;
	float m_20;
};
// ?rva0053FE2A@Rva0053FE2A@@QAEXPAUS12@@PAUS16@@MH@Z present-unmatched
void Rva0053FE2A::rva0053FE2A(S12 *a1, S16 *a2, float f, int d)
{
	m_00 = d;
	m_04 = a1->a;
	m_08 = a1->b;
	m_0c = a1->c;
	m_10 = *a2;
	m_20 = f;
}
